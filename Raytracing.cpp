#include <cmath>

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
	window.setMouseCursorVisible(false);

	// Create an obstacle
	Obstacle myObstacle(Vector2f(100.f, 50.f));

	// Game loop
	while (window.isOpen())
	{
		myObstacle.setPosition(400.f, 230.f);
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

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