#pragma once
#include "Entity.h"
#include <iostream>

class EntityBall : public Entity
{
public:
	EntityBall();
	~EntityBall();

	void Update(sf::RenderWindow* window);
	void Reset(sf::RenderWindow* window);
private:

};

