#pragma once

#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include "Game.hpp"
#include <vector>


class Bird {
public:
	Bird( GameDataRef data);
	void draw();
	void animate(float dt);
	void Update(float dt);
	void Tap();
private:
	GameDataRef _data;

	sf::Sprite _birdSprite;
	std::vector<sf::Texture> _animationFrames;

	unsigned int _currentFrame;

	sf::Clock _clock;
	sf::Clock _movementClock;

	int _birdstate;
};