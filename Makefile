all: traffic.cpp input.cpp output.cpp
	g++ -fopenmp -o traffic traffic.cpp input.cpp output.cpp randomgen.cpp debug.cpp randominput.cpp

clean:
	rm -f traffic