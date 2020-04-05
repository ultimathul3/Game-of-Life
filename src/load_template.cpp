#include "headers/declaration.hpp"


void load_template(string name)
{
	run = false;
	ifstream file(name);
	file >> cells_size;

	width = 1000 - 1000 % cells_size; height = 700 - 700 % cells_size;
	N = height / cells_size; M = width / cells_size;
	world.assign(2,  vector2d(N, vector<int>(M, 0)));
	
	cell.setSize(Vector2f(cells_size, cells_size));
	delete window;
	window = new RenderWindow(VideoMode(width, height), "Game of Live");

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			file >> world[0][i][j];

	file.close();
}