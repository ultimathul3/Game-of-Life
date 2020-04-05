SRC_DIR=src/
OBJ_DIR=.obj/
LIBS=-lsfml-graphics -lsfml-window -lsfml-system
CPP=main.cpp controls.cpp draw.cpp load_template.cpp next_gen.cpp mouse.cpp
NAME=Game-of-Life

SOURCES=$(wildcard $(SRC_DIR)*.cpp)
OBJECTS=$(subst $(SRC_DIR),$(OBJ_DIR),$(SOURCES:.cpp=.o))

run: $(OBJECTS)
	mv *.o .obj/ || true
	g++ $(OBJECTS) -o $(NAME) $(LIBS)
	./$(NAME)

all: clean $(OBJECTS)
	mv *.o .obj/ || true
	g++ $(OBJECTS) -o $(NAME) $(LIBS)
	./$(NAME)

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

clean:
	rm -rf $(OBJ_DIR)*.o
