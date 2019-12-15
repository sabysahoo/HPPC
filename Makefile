all: traffic.cpp input.cpp output.cpp
	g++-7 -fopenmp -o traffic traffic.cpp input.cpp output.cpp

clean:
	rm -f traffic
