#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>
#include <SFML/OpenGL.hpp>
#include <yoga/Yoga.h>

int main()
{
	const sf::Clock clock;
	sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "SFML works!");
	auto size = window.getSize();
	std::cout << "Window size: " << size.x << "x" << size.y << std::endl;

	while (window.isOpen())
	{
		while (const std::optional event = window.pollEvent())
		{
			if (event->is<sf::Event::Closed>())
				window.close();
		}

		window.clear();

		glClearColor(
			sin(clock.getElapsedTime().asSeconds()),
			cos(clock.getElapsedTime().asSeconds()),
			tan(clock.getElapsedTime().asSeconds()),
			1);
		glClear(GL_COLOR_BUFFER_BIT);

		window.display();
	}
}
