#pragma once

constexpr auto SCREEN_WIDTH = 768;
constexpr auto SCREEN_HEIGHT = 1024;

constexpr auto SPLASH_STATE_SHOW_TIME = 3.0;

constexpr auto SPLASH_SCENE_BACKGROUND_FILEPATH = "Resources/res/splash.png";
constexpr auto MAIN_MENU_BACKGROUND_FILEPATH = "Resources/res/sky.png";
constexpr auto GAME_BACKGROUND_FILEPATH = "Resources/res/sky.png";
constexpr auto GAME_OVER_BACKGROUND_FILEPATH = "Resources/res/sky.png";

constexpr auto GAME_TITLE_FILEPATH = "Resources/res/title.png";
constexpr auto PLAY_BUTTON_FILEPATH = "Resources/res/PlayButton.png";

constexpr auto PIPE_UP_FILEPATH = "Resources/res/PipeUp.png";
constexpr auto PIPE_DOWN_FILEPATH = "Resources/res/PipeDown.png";
constexpr auto SCORING_PIPE_FILEPATH = "Resources/res/InvisibleScoringPipe.png";

constexpr auto LAND_FILEPATH = "Resources/res/Land.png";

constexpr auto BIRD_FRAME_1_FILEPATH = "Resources/res/bird-01.png";
constexpr auto BIRD_FRAME_2_FILEPATH = "Resources/res/bird-02.png";
constexpr auto BIRD_FRAME_3_FILEPATH = "Resources/res/bird-03.png";
constexpr auto BIRD_FRAME_4_FILEPATH = "Resources/res/bird-04.png";

constexpr auto FLAPPY_FONT_FILEPATH = "Resources/fonts/FlappyFont.ttf";

constexpr auto GAME_OVER_TITLE_FILEPATH = "Resources/res/Game-Over-Title.png";
constexpr auto GAME_OVER_BODY_FILEPATH = "Resources/res/Game-Over-Body.png";

constexpr auto BRONZE = "Resources/res/Bronze-Medal.png";
constexpr auto SILVER = "Resources/res/Silver-Medal.png";
constexpr auto GOLD = "Resources/res/Gold-Medal.png";
constexpr auto PLATINIUM = "Resources/res/Platinum-Medal.png";

constexpr auto PIPE_MOVEMENT_SPEED = 200.0f;
constexpr auto PIPE_SPAWN_FREQUENCY = 3.0f;
constexpr auto BIRD_ANIMATION_DURATION = 0.4f;

constexpr auto BIRD_STATE_STILL = 1;
constexpr auto BIRD_STATE_FALLING = 2;
constexpr auto BIRD_STATE_FLYING = 3;

constexpr auto GRAVITY = 350.0f;
constexpr auto FLYING_SPEED = 350.0f;

constexpr auto FLYING_DURATION = 0.25f;

constexpr auto ROTATION_SPEED = 100.0f;

enum GameStates {
	eReady,
	ePlaying,
	eGameOver
};

constexpr auto FLASH_SPEED = 1500.0f;

constexpr auto TIME_BEFORE_GAME_OVER_APPEARS = 1.5f;