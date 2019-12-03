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

int performStateSimulation(int vertical_0[], int vertical_1[], int vertical_2[], int vertical_3[], int horizontal_0[], int horizontal_1[], int horizontal_2[], int horizontal_3[], int road_size, bool light_holder[], bool light_state);

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

  //printRoadData(vertical_0, vertical_1, vertical_2, vertical_3, horizontal_0, horizontal_1, horizontal_2, horizontal_3, road_size);

  startSimulation(vertical_0, vertical_1, vertical_2, vertical_3, horizontal_0, horizontal_1, horizontal_2, horizontal_3, road_size, east_light, west_light, north_light, south_light);

  cout<< "The project seems fine! The total_cars are: " << total_cars << "\n";

  return 0;
}

void startSimulation(int vertical_0[], int vertical_1[], int vertical_2[], int vertical_3[], int horizontal_0[], int horizontal_1[], int horizontal_2[], int horizontal_3[], int road_size, int east_light, int west_light, int north_light, int south_light){
  int sleep_time = 3;
  int light_time = sleep_time * 2;  // At green light two states are passed
  int clear_time = sleep_time * 4;
  int local_time = 0;
  bool light_holder[4] = {west_light, south_light, east_light, north_light};
  bool light_state = true;  // this is the clear if false
  while(total_cars > 0 ){
    if(local_time == light_time && light_state == true){
      local_time = 0;
      bool light_store_last = light_holder[3];
      for(int i =3; i>=0; i--){
        light_holder[i] = light_holder[i-1];
      }
      light_holder[0] = light_store_last;
      light_state =  false;
    } else if(local_time == clear_time && light_state == false ) {
      local_time = 0;
      light_state = true;
    }
    local_time += sleep_time;
    int name = performStateSimulation(vertical_0, vertical_1, vertical_2, vertical_3, horizontal_0, horizontal_1, horizontal_2, horizontal_3, road_size, light_holder, light_state);
    sleep(sleep_time);
  }
}

int performStateSimulation(int vertical_0[], int vertical_1[], int vertical_2[], int vertical_3[], int horizontal_0[], int horizontal_1[], int horizontal_2[], int horizontal_3[], int road_size, bool light_holder[], bool light_state){
  int section_xy = (road_size - 4)/2;
  int intesection_crossing_point = section_xy-1;
  if(light_holder[0] == green && light_state == true){
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
    // vertical 0, 1 --- lower part
    if(vertical_0[road_size-1]>0){
        total_cars--;
    }
    if(vertical_1[road_size-1]>0){
        total_cars--;
    }
    for(int i = road_size-1; i>=((road_size-1)-section_xy); i--){
      vertical_0[i] = vertical_0[i-1];
      vertical_1[i] = vertical_1[i-1];
    }
    // vertical 0, 1 --- upper part
    for(int i = intesection_crossing_point; i>=1; i--){
      if(vertical_0[i] == 0){
        vertical_0[i] = vertical_0[i-1];
        vertical_0[i-1] = 0;
      }
      if(vertical_1[i] == 0){
        vertical_1[i] = vertical_1[i-1];
        vertical_1[i-1] = 0;
      }
    }

  } else if(light_holder[1] == green && light_state == false) {
    if(horizontal_2[road_size-1]>0){
        total_cars--;
    }
    if(horizontal_3[road_size-1]>0){
        total_cars--;
    }
    for(int i = road_size-1; i>=section_xy+1; i--){
      horizontal_2[i] = horizontal_2[i-1];
      horizontal_3[i] = horizontal_3[i-1];
    }
    horizontal_2[section_xy] = 0;
    horizontal_3[section_xy] = 0;
    for(int i = intesection_crossing_point; i>=1; i--){
      if(horizontal_2[i] == 0){
        horizontal_2[i] = horizontal_2[i-1];
        horizontal_2[i-1] = 0;
      }
      if(horizontal_3[i] == 0){
        horizontal_3[i] = horizontal_3[i-1];
        horizontal_3[i-1] = 0;
      }
    }

    // vertical 0, 1
    if(vertical_0[road_size-1]>0){
        total_cars--;
    }
    if(vertical_1[road_size-1]>0){
        total_cars--;
    }
    for(int i = road_size-1; i>=((road_size-1)-section_xy); i--){
      vertical_0[i] = vertical_0[i-1];
      vertical_1[i] = vertical_1[i-1];
    }
    // vertical 0, 1 --- upper part
    for(int i = intesection_crossing_point; i>=1; i--){
      if(vertical_0[i] == 0){
        vertical_0[i] = vertical_0[i-1];
        vertical_0[i-1] = 0;
      }
      if(vertical_1[i] == 0){
        vertical_1[i] = vertical_1[i-1];
        vertical_1[i-1] = 0;
      }
    }
  }
    printRoadData(vertical_0, vertical_1, vertical_2, vertical_3, horizontal_0, horizontal_1, horizontal_2, horizontal_3, road_size);
  cout<< "No. of cars exited are: " << total_cars << endl;
  cout<< "Light states are: " << "W:"<< light_holder[0] << "S:"<< light_holder[1] << "E:"<< light_holder[2] << "N:"<< light_holder[3] << endl;
  return 0;
}