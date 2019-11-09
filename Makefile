CC= g++ 
LIBS=-lsfml-graphics -lsfml-window -lsfml-system

SRC= game.cpp \
Map.cpp \
Room.cpp \
MapMaker.cpp \
Ellipse.cpp \

EXECUTABLE= game

all: $(EXECUTABLE)

$(EXECUTABLE): $(SRC)
	$(CC) -o ${EXECUTABLE} $(SRC) $(LIBS)

clean:
	rm -rf $(OBJECTS) $(EXECUTABLE) core dragonfly.log Makefile.bak *~
