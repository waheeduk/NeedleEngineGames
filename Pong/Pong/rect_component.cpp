#include "rect_component.hpp"

RectComponent::RectComponent(class Actor* owner, int w, int h)
	:Component(owner),
	mDimensions(w, h)
{

}

const Vec2& RectComponent::GetPos() const
{
	Vec2 pos = mOwner->GetPosition();
	return pos;
}
