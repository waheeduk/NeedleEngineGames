#include "actor.hpp"
#include "game.hpp"
#include "components.hpp"
#include "Math.hpp"

Actor::Actor(class Game* game)
	:mState(EActive), mPosition{ 0.0f, 0.0f }, mScale(1.0f), mRotation(1.0f), mGame(game), mForwardDir(Vec2(0.0f, -1.0f))
{
	mGame->AddActor(this);
}

Actor::~Actor()
{
	mGame->RemoveActor(this);
	while (!mComponents.empty())
	{
		delete mComponents.back();
	}
}

void Actor::Update(float deltaTime)
{
	if (mState == EActive)
	{
		UpdateComponents(deltaTime);
		UpdateActor(deltaTime);
	}
}

//loops through and updates all the components in an actor
void Actor::UpdateComponents(float deltaTime)
{
	for (auto component : mComponents)
	{
		component->Update(deltaTime);
	}
}

void Actor::UpdateActor(float deltaTime)
{

}

Vec2 Actor::GetForward()
{
	return Vec2(Math::Cos(mRotation), -Math::Sin(mRotation));
}

void Actor::AddComponent(class Component* component)
{
	mComponents.emplace_back(component);
}

void Actor::RemoveComponent(class Component* component)
{
	auto iter = std::find(mComponents.begin(), mComponents.end(), component);
	if (iter != mComponents.end())
	{
		mComponents.erase(iter);
	}
}

void Actor::ActorInput(const uint8_t* keyState)
{
}

void Actor::ProcessInput(const uint8_t* keyState)
{
	if (mState == EActive)
	{
		for (auto component : mComponents)
		{
			component->ProcessInput(keyState);
		}
		ActorInput(keyState);
	}
}
