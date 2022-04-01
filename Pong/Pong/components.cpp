#include "components.hpp"
#include "actor.hpp"

Component::Component(Actor* owner, int updateOrder)
	:mOwner(owner)
	, mUpdateOrder(updateOrder)
{
	// adds the component to actor's vector of components
	mOwner->AddComponent(this);
}

Component::~Component()
{
	mOwner->RemoveComponent(this);
}

void Component::Update(float deltaTime)
{
}