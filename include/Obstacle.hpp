#pragma once

#include <vector>

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

#define OBSTACLE_COLOR sf::Color::Blue
#define POINT_RADIUS 2.f
#define POINT_COLOR sf::Color::Red

class Obstacle : public sf::Drawable
{
public:
	explicit Obstacle(sf::Vector2f size);
	explicit Obstacle(float width, float height);
	~Obstacle();

	void setPosition(sf::Vector2f position);
	void setPosition(float x, float y);

	// Get rid of this. It's not good. Don't make private members public like this.
	std::vector<sf::CircleShape*> GetAllPoints() { return m_Points; };
	
protected:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	sf::RectangleShape* m_Shape;
	std::vector<sf::CircleShape*> m_Points;

private:
	void Initialize();
};