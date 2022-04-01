#include "sprite_component.hpp"
#include "json.hpp"
#include "Vec2.hpp"

class TilemapComponent : public SpriteComponent
{
public:
	TilemapComponent(class Actor* owner, int drawOrder = 10);
	void SetTileSize(int w, int h);
	void SetMapSize(int w, int h);
	void LoadTilemap(std::string filename);
	void SetTexture(SDL_Texture* texture);
	void Draw(SDL_Renderer* mRenderer) override;
private:
	Vec2 mTileSize;
	Vec2 mMapSize;
	std::vector<Vec2>mTilePositions; // holds all the different tiles that are to be rendered onto the screen
	SDL_Texture* mTexture;
};