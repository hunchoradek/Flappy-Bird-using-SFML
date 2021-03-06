#include "Bird.hpp"

Bird::Bird(GameDataRef data) : _data(data) {
	_currentFrame = 0;

	_animationFrames.push_back(_data->assets.GetTexture("1klatka"));
	_animationFrames.push_back(_data->assets.GetTexture("2klatka"));
	_animationFrames.push_back(_data->assets.GetTexture("3klatka"));
	_animationFrames.push_back(_data->assets.GetTexture("4klatka"));

	_birdSprite.setTexture(_animationFrames.at(_currentFrame));

	_birdSprite.setPosition((_data->window.getSize().x / 4) - (_birdSprite.getGlobalBounds().width / 2), (_data->window.getSize().y / 2) - (_birdSprite.getGlobalBounds().height / 2));
	_birdstate = BIRD_STATE_STILL;

	sf::Vector2f origin = sf::Vector2f(_birdSprite.getGlobalBounds().width/2, _birdSprite.getGlobalBounds().height/2);

	_birdSprite.setOrigin(origin);

	_rotation = 0;
}
void Bird::draw(){
	_data->window.draw(_birdSprite);
}
void Bird::animate(float dt) {
	if (_clock.getElapsedTime().asSeconds() > BIRD_ANIMATION_DURATION / 4) {
		if (_currentFrame < 3) {
			_currentFrame++;
		}
		else {
			_currentFrame = 0;
		}
		_birdSprite.setTexture(_animationFrames.at(_currentFrame));

		_clock.restart();
	}
}
void Bird::Update(float dt) {
	if (_birdstate == BIRD_STATE_FALLING) {
		_birdSprite.move(0, GRAVITY * dt);

		_rotation += ROTATION_SPEED * dt;

		if (_rotation > 25.0f) {
			_rotation = 25.0f;
		}
		_birdSprite.setRotation(_rotation);
	}
	else if (_birdstate == BIRD_STATE_FLYING) {
		_birdSprite.move(0, -FLYING_SPEED * dt);

		_rotation -= ROTATION_SPEED * dt;

		if (_rotation < -25.0f) {
			_rotation = -25.0f;
		}
		_birdSprite.setRotation(_rotation);
	}

	if (_movementClock.getElapsedTime().asSeconds() > FLYING_DURATION) {
		_movementClock.restart();
		_birdstate = BIRD_STATE_FALLING;
	}
}
void Bird::Tap() {
	_movementClock.restart();
	_birdstate = BIRD_STATE_FLYING;
}
const sf::Sprite &Bird::GetSprite() const {
	return _birdSprite;
}