LIBS=-lsfml-graphics -lsfml-window -lsfml-system
NAME=Game-of-Life
OBJ_DIR=.obj/
SRC_DIR=src/

OBJECTS=$(subst $(SRC_DIR),$(OBJ_DIR),$(SOURCES:.cpp=.o))
SOURCES=$(wildcard $(SRC_DIR)*.cpp)

run: $(OBJECTS)
	mv *.o .obj/ || true
	g++ $(OBJECTS) -o $(NAME) $(LIBS)
	./$(NAME)

clean:
	rm -rf $(OBJ_DIR)*.o

all: clean run

$(OBJ_DIR)main.o: $(SRC_DIR)main.cpp
	g++ -c $(SRC_DIR)main.cpp

$(OBJ_DIR)controls.o: $(SRC_DIR)controls.cpp
	g++ -c $(SRC_DIR)controls.cpp

$(OBJ_DIR)draw.o: $(SRC_DIR)draw.cpp
	g++ -c $(SRC_DIR)draw.cpp

$(OBJ_DIR)load_template.o: $(SRC_DIR)load_template.cpp
	g++ -c $(SRC_DIR)load_template.cpp

$(OBJ_DIR)next_gen.o: $(SRC_DIR)next_gen.cpp
	g++ -c $(SRC_DIR)next_gen.cpp

$(OBJ_DIR)mouse.o: $(SRC_DIR)mouse.cpp
	g++ -c $(SRC_DIR)mouse.cpp