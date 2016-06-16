#include "stdafx.h"
#include "StateMainMenu.h"
#include "StateGame.h"
#include<iostream>

StateMainMenu::StateMainMenu()
{
}


StateMainMenu::~StateMainMenu()
{
}

void StateMainMenu::Initialize(sf::RenderWindow* window) {
	this->font = new sf::Font;
	if (!this->font->loadFromFile("res/font.ttf")){
		//handle not being able to load font
		//example load a default font
		//this->font->loadFromFile("Arial.ttf");
	}

	this->title = new sf::Text("PONG", *this->font, 256U);
	this->title->setOrigin(this->title->getGlobalBounds().width / 2 +25, this->title->getGlobalBounds().height / 2);
	this->title->setPosition(window->getSize().x / 2, window->getSize().y / 8);

	this->play = new sf::Text("Play", *this->font, 64U);
	this->play->setOrigin(this->play->getGlobalBounds().width / 2, this->play->getGlobalBounds().height / 2);
	this->play->setPosition(window->getSize().x / 2, window->getSize().y / 2 + this->play->getGlobalBounds().height);

	this->quit = new sf::Text("Quit", *this->font, 64U);
	this->quit->setOrigin(this->quit->getGlobalBounds().width / 2, this->quit->getGlobalBounds().height / 2);
	this->quit->setPosition(window->getSize().x / 2, window->getSize().y / 2 + 2*this->play->getGlobalBounds().height);

	this->selected = 0;
	this->upKey = false;
	this->downKey = false;
	this->totalMenuOptions = 2;
}
void StateMainMenu::Update(sf::RenderWindow* window) {
	

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && this->upKey) {
		selected -= 1;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && this->downKey) {
		selected += 1;
	}

	if (this->selected < 0) {
		selected = 0;
	}
	if (this->selected > this->totalMenuOptions - 1) {
		selected = 1;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return) && this->selected == 0) {
		std::cout << "play";
		state.SetState(new StateGame);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return) && this->selected == 1) {
		std::cout << "quit";
		window->close();
	}
	this->upKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up);
	this->downKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down);
}
void StateMainMenu::Render(sf::RenderWindow* window) {
	
	if (selected == 0) {
		quit->setColor(sf::Color::White);
		play->setColor(sf::Color::Blue);

	}
	else {
		play->setColor(sf::Color::White);
		quit->setColor(sf::Color::Blue);

	}

	window->draw(*this->title);
	window->draw(*this->play);
	window->draw(*this->quit);
}
void StateMainMenu::Destroy(sf::RenderWindow* window) {
	delete this->font;
	delete this->title;
	delete this->play;
	delete this->quit;
}