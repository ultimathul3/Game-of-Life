LIBS=-lsfml-graphics -lsfml-window -lsfml-system
OBJECTS=main.o
NAME="Game of Life"

run: $(OBJECTS)
	g++ $(OBJECTS) -o $(NAME) $(LIBS)
	./$(NAME)

main.o: main.cpp
	g++ -c main.cpp
