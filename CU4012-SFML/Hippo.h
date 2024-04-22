#pragma once
#include "Framework/GameObject.h"
#include "Framework/Animation.h"
class Hippo : public GameObject
{
	int speed;
	sf::Texture MarioSprite;
	Animation walk;
	Animation swim;
	Animation duck;
	Animation* currentAnimation; 

public: 

	Hippo(); 
	void handleInput(float dt) override; 

};

