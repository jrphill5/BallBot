CXX=g++
CXXFLAGS=-O2 -Wall
INCLUDES=`pkg-config --cflags --libs opencv`
PROJECT=bot

all: boneCV.o
	$(CXX) $(CXXFLAGS) $(INCLUDES) boneCV.o -o $(PROJECT)

boneCV.o: boneCV.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c boneCV.cpp -o boneCV.o

clean:
	rm $(PROJECT) *.o *.png
