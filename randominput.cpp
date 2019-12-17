#include <iostream>
#include "header.h"
using namespace std;


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
