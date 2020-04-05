#include "headers/declaration.hpp"


void draw()
{
    for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (world[0][i][j] == 1)
				{
					cell.setPosition(j * cells_size, i * cells_size);
					window->draw(cell);
				}
			}
		}

		for (int i = 0; i < M; i++)
		{
			vertical_line.setPosition(i * cells_size - 1, 0);
			window->draw(vertical_line);
		}
        
		for (int i = 0; i < N; i++)
		{
			horizontal_line.setPosition(0, i * cells_size - 1);
			window->draw(horizontal_line);
		}
}