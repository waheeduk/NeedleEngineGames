#pragma once
#include "sprite_component.hpp"
#include <vector>
#include "Vec2.hpp"

class BGSpriteComponent : public SpriteComponent
{
public:
	// Lower draworder indicates its 'further away' from camera
	BGSpriteComponent(class Actor* owner, int drawOrder = 10);
	// Update draw overridden from parent
	void Update(float deltaTime) override;
	void Draw(SDL_Renderer* renderer) override;
	// Set textures used for the background
	void SetBGTextures(const std::vector<SDL_Texture*>& textures);
	// Get/set screen size and scroll speed
	void SetScreenSize(const Vec2& size) { mScreenSize = size; }
	void SetScrollSpeed(float speed) { mScrollSpeed = speed; }
	float GetScrollSpeed() const { return mScrollSpeed; }
private:
	// Struct to encapsulate each bg image and its offset
	struct BGTexture
	{
		SDL_Texture* mTexture;
		Vec2 mOffset;
	};
	std::vector<BGTexture> mBGTextures;
	Vec2 mScreenSize;
	float mScrollSpeed;
};