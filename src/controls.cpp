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

    if (event.type == Event::KeyReleased && event.key.code == Keyboard::L) 
        load_template("templates/user_template");

    if (event.type == Event::KeyReleased && event.key.code == Keyboard::Num1) 
        load_template("templates/gun");
    
    if (event.type == Event::KeyReleased && event.key.code == Keyboard::Num2) 
        load_template("templates/spaceships");
    
    if (event.type == Event::KeyReleased && event.key.code == Keyboard::Num3) 
        load_template("templates/15x15");
    
    if (event.type == Event::KeyReleased && event.key.code == Keyboard::Num4) 
        load_template("templates/pulsar");
    
    if (event.type == Event::KeyReleased && event.key.code == Keyboard::Num5) 
        load_template("templates/eight");

    if (event.type == Event::KeyReleased && event.key.code == Keyboard::Num6) 
        load_template("templates/pentadecathlon");
    
    if (event.type == Event::KeyReleased && event.key.code == Keyboard::Num7) 
        load_template("templates/r-pentamino");
}