#include <iostream>
#include <fstream>
#include <vector>

using namespace std; 

void print_Road_Top(int vertical_0[], int vertical_1[], int vertical_2[], int vertical_3[],  int road_size);

int readInputSize(string file_name);

void populateRoad(int vertical_0[], int vertical_1[], int vertical_2[], int vertical_3[],
                  int horizontal_0[], int horizontal_1[] ,int horizontal_2[] , int horizontal_3[]);

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
 
  string file_name = "input.csv";
  // Total number of cars in one road. Reads the input file and gets array dimensions.
  int road_size = readInputSize(file_name);
  std::cout<< "The dimensions are: " << road_size << " \n" ;

  // Total number of cars from the input.
  int total_cars = 0;
  
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

  populateRoad(vertical_0, vertical_1, vertical_2, vertical_3,
               horizontal_0, horizontal_1, horizontal_2, horizontal_3);

  print_Road_Top(vertical_0, vertical_1, vertical_2, vertical_3, road_size);
  std::cout<< "The project is fine! \n" ;

  return 0;
}

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

int readInputSize(string file_name){
  int road_size = 0; 
  string line;
 
  /* Creating input filestream */ 
  ifstream file(file_name);
  while (getline(file, line))
      road_size++;

  return road_size;
}


void populateRoad(int vertical_0[], int vertical_1[], int vertical_2[], int vertical_3[],
                  int horizontal_0[], int horizontal_1[] ,int horizontal_2[] , int horizontal_3[]){

  //readfile
  fstream file;
  vector<string> row;

  file.open("sample.csv");

  string line;
  int spot = -1;

  while (getline( file, line, '\n')){

    spot++;

    row.clear();

    istringstream templine(line);
    string data;

    while ( getline( templine, data, ',') ){
      row.push_back(data);
    }

    if(spot<5 || spot>8){

      int start = ((row.size()+1)-4)/2;
      int end = start+4;

      for( int i=start; i<end; i++){

        if( i == 5){
          vertical_0[spot] = stoi(row[i]);
        }
        else if( i == 6){
          vertical_1[spot] = stoi(row[i]);
        }
        else if(i == 7){
          vertical_2[spot] = stoi(row[i]);
        }
        else{
          vertical_3[spot] = stoi(row[i]);
        }

      }
    }
    else{

      for( int i = 0; i<row.size(); i++){

        if(spot == 5){
          horizontal_0[i] = stoi(row[i]);
        }
        else if(spot == 6){
          horizontal_1[i] = stoi(row[i]);
        }
        else if(spot == 7){
          horizontal_2[i] = stoi(row[i]);
        }
        else{
          horizontal_3[i] = stoi(row[i]);
        }
    }

  }
}

  file.close();

}


void readInput(string file_name, int road_size, int vertical_0[], int vertical_1[], int vertical_2[], int vertical_3[], int horizontal_0[], int horizontal_1[], int horizontal_2[], int horizontal_3[]){
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

      if(post==section_xy){
        vertical_0[file_size] = stoi(token);
      } else if(post==(section_xy+1)){
        vertical_1[file_size] = stoi(token);
      } else if(post==(section_xy+2)){
        vertical_2[file_size] = stoi(token);
      } else if(post==(section_xy+3)){
        vertical_3[file_size] = stoi(token);
      }

      if(file_size==section_xy){
        horizontal_0[post] = stoi(token);
      } else if(file_size==(section_xy+1)){
        horizontal_1[file_size] = stoi(token);
      } else if(file_size==(section_xy+2)){
        horizontal_2[file_size] = stoi(token);
      } else if(file_size==(section_xy+3)){
        horizontal_3[file_size] = stoi(token);
      } 

      line.erase(0, pos + delimiter.length());
      post++;
    }
//    cout << line << std::endl;

    file_size++;

  }

}

