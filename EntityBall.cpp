#include "stdafx.h"
#include "EntityBall.h"


EntityBall::EntityBall()
{
	this->Load("res/ball.png");
}

void EntityBall::Update(sf::RenderWindow* window){
	//velocity = sf::Vector2f(1.0f, 1.0f);
	Entity::Update();
}

void EntityBall::Reset(sf::RenderWindow* window) {
	this->velocity.x = 1.0f;
	this->velocity.y = ((rand() % 2) == 0) ? 1.0f : -1.0f;
	this->setPosition(window->getSize().x / 2, window->getSize().y / 2);
	std::cout << "Reset ball";
}

EntityBall::~EntityBall()
{

}
