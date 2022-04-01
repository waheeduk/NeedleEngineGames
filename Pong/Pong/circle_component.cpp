#include "circle_component.hpp"

CircleComponent::CircleComponent(class Actor* owner)
	:Component(owner),
	mRadius(0.0f)
{

}

const Vec2& CircleComponent::GetCenter() const
{
	return mOwner->GetPosition();
}

