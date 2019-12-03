all: traffic.cpp input.cpp output.cpp
	g++ -o traffic traffic.cpp input.cpp output.cpp

clean:
	rm -f traffic
