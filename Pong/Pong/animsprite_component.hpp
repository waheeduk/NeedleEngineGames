#pragma once
#include "sprite_component.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

//first you load in a set of textures
//then you add add one (or more) animation structs
//set the current animation

//struct to define an animation, so we can have a vector of unique animations
struct Animation
{
	int index;
	int frames;
	int speed;
	std::string name;
	bool loop;
	Animation(int i, int f, int s, std::string n, bool l)
		:index(i), frames(f), speed(s), name(n), loop(l) {}
	Animation() {}
	bool operator==(const Animation& rhs) { return (name == rhs.name); }
};


class AnimSpriteComponent : public SpriteComponent
{
public:
	AnimSpriteComponent(class Actor* owner, int drawOrder = 100);
	// Update animation every frame (overridden from component)
	void Update(float deltaTime) override;
	// Set the textures used for animation
	void SetAnimTextures(const std::vector<SDL_Texture*>& textures);
	// Set/get the animation FPS
	float GetAnimFPS() const { return mAnimFPS; }
	void SetAnimFPS(float fps) { mAnimFPS = fps; }
	Animation GetAnimation(std::string name);
	void AddAnimation(Animation animation);
	void SetCurrentAnimation(std::string animation);
private:
	// All textures in the animation
	std::vector<SDL_Texture*> mAnimTextures;
	//set current animation if multiple
	std::vector<Animation>mAnimations;
	Animation mCurrAnimation;
	//the starting frame from whence to start animating
	int mIndex;
	// Current frame displayed
	float mCurrFrame;
	// Animation frame rate
	float mAnimFPS;
	//animation looping flag
	bool mLoop;
};