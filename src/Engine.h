/**
* @file Engine.h
* @author Hudson Schumaker
* @brief Defines the Engine class.
* @version 1.0.0
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2025, Dodoi-Lab
*/
#pragma once
#include "Pch.h"

class Engine final {	
private:
	Engine() = default;
	void setup();
	void quit();

public:
	~Engine();
	static Engine& getInstance();
	void start();
};
