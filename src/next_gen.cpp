#include "headers/declaration.hpp"


void next_gen()
{
	bool life = false;
	for(int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (world[0][i][j])
			{
				life = true;
				if (i > 0)
				{
					if (j > 0) world[1][i - 1][j - 1]++;
					if (j < M - 1) world[1][i - 1][j + 1]++;
					world[1][i - 1][j]++;
				}
				if (j > 0) world[1][i][j - 1]++;
				if (j < M - 1) world[1][i][j + 1]++;
				if (i < N - 1)
				{
					if (j > 0) world[1][i + 1][j - 1]++;
					if (j < M - 1) world[1][i + 1][j + 1]++;
					world[1][i + 1][j]++;
				}
				world[1][i][j]++;
			}
		}
	}

	if (!life)
	{
		run = false;
		window->setFramerateLimit(60);
		return;
	}

	for (int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			if (!world[0][i][j] && world[1][i][j] == 3 || world[0][i][j] && (world[1][i][j] == 3 || world[1][i][j] == 4))
				world[0][i][j] = 1;
			else
				world[0][i][j] = 0;
			world[1][i][j] = 0;
		}
	}
}