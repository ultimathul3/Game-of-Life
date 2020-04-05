#ifndef DECLARATION_HPP
#define DECLARATION


#include <iostream>
#include <fstream>
#include <vector>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;


#define vector3d vector<vector<vector<int>>>
#define vector2d vector<vector<int>>


extern RectangleShape vertical_line, horizontal_line;
extern RenderWindow *window;
extern RectangleShape cell;
extern int width, height;
extern int cells_size;
extern vector3d world;
extern int N, M;
extern bool run;


void load_template(string name);
void controls(Event &event);
void next_gen();
void mouse();
void draw();


#endif