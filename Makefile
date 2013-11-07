CXX := g++
CXXFLAGS  := -Wall -g -pedantic -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system
OBJETOS := main.o
MODULE := main.cpp

PROJECT := roleandmusic

$(PROJECT): $(OBJETOS)
	$(CXX) $(LDFLAGS) -o $@ $^ $(CXXFLAGS)

all: $(PROJECT)

clean:
	$(RM) $(OBJETOS) $(PROJECT) *~

#juego.o: juego.h tablero.h
#tablero.o: tablero.h
