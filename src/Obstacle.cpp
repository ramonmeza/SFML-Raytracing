#include "Obstacle.hpp"
#include <iostream>

Obstacle::Obstacle(sf::Vector2f size)
{
	m_Shape = new sf::RectangleShape(size);

	Initialize();
}

Obstacle::Obstacle(float width, float height)
{
	m_Shape = new sf::RectangleShape(sf::Vector2f(width, height));

	Initialize();
}

Obstacle::~Obstacle()
{
	// Delete allocated memory from rectangle
	delete m_Shape;
	m_Shape = nullptr;

	// Delete vector of points
	for (sf::CircleShape* point : m_Points)
	{
		delete point;
		point = nullptr;
	}

	// Clear vector of points
	m_Points.clear();
}

void Obstacle::Initialize()
{
	// Set properties for the shape
	m_Shape->setFillColor(OBSTACLE_COLOR);
	m_Shape->setOrigin(m_Shape->getSize().x / 2.f, m_Shape->getSize().y / 2.f);

	// Create points
	if (m_Shape != nullptr)
	{
		// For each point on the rectangle (might change to sf::Shape instead of sf::RectangleShape later on)
		for (int i = 0; i < m_Shape->getPointCount(); i++)
		{
			// Create a new point
			sf::CircleShape* point = new sf::CircleShape(POINT_RADIUS);
			point->setFillColor(POINT_COLOR);
			point->setOrigin(point->getRadius(), point->getRadius());

			// Set new visual point's position to match the actual point's position
			point->setPosition(m_Shape->getPoint(i) + (m_Shape->getPosition() - m_Shape->getOrigin()));

			// Add point to vector of all points
			m_Points.push_back(point);

			// Point the memory to null, just in case
			point = nullptr;
		}
	}
}

void Obstacle::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	// Draw the shape first
	target.draw(*m_Shape);

	// Draw each point on top of the shape
	for(sf::CircleShape* point : m_Points)
	{
		target.draw(*point);
	}
}

void Obstacle::setPosition(float x, float y)
{
	// Set the shape's position
	m_Shape->setPosition(x, y);

	// Set each points' new position
	for (int i = 0; i < m_Shape->getPointCount(); i++)
	{
		m_Points[i]->setPosition(m_Shape->getPoint(i) + (m_Shape->getPosition() - m_Shape->getOrigin()));
	}
}

void Obstacle::setPosition(sf::Vector2f position)
{
	// Use the other setPosition's implemention
	setPosition(position.x, position.y);
}