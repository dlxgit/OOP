#include "Draw.h"

void DrawShapes(const std::vector<std::shared_ptr<sf::Shape>> & shapes)
{

	sf::RenderWindow window(sf::VideoMode(800, 600), "Shapes");

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
				return;
			}
		}

		window.clear(sf::Color::White);
		for (const auto & elem : shapes)
		{
			window.draw(*elem);
		}

		window.display();
	}
}