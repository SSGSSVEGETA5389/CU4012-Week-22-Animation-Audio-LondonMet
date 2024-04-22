#include "Hippo.h"

Hippo::Hippo()
{
	speed = 200;

	MarioSprite.loadFromFile("gfx/HippoSpriteSheet.png");
	setTexture(&MarioSprite);
	setSize(sf::Vector2f(34 * 4, 34* 4));
	setPosition(100, 100);

	//Walk 
	walk.addFrame(sf::IntRect(55, 11,  24,34));
	walk.addFrame(sf::IntRect(78, 10, 24,34));
	walk.addFrame(sf::IntRect(101, 9, 24,36));
	walk.addFrame(sf::IntRect(125, 9, 22,34));
	walk.addFrame(sf::IntRect(147, 10, 24,34));
	walk.addFrame(sf::IntRect(171, 9, 23,36));
	walk.setFrameSpeed(1.f / 10.f);

	//Swim
	swim.addFrame(sf::IntRect(0, 21, 16, 20));
	swim.addFrame(sf::IntRect(16, 21, 16, 20));
	swim.addFrame(sf::IntRect(32, 21, 16, 20));
	swim.setFrameSpeed(1.f / 10.f);

	//Duck
	duck.addFrame(sf::IntRect(254, 71, 34,29));
	//duck.addFrame(sf::IntRect(17, 44, 17, 17));
	duck.setFrameSpeed(1.f / 10.f);

	currentAnimation = &walk;


}

void Hippo::handleInput(float dt)
{
	velocity.x = 0.f;
	
	setTextureRect(currentAnimation->getCurrentFrame());

	//left
	if (input->isKeyDown(sf::Keyboard::A))
	{
		velocity.x = -speed;
		currentAnimation = &walk;
		currentAnimation->setFlipped(true);


	}

	//Right

	else if (input->isKeyDown(sf::Keyboard::D))
	{
		velocity.x = speed;
		currentAnimation = &walk;
		currentAnimation->setFlipped(false);

	}

	//Duck

	else if (input->isKeyDown(sf::Keyboard::S))
	{
		currentAnimation = &duck;
	}

	else
	{
		currentAnimation->reset();
		currentAnimation = &walk;

	}

	//Jump 

	if (input->isKeyDown(sf::Keyboard::W) && canJump)

	{
		Jump(200.f);
		audio->playSoundbyName("jump");


	}
	currentAnimation->animate(dt);


}
