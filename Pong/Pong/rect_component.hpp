#pragma once
#include "components.hpp"

class RectComponent : public Component
{
public:
	RectComponent(class Actor* owner, int w, int h);
	//basic setters getters
	Vec2 GetDimensions() { return mDimensions; }
	const Vec2& GetPos() const;
private:
	Vec2 mDimensions;
};