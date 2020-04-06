#include "headers/declaration.hpp"


RectangleShape vertical_line, horizontal_line;
RenderWindow *window;
RectangleShape cell;
int width, height;
int cells_size;
vector3d world;
int N, M;
bool run = false;


int main()
{
	ifstream file("cells_size.txt");
	file >> cells_size;
	if (!file || cells_size < 5 || cells_size > 100) cells_size = 20;
	file.close();

	width = 1000 - 1000 % cells_size, height = 700 - 700 % cells_size;
	N = height / cells_size, M = width / cells_size;
	world.assign(2,  vector2d(N, vector<int>(M, 0)));

	window = new RenderWindow(VideoMode(width, height), "Game of Live");

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			world[0][i][j] = 0;	

	cell.setSize(Vector2f(cells_size, cells_size));
	cell.setFillColor(Color(0, 100, 0));

	vertical_line.setSize(Vector2f(1, width));
	vertical_line.setFillColor(Color(100, 100, 100));
	horizontal_line.setSize((Vector2f(width, 1)));
	horizontal_line.setFillColor(Color(100, 100, 100));

	cout << "Draw cells and press Enter. Press R to restart." << endl;
	cout << "Press S to save user template. Press L to load user template." << endl;
	cout << "Press 1 to load gun template." << endl;
	cout << "Press 2 to load spaceships template." << endl;
	cout << "Press 3 to load 15x15 template." << endl;
	cout << "Press 4 to load pulsar template." << endl;
	cout << "Press 5 to load eight template." << endl;
	cout << "Press 6 to load pentadecathlon template." << endl;
	cout << "Press 7 to load R-pentamino template." << endl;

	while (window->isOpen())
	{
		Event event;
		while (window->pollEvent(event))
		{
			if (event.type == Event::Closed)
				window->close();
			controls(event);
		}
		
		if (run)
			next_gen();
		else
			mouse();

		window->clear(Color(150, 150, 150));
		draw();
		window->display();
	}

	return 0;
}