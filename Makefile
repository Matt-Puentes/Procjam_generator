CC= g++ 
LIBS=-lsfml-graphics -lsfml-window -lsfml-system

SRC= game.cpp \

EXECUTABLE= game

all: $(EXECUTABLE)

$(EXECUTABLE): $(SRC)
	$(CC) -o ${EXECUTABLE} $(SRC) $(LIBS)

clean:
	rm -rf $(OBJECTS) $(EXECUTABLE) core dragonfly.log Makefile.bak *~
