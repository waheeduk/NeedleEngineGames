#pragma once

#include "components.hpp"
#include <SDL.h>

class SpriteComponent : public Component
{
public:
	// constructor & destructor
	// draw order uses painter algorithm to state where the sprite should be
	// lower number means closer to screen
	SpriteComponent(class Actor* owner, int drawOrder = 100);
	~SpriteComponent();

	virtual void Draw(SDL_Renderer* renderer);
	virtual void SetTexture(SDL_Texture* texture);

	int GetDrawOrder() const { return mDrawOrder; }
	int GetTexHeight() const { return mTexHeight; }
	int GetTexWidth() const { return mTexWidth; }
protected:
	SDL_Texture* mTexture;
	int mDrawOrder;
	int mTexWidth;
	int mTexHeight;
};