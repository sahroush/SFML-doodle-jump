CXX = g++
CXXFLAGS = -std=c++17 -Wall -lsfml-graphics -lsfml-window -lsfml-system
SRCS = src/main.cpp src/player.cpp src/platform.cpp src/system.cpp src/entity.cpp
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

main.o: main.cpp platform.cpp player.cpp system.cpp global_stuff.hpp
system.o: platform.cpp player.cpp system.cpp global_stuff.hpp system.hpp
player.o: player.cpp global_stuff.hpp player.hpp
platform.o: platfform.cpp global_stuff.hpp.hpp platform.hpp
entity.o: system.o