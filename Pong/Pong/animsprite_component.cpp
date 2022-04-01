#include "animsprite_component.hpp"
#include "Vec2.hpp"

AnimSpriteComponent::AnimSpriteComponent(Actor* owner, int drawOrder)
	:SpriteComponent(owner, drawOrder), mIndex(0), mLoop(true)
	, mCurrFrame(0.0f)
	, mAnimFPS(24.0f)
{
}

void AnimSpriteComponent::Update(float deltaTime)
{
	SpriteComponent::Update(deltaTime);
	if (mAnimTextures.size() > 0)
	{
		// Update the current frame based on frame rate and delta time
		mCurrFrame += mAnimFPS * deltaTime;
		// Loop current frame if needed
		while (mCurrFrame >= mIndex + mCurrAnimation.frames)
		{
			mCurrFrame -= mCurrAnimation.frames;
		}

		// Set the current texture
		SetTexture(mAnimTextures[static_cast<int>(mCurrFrame)]);
	}
}

void AnimSpriteComponent::SetAnimTextures(const std::vector<SDL_Texture*>& textures)
{
	mAnimTextures = textures;
	if (mAnimTextures.size() > 0)
	{
		// Set the active texture to first frame
		mCurrFrame = 0.0f;
		SetTexture(mAnimTextures[0]);
	}
}

Animation AnimSpriteComponent::GetAnimation(std::string name)
{
	for (int i = 0; i < mAnimations.size() - 1; i++)
	{
		if (mAnimations[i].name == name) return mAnimations[i];
	}
}

void AnimSpriteComponent::AddAnimation(Animation animation)
{
	if (std::find(mAnimations.begin(), mAnimations.end(), animation) == mAnimations.end())
	{
		mAnimations.push_back(animation);
	}
	else
	{
		std::cout << "Error trying to add animation " << animation.name << " as it already exists in list of animations.";
	}
}

void AnimSpriteComponent::SetCurrentAnimation(std::string animation)
{
	mIndex = 0;
	for (int i = 0; i < mAnimations.size() ; i++)
	{
		std::cout << "for loop found animation called " << mAnimations[i].name << std::endl;
		if (mAnimations[i].name == animation)
		{
			mCurrAnimation = mAnimations[i];
			mIndex = mAnimations[i].index;
			mCurrFrame = mIndex;
			mAnimFPS = mAnimations[i].speed;
			mLoop = mAnimations[i].loop;
			std::cout << mCurrAnimation.name << std::endl;
		}
		else
		{
			std::cout << "animation of " << animation << " not found" << std::endl;
		}
	}
}
