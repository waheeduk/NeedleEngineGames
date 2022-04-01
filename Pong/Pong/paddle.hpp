#pragma once
#include "actor.hpp"

class Paddle : public Actor
{
public:
	Paddle(class Game* game);
	void UpdateActor(float deltaTime);
};