#include "headers/declaration.hpp"


void controls(Event &event)
{
    if (Keyboard::isKeyPressed(Keyboard::Return))
    {
        run = true;
        window->setFramerateLimit(10);
    }

    if (event.type == Event::KeyReleased && event.key.code == Keyboard::R)
    {
        run = false;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                world[0][i][j] = 0;	
        window->setFramerateLimit(60);
    }

    if (event.type == Event::KeyReleased && event.key.code == Keyboard::S)
    {
        ofstream file("templates/user_template");
        file << cells_size << endl;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                file << world[0][i][j] << ' ';
            }
            file << endl;
        }
        file.close();
    }

    if (event.type == Event::KeyReleased)
    {
        switch(event.key.code)
        {
        case Keyboard::L: load_template("user_template"); break;
        case Keyboard::Num1: load_template("gun"); break;
        case Keyboard::Num2: load_template("spaceships"); break;
        case Keyboard::Num3: load_template("15x15"); break;
        case Keyboard::Num4: load_template("pulsar"); break;
        case Keyboard::Num5: load_template("eight"); break;
        case Keyboard::Num6: load_template("pentadecathlon"); break;
        case Keyboard::Num7: load_template("r-pentamino"); break;
        }
    }
}