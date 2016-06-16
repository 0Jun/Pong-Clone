#pragma once
#include "StateManager.h"
#include "EntityBall.h"

class StateGame : public Manager
{
public:
	StateGame();
	~StateGame();
	void Initialize(sf::RenderWindow* window);
	void Update(sf::RenderWindow* window);
	void Render(sf::RenderWindow* window);
	void Destroy(sf::RenderWindow* window);
private:
	EntityBall* ballObject;
	sf::Font* font;
	sf::Text* text;
	
	
};

