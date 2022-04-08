CXX = clang++
CXXFLAGS = -Wall -g -O2 -std=c++11
LDFLAGS = -lsfml-system -lsfml-window -lsfml-graphics

TARGETS = main

all: $(TARGETS)

$(TARGETS): Element.o Rectangle.o Circle.o Math.o main.o
	$(CXX) $(LDFLAGS) Element.o Rectangle.o Circle.o Math.o main.o -o $(TARGETS)
Element.o: Element.cc Element.h Math.h
	$(CXX) $(CXXFLAGS) -c -o Element.o Element.cc
Rectangle.o: Rectangle.cc Rectangle.h Element.h
	$(CXX) $(CXXFLAGS) -c -o Rectangle.o Rectangle.cc
Circle.o: Circle.cc Circle.h Element.h
	$(CXX) $(CXXFLAGS) -c -o Circle.o Circle.cc
Math.o: Math.cc Math.h
	$(CXX) $(CXXFLAGS) -c -o Math.o Math.cc
main.o: main.cc Element.h Rectangle.h Circle.h Math.h
	$(CXX) $(CXXFLAGS) -c -o main.o main.cc

clean:
	rm -f $(TARGETS) && rm -f *.o