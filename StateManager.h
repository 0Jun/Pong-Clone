#pragma once
#include<SFML/Graphics.hpp>
class Manager {
public:
	//dat poly
	virtual void Initialize(sf::RenderWindow* window) = 0; //Initialize stuff
	virtual void Update(sf::RenderWindow* window) = 0;	//Update positions, Physics and stuff
	virtual void Render(sf::RenderWindow* window) = 0;	//Render the changes on screen
	virtual void Destroy(sf::RenderWindow* window) = 0;	//Destroy~
};

class StateManager {
public:
	StateManager()
	{
		this->state = NULL;
	}

	void SetWindow(sf::RenderWindow* window)
	{
		this->window = window;
	}

	void SetState(Manager* state)
	{
		if (this->state != NULL)
		{
			this->state->Destroy(this->window);
		}
		this->state = state;
		if (this->state != NULL)
		{
			this->state->Initialize(this->window);
		}
	}

	void Update()
	{
		if (this->state != NULL)
		{
			this->state->Update(this->window);
		}
	}

	void Render()
	{
		if (this->state != NULL)
		{
			this->state->Render(this->window);
		}
	}

	~StateManager()
	{
		if (this->state != NULL)
		{
			this->state->Destroy(this->window);
		}
	}

private:
	sf::RenderWindow* window;
	Manager* state;
};

