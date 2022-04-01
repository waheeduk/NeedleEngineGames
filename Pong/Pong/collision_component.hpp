#pragma once
#include "components.hpp"
#include "circle_component.hpp"
#include "rect_component.hpp"
#include <SDL.h>

class CollisionComponent : public Component
{
public:
	//constructor / destructor
	CollisionComponent(class Actor* owner, int UpdateOrder = 10);
	bool CircleCollision(CircleComponent& a, CircleComponent& b);
	bool RectCollision(SDL_Rect& a, SDL_Rect& b);
};