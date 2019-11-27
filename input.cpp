#include <iostream>
#include <fstream>
#include "header.h"
using namespace std; 

int getRoadSize(string file_name){
  int road_size = 0; 
  string line;
 
  /* Creating input filestream */ 
  ifstream file(file_name);
  while (getline(file, line))
      road_size++;

  return road_size;
}

int readInput(string file_name, int road_size, int total_cars, int vertical_0[], int vertical_1[], int vertical_2[], int vertical_3[], int horizontal_0[], int horizontal_1[], int horizontal_2[], int horizontal_3[]){
  int section_xy = (road_size - 4)/2;
  string line;
  int file_size = 0; 
  /* Creating input filestream */ 
  ifstream file(file_name);
  while (getline(file, line)){
    size_t pos = 0;
    int post = 0;
    string token;
    string delimiter = ",";
    while ((pos = line.find(delimiter)) != std::string::npos) {
      token = line.substr(0, pos);
      int car_number = 0;     
      try {
        car_number = stoi(token);
        if(car_number>0 && car_number<4){
          total_cars++;
        }
      }
      catch(invalid_argument& e){
        // if no conversion could be performed, dont do anything
      }
      if(post==section_xy){
        vertical_0[file_size] = car_number;
      } else if(post==(section_xy+1)){
        vertical_1[file_size] = car_number;
      } else if(post==(section_xy+2)){
        vertical_2[file_size] = car_number;
      } else if(post==(section_xy+3)){
        vertical_3[file_size] = car_number;
      }

      if(file_size==section_xy){
        horizontal_0[post] = car_number;
      } else if(file_size==(section_xy+1)){
        horizontal_1[post] = car_number;
      } else if(file_size==(section_xy+2)){
        horizontal_2[post] = car_number;
      } else if(file_size==(section_xy+3)){
        horizontal_3[post] = car_number;
      } 

      line.erase(0, pos + delimiter.length());
      post++;
    }
    // cout << line << std::endl;
    file_size++;
  }

  return total_cars;
}
