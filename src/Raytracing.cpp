/*

TODO

Use obstacle bounding box to determine whether a ray intersects an obstacle.
Use it to determine whether one vertice is on the object's non-visible side.

*/

#include <cmath>
#include <iostream>

#include <SFML/Graphics.hpp>

#include "Obstacle.hpp"

using namespace sf;
using namespace std;

float DistanceBetween(Vector2f src, Vector2f dest);

int main(int argc, char* argv[])
{
	// Create window
	RenderWindow window(VideoMode(600, 600), "Raytracing");

	// Hide normal mouse cursor
	// window.setMouseCursorVisible(false);

	// Create an obstacle
	Obstacle myObstacle(Vector2f(100.f, 50.f));
	myObstacle.setPosition(400.f, 230.f);

	// Game loop
	while (window.isOpen())
	{
		// Handle events
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		// Update

		// Get all points
		vector<CircleShape*> points = myObstacle.GetAllPoints();

		// Find closest point to mouse
		CircleShape* closest = nullptr;
		for (CircleShape* point : points)
		{
			point->setFillColor(POINT_COLOR);

			if (closest == nullptr)
			{
				closest = point;
			}
			else
			{
				if (DistanceBetween((Vector2f)Mouse::getPosition(window), point->getPosition()) <
					DistanceBetween((Vector2f)Mouse::getPosition(window), closest->getPosition()))
				{
					closest = point;
				}
			}
		}

		// Highlight closest
		if (closest != nullptr)
		{
			closest->setFillColor(Color::Green);
		}

		// Render
		window.clear();
		window.draw(myObstacle);
		window.display();
	}

	return 0;
}

float DistanceBetween(Vector2f src, Vector2f dest)
{
	Vector2f difference = Vector2f((dest.x - src.x), (dest.y - src.y));
	return sqrt(powf(difference.x, 2.f) + powf(difference.y, 2.f));
}