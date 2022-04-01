#pragma once

#include "Vec2.hpp"
#include <vector>

class Actor
{
public:
	enum State
	{
		EActive,
		EPaused,
		EDead
	};

	//constructor uses dependency injection to access game functions i.e. add another actor

	Actor(class Game* game);
	virtual ~Actor();

	//update from game class
	void Update(float deltaTime);
	//updates actor components
	void UpdateComponents(float deltaTime);
	//updates actor specific code
	virtual void UpdateActor(float deltaTime);

	//getters setters
	State GetState() const { return mState; }
	void SetState(State state) { mState = state;  }
	const Vec2& GetPosition() const { return mPosition;  }
	void SetPosition(const Vec2& pos) { mPosition = pos; }
	float GetScale() const { return mScale; }
	void SetScale(float scale) { mScale = scale; }
	float GetRotation() const { return mRotation; }
	void SetRotation(float rotation) { mRotation = rotation; }
	Vec2 GetForward(); //returns the forward vector from the actor's rotation angle
	void SetForwardDir(Vec2 dir) { mForwardDir = dir;  }
	Vec2 GetForwardDir() { return mForwardDir; }
	class Game* GetGame() { return mGame; }

	//add remove components
	void AddComponent(class Component* component);
	void RemoveComponent(class Component* component);
	//handle input
	virtual void ActorInput(const uint8_t* keyState);
	void ProcessInput(const uint8_t* keyState);
private:
	State mState;
	//transform
	Vec2 mPosition;
	float mScale;
	float mRotation;
	Vec2 mForwardDir;
	//components in actor
	std::vector<class Component*>mComponents;
	class Game* mGame;
};
