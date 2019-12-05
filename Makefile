all: traffic.cpp input.cpp output.cpp
	g++-7 -o traffic traffic.cpp input.cpp output.cpp

clean:
	rm -f traffic
