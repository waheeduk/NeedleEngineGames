#include "InputComponent.hpp"
#include "actor.hpp"

InputComponent::InputComponent(class Actor* owner)
	:MoveComponent(owner),
	mForwardKey(0),
	mBackKey(0),
	mClockwiseKey(0),
	mAnticlockwiseKey(0),
	mMaxForwardSpeed(0.0f),
	mMaxAngularSpeed(0.0f)
{

}

void InputComponent::ProcessInput(const uint8_t* keyState)
{
	// Calculate forward speed for MoveComponent
	
	if (keyState[mForwardKey])
	{
		AddForce(mOwner->GetForwardDir() * mMaxForwardSpeed);
	}
	if (keyState[mBackKey])
	{
		AddForce(mOwner->GetForwardDir() * mMaxForwardSpeed * -1.0f);
	}
}