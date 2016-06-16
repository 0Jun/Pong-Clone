// Pong.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<SFML\Graphics.hpp>
#include "StateManager.h"
#include "StateMainMenu.h"

StateManager state;
bool quitGame = false;
#define SW 800
#define SH 400
int main()
{
	sf::RenderWindow window(sf::VideoMode( SW, SH), "Pong!");
	window.setFramerateLimit(60);
	const sf::Color color{ sf::Color(13, 8, 13) };
	state.SetWindow(&window);
	state.SetState(new StateMainMenu);
	sf::Event event;

	
	while (window.isOpen()) {
		while (window.pollEvent(event)) { 
			if (event.type == sf::Event::EventType::Closed) {
				window.close();
			}
		}
		if (quitGame) { //close game
			window.close();
		}
		

		window.clear(color);
		state.Update();
		state.Render();
		window.display();
	}
    return 0;
}

