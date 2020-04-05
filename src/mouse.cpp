#include "headers/declaration.hpp"


void mouse()
{
    if (run)
			next_gen();
		else
		{		
			if (Mouse::isButtonPressed(Mouse::Left))
			{
				Vector2i mouse = Mouse::getPosition(*window);
				if (mouse.x >= 0 && mouse.y >= 0 && mouse.x < width && mouse.y < height)
				{
					world[0][mouse.y / cells_size][mouse.x / cells_size] = 1;
				}
			}
			if (Mouse::isButtonPressed(Mouse::Right))
			{
				Vector2i mouse = Mouse::getPosition(*window);
				if (mouse.x >= 0 && mouse.y >= 0 && mouse.x < width && mouse.y < height)
				{
					world[0][mouse.y / cells_size][mouse.x / cells_size] = 0;
				}
			}
		}
}