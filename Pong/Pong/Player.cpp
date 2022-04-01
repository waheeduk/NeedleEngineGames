#include "Player.hpp"
#include "InputComponent.hpp"
#include "sprite_component.hpp"
#include "game.hpp"

Player::Player(Game* game)
	:Actor(game)
{
	//create sprite
	SpriteComponent* sc = new SpriteComponent(this, 100);
	sc->SetTexture(game->GetTexture("assets/circle.png"));
	//handle input
	InputComponent* ic = new InputComponent(this);
	ic->SetForwardKey(SDL_SCANCODE_W);
	ic->SetBackKey(SDL_SCANCODE_S);
	ic->SetMaxForwardSpeed(3000.0f);

}

void Player::UpdateActor(float deltaTime)
{
	
}

void Player::ActorInput(const uint8_t* keyState)
{
	Vec2 vel = { 0.0f, 0.0f };
	Vec2 pos = this->GetPosition();
	pos += vel;
	this->SetPosition(pos);
}