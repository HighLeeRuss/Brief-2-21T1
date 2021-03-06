#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Graphics.hpp>
#include "kf/kf_log.h"
#include "kf/kf_vector.h"
#include "kf/kf_streams.h"
#include "kf/kf_random.h"
#include "kage/anim.h"
#include "kage/atlas.h"
#include "kage/gameobject.h"
#include "imgui/imgui.h"
#include "kage/imgui-SFML.h"
#include "kage/input.h"
#include "kage/physics.h"
#include "kage/sfml_util.h"
#include "kage/sound_manager.h"
#include "kage/system.h"
#include "kage/texture_manager.h"
#include "kage/world.h"
#include "kage/physics.h"
#include "TileMap.h"

// GameObjects
 #include "Rabbit.h"
#include "Devil.h"
#include "FireBall.h"
#include "Giant.h"
#include "ManaOrb.h"
#include "Player.h"
#include "EndCollider.h"


#pragma warning(disable: 4100)

// Categories for Physics filtering
enum Categories
{
	
};

enum GameState
{
	e_editor = 0,
	e_game,
};


namespace App
{
	// For app_main.cpp. You don't normally need to change these
	bool init();
	void run();
	bool isRunning();
	void quit();
	sf::RenderWindow& getWindow();
	sf::Clock& getClock();
	sf::Font& getFont();
	kf::Xor128& getRNG();
	extern GameState m_currentState;
	

	// For app.cpp. This is where you do most of your stuff.
	bool start();
	void update(float deltaT);
	void updateGame(float deltaT);
	void updateEditor(float deltaT);
	void render();
	void renderGame();
	void renderEditor();
	void cleanup();
	//GameState getState();
	void setState(GameState newState);
	void enterStateEditor();
	void enterStateGame();
	void buildMap();


	// Example of exposing a variable to other files.
	// extern means this isn't actually making the variable, it's just saying its available, 
	// but was physically created somewhere else.
	// Any file that includes app.h can access this variable using App::exampleValue.
	// Consider making get/set functions instead, they are safer.
	extern int exampleValue;
	extern TileMap tileMap;
};
