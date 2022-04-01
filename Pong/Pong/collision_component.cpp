#include "collision_component.hpp"

CollisionComponent::CollisionComponent(class Actor* owner, int UpdateOrder)
	:Component(owner)
{

}

bool CollisionComponent::CircleCollision(CircleComponent& a, CircleComponent& b)
{
	// returns true if collision //
	//gets distance squared between circle components
	Vec2 dist = a.GetCenter();
	float distSq = dist.distanceSq(b.GetCenter());
	//get sum of radii squared 
	float radiiSq = a.GetRadius() + b.GetRadius();
	radiiSq *= radiiSq;

	return distSq <= radiiSq;
}

bool CollisionComponent::RectCollision(SDL_Rect& a, SDL_Rect& b)
{
	//simple AABB collision system
	if (!
		a.x > b.x + b.h &&
		a.x + a.w < b.x &&
		a.y + a.h < b.y &&
		a.y > b.y + b.h
		)
	{
		return true;
	}
	else
	{
		return false;
	}
}