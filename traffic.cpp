#include <iostream>
#include <fstream>
#include "header.h"
#include <unistd.h>
#include <ctime>
#include <iomanip>      // std::setprecision
# include <omp.h>
using namespace std;

#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define RESET     "\033[0m"
#define BLUE    "\033[34m"      /* Blue */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */

/*  Road size:
*   road_size = from user input
*/
int road_size;

/* Cars States:
* 0: No Car
* 1: Car moving straight
* 2: Car turning left
* 3: Car turning right
*/
const int no_car = 0;
const int straight_car = 1;
const int left_car = 2;
const int right_car = 3;

/* Traffic Light States:
* 0: Red Light
* 1: Green Light
*/
const int red = 0;
const int green = 1;

// Total number of cars from the input.
int total_cars = 0;
int total_cars_2 = 0;

// Total time for simulation logic
clock_t total_time = 0; 

// Utility function to find ceiling of r in arr[l..h] 
int findCeil(int arr[], int r, int l, int h) 
{ 
  int mid; 
  while (l < h) 
  { 
    mid = l + ((h - l) >> 1); // Same as mid = (l+h)/2 
    (r > arr[mid]) ? (l = mid + 1) : (h = mid); 
  } 
  return (arr[l] >= r) ? l : -1; 
} 

// The main function that returns a random number 
// from arr[] according to distribution array 
// defined by freq[]. n is size of arrays. 
int myRand(int arr[], int freq[], int n) 
{ 
  // Create and fill prefix array 
  int prefix[n], i; 
  prefix[0] = freq[0]; 
  for (i = 1; i < n; ++i) 
    prefix[i] = prefix[i - 1] + freq[i]; 
  // prefix[n-1] is sum of all frequencies. 
  // Generate a random number with 
  // value from 1 to this sum 
  int r = (rand() % prefix[n - 1]) + 1; 
  // Find index of ceiling of r in prefix arrat 
  int indexc = findCeil(prefix, r, 0, n - 1); 
  return arr[indexc]; 
} 

int makeInputRightTurns(int road_size, int total_cars, int vertical_0[], int vertical_3[], int horizontal_0[], int horizontal_3[]);

int makeInputLeftTurns(int road_size, int total_cars, int vertical_1[], int vertical_2[], int horizontal_1[], int horizontal_2[]);

int readInput(int road_size, int total_cars, int vertical_0[], int vertical_1[], int vertical_2[], int vertical_3[], int horizontal_0[], int horizontal_1[], int horizontal_2[], int horizontal_3[]);

void startSimulation(int vertical_0[], int vertical_1[], int vertical_2[], int vertical_3[], int horizontal_0[], int horizontal_1[], int horizontal_2[], int horizontal_3[], int road_size, int east_light, int west_light, int north_light, int south_light);

int performStateSimulation(int vertical_0[], int vertical_1[], int vertical_2[], int vertical_3[], int horizontal_0[], int horizontal_1[], int horizontal_2[], int horizontal_3[], int road_size, bool light_holder[], bool light_state);

void clearV0V1Ends(int vertical_0[], int vertical_1[], int road_size, int section_xy);

void clearH0H1Ends(int horizontal_0[], int horizontal_1[], int section_xy, int road_size);

void clearV2V3Ends(int vertical_2[], int vertical_3[], int section_xy, int road_size);

void clearV0V1Fronts(int vertical_0[], int vertical_1[], int horizontal_0[], int intesection_crossing_point);

void clearH0H1Fronts(int horizontal_0[], int horizontal_1[], int vertical_3[], int road_size, int intesection_crossing_point, int section_xy);

void clearV2V3Fronts(int vertical_2[], int vertical_3[], int horizontal_3[], int road_size, int intesection_crossing_point, int section_xy);

void clearH2H3Ends(int horizontal_2[], int horizontal_3[], int road_size, int section_xy);

void clearH2H3Fronts(int horizontal_2[], int horizontal_3[], int vertical_0[], int intesection_crossing_point );

/* Main */
int main(int argc, char** argv){
  /*
  string file_name = argv[1];
  // Total number of cars in one road. Reads the input file and gets array dimensions.
  road_size = getRoadSize(file_name);
  std::cout<< "The dimensions are: " << road_size << " \n" ;
  */
  int road_size = atoi(argv[1]);

  // Lights for each intersection are named in the direction of the cars moving.
  bool east_light = red;
  bool west_light = green;
  bool north_light = red;
  bool south_light = red;

  // Initialize streets
  int horizontal_0 [road_size], horizontal_1 [road_size], horizontal_2 [road_size], horizontal_3 [road_size];
  int vertical_0 [road_size], vertical_1 [road_size], vertical_2 [road_size], vertical_3 [road_size];
  
  int right_total = makeInputRightTurns(road_size, total_cars, vertical_0, vertical_3, horizontal_0, horizontal_3);
  cout << "Total after right: " << right_total << endl;
  int left_total =  makeInputLeftTurns(road_size, total_cars, vertical_1, vertical_2, horizontal_1, horizontal_2);
  total_cars = right_total + left_total;  
  cout << "Total after left: " << total_cars << endl;

  //total_cars = readInput(file_name, road_size, total_cars, vertical_0, vertical_1, vertical_2, vertical_3, horizontal_0, horizontal_1, horizontal_2, horizontal_3);
  total_cars_2 = total_cars;
 
  /* debuggin openmp next state arr init
  int section_xy = (road_size - 4)/2;
  int horizontal_3_next_state[road_size-((road_size-1)-section_xy)];
  int horizontal_2_next_state[road_size-(section_xy+1)];
  cout<< "The horizontal 3: " << road_size-((road_size-1)-section_xy) << "\n";
  cout<< "The horizontal 2: " << road_size-(section_xy+1) << "\n"; 
  cout<< "The horizontal 3 end index: " << ((road_size-1)-section_xy) << "\n"; 
  cout<< "The horizontal 2 end index: " << section_xy+1 << "\n"; 
  cout<< "The horizontal 3 , 2 start index: " << road_size-1 << "\n"; 
  */

  startSimulation(vertical_0, vertical_1, vertical_2, vertical_3, horizontal_0, horizontal_1, horizontal_2, horizontal_3, road_size, east_light, west_light, north_light, south_light);

  //printRoadData(vertical_0, vertical_1, vertical_2, vertical_3, horizontal_0, horizontal_1, horizontal_2, horizontal_3, road_size);

  cout<< "The project seems fine! The total_cars are: " << total_cars_2 << "\n";

  return 0;
}

/*
* startSimulation - Initialize the simulation variables and call
*   the simulation function for each interval until all the cars
*   have exited the simulation boundary.
*
* Args:
*   int vertical_0[]: array representing the (relative) right lane
*     of the south-bound road
*   int vertical_1[]: array representing the (relative) left lane
*     of the south-bound road
*   int vertical_2[]: array representing the (relative) left lane
*     of the north-bound road
*   int vertical_3[]: array representing the (relative) right lane
*     of the north-bound road
*   int horizontal_0[]: array representing the (relative) right lane
*     of the west-bound road
*   int horizontal_1[]: array representing the (relative) left lane
*     of the west-bound road
*   int horizontal_2[]: array representing the (relative) left lane
*     of the east-bound road
*   int horizontal_3[]: array representing the (relative) right lane
*     of the east-bound road.
*   int road_size: size of the road
*   int east_light: color of the east light
*   int west_light: color of the west light
*   int north_light: color of the north light
*   int south_light: color of the south light
*/
void startSimulation(int vertical_0[], int vertical_1[], int vertical_2[], int vertical_3[], int horizontal_0[], int horizontal_1[], int horizontal_2[], int horizontal_3[], int road_size, int east_light, int west_light, int north_light, int south_light){
  int sleep_time = 0.1;   // Time for each state completion
  int light_time = sleep_time * 6;  // Green light total time = [each state time]*[factor]
  int clear_time = sleep_time * 4;  // Yellow light time = [each state time]*[factor = 4] as 4 states have to clear out
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
    clock_t c_start = clock();
    int name = performStateSimulation(vertical_0, vertical_1, vertical_2, vertical_3, horizontal_0, horizontal_1, horizontal_2, horizontal_3, road_size, light_holder, light_state);
    //clock_t c_end = clock();
    //cout << " Local timen for each state" << c_end - c_start << endl;
    //total_time += (c_end - c_start);
    sleep(sleep_time);
  }
  cout << total_time << endl;
  cout << setprecision(2) << "CPU time used: " << 1000.0 * (total_time) / CLOCKS_PER_SEC << " ms\n";
}

/*
* performStateSimulation - Performs the simulation, and prints the
*   system state at the end of the interval.
*
* Args:
*   int vertical_0[]: array representing the (relative) right lane
*     of the south-bound road
*   int vertical_1[]: array representing the (relative) left lane
*     of the south-bound road
*   int vertical_2[]: array representing the (relative) left lane
*     of the north-bound road
*   int vertical_3[]: array representing the (relative) right lane
*     of the north-bound road
*   int horizontal_0[]: array representing the (relative) right lane
*     of the west-bound road
*   int horizontal_1[]: array representing the (relative) left lane
*     of the west-bound road
*   int horizontal_2[]: array representing the (relative) left lane
*     of the east-bound road
*   int horizontal_3[]: array representing the (relative) right lane
*     of the east-bound road.
*   int road_size: size of the road
*   bool light_holder[]: array holding the state of the West, South,
*     East, and North traffic lights, respectively.
*   bool light_state: determines if the intersection needs to be cleared
*     (false means clear out).
*
* Returns:
*   int: indicating the simulation is finished
*/
int performStateSimulation(int vertical_0[], int vertical_1[], int vertical_2[], int vertical_3[], int horizontal_0[], int horizontal_1[], int horizontal_2[], int horizontal_3[], int road_size, bool light_holder[], bool light_state){
  clock_t c_start = clock();
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
        if( i == section_xy+3 && horizontal_2[i-1] == 3 ){
        vertical_2[section_xy+2] = horizontal_2[i-1];
        horizontal_2[i-1] = 0;
        } 
        if( i == section_xy+1 && horizontal_3[i-1] == 2 ){
          horizontal_2[i] = horizontal_2[i-1];
        } else {
        horizontal_2[i] = horizontal_2[i-1]; //straight road
        }
      }
      for(int i = road_size-1; i>=1; i--){
        if( i == section_xy+1 && horizontal_3[i-1] == 2 ){
          horizontal_3[i] = horizontal_3[i-1];
          vertical_0[((road_size-2)-intesection_crossing_point)] = horizontal_3[i-1];
          horizontal_3[i] = 0;
        } else {
        horizontal_3[i] = horizontal_3[i-1]; //straight road
        }
      }
      horizontal_2[0] = 0;
      horizontal_3[0] = 0;
      // vertical 2, 3 --- upper part
      clearV2V3Ends(vertical_2, vertical_3, section_xy, road_size);
      // horizontal 0,1 left part
      clearH0H1Ends(horizontal_0, horizontal_1, section_xy, road_size);
      // vertical 0, 1 --- lower part
      clearV0V1Ends(vertical_0, vertical_1, road_size, section_xy);
      // vertical 0, 1 --- upper part
      clearV0V1Fronts(vertical_0, vertical_1, horizontal_0, intesection_crossing_point);
       // horizontal 0, 1 --- right part
      clearH0H1Fronts(horizontal_0, horizontal_1, vertical_3, road_size, intesection_crossing_point, section_xy);
      // vertical 2, 3 --- lower part
      clearV2V3Fronts(vertical_2, vertical_3, horizontal_3, road_size, intesection_crossing_point, section_xy);
  clock_t c_end = clock();
  total_time += (c_end - c_start);
  } else if(light_holder[1] == green && light_state == false) {
      if(horizontal_2[road_size-1]>0){
          total_cars--;
      }
      if(horizontal_3[road_size-1]>0){
          total_cars--;
      }

      for(int i = road_size-1; i>=section_xy+1; i--){
        if( i == section_xy+3 && horizontal_2[i-1] == 3 ){
      vertical_2[section_xy+2] = horizontal_2[i-1];
      horizontal_2[i-1] = 0;
        }
        if( i == section_xy+1 && horizontal_3[i-1] == 2 ){
          horizontal_2[i] = horizontal_2[i-1];
          vertical_0[((road_size-2)-intesection_crossing_point)] = horizontal_3[i-1];
          horizontal_3[i] = 0;
        } else {
        horizontal_2[i] = horizontal_2[i-1];
        horizontal_3[i] = horizontal_3[i-1];
        }
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
      // vertical 2, 3 --- upper part
      clearV2V3Ends(vertical_2, vertical_3, section_xy, road_size);
      // horizontal 0,1 left part
      clearH0H1Ends(horizontal_0, horizontal_1, section_xy, road_size);    
      // vertical 0, 1
      clearV0V1Ends(vertical_0, vertical_1, road_size, section_xy);
      // vertical 0, 1 --- upper part
      clearV0V1Fronts(vertical_0, vertical_1, horizontal_0, intesection_crossing_point);
      // horizontal 0, 1 --- right part
      clearH0H1Fronts(horizontal_0, horizontal_1, vertical_3, road_size, intesection_crossing_point, section_xy);
      // vertical 2, 3 --- lower part
      clearV2V3Fronts(vertical_2, vertical_3, horizontal_3, road_size, intesection_crossing_point, section_xy);
  } else if(light_holder[1] == green && light_state == true){
      if(vertical_2[0]>0){
          total_cars--;
      }
      if(vertical_3[0]>0){
          total_cars--;
      }
      for(int i = 0; i<=road_size-2; i++){
        if( i == section_xy && vertical_2[i+1] == 3 ){
      horizontal_1[section_xy+2] = vertical_2[i+1];
      vertical_2[i+1] = 0;
        } 
        if( i == section_xy+2 && vertical_3[section_xy+3] == 2){
          vertical_2[i] = vertical_2[i+1];
          vertical_3[i] = vertical_3[i+1];
          horizontal_3[((road_size-2)-intesection_crossing_point)] = vertical_3[i+1];
          vertical_3[i] = 0;
        } else {
        vertical_2[i] = vertical_2[i+1];
        vertical_3[i] = vertical_3[i+1];
        }
      }
      vertical_2[road_size-1] = 0;
      vertical_3[road_size-1] = 0;
      // horizontal 2, 3 left part
      clearH2H3Ends(horizontal_2, horizontal_3, road_size, section_xy);
      // horizontal 0, 1 --- left part
      clearH0H1Ends(horizontal_0, horizontal_1, section_xy, road_size);
      // vertical 0, 1 --- lower part
      clearV0V1Ends(vertical_0, vertical_1, road_size, section_xy);
      // vertical 0, 1 --- upper part
      clearV0V1Fronts(vertical_0, vertical_1, horizontal_0, intesection_crossing_point);
      // horizontal 2, 3 --- right part
      clearH2H3Fronts(horizontal_2, horizontal_3, vertical_0, intesection_crossing_point);
      // horizontal 0, 1 --- right part
      clearH0H1Fronts(horizontal_0, horizontal_1, vertical_3, road_size, intesection_crossing_point, section_xy);
  } else if(light_holder[2] == green && light_state == false){
      if(vertical_2[0]>0){
          total_cars--;
      }
      if(vertical_3[0]>0){
          total_cars--;
      }
      for(int i = 0; i<=((road_size-2)-section_xy); i++){
        if( i == section_xy && vertical_2[i+1] == 3 ){
      horizontal_1[section_xy+2] = vertical_2[i+1];
      vertical_2[i+1] = 0;
        }         
        if( i == section_xy+2 && vertical_3[section_xy+3] == 2){
          vertical_2[i] = vertical_2[i+1];
          vertical_3[i] = vertical_3[i+1];
          horizontal_3[((road_size-2)-intesection_crossing_point)] = vertical_3[i+1];
          vertical_3[i] = 0;
        } else {
        vertical_2[i] = vertical_2[i+1];
        vertical_3[i] = vertical_3[i+1];
        }
      }
      vertical_2[((road_size-1)-section_xy)] = 0;
      vertical_3[((road_size-1)-section_xy)] = 0;
      for(int i = ((road_size-1)-intesection_crossing_point); i<=road_size-2; i++){
        if(vertical_2[i] == 0){
          vertical_2[i] = vertical_2[i+1];
          vertical_2[i+1] = 0;
        }
        if(vertical_3[i] == 0){
          vertical_3[i] = vertical_3[i+1];
          vertical_3[i+1] = 0;
        }
      }
      // horizontal 0, 1 --- left part
      clearH0H1Ends(horizontal_0, horizontal_1, section_xy, road_size);
      // horizontal 2, 3 left part
      clearH2H3Ends(horizontal_2, horizontal_3, road_size, section_xy);
      // vertical 0, 1
      clearV0V1Ends(vertical_0, vertical_1, road_size, section_xy);
      // vertical 0, 1 --- upper part
      clearV0V1Fronts(vertical_0, vertical_1, horizontal_0, intesection_crossing_point);
      // horizontal 2, 3 --- right part
      clearH2H3Fronts(horizontal_2, horizontal_3, vertical_0, intesection_crossing_point);
      // horizontal 0, 1 --- right part
      clearH0H1Fronts(horizontal_0, horizontal_1, vertical_3, road_size, intesection_crossing_point, section_xy);
  } else if(light_holder[2] == green && light_state == true){
      if(horizontal_0[0]>0){
          total_cars--;
      }
      if(horizontal_1[0]>0){
          total_cars--;
      }
      for(int i = 0; i<=road_size-2; i++){
        if( i == section_xy && horizontal_1[i+1] == 3 ){
      vertical_1[section_xy+1] = horizontal_1[i+1];
      horizontal_1[i+1] = 0;
        }         
        if(i == section_xy+2 && horizontal_0[section_xy+3] == 2){
          horizontal_0[i] = horizontal_0[i+1];
          horizontal_1[i] = horizontal_1[i+1];
          vertical_3[intesection_crossing_point+1] = horizontal_0[i+1];
          horizontal_0[i] = 0;
        } else {
        horizontal_0[i] = horizontal_0[i+1];
        horizontal_1[i] = horizontal_1[i+1];
        }
      }
      horizontal_0[road_size-1] = 0;
      horizontal_1[road_size-1] = 0;
      // vertical 2, 3 --- upper part
      clearV2V3Ends(vertical_2, vertical_3, section_xy, road_size);
      // horizontal 2, 3 left part
      clearH2H3Ends(horizontal_2, horizontal_3, road_size, section_xy);
      // vertical 0, 1 --- lower part
      clearV0V1Ends(vertical_0, vertical_1, road_size, section_xy);
      // vertical 0, 1 --- upper part
      clearV0V1Fronts(vertical_0, vertical_1, horizontal_0, intesection_crossing_point);
      // horizontal 2, 3 --- right part
      clearH2H3Fronts(horizontal_2, horizontal_3, vertical_0, intesection_crossing_point);
      // vertical 2, 3 --- lower part
      clearV2V3Fronts(vertical_2, vertical_3, horizontal_3, road_size, intesection_crossing_point, section_xy);
  } else if(light_holder[3] == green && light_state == false){
      if(horizontal_0[0]>0){
          total_cars--;
      }
      if(horizontal_1[0]>0){
          total_cars--;
      }
      for(int i = 0; i<=((road_size-2)-section_xy); i++){
        if( i == section_xy && horizontal_1[i+1] == 3 ){
      vertical_1[section_xy+1] = horizontal_1[i+1];
      horizontal_1[i+1] = 0;
        }         
        if(i == section_xy+2 && horizontal_0[section_xy+3] == 2){
          horizontal_0[i] = horizontal_0[i+1];
          horizontal_1[i] = horizontal_1[i+1];
          vertical_3[intesection_crossing_point+1] = horizontal_0[i+1];
          horizontal_0[i] = 0;
        } else {
        horizontal_0[i] = horizontal_0[i+1];
        horizontal_1[i] = horizontal_1[i+1];
        }
      }
      horizontal_0[((road_size-1)-section_xy)] = 0;
      horizontal_1[((road_size-1)-section_xy)] = 0;
      for(int i = ((road_size-1)-intesection_crossing_point); i<=road_size-2; i++){
        if(horizontal_0[i] == 0){
          horizontal_0[i] = horizontal_0[i+1];
          horizontal_0[i+1] = 0;
        }
        if(horizontal_1[i] == 0){
          horizontal_1[i] = horizontal_1[i+1];
          horizontal_1[i+1] = 0;
        }
      }
      // horizontal 2, 3 left part
      clearH2H3Ends(horizontal_2, horizontal_3, road_size, section_xy);
      // vertical 2, 3 --- upper part
      clearV2V3Ends(vertical_2, vertical_3, section_xy, road_size);
      // vertical 0, 1
      clearV0V1Ends(vertical_0, vertical_1, road_size, section_xy);
      // vertical 0, 1 --- upper part
      clearV0V1Fronts(vertical_0, vertical_1, horizontal_0, intesection_crossing_point);
      // vertical 2, 3 --- lower part
      clearV2V3Fronts(vertical_2, vertical_3, horizontal_3, road_size, intesection_crossing_point, section_xy);
      // horizontal 2, 3 --- right part
      clearH2H3Fronts(horizontal_2, horizontal_3, vertical_0, intesection_crossing_point);
  } else if(light_holder[3] == green && light_state == true){
      if(vertical_0[road_size-1]>0){
          total_cars--;
      }
      if(vertical_1[road_size-1]>0){
        total_cars--;
      }
      for(int i = road_size-1; i>=1; i--){
      if( i == section_xy+3 && vertical_1[i-1] == 3 ){
      horizontal_2[section_xy+1] = vertical_1[i-1];
      vertical_1[i-1] = 0;
        }         
        if( i == section_xy+1 && vertical_0[i-1] == 2 ){
        vertical_1[i] = vertical_1[i-1];
        vertical_0[i] = vertical_0[i-1];
        horizontal_0[intesection_crossing_point+1] = vertical_0[i-1];
        vertical_0[i] = 0;
        } else {
        vertical_0[i] = vertical_0[i-1];
        vertical_1[i] = vertical_1[i-1];
        }
      }
      vertical_0[0] = 0;
      vertical_1[0] = 0;
      clearH2H3Ends(horizontal_2, horizontal_3, road_size, section_xy);
      // vertical 2, 3 --- upper part
      clearV2V3Ends(vertical_2, vertical_3, section_xy, road_size);
      clearH0H1Ends(horizontal_0, horizontal_1, section_xy, road_size);
      // horizontal 0, 1 --- right part
      clearH0H1Fronts(horizontal_0, horizontal_1, vertical_3, road_size, intesection_crossing_point, section_xy);
      // vertical 2, 3 --- lower part
      clearV2V3Fronts(vertical_2, vertical_3, horizontal_3, road_size, intesection_crossing_point, section_xy);
      clearH2H3Fronts(horizontal_2, horizontal_3, vertical_0, intesection_crossing_point);
  } else if(light_holder[0] == green && light_state == false){
      if(vertical_0[road_size-1]>0){
          total_cars--;
      }
      if(vertical_1[road_size-1]>0){
          total_cars--;
      }
      for(int i = road_size-1; i>=section_xy+1; i--){
        if( i == section_xy+3 && vertical_1[i-1] == 3 ){
        horizontal_2[section_xy+1] = vertical_1[i-1];
      vertical_1[i-1] = 0;
          }       
        if( i == section_xy+1 && vertical_0[i-1] == 2 ){
          vertical_1[i] = vertical_1[i-1];
          vertical_0[i] = vertical_0[i-1];
          horizontal_0[intesection_crossing_point+1] = vertical_0[i-1];
          vertical_0[i] = 0;
        } else {
          vertical_0[i] = vertical_0[i-1];
          vertical_1[i] = vertical_1[i-1];
        }
      }
      vertical_0[section_xy] = 0;
      vertical_1[section_xy] = 0;

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
      // vertical 2, 3 --- upper part
      clearV2V3Ends(vertical_2, vertical_3, section_xy, road_size);
      clearH2H3Ends(horizontal_2, horizontal_3, road_size, section_xy);
      // horizontal 0,1 left part
      clearH0H1Ends(horizontal_0, horizontal_1, section_xy, road_size);
      // horizontal 0, 1 --- right part
      clearH0H1Fronts(horizontal_0, horizontal_1, vertical_3, road_size, intesection_crossing_point, section_xy);
      // vertical 2, 3 --- lower part
      clearV2V3Fronts(vertical_2, vertical_3, horizontal_3, road_size, intesection_crossing_point, section_xy);

      clearH2H3Fronts(horizontal_2, horizontal_3, vertical_0, intesection_crossing_point);
  }
  //printRoadData(vertical_0, vertical_1, vertical_2, vertical_3, horizontal_0, horizontal_1, horizontal_2, horizontal_3, road_size);
  printRoadTop(vertical_0, vertical_1, vertical_2, vertical_3, horizontal_0, horizontal_1, horizontal_2, horizontal_3, road_size, light_holder, light_state);
  cout<< "No. of cars exited are: " << (total_cars_2)-total_cars  << endl;
  cout<< "Light states are: " << "W:"<< light_holder[0] << "S:"<< light_holder[1] << "E:"<< light_holder[2] << "N:"<< light_holder[3] << endl;
  return 0;
}

// this end needs to be tested and fixed
void clearV0V1Ends(int vertical_0[], int vertical_1[], int road_size, int section_xy){
  if(vertical_0[road_size-1]>0){
      total_cars--;
  }
  if(vertical_1[road_size-1]>0){
      total_cars--;
  }
  /* Duplicating arrays  */
  int vertical_0_next_state[road_size-1];
  int vertical_1_next_state[road_size-1];
  #pragma omp parallel for
  for(int i = road_size-1; i>=0; i--){
    vertical_0_next_state[i] = vertical_0[i];
  }
  #pragma omp parallel for
  for(int i = road_size-1; i>=0; i--){
    vertical_1_next_state[i] = vertical_1[i];
  }
  /* Duplicating arrays  */
  #pragma omp parallel for
  for(int i = road_size-1; i>=((road_size-1)-section_xy); i--){
    vertical_0[i] = vertical_0_next_state[i-1];
  }
  #pragma omp parallel for
  for(int i = road_size-1; i>=(section_xy+1); i--){
    vertical_1[i] = vertical_1_next_state[i-1];
  }
  vertical_1[section_xy+1] = 0;
}

void clearH0H1Ends(int horizontal_0[], int horizontal_1[], int section_xy, int road_size){
  if(horizontal_0[0]>0){
      total_cars--;
  }
  if(horizontal_1[0]>0){
      total_cars--;
  }
  /* Duplicating arrays  */
  int horizontal_0_next_state[road_size-1];
  int horizontal_1_next_state[road_size-1];
  #pragma omp parallel for
  for(int i = road_size-1; i>=0; i--){
    horizontal_0_next_state[i] = horizontal_0[i];
  }
  #pragma omp parallel for
  for(int i = road_size-1; i>=0; i--){
    horizontal_1_next_state[i] = horizontal_1[i];
  }
  /* Duplicating arrays  */
  #pragma omp parallel for  
  for(int i = 0; i<=(section_xy-1); i++){
    horizontal_0[i] = horizontal_0_next_state[i+1];
  }
  horizontal_0[section_xy] = 0;
  #pragma omp parallel for  
  for(int i = 0; i<=(section_xy+2); i++){
    horizontal_1[i] = horizontal_1_next_state[i+1];
  }
  horizontal_1[section_xy+2] = 0;
}

void clearV2V3Ends(int vertical_2[], int vertical_3[], int section_xy, int road_size){
  if(vertical_2[0]>0){
      total_cars--;
  }
  if(vertical_3[0]>0){
      total_cars--;
  }
  /* Duplicating arrays  */
  int vertical_2_next_state[road_size-1];
  int vertical_3_next_state[road_size-1];
  #pragma omp parallel for
  for(int i = road_size-1; i>=0; i--){
    vertical_2_next_state[i] = vertical_2[i];
  }
  #pragma omp parallel for
  for(int i = road_size-1; i>=0; i--){
    vertical_3_next_state[i] = vertical_3[i];
  }
  /* Duplicating arrays  */
  #pragma omp parallel for
  for(int i = 0; i<=(section_xy-1); i++){
    vertical_3[i] = vertical_3_next_state[i+1];
  }
  vertical_3[section_xy] = 0;
  #pragma omp parallel for
  for(int i = 0; i<=(section_xy+2); i++){
    vertical_2[i] = vertical_2_next_state[i+1];
  }
  vertical_2[section_xy+2] = 0;
}

void clearV0V1Fronts(int vertical_0[], int vertical_1[], int horizontal_0[], int intesection_crossing_point){
  bool turn_available = (horizontal_0[intesection_crossing_point+1] == 0 && horizontal_0[intesection_crossing_point+2] == 0 && horizontal_0[intesection_crossing_point+3] == 0);
  //cout << "Is turn_available?" << turn_available << endl;
  if(vertical_0[intesection_crossing_point] == 2 && turn_available){
    horizontal_0[intesection_crossing_point+1] = vertical_0[intesection_crossing_point];
    vertical_0[intesection_crossing_point] = 0;
  }
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

void clearH0H1Fronts(int horizontal_0[], int horizontal_1[], int vertical_3[], int road_size, int intesection_crossing_point, int section_xy){
  bool turn_available = (vertical_3[section_xy] == 0 && vertical_3[section_xy+1] == 0 && vertical_3[section_xy+2] == 0);
  if(horizontal_0[((road_size-1)-intesection_crossing_point)] == 2 && turn_available){
    vertical_3[section_xy] = horizontal_0[((road_size-1)-intesection_crossing_point)];
    horizontal_0[((road_size-1)-intesection_crossing_point)] = 0;
  }
  for(int i = ((road_size-1)-intesection_crossing_point); i<road_size-1; i++){
      if(horizontal_0[i] == 0){
        horizontal_0[i] = horizontal_0[i+1];
        horizontal_0[i+1] = 0;
      }
      if(horizontal_1[i] == 0){
        horizontal_1[i] = horizontal_1[i+1];
        horizontal_1[i+1] = 0;
      }
    }
    //deleted these if stops working check this out
    //horizontal_0[section_xy] = 0;
   // horizontal_1[section_xy] = 0;
}

void clearV2V3Fronts(int vertical_2[], int vertical_3[], int horizontal_3[], int road_size, int intesection_crossing_point, int section_xy){
  bool turn_available = (horizontal_3[section_xy+1] == 0 && horizontal_3[section_xy+2] == 0 && horizontal_3[section_xy+3] == 0);
  if(vertical_3[((road_size-1)-intesection_crossing_point)] == 2 && turn_available){
    horizontal_3[section_xy+3] = vertical_3[((road_size-1)-intesection_crossing_point)];
    vertical_3[((road_size-1)-intesection_crossing_point)] = 0;
  }
  for(int i = ((road_size-1)-intesection_crossing_point); i<road_size-1; i++){
    if(vertical_2[i] == 0){
      vertical_2[i] = vertical_2[i+1];
      vertical_2[i+1] = 0;
    }
    if(vertical_3[i] == 0){
      vertical_3[i] = vertical_3[i+1];
      vertical_3[i+1] = 0;
    }
  }
}

void clearH2H3Ends(int horizontal_2[], int horizontal_3[], int road_size, int section_xy){
  if(horizontal_2[road_size-1]>0){
      total_cars--;
  }
  if(horizontal_3[road_size-1]>0){
      total_cars--;
  }
  /* Duplicating arrays  */
  int horizontal_3_next_state[road_size-1];
  int horizontal_2_next_state[road_size-1];
  #pragma omp parallel for
  for(int i = road_size-1; i>=0; i--){
    horizontal_3_next_state[i] = horizontal_3[i];
  }
  #pragma omp parallel for
  for(int i = road_size-1; i>=0; i--){
    horizontal_2_next_state[i] = horizontal_2[i];
  }
  /* Duplicating arrays  */

  /* test printing
  for(int i = road_size-1; i>=0; i--){
    cout << horizontal_3_next_state[i] << "  ";
  }
  cout << endl;
  for(int i = road_size-1; i>=0; i--){
    cout << horizontal_3[i] << "  ";
  }
  cout << endl;
  */
  #pragma omp parallel for
  for(int i = road_size-1; i>=((road_size-1)-section_xy); i--){
    horizontal_3[i] = horizontal_3_next_state[i-1];
  }
  #pragma omp parallel for
  for(int i = road_size-1; i>=section_xy+1; i--){
    horizontal_2[i] = horizontal_2_next_state[i-1];
  }
  horizontal_2[section_xy+1] = 0;
}

void clearH2H3Fronts(int horizontal_2[], int horizontal_3[], int vertical_0[], int intesection_crossing_point ){
  bool turn_available = (horizontal_3[intesection_crossing_point+2] == 0 && horizontal_3[intesection_crossing_point+3] == 0 && horizontal_3[intesection_crossing_point+4] == 0);
  if(horizontal_3[intesection_crossing_point] == 2 && turn_available){
    vertical_0[intesection_crossing_point+4] = horizontal_3[intesection_crossing_point];
    horizontal_3[intesection_crossing_point] = 0;
  }
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
}

int makeInputRightTurns(int road_size, int total_cars, int vertical_0[], int vertical_3[], int horizontal_0[], int horizontal_3[]){
  int size = road_size;
  int section_xy = (size - 4)/2;
  int arr[] = {0, 1, 2}; 
  int freq[] = {40, 40, 20}; 
  int result[size]; 
  int i, n = sizeof(arr) / sizeof(arr[0]); 
  // Use a different seed value for every run. 
  srand(time(NULL)); 
  // Let us generate 10 random numbers accroding to 
  // given distribution 
  for (i = 0; i < size; i++){ 
        vertical_0[i] = myRand(arr, freq, n);
        vertical_3[i] = myRand(arr, freq, n);
        horizontal_0[i] = myRand(arr, freq, n);
        horizontal_3[i] = myRand(arr, freq, n);        
    }
    for (i = section_xy; i < section_xy+4; i++ ){
        vertical_0[i] = 0;
        vertical_3[i] = 0;
        horizontal_0[i] = 0;
        horizontal_3[i] = 0;
    }
    for (i = 0; i < size; i++){
      if(vertical_0[i] > 0) total_cars++; 
    }
    for (i = 0; i < size; i++){
      if(vertical_3[i] > 0) total_cars++; 
    }
    for (i = 0; i < size; i++){
      if(horizontal_0[i] > 0) total_cars++; 
    }
    for (i = 0; i < size; i++){
      if(horizontal_3[i] > 0) total_cars++; 
    }
  return total_cars; 
}

int makeInputLeftTurns(int road_size, int total_cars, int vertical_1[], int vertical_2[], int horizontal_1[], int horizontal_2[]){
  int size = road_size;
  int section_xy = (size - 4)/2;
  int arr[] = {0, 1, 3}; 
  int freq[] = {40, 40, 20}; 
    int result[size]; 
  int i, n = sizeof(arr) / sizeof(arr[0]); 
  // Use a different seed value for every run. 
  srand(time(NULL)); 
  // Let us generate 10 random numbers accroding to 
  // given distribution 
  for (i = 0; i < size; i++){ 
        vertical_1[i] = myRand(arr, freq, n);
        vertical_2[i] = myRand(arr, freq, n);
        horizontal_1[i] = myRand(arr, freq, n);
        horizontal_2[i] = myRand(arr, freq, n);        
    }
    for (i = section_xy; i < section_xy+4; i++ ){
        vertical_1[i] = 0;
        vertical_2[i] = 0;
        horizontal_1[i] = 0;
        horizontal_2[i] = 0;
    }
    for (i = 0; i < size; i++){
      if(vertical_1[i] > 0) total_cars++; 
    }
    for (i = 0; i < size; i++){
      if(vertical_2[i] > 0) total_cars++; 
    }
    for (i = 0; i < size; i++){
      if(horizontal_1[i] > 0) total_cars++; 
    }
    for (i = 0; i < size; i++){
      if(horizontal_2[i] > 0) total_cars++; 
    }
  return total_cars; 
}
