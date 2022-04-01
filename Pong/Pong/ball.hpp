#pragma once
#include "actor.hpp"
#include "MoveComponent.hpp"


class Ball : public Actor
{
public:
	Ball(class Game* game);
	void UpdateActor(float deltaTime);
	void ActorInput(const uint8_t* keyState) override;
	Vec2 HandleCollision();
	void SetDirection(Vec2 dir) { mDirection = dir; }
	MoveComponent* mc = new MoveComponent(this);
private:
	float mSpeed;
	Vec2 mDirection;
	bool mMoving;
};