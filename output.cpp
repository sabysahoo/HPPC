#include <iostream>
#include "header.h"
using namespace std;

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

void printRoadTop(int vertical_0[], int vertical_1[], int vertical_2[], int vertical_3[], int horizontal_0[], int horizontal_1[], int horizontal_2[], int horizontal_3[], int road_size, bool light_holder[]){

  int section_xy = (road_size - 4)/2;

  for(int i= 0; i<section_xy; i++){

    cout << BOLDWHITE;

    for(int j= 0; j<section_xy; j++){
      cout<< "+" <<"\t";
    }

    cout << RESET;

    if( vertical_0[i] > 0){
      cout << BOLDBLACK;
    }
    else{
      cout << BOLDCYAN;
    }
    cout<< vertical_0[i]<< "\t";
    cout << RESET;

    if( vertical_1[i] > 0){
      cout << BOLDBLACK;
    }
    else{
      cout << BOLDCYAN;
    }

    cout<< vertical_1[i]<< "\t";
    cout << RESET;

    if( vertical_2[i] > 0){
      cout << BOLDBLACK;
    }
    else{
      cout << BOLDCYAN;
    }

    cout<< vertical_2[i]<< "\t";
    cout << RESET;

    if( vertical_3[i] > 0){
      cout << BOLDBLACK;
    }
    else{
      cout << BOLDCYAN;
    }

    cout<< vertical_3[i]<< "\t";

    cout << BOLDWHITE;


    for(int j=0; j<section_xy; j++){
      cout<< "+" <<"\t";
    }

    cout<< "\n";
    cout<< "\n";

  }

  cout << RESET;

  for( int i = 0; i<road_size; i++){
    if( horizontal_0[i] > 0){
      cout << BOLDBLACK;
    }
    else{
      cout << BOLDCYAN;
    }
      cout << horizontal_0[i] << "\t";
  }

  cout<< "\n";
  cout<< "\n";

  for( int i = 0; i<road_size; i++){
    if( horizontal_1[i] > 0){
      cout << BOLDBLACK;
    }
    else{
      cout << BOLDCYAN;
    }
      cout << horizontal_1[i] << "\t";
  }
  cout<< "\n";
  cout<< "\n";

  for( int i = 0; i<road_size; i++){
    if( horizontal_2[i] > 0){
      cout << BOLDBLACK;
    }
    else{
      cout << BOLDCYAN;
    }
      cout << horizontal_2[i] << "\t";
  }
  cout<< "\n";
  cout<< "\n";


  for( int i = 0; i<road_size; i++){
    if( horizontal_3[i] > 0){
      cout << BOLDBLACK;
    }
    else{
      cout << BOLDCYAN;
    }
      cout << horizontal_3[i] << "\t";
  }
  cout<< "\n";
  cout<< "\n";

  cout<< BOLDWHITE;

  for(int i= section_xy+4; i<road_size; i++){

    cout << BOLDWHITE;

    for(int j= 0; j<section_xy; j++){
      cout<< "+" <<"\t";
    }

    cout << RESET;

    if( vertical_0[i] > 0){
      cout << BOLDBLACK;
    }
    else{
      cout << BOLDCYAN;
    }
    cout<< vertical_0[i]<< "\t";
    cout << RESET;

    if( vertical_1[i] > 0){
      cout << BOLDBLACK;
    }
    else{
      cout << BOLDCYAN;
    }

    cout<< vertical_1[i]<< "\t";
    cout << RESET;

    if( vertical_2[i] > 0){
      cout << BOLDBLACK;
    }
    else{
      cout << BOLDCYAN;
    }

    cout<< vertical_2[i]<< "\t";
    cout << RESET;

    if( vertical_3[i] > 0){
      cout << BOLDBLACK;
    }
    else{
      cout << BOLDCYAN;
    }

    cout<< vertical_3[i]<< "\t";

    cout << BOLDWHITE;

    cout << BOLDWHITE;

    for(int j=0; j<section_xy; j++){
      cout<< "+" <<"\t";
    }

    cout << RESET;

    cout<< "\n";
    cout<< "\n";
  }


}

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
