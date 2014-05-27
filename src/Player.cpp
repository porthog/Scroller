/*
 * Player.cpp
 *
 *  Created on: May 6, 2014
 *      Author: Charles Miller
 */

#include "Player.hpp"

sf::Texture Player::playerTexture;

Player::Player(sf::Vector2f s, sf::Color c, b2World& w, sf::Vector2f p):
	Object(s, c, w, p)
{
	timer.restart();

	//Player specific
	bodyDef.fixedRotation = true;

}

Player::Player(std::string pa, b2World& w, sf::Vector2f pos):
	Object(pa, w, pos)
{
	timer.restart();

	//Player specific
	bodyDef.fixedRotation = true;


	playerTexture.loadFromFile("res/player.png");

	shape.setTexture(&playerTexture);
	shape.setSize(sf::Vector2f(playerTexture.getSize()));


	dynamicBody.SetAsBox((playerTexture.getSize().x/2)/32, (playerTexture.getSize().y/2)/32);
}

void Player::update(sf::Event e)
{

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		if(body->GetLinearVelocity().y > -1.5)
			body->SetLinearVelocity(b2Vec2(body->GetLinearVelocity().x, -8));
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		if(body->GetLinearVelocity().x > -12)
			body->SetLinearVelocity(b2Vec2(body->GetLinearVelocity().x - 2, body->GetLinearVelocity().y));
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		if(body->GetLinearVelocity().x < 12)
			body->SetLinearVelocity(b2Vec2(body->GetLinearVelocity().x + 2, body->GetLinearVelocity().y));
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		dynamicBody.SetAsBox((shape.getSize().x/2)/30, ((shape.getSize().y/2)/30) - objectTexture.getSize().y*.2);
	}

	else if(e.type == sf::Event::KeyReleased)
	{
		if(e.key.code == sf::Keyboard::Left || e.key.code == sf::Keyboard::Right)
		{
			body->SetLinearVelocity(b2Vec2(0, body->GetLinearVelocity().y));
		}
	}


	shape.setPosition(body->GetPosition().x*30, body->GetPosition().y*30);
	//shape.setRotation(getAngleDegrees(body->GetAngle()));

	//hitbox.setPosition(toSf(body->GetPosition().x), toSf(body->GetPosition().y));
}

void Player::draw(sf::RenderWindow& app)
{
	app.draw(shape);

	if(debug)
		app.draw(hitbox);
}

Player::~Player(){}

sf::RectangleShape Player::getShape()
{
	return shape;
}
