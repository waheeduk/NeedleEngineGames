#pragma once

#include "MoveComponent.hpp"
#include <cstdint>

class InputComponent : public MoveComponent
{
public:
	InputComponent(class Actor* owner);

	void ProcessInput(const uint8_t* keyState) override;

	// getters / setters 
	float GetMaxForward() const { return mMaxForwardSpeed; }
	float GetMaxAngular() const { return mMaxAngularSpeed; }
	int GetForwardKey() const { return mForwardKey; }
	int GetBackKey() const { return mBackKey; }
	void SetMaxForwardSpeed(float speed) { mMaxForwardSpeed = speed; }
	void SetMaxAngularSpeed (float speed) { mMaxAngularSpeed = speed; }
	void SetForwardKey(int key) { mForwardKey = key; }
	void SetBackKey(int key) { mBackKey = key; }
	void SetClockwiseKey(int key) { mClockwiseKey = key; }
	void SetAnticlockwiseKey(int key) { mAnticlockwiseKey = key;  }
	int GetClockwiseKey() { return mClockwiseKey; }
	int GetAnticlockwiseKey() { return mAnticlockwiseKey; }
private:
	// The maximum forward/angular speeds
	float mMaxForwardSpeed;
	float mMaxAngularSpeed;
	// Keys for forward/back movement
	int mForwardKey;
	int mBackKey;
	// keys for left right with rotational movement enabled (must be enabled in actor )
	int mClockwiseKey;
	int mAnticlockwiseKey;
};