CXX = clang++
CXXFLAGS = -Wall -g -O2 -std=c++11
LDFLAGS = -lsfml-system -lsfml-window -lsfml-graphics

TARGETS = main

all: $(TARGETS)

$(TARGETS): Element.o Rectangle.o Circle.o Math.o Game.o Maps.o Physics.o Player.o Text.o ScoreBoard.o main.o 
	$(CXX) $(LDFLAGS) Element.o Rectangle.o Circle.o Math.o Game.o Maps.o Physics.o Player.o Text.o ScoreBoard.o main.o -o $(TARGETS)
Element.o: Element.cc Element.hpp Math.hpp
	$(CXX) $(CXXFLAGS) -c -o Element.o Element.cc
Rectangle.o: Rectangle.cc Rectangle.hpp Element.hpp
	$(CXX) $(CXXFLAGS) -c -o Rectangle.o Rectangle.cc
Circle.o: Circle.cc Circle.hpp Element.hpp
	$(CXX) $(CXXFLAGS) -c -o Circle.o Circle.cc
Math.o: Math.cc Math.hpp
	$(CXX) $(CXXFLAGS) -c -o Math.o Math.cc
Game.o: Game.cc Game.hpp Element.hpp Rectangle.hpp Circle.hpp Physics.hpp Player.hpp Text.hpp
	$(CXX) $(CXXFLAGS) -c -o Game.o Game.cc
Maps.o: Maps.cc Maps.hpp Rectangle.hpp Circle.hpp Text.hpp
	$(CXX) $(CXXFLAGS) -c -o Maps.o Maps.cc
Physics.o: Physics.cc Physics.hpp Math.hpp Element.hpp
	$(CXX) $(CXXFLAGS) -c -o Physics.o Physics.cc
Player.o: Player.cc Player.hpp Rectangle.hpp
	$(CXX) $(CXXFLAGS) -c -o Player.o Player.cc
Text.o: Text.cc Text.hpp Element.hpp
	$(CXX) $(CXXFLAGS) -c -o Text.o Text.cc
ScoreBoard.o: ScoreBoard.cc ScoreBoard.hpp Rectangle.hpp Text.hpp
	$(CXX) $(CXXFLAGS) -c -o ScoreBoard.o ScoreBoard.cc
main.o: main.cc Element.hpp Rectangle.hpp Circle.hpp Math.hpp Game.hpp Maps.hpp Physics.hpp
	$(CXX) $(CXXFLAGS) -c -o main.o main.cc

clean:
	rm -f $(TARGETS) && rm -f *.o