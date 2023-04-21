CXX = g++
CXXFLAGS = -std=c++11 -Wall -lsfml-graphics -lsfml-window -lsfml-system
SRCS = src/main.cpp src/player.cpp src/platform.cpp src/system.cpp
OBJS = $(SRCS:.cpp=.o)
MAIN = src/doodlejump

.PHONY: clean

all: $(MAIN)

$(MAIN): $(OBJS)
	$(CXX) $ $(OBJS) $(CXXFLAGS) -o $(MAIN)

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(MAIN)

main.o: main.cpp platform.cpp player.cpp system.cpp global_headers.hpp
system.o: platform.cpp player.cpp system.cpp global_headers.hpp system.h
player.o: player.cpp global_headers.hpp player.h
platform.o: platfform.cpp global_headers.hpp platform.h

