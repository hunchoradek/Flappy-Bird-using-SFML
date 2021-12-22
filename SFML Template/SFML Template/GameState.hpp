#pragma once

#include <SFML/Graphics.hpp>
#include "state.hpp"
#include "Game.hpp"
#include "Pipe.hpp"

class GameState : public State {
public:
	GameState(GameDataRef data);
	void Init();

	void HandleInput();
	void Update(float dt);
	void Draw(float dt);

private:
	GameDataRef _data;
	sf::Clock clock;
	sf::Texture _backgroundTexture;
	sf::Sprite _background;
	Pipe* pipe;
};