#pragma once
#include "actor.hpp"

//a basic player controlled sprite represented by a circle to test the input/movement systems

class Player : public Actor
{
public:
	Player(class Game* game);
	void UpdateActor(float deltaTime) override;
	void ActorInput(const uint8_t* keyState) override;
};