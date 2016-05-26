# Linux (default)
TARGET = ../Bin/Assignment2
CC = g++
DEBUG = -g
LDFLAGS = -lm -lGL -lGLU -lSDL2 -lglut
OPT = -O3
CPPFLAGS = -Wall -Wextra -pedantic -std=c++11 $(OPT) $(DEBUG) -lGLEW
SRC = main.cpp Point3f.cpp SineWave3D.cpp shaders.cpp
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
