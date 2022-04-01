#include "game.hpp"
#include "actor.hpp"
#include "sprite_component.hpp"
#include "animsprite_component.hpp"
#include "tilemap_component.hpp"
#include <SDL_image.h>
#include "Math.hpp"

Game::Game(unsigned int screenWidth, unsigned int screenHeight)
	:mWindow(nullptr),
	mRenderer(nullptr),
	mIsRunning(true),
	mUpdatingActors(false)
{
	mIsRunning = true;
	mWindow = nullptr;
	mScreenWidth = screenWidth;
	mScreenHeight = screenHeight;
}

bool Game::Initialise()
{
	//initialises SDL and returns a flag if successful
	int sdlResult = SDL_Init(SDL_INIT_VIDEO);
	//checks initialisation is successful
	if (sdlResult != 0)
	{
		SDL_Log("Unable to initialise SDL %s", SDL_GetError());
		return false;
	}
	//mWindow member variable set to window with params: name, window x/y pos, window width/height, flags
	mWindow = SDL_CreateWindow("GAME", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, mScreenWidth, mScreenHeight, 0);
	//checks window creation is sucessful
	if (!mWindow)
	{
		SDL_Log("Failed to create a window! %s", SDL_GetError());
		return false;
	}
	//checks renderer creation is successful
	mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (!mRenderer)
	{
		SDL_Log("Failed to create a renderer! %s", SDL_GetError());
		return false;
	}

	IMG_Init(IMG_INIT_PNG);

	LoadData();

	return true;
}

void Game::RunLoop()
{
	while (mIsRunning)
	{
		ProcessInput();
		UpdateGame();
		GenerateOutput();
	}
	Shutdown();
}

void Game::UpdateGame()
{
	//clamp frames to 16ms i.e. 60fps
	while (!SDL_TICKS_PASSED(SDL_GetTicks(), mTicksCount + 16));

	float deltaTime = (SDL_GetTicks() - mTicksCount) / 1000.0f;
	if (deltaTime > 0.05f)
	{
		deltaTime = 0.05f;
	}
	mTicksCount = SDL_GetTicks();

	//update all actors
	mUpdatingActors = true;
	for (auto actor : mActors)
	{
		actor->Update(deltaTime);
	}
	mUpdatingActors = false;
	//move pending actors to active actors
	for (auto pending : mPendingActors)
	{
		mActors.emplace_back(pending);
	}
	mPendingActors.clear();
	//move dead actors to a temp vector so as not to interupt loop during iteration and cause crash
	for (auto actor : mActors)
	{
		if (actor->GetState() == Actor::EDead)
		{
			deadActors.emplace_back(actor);
		}
	}
	//delete dead actors
	for (auto actor : deadActors)
	{
		delete actor;
	}
}

void Game::Shutdown()
{
	//deallocates resources and closes SDL
	SDL_DestroyWindow(mWindow);
	SDL_DestroyRenderer(mRenderer);

	//deletes actors
	while (!mActors.empty())
	{
		delete mActors.back();
	}
}

void Game::ProcessInput()
{
	SDL_Event event;
	//checks if there are events in the queue
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			mIsRunning = false;
			break;
		}
	}
	const Uint8* state = SDL_GetKeyboardState(NULL);
	if (state[SDL_SCANCODE_ESCAPE]) mIsRunning = false;
	mUpdatingActors = true;
	for (auto actor : mActors)
	{
		actor->ProcessInput(state);
	}
	mUpdatingActors = false;

}

void Game::GenerateOutput()
{
	SDL_SetRenderDrawColor(mRenderer, 255, 255, 255, 255);
	SDL_RenderClear(mRenderer);
	for (auto sprite : mSprites)
	{
		sprite->Draw(mRenderer);
	}
	SDL_RenderPresent(mRenderer);
}

void Game::AddActor(Actor* actor)
{
	if (mUpdatingActors)
	{
		mPendingActors.emplace_back(actor);
	}
	else
	{
		mActors.emplace_back(actor);
	}
}

void Game::RemoveActor(Actor* actor)
{
	//removes actor if in pending actors, swaps it to back and pop_back
	auto iter = std::find(mPendingActors.begin(), mPendingActors.end(), actor);
	if (iter != mPendingActors.end())
	{
		std::iter_swap(iter, mPendingActors.end() - 1);
		mPendingActors.pop_back();
	}
	//removes actor if in actor vector
	iter = std::find(mActors.begin(), mActors.end(), actor);
	if (iter != mActors.end())
	{
		std::iter_swap(iter, mActors.end() - 1);
		mActors.pop_back();
	}
}

//checks if we've already loaded a reference to an image to prevent numerous unneccessary calls to load data
SDL_Texture* Game::GetTexture(const std::string& filename)
{
	SDL_Texture* texture = nullptr;
	//checks unordered map of textures
	auto iter = mTextures.find(filename);
	//if texture found
	if (iter != mTextures.end())
	{
		texture = iter->second;
	}
	//else loads in the texture
	{
		SDL_Surface* surf = IMG_Load(filename.c_str());
		//error checking
		if (!surf)
		{
			SDL_Log("Failed to load texture %s", filename.c_str());
			return nullptr;
		}
		texture = SDL_CreateTextureFromSurface(mRenderer, surf);
		SDL_FreeSurface(surf);
		if (!texture)
		{
			SDL_Log("Failed to convert surface to texture for %s", filename.c_str());
			return nullptr;
		}
		mTextures.emplace(filename.c_str(), texture);
	}
	return texture;
}

//loads all the game's actors
void Game::LoadData()
{
	//load in game actors
	mPlayer = new Player(this);
	mPlayer->SetPosition(Vec2(50.0f, 100.0f));
	mPlayer->SetForwardDir(Vec2(0.0f, -5.0f));
	mBall = new Ball(this);
	mBall->SetPosition(Vec2((float)mScreenWidth / 2, (float)mScreenHeight / 2));
}

void Game::AddSprite(SpriteComponent* sprite)
{
	int thisDrawOrder = sprite->GetDrawOrder();
	auto iter = mSprites.begin();
	for (; iter != mSprites.end(); ++iter)
	{
		if (thisDrawOrder < (*iter)->GetDrawOrder())
		{
			break;
		}
	}
	//inserts element before position of iterator
	mSprites.insert(iter, sprite);
}

void Game::RemoveSprite(SpriteComponent* sprite)
{

}