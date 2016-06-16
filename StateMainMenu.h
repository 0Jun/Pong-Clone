#pragma once

#include "StateManager.h"
#include <SFML\Graphics.hpp>
#include <iostream>

class StateMainMenu : public Manager{
public:
	StateMainMenu();
	~StateMainMenu();

	void Initialize(sf::RenderWindow* window);
	void Update(sf::RenderWindow* window);
	void Render(sf::RenderWindow* window);
	void Destroy(sf::RenderWindow* window);

private:
	sf::Font* font;
	sf::Text* title;
	sf::Text* play;
	sf::Text* quit;

	int selected;
	int totalMenuOptions;
	bool upKey, downKey;

};


extern StateManager state;
extern bool quitGame;