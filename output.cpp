#include <iostream>
#include "header.h"

using namespace std; 


void printRoadTop(int vertical_0[], int vertical_1[], int vertical_2[], int vertical_3[],  int road_size){
  int section_xy = (road_size - 4)/2;
  for(int i= 0; i < section_xy; i++){
    for(int j= 0; j < section_xy; j++){
      cout<< "+" <<"\t";
    } 
    cout<< vertical_0[i]<<"\t"<<
    vertical_1[i]<<"\t"<<
    vertical_2[i]<<"\t"<<
    vertical_3[i]<<"\t";     
    for(int j= 0; j < section_xy; j++){
      cout<< "+" <<"\t";
    }
    cout<< "\n";
  }
}


/*
* printRoadData - Reads the street arrays and prints the result.
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
*/
void printRoadData(int vertical_0[], int vertical_1[], int vertical_2[], int vertical_3[], int horizontal_0[], int horizontal_1[] ,int horizontal_2[] , int horizontal_3[], int road_size){
  //show road
  cout << "Vertical Lanes: \n";
  for( int i = 0; i<road_size; i++){
    cout << vertical_0[i];
    cout << vertical_1[i];
    cout << vertical_2[i];
    cout << vertical_3[i];
    cout << "\n";
  }

  cout << "Horizontal Lanes: \n";
  for( int i = 0; i<road_size; i++){
    cout << horizontal_0[i];
  }
  cout << "\n";
  for( int i = 0; i<road_size; i++){
    cout << horizontal_1[i];
  }
  cout << "\n";
  for( int i = 0; i<road_size; i++){
    cout << horizontal_2[i];
  }
  cout << "\n";
  for( int i = 0; i<road_size; i++){
    cout << horizontal_3[i];
  }

  cout << "\n";
}
