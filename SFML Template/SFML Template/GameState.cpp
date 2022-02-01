#include <sstream>
#include "GameState.hpp"
#include "DEFINITIONS.hpp"

#include <iostream>

GameState::GameState(GameDataRef data) : _data(data) {

}

void GameState::Init() {
	_data->assets.LoadTexture("Game Background", GAME_BACKGROUND_FILEPATH);
	_data->assets.LoadTexture("PipeUp", PIPE_UP_FILEPATH);
	_data->assets.LoadTexture("PipeDown", PIPE_DOWN_FILEPATH);
	_data->assets.LoadTexture("Land", LAND_FILEPATH);
	_data->assets.LoadTexture("1klatka", BIRD_FRAME_1_FILEPATH);
	_data->assets.LoadTexture("2klatka", BIRD_FRAME_2_FILEPATH);
	_data->assets.LoadTexture("3klatka", BIRD_FRAME_3_FILEPATH);
	_data->assets.LoadTexture("4klatka", BIRD_FRAME_4_FILEPATH);

	pipe = new Pipe(_data);
	land = new Land(_data);
	bird = new Bird(_data);

	_background.setTexture(this->_data->assets.GetTexture("Game Background"));

	_gameState = GameStates::eReady;
}

void GameState::HandleInput() {
	sf::Event event;

	while (_data->window.pollEvent(event)) {
		if (sf::Event::Closed == event.type)
			_data->window.close();
		if (_data->input.IsSpriteClicked(_background, sf::Mouse::Left, _data->window)) {
			if (GameStates::eGameOver != _gameState) {
				_gameState = GameStates::ePlaying;
				bird->Tap();
			}
				
		}
	}
}

void GameState::Update(float dt) {
	if (GameStates::eGameOver != _gameState) {
		bird->animate(dt);
		land->MoveLand(dt);
	}

	if (GameStates::ePlaying == _gameState) {
		pipe->MovePipes(dt);
		if (clock.getElapsedTime().asSeconds() > PIPE_SPAWN_FREQUENCY) {
			pipe->RandomisePipeOffset();

			pipe->SpawnInvisiblePipe();
			pipe->SpawBottomPipe();
			pipe->SpawnTopPipe();

			clock.restart();
		}
		bird->Update(dt);

		std::vector<sf::Sprite> pipeSprites = pipe->GetSprites();

		for (int i = 0; i < pipeSprites.size(); i++) {
			if (collision.CheckSpriteCollisionNew(bird->GetSprite(), 0.625f,  pipeSprites.at(i), 1.0f)) {
				_gameState = GameStates::eGameOver;
			}
		}

		std::vector<sf::Sprite> landSprites = land->GetSprites();

		for (int i = 0; i < landSprites.size(); i++) {
			if (collision.CheckSpriteCollision(bird->GetSprite(), landSprites.at(i))) {
				_gameState = GameStates::eGameOver;
			}
		}
	}

}

void GameState::Draw(float dt) {
	_data->window.clear();

	_data->window.draw(_background);
	pipe->DrawPipes();
	land->DrawLand();
	bird->draw();

	_data->window.display();
}
