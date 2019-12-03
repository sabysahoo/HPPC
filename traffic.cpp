#include <iostream>
#include <fstream>
#include "header.h"
#include <unistd.h>
using namespace std; 

// Cars States: 0 is No Car, 1 is Car moving Straight, 2 is Car turning Left
// 3 is Car turning Right
const int no_car = 0;
const int straight_car = 1;
const int left_car = 2;
const int right_car = 3;

// Traffic Light States: 0 is Red Light, 1 is Green Light 
const int red = 0;
const int green = 1;

// Total number of cars from the input.
int total_cars = 0;

void startSimulation(int vertical_0[], int vertical_1[], int vertical_2[], int vertical_3[], int horizontal_0[], int horizontal_1[], int horizontal_2[], int horizontal_3[], int road_size, int east_light, int west_light, int north_light, int south_light);

int performStateSimulation(int vertical_0[], int vertical_1[], int vertical_2[], int vertical_3[], int horizontal_0[], int horizontal_1[], int horizontal_2[], int horizontal_3[], int road_size, int east_light, int west_light, int north_light, int south_light);

int main(int argc, char** argv){
 
  string file_name = argv[1];
  // Total number of cars in one road. Reads the input file and gets array dimensions.
  int road_size = getRoadSize(file_name);
  std::cout<< "The dimensions are: " << road_size << " \n" ;

  // Lights for each intesection are named in the direction of the cars moving.
  bool east_light = red;
  bool west_light = green;
  bool north_light = red;
  bool south_light = red;
  
  int horizontal_0 [road_size], horizontal_1 [road_size], horizontal_2 [road_size], horizontal_3 [road_size];
  int vertical_0 [road_size], vertical_1 [road_size], vertical_2 [road_size], vertical_3 [road_size];

  total_cars = readInput(file_name, road_size, total_cars, vertical_0, vertical_1, vertical_2, vertical_3, horizontal_0, horizontal_1, horizontal_2, horizontal_3);

  //printRoadTop(vertical_0, vertical_1, vertical_2, vertical_3, road_size);

  printRoadData(vertical_0, vertical_1, vertical_2, vertical_3, horizontal_0, horizontal_1, horizontal_2, horizontal_3, road_size);

  startSimulation(vertical_0, vertical_1, vertical_2, vertical_3, horizontal_0, horizontal_1, horizontal_2, horizontal_3, road_size, east_light, west_light, north_light, south_light);

  cout<< "The project seems fine! The total_cars are: " << total_cars << "\n";

  return 0;
}

void startSimulation(int vertical_0[], int vertical_1[], int vertical_2[], int vertical_3[], int horizontal_0[], int horizontal_1[], int horizontal_2[], int horizontal_3[], int road_size, int east_light, int west_light, int north_light, int south_light){

  while(true){
    cout << "zach" << endl;
    int name = performStateSimulation(vertical_0, vertical_1, vertical_2, vertical_3, horizontal_0, horizontal_1, horizontal_2, horizontal_3, road_size, east_light, west_light, north_light, south_light);
    sleep(3);
  }

}

int performStateSimulation(int vertical_0[], int vertical_1[], int vertical_2[], int vertical_3[], int horizontal_0[], int horizontal_1[], int horizontal_2[], int horizontal_3[], int road_size, int east_light, int west_light, int north_light, int south_light){
  if(west_light == green){
    if(horizontal_2[road_size-1]>0){
        total_cars--;
    }
    if(horizontal_3[road_size-1]>0){
        total_cars--;
    }
    for(int i = road_size-1; i>=1; i--){
      horizontal_2[i] = horizontal_2[i-1];
      horizontal_3[i] = horizontal_3[i-1];
    }
    horizontal_2[0] = 0;
    horizontal_3[0] = 0;
  }
  cout<< "No. of cars exited are: " << total_cars << endl;
    printRoadData(vertical_0, vertical_1, vertical_2, vertical_3, horizontal_0, horizontal_1, horizontal_2, horizontal_3, road_size);
  return 0;
}