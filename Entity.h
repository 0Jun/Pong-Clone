#pragma once
#include<SFML\Graphics.hpp>

class Entity : public sf::Sprite {
public:
	sf::Vector2f velocity;
	Entity() {
		this->texture = new sf::Texture;
	}
	void Load(std::string filename) {
		this->texture->loadFromFile(filename);
		this->setTexture(*this->texture);
	}

	void Update() {
		this->move(this->velocity);
	}

	bool CheckCollision(Entity* entity)
	{
		return this->getGlobalBounds().intersects(entity->getGlobalBounds());
	}

	~Entity() {
		delete this->texture;
	}

private:
	sf::Texture* texture;
};