#include "Zombie.h"

Zombie::Zombie()
{
	speed = 200; 

	ZombieSpriteSheet.loadFromFile("gfx/animZombie.png");
	setSize(sf::Vector2f(55, 108));
	setPosition(100, 100);
	setTexture(&ZombieSpriteSheet);

	//Walk animation

	walk.addFrame(sf::IntRect(0, 0, 55, 108));
	walk.addFrame(sf::IntRect(55, 0, 55, 108));
	walk.addFrame(sf::IntRect(110, 0, 55, 108));
	walk.addFrame(sf::IntRect(165, 0, 55, 108));
	walk.addFrame(sf::IntRect(220, 0, 55, 108));
	walk.addFrame(sf::IntRect(275, 0, 55, 108));
	walk.addFrame(sf::IntRect(330, 0, 55, 108));
	walk.addFrame(sf::IntRect(385, 0, 55, 108));

	walk.setFrameSpeed(1.f / 10.f);
}

Zombie::~Zombie()
{


}

void Zombie::update(float dt)
{
	/*walk.animate(dt); 
	setTextureRect(walk.getCurrentFrame()); */

}

void Zombie::handleInput(float dt)
{
	velocity.x = 0; 
	setTextureRect(walk.getCurrentFrame()); 

	//Right

	if (input->isKeyDown(sf::Keyboard::D))

	{

		velocity.x = speed; 
		walk.setFlipped(false);
		walk.animate(dt);
	}

	//Left

	if (input->isKeyDown(sf::Keyboard::A))

	{
		velocity.x = -speed; 
		walk.setFlipped(true);
		walk.animate(dt);

	}

	//Jump

	if (input->isKeyDown(sf::Keyboard::W) && canJump)

	{
		Jump(200.f);
		audio->playSoundbyName("jump"); 


	}

}
