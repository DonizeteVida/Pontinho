#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>
#include <SFML/OpenGL.hpp>
#include <yoga/Yoga.h>

void calculateShape(YGNodeRef &node, sf::RectangleShape &shape)
{
	const auto left = YGNodeLayoutGetLeft(node);
	const auto top = YGNodeLayoutGetTop(node);
	const auto width = YGNodeLayoutGetWidth(node);
	const auto height = YGNodeLayoutGetHeight(node);

	shape.setPosition({left, top});
	shape.setSize({width, height});
}

int main()
{
	const sf::Clock clock;
	sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "SFML works!");
	sf::RectangleShape shape;

	YGNodeRef root = YGNodeNew();
	YGNodeStyleSetFlexDirection(root, YGFlexDirectionRow);

	YGNodeRef child0 = YGNodeNew();
	YGNodeStyleSetFlexGrow(child0, 1.0f);
	YGNodeStyleSetFlexBasis(child0, 0.0f);
	YGNodeInsertChild(root, child0, 0);

	YGNodeRef child1 = YGNodeNew();
	YGNodeStyleSetFlexGrow(child1, 1.0f);
	YGNodeStyleSetFlexBasis(child1, 0.0f);
	YGNodeInsertChild(root, child1, 1);

	while (window.isOpen())
	{
		while (const std::optional event = window.pollEvent())
		{
			if (event->is<sf::Event::Closed>())
			{
				window.close();
			}
			else if (const auto &resize = event->getIf<sf::Event::Resized>())
			{
				const auto [width, height] = resize->size;

				std::cout << "Resized: " << width << "x" << height << std::endl;

				YGNodeStyleSetWidth(root, width);
				YGNodeStyleSetHeight(root, height);
				YGNodeCalculateLayout(root, width, height, YGDirectionLTR);
			}
		}

		window.clear(sf::Color::Black);

		calculateShape(child0, shape);
		shape.setFillColor(sf::Color::Red);
		window.draw(shape);

		calculateShape(child1, shape);
		shape.setFillColor(sf::Color::Green);
		window.draw(shape);

		window.display();
	}
}
