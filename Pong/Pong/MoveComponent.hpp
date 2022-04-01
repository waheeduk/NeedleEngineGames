#pragma once
#include "components.hpp"
#include "Math.hpp"

class MoveComponent : public Component
{
public:
	MoveComponent(class Actor* owner, int UpdateOrder = 10);
	void Update(float deltaTime) override;
	float GetForwardSpeed() { return mForwardSpeed; }
	void SetForwardSpeed(float speed) { mForwardSpeed = speed; }
	float GetAngularSpeed() { return mAngularSpeed; }
	void SetAngularSpeed(float speed) { mAngularSpeed = speed; }
	void SetRotationalFlag(bool flag) { mRotationalMovement = flag; }
	void AddForce(Vec2 force) { mSumForces += force; }
	float mMass;
	Vec2 mSumForces;
	Vec2 mVelocity;
private:
	//controls rotational speed
	float mAngularSpeed;
	//controls movement speed
	float mForwardSpeed;
	//controls whether rotational control is allowed or whether its along four axes
	bool mRotationalMovement;

};