#include <iostream>

void print_Road_Top(int vertical_0[], int vertical_1[], int vertical_2[], int vertical_3[],  int road_size){
  int section_xy = (road_size - 4)/2;
  for(int i= 0; i < section_xy; i++){
    for(int j= 0; j < section_xy; j++){
      std::cout<< "+" <<"\t";
    } 
    std::cout<< vertical_0[i]<<"\t"<<
    vertical_1[i]<<"\t"<<
    vertical_2[i]<<"\t"<<
    vertical_3[i]<<"\t";     
    for(int j= 0; j < section_xy; j++){
      std::cout<< "+" <<"\t";
    }
    std::cout<< "\n";
  }
}

int main(){
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
  // Total number of cars in one road.
  int road_size = 14;
  
  // Lights for each intesection are named in the direction of the cars moving.
  bool east_light= red;
  bool west_light= red;
  bool north_light= red;
  bool south_light= red;
  
  int horizontal_0 [road_size];
  int horizontal_1 [road_size];
  int horizontal_2 [road_size];
  int horizontal_3 [road_size];
  int vertical_0 [road_size];
  int vertical_1 [road_size];
  int vertical_2 [road_size];
  int vertical_3 [road_size];
  
  for(int i =0; i < road_size; i++){
    horizontal_0[i] = 0;
    horizontal_1[i] = 0;
    horizontal_2[i] = 0;
    horizontal_3[i] = 0;
    vertical_0[i] = 0;
    vertical_1[i] = 0;
    vertical_2[i] = 0;
    vertical_3[i] = 0;
  }
  
  print_Road_Top(vertical_0, vertical_1, vertical_2, vertical_3, road_size);
  std::cout<< "The project is fine! \n" ;
  

  return 0;
}

/**
void print_Road(int vertical_0[], int vertical_1[], int vertical_2[], int vertical_3[],  int road_size){

  int section_xy = (road_size - 4)/2;
  for(int i= 0; i < section_xy; i++){
    for(int j= 0; j < section_xy; j++){
      std::cout<< "+" <<"\t";
    }
    for(int j= section_xy; j < section_xy + 4; j++){
        std::cout<< vertical_0[i]<<"\t"<<
        vertical_1[i]<<"\t"<<
        vertical_2[i]<<"\t"<<
        vertical_3[i]<<"\t";   
    }
    for(int j= 0; j < section_xy; j++){
      std::cout<< "+" <<"\t";
    }
    
    std::cout<< "\n";
  }

  for(int i= 0; i < road_size; i++){
    std::cout<< horizontal_0[i]<<"\t"<< horizontal_1[i]<<"\t" << 
    horizontal_2[i]<<"\t"<< horizontal_3[i]<<"\t"<< vertical_0[i]<<"\t"<<
    vertical_1[i]<<"\t"<< vertical_2[i]<<"\t"<< vertical_3[i]<<"\n";
  }

}

void print_Road(int vertical_0[], int vertical_1[], int vertical_2[], int vertical_3[],  int road_size){

  int section_xy = (road_size - 4)/2;
  for(int i= 0; i < section_xy; i++){
    for(int j= 0; j < road_size; j++){
      if(j<section_xy || j > section_xy + 4){
        std::cout<< "+" <<"\t";
      } else {
        std::cout<< vertical_0[i]<<"\t"<<
        vertical_1[i]<<"\t"<<
        vertical_2[i]<<"\t"<<
        vertical_3[i]<<"\t";
      }  
    }
    std::cout<< "\n";
  }

  for(int i= 0; i < road_size; i++){
    std::cout<< horizontal_0[i]<<"\t"<< horizontal_1[i]<<"\t" << 
    horizontal_2[i]<<"\t"<< horizontal_3[i]<<"\t"<< vertical_0[i]<<"\t"<<
    vertical_1[i]<<"\t"<< vertical_2[i]<<"\t"<< vertical_3[i]<<"\n";
  }

}

**/