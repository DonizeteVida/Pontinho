#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>
#include <SFML/OpenGL.hpp>

int main()
{
	const sf::Clock clock;
	sf::RenderWindow window( sf::VideoMode( { 200, 200 } ), "SFML works!" );
	sf::CircleShape shape( 100.f );
	shape.setFillColor( sf::Color::Green );

	while ( window.isOpen() )
	{
		while ( const std::optional event = window.pollEvent() )
		{
			if ( event->is<sf::Event::Closed>() )
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
