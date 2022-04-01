#ifndef GAME_H
#define GAME_H
#include <SDL.h>
#include <vector>
#include <string>
#include <unordered_map>
#include "Player.hpp"
#include "ball.hpp"

class Game
{
public:
	//constructor
	Game(unsigned int screenWidth, unsigned int screenHeight);
	//initialise SDL
	bool Initialise();
	//main game loop
	void RunLoop();
	//shutdown
	void Shutdown();
	
	void AddActor(class Actor* actor);
	void RemoveActor(class Actor* actor);
	SDL_Texture* GetTexture(const std::string& filename);

	void AddSprite(class SpriteComponent* sprite);
	void RemoveSprite(class SpriteComponent* sprite);
	Vec2 GetScreenDimensions() { return Vec2((float)mScreenWidth, (float)mScreenHeight); }
private:
	//main game loop function
	void ProcessInput();
	void UpdateGame();
	void GenerateOutput();
	void LoadData();

	//renderer
	SDL_Renderer* mRenderer;

	//map of all textures loaded into the game
	std::unordered_map<std::string, SDL_Texture*> mTextures;

	//window management
	SDL_Window* mWindow;
	bool mIsRunning;
	bool mUpdatingActors;
	unsigned int mScreenWidth;
	unsigned int mScreenHeight;

	//delta time variable
	Uint32 mTicksCount;

	//gameObjects
	std::vector<class Actor*>mActors;
	std::vector<class Actor*>mPendingActors;
	std::vector<class Actor*>deadActors;
	std::vector<class SpriteComponent*>mSprites;

	Player* mPlayer;
	Ball* mBall;
};

#endif