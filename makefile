CXX = g++
CXXFLAGS = -std=c++11 -Wall -lgmpxx -lgmp
 

compile: facto.cpp factoring_object.cpp
	$(CXX) facto.cpp factoring_object.cpp $(CXXFLAGS) -o facto
 
run:
	./facto < input
