#include "stdafx.h"
#include "StateGame.h"
#include "StateMainMenu.h"



void StateGame::Initialize(sf::RenderWindow* window){
	this->font = new sf::Font();
	this->font->loadFromFile("res/font.ttf");
	this->ballObject = new EntityBall();
	this->ballObject->Reset(window);
}
void StateGame::Update(sf::RenderWindow* window){
	this->ballObject->Update(window);
}


void StateGame::Render(sf::RenderWindow* window){
	window->draw(*this->ballObject);
}
void StateGame::Destroy(sf::RenderWindow* window){}



StateGame::StateGame()
{
}


StateGame::~StateGame()
{
	delete this->font;
	delete this->text;
	delete this->ballObject;
}