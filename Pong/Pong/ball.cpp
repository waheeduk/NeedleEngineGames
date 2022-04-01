#include "ball.hpp"
#include "game.hpp"
#include "sprite_component.hpp"
#include "collision_component.hpp"

Ball::Ball(Game* game)
	:Actor(game),
	mSpeed(1.0f),
	mDirection(Vec2(0.0f, 2000.0f)),
	mMoving(false)
{
	//create sprite component
	SpriteComponent* sc = new SpriteComponent(this);
	sc->SetTexture(game->GetTexture("assets/circle.png"));
	//create collision component
	CollisionComponent* cc = new CollisionComponent(this);
}

void Ball::UpdateActor(float deltaTime)
{
	if (mMoving == true)
	{
		//stops ball from going above or below screen
		mc->AddForce(mDirection);
		if (this->GetPosition().y < 0)
		{
			SetDirection(Vec2(mDirection.x, mDirection.y *= -1));
		}
		if (this->GetPosition().y >= this->GetGame()->GetScreenDimensions().y)
		{
			SetDirection(Vec2(mDirection.x, mDirection.y *= -1));
		}
		//collides ball with paddles

		//detects if a point was scored
	}
}
void Ball::ActorInput(const uint8_t* keyState)
{
	if ((mMoving == false) && (keyState[SDL_SCANCODE_SPACE]))
	{
		mMoving = true;
	}
}
Vec2 Ball::HandleCollision()
{
	return Vec2(1.0f, 0.0f);
}