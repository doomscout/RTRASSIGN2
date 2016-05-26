# Linux (default)
TARGET = ../Bin/Assignment1
CC = g++
DEBUG = -g
LDFLAGS = -lm -lGL -lSDL2 -lglut  -lGLU
OPT = -O3
CPPFLAGS = -Wall -Wextra -pedantic -std=c++11 $(OPT) $(DEBUG) -lGLEW
SRC = sinewave3D-glm.cpp shaders.cpp
OBJ := $(SRC:.cpp=.o)
#executable
all : $(TARGET)

$(TARGET) : $(OBJ)
	$(CC) -o $@ $(OBJ) $(LDFLAGS)

-include depend

depend :
	$(CC) $(CPPFLAGS) -MM $(SRC) > depend

.PHONY : clean

clean :
	-rm -f depend
	-rm -f $(TARGET) $(OBJ)
	-rm -f *~




