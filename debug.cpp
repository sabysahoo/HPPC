#include <fstream>
#include "header.h"
using namespace std;

int* countNum(int array[], int road_size){
  int* arr = new int[5];
  arr[0] = 0;
  arr[1] = 0;
  arr[2] = 0;
  arr[3] = 0;
  arr[4] = 0;
  for( int i = 0; i<road_size; i++){
    if( array[i] == 0){
      arr[0]++;
    }
    else if( array[i] == 1){
      arr[1]++;
    }
    else if( array[i] == 2){
      arr[2]++;
    }
    else if(array[i] == 3){
      arr[3]++;
    }
    else{
      arr[4]++;
    }
  }
  return arr;
}


void debugCars(int vertical_0[], int vertical_1[], int vertical_2[], int vertical_3[], int horizontal_0[], int horizontal_1[], int horizontal_2[], int horizontal_3[], int road_size){

  int* h0 = countNum(horizontal_0, road_size);
  int* h1 = countNum(horizontal_1, road_size);
  int* h2 = countNum(horizontal_2, road_size);
  int* h3 = countNum(horizontal_3, road_size);

  int* v0 = countNum(vertical_0, road_size);
  int* v1 = countNum(vertical_1, road_size);
  int* v2 = countNum(vertical_2, road_size);
  int* v3 = countNum(vertical_3, road_size);

  int found = 0;
  for( int i = 1; i<5; i++){
    found = found + h0[i] + h1[i] + h2[i] + h3[i] + v0[i] + v1[i] + v2[i] + v3[i];
  }

  printf("Horizontal_0 stats: 0: %d, 1: %d, 2: %d, 3: %d, Other: %d \n", h0[0], h0[1], h0[2], h0[3], h0[4]);
  printf("Horizontal_1 stats: 0: %d, 1: %d, 2: %d, 3: %d, Other: %d \n", h1[0], h1[1], h1[2], h1[3], h1[4]);
  printf("Horizontal_2 stats: 0: %d, 1: %d, 2: %d, 3: %d, Other: %d \n", h2[0], h2[1], h2[2], h2[3], h2[4]);
  printf("Horizontal_3 stats: 0: %d, 1: %d, 2: %d, 3: %d, Other: %d \n", h3[0], h3[1], h3[2], h3[3], h3[4]);

  printf("Vertical_0 stats: 0: %d, 1: %d, 2: %d, 3: %d, Other: %d \n", v0[0], v0[1], v0[2], v0[3], v0[4]);
  printf("Vertical_1 stats: 0: %d, 1: %d, 2: %d, 3: %d, Other: %d \n", v1[0], v1[1], v1[2], v1[3], v1[4]);
  printf("Vertical_2 stats: 0: %d, 1: %d, 2: %d, 3: %d, Other: %d \n", v2[0], v2[1], v2[2], v2[3], v2[4]);
  printf("Vertical_3 stats: 0: %d, 1: %d, 2: %d, 3: %d, Other: %d \n", v3[0], v3[1], v3[2], v3[3], v3[4]);
  printf("All cars found: %d \n", found);

}
