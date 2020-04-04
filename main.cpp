#include <SFML/Graphics.hpp>
using namespace sf;


int main()
{
	RenderWindow window(VideoMode(800, 600), "Game of Life");
	window.setFramerateLimit(60);

	srand(time(0));


	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}


		window.clear(Color::White);
		window.display();
	}

	return 0;
}