#pragma once

#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include <vector>
#include "DEFINITIONS.hpp"

class Pipe {
public:
	Pipe(GameDataRef data);
	void SpawBottomPipe();
	void SpawnTopPipe();
	void SpawnInvisiblePipe();
	void MovePipes( float dt);
	void DrawPipes();
private:
	GameDataRef _data;
	std::vector<sf::Sprite> pipeSprites;
};
