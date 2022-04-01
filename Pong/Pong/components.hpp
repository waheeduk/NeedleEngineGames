#pragma once

#include "actor.hpp"

class Component
{
public:
	// constructor
	// components are updated with smallest number first
	Component(class Actor* owner, int updateOrder = 100);
	// destructor
	virtual ~Component();
	// Update this component by delta time
	virtual void Update(float deltaTime);
	virtual void ProcessInput(const uint8_t* keyState) {};

	int GetUpdateOrder() const { return mUpdateOrder; }
protected:
	// actor that owns the component
	class Actor* mOwner;
	// update order of component
	int mUpdateOrder;
};
