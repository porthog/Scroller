/*
 * Terrain.hpp
 *
 *  Created on: May 27, 2014
 *      Author: Charles Miller
 */

#ifndef TERRAIN_HPP_
#define TERRAIN_HPP_

#include <iostream>
#include <SFML/Graphics.hpp>

#include "Base.hpp"

#include "sub/b2toSf.hpp"

enum terrainType
{
	grass,
	ice,
	lava
};

class Terrain
{
public:

	Terrain(b2World& w, sf::Vector2f s, sf::Vector2f p);

	virtual terrainType getType();

	virtual void update();

	virtual void draw(sf::RenderWindow& app);

	virtual ~Terrain();

protected:

	Body m_body;

private:

	terrainType m_type;

};



#endif /* TERRAIN_HPP_ */
