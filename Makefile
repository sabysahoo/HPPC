all: traffic.cpp input.cpp output.cpp
	g++ -fopenmp -o traffic traffic.cpp input.cpp output.cpp

clean:
	rm -f traffic
