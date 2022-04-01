#include "tilemap_component.hpp"
#include <fstream>
#include <iostream>
using json = nlohmann::json;


TilemapComponent::TilemapComponent(class Actor* owner, int drawOrder)
	:SpriteComponent(owner, drawOrder)
{

}

void TilemapComponent::SetTileSize(int w, int h)
{
	mTileSize = { (float)w, (float)h };
}

void TilemapComponent::SetMapSize(int w, int h)
{
	mMapSize = { (float)w, (float)h };
}

void TilemapComponent::LoadTilemap(std::string filename)
{
	std::ifstream mapFile(filename);
	if (!mapFile)
	{
		std::cout << "Cannot open file "<<filename<<" in tilemap component.";
	}
	else
	{
		json data;
		mapFile >> data;
		int length = data["layers"].size();
		std::cout << "layer length (ie number of layers) is " << length << std::endl;
		std::cout << "data layer 1 size is ";
		std::cout << data["layers"][length - 1]["data"].size() << std::endl;
		for (int i = 0; i < data["layers"][length - 1]["data"].size(); i++)
		{
			Vec2 res;
			int d = data["layers"][length - 1]["data"][i];
			int x = ((d - 1) % 8) * mTileSize.x;
			int y = ((d - 1) / 8) * mTileSize.y;
			res = { float(x), float(y) };
			std::cout << res.x << " " << res.y << std::endl;
			mTilePositions.push_back(res);
		}
	}
}

void TilemapComponent::SetTexture(SDL_Texture* texture)
{
	mTexture = texture;
}

void TilemapComponent::Draw(SDL_Renderer* mRenderer)
{
	for (int i = 0; i < mTilePositions.size(); i++)
	{
		SDL_Rect r;
		SDL_Rect t;
		r.w = mTileSize.x;
		t.w = mTileSize.x;
		r.h = mTileSize.y;
		t.h = mTileSize.y;
		r.x = mTilePositions[i].x;
		r.y = mTilePositions[i].y;
		t.x = (i % 4) * mTileSize.x;
		t.y = (i / 4) * mTileSize.y;
		std::cout << t.x << " " << t.y << std::endl;
		SDL_RenderCopyEx(
			mRenderer,
			mTexture,
			&r,
			&t,
			0,
			nullptr,
			SDL_FLIP_NONE
		);
	}
}