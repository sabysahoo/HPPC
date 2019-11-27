#include <iostream>
#include <fstream>
#include "header.h"
using namespace std; 

int main(int argc, char** argv){

  // Cars States: 0 is No Car, 1 is Car moving Straight, 2 is Car turning Left
  // 3 is Car turning Right
  const int no_car = 0;
  const int straight_car = 1;
  const int left_car = 2;
  const int right_car = 3;
 
  // Traffic Light States: 0 is Red Light, 1 is Green Light 
  const int red = 0;
  const int green = 1;
 
  string file_name = argv[1];
  // Total number of cars in one road. Reads the input file and gets array dimensions.
  int road_size = getRoadSize(file_name);
  std::cout<< "The dimensions are: " << road_size << " \n" ;

  // Total number of cars from the input.
  int total_cars = 0;
  
  // Lights for each intesection are named in the direction of the cars moving.
  bool east_light = red;
  bool west_light = red;
  bool north_light = red;
  bool south_light = red;
  
  int horizontal_0 [road_size], horizontal_1 [road_size], horizontal_2 [road_size], horizontal_3 [road_size];
  int vertical_0 [road_size], vertical_1 [road_size], vertical_2 [road_size], vertical_3 [road_size];

  total_cars = readInput(file_name, road_size, total_cars, vertical_0, vertical_1, vertical_2, vertical_3, horizontal_0, horizontal_1, horizontal_2, horizontal_3);

  printRoadTop(vertical_0, vertical_1, vertical_2, vertical_3, road_size);

  printRoadData(vertical_0, vertical_1, vertical_2, vertical_3, horizontal_0, horizontal_1, horizontal_2, horizontal_3, road_size);

  cout<< "The project seems fine! The total_cars are: " << total_cars << "\n";

  return 0;
}
