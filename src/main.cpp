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
	sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Pontino");
	window.setFramerateLimit(30);
	window.setVerticalSyncEnabled(true);

	sf::RectangleShape shape;

	YGNodeRef root = YGNodeNew();
	YGNodeStyleSetFlexDirection(root, YGFlexDirectionRow);

	YGNodeRef child0 = YGNodeNew();
	YGNodeStyleSetFlexDirection(child0, YGFlexDirectionRow);
	YGNodeStyleSetFlexGrow(child0, 1.0f);
	YGNodeInsertChild(root, child0, 0);

	YGNodeRef child1 = YGNodeNew();
	YGNodeStyleSetFlexGrow(child1, 1.0f);
	YGNodeInsertChild(root, child1, 1);

	YGNodeRef child0_1 = YGNodeNew();
	YGNodeStyleSetFlexGrow(child0_1, 1.0f);
	YGNodeInsertChild(child0, child0_1, 0);

	YGNodeRef child0_2 = YGNodeNew();
	YGNodeStyleSetFlexGrow(child0_2, 1.0f);
	YGNodeInsertChild(child0, child0_2, 1);

	YGNodeRef child0_3 = YGNodeNew();
	YGNodeStyleSetFlexGrow(child0_3, 1.0f);
	YGNodeInsertChild(child0, child0_3, 1);

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

				window.setView(sf::View(sf::FloatRect({0, 0}, {(float)width, (float)height})));

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

		calculateShape(child0_1, shape);
		shape.setFillColor(sf::Color::Blue);
		window.draw(shape);

		calculateShape(child0_2, shape);
		shape.setFillColor(sf::Color::Yellow);
		window.draw(shape);

		calculateShape(child0_3, shape);
		shape.setFillColor(sf::Color::Cyan);
		window.draw(shape);

		window.display();
	}
}
