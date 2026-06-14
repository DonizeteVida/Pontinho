#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>
#include <SFML/OpenGL.hpp>

#include <yoga/Yoga.h>

#include <assets/font.h>

#include <WidgetContext.hpp>
#include <Container.hpp>
#include <Column.hpp>
#include <Row.hpp>
#include <Text.hpp>

void printNodes(YGNodeRef node) {
	auto count = YGNodeGetChildCount(node);

	std::cout << "Begin: " << count << '\n';
	for (int i = 0; i < count; i++) {
		auto child = YGNodeGetChild(node, i);
		printNodes(child);
	}
	std::cout << "End" << '\n';
} 

int main()
{
	sf::Font font(default_font_ttf, default_font_ttf_size);
	sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Pontino");
	window.setFramerateLimit(30);
	window.setVerticalSyncEnabled(true);

	Pontinho::ContainerWidget root;
	Pontinho::WidgetContext::PushParent(root.node);

	Pontinho::Column([&] {
		Pontinho::Column([&] {
			Pontinho::Text(font, "B");
			Pontinho::Text(font, "C");
			Pontinho::Text(font, "D");
		});

		Pontinho::Column([&] {
			Pontinho::Text(font, "E");
			Pontinho::Text(font, "F");
			Pontinho::Text(font, "G");
		});
	});

	printNodes(root.node);

	assert(root.node == Pontinho::WidgetContext::Get());

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

				root.SetWidth(width);
				root.SetHeight(height);
				YGNodeCalculateLayout(root.node, YGUndefined, YGUndefined, YGDirectionLTR);
			}
		}

		window.clear(sf::Color::Black);

		root.Draw(window);

		window.display();
	}
}
