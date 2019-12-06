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
#define WHITE   "\033[97m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

const char *light = u8"\u2B24";

void printRoadTop(int vertical_0[], int vertical_1[], int vertical_2[], int vertical_3[], int horizontal_0[], int horizontal_1[], int horizontal_2[], int horizontal_3[], int road_size, bool light_holder[], bool light_state){

  int section_xy = (road_size - 4)/2;
  int sectionBegin = section_xy - 8;

  //print vertical values for top half ======================================
  for(int i=sectionBegin; i<section_xy; i++){

    cout << WHITE;

    for(int j = sectionBegin; j<section_xy+1; j++){
      cout<< " " <<"\t";
    }

    cout << RESET;

    if( vertical_0[i] > 0){
      cout << BOLDBLACK;
    }
    else{
      cout << WHITE;
    }

    cout<< vertical_0[i]<< "\t";
    cout << RESET;

    if( vertical_1[i] > 0){
      cout << BOLDBLACK;
    }
    else{
      cout << WHITE;
    }

    cout<< vertical_1[i]<< "\t";
    cout << RESET;

    if( vertical_2[i] > 0){
      cout << BOLDBLACK;
    }
    else{
      cout << WHITE;
    }

    cout<< vertical_2[i]<< "\t";
    cout << RESET;

    if( vertical_3[i] > 0){
      cout << BOLDBLACK;
    }
    else{
      cout << WHITE;
    }

    cout<< vertical_3[i]<< "\t";

    cout << WHITE;


    for(int j=sectionBegin; j<section_xy+1; j++){
      cout<< " " <<"\t";
    }

    cout<< "\n";
    cout<< "\n";

  }
  //==================================================================


  //print northern lights ============================================
  for( int i = sectionBegin; i<road_size-sectionBegin; i++){

    if( i > section_xy && i < section_xy + 5 ){

      if( i == section_xy+1 || i == section_xy+2){

          if( light_holder[3] == 1 && light_state == true){
            cout << BOLDGREEN;
            cout << light << "\t";
          }
          else if( light_holder[0] == 1 && light_state == false){
            cout << BOLDYELLOW;
            cout << light << "\t";
          }
          else{
            cout << BOLDRED;
            cout << light << "\t";
          }
      }
      else{

          if( light_holder[1] == true && light_state == true){
            cout << BOLDGREEN;
            cout << light << "\t";
          }
          else if( light_holder[2] == true && light_state == false){
            cout << BOLDYELLOW;
            cout << light << "\t";
          }
          else{
            cout << BOLDRED;
            cout << light << "\t";
          }
      }

    } //end middle light section

    else{
      cout << " " << "\t";
    }
  }

  cout<< "\n";
  cout<< "\n";
  //====================================================================


  //begin horizontal printing===========================================
  cout << RESET;

  //print h0 lanes
  for( int i = sectionBegin; i<road_size-sectionBegin; i++){

    if( horizontal_0[i] > 0){
      cout << BOLDBLACK;
    }
    else{
      cout << WHITE;
    }

    if( i < section_xy ){
      cout << horizontal_0[i] << "\t";
    }

    if( (i >= section_xy) && (i < section_xy + 4) ){

      cout << BOLDBLACK;

      if( horizontal_0[i] > 0){
        cout << horizontal_0[i] << "\t";
      }
      else if( i == section_xy && vertical_0[section_xy] > 0){
        cout << vertical_0[section_xy] << "\t";
      }
      else if( i == section_xy+1 && vertical_1[section_xy] > 0){
              cout << vertical_1[section_xy] << "\t";
      }
      else if( i == section_xy+2 && vertical_2[section_xy] > 0){
            cout << vertical_2[section_xy] << "\t";
      }
      else if( i == section_xy+3 && vertical_3[section_xy] > 0){
              cout << vertical_3[section_xy] << "\t";
      }
      else{
        cout << WHITE;
        cout << "0" << "\t";
      }

    }

   //end middle print

      if( i == section_xy-1 ){

          if( light_holder[2] == 1 && light_state == true){
            cout << BOLDGREEN;
          }
          else if( light_holder[3] == 1 && light_state == false){
            cout << BOLDYELLOW;
          }
          else{
            cout << BOLDRED;
          }
          cout << light << "\t";
        }

        if( i == section_xy+3){
          if( light_holder[2] == 1 && light_state == true){
            cout << BOLDGREEN;
          }
          else if( light_holder[3] == 1 && light_state == false){
            cout << BOLDYELLOW;
          }
          else{
            cout << BOLDRED;
          }
          cout << light << "\t";
        }

        if( i >= section_xy + 4){
          if( horizontal_0[i] > 0){
            cout << BOLDBLACK;
          }
          else{
            cout << WHITE;
          }
          cout << horizontal_0[i] << "\t";
        }

  }

  cout<< "\n";
  cout<< "\n";

  //print h1 street
  for( int i = sectionBegin; i<road_size-sectionBegin; i++){
    if( horizontal_1[i] > 0){
      cout << BOLDBLACK;
    }
    else{
      cout << WHITE;
    }
    if( i < section_xy ){
      cout << horizontal_1[i] << "\t";
    }

    if( i >= section_xy && i < section_xy + 4){

      cout << BOLDBLACK;

      if( horizontal_1[i] > 0){
        cout << horizontal_1[i] << "\t";
      }
      else if( i == section_xy && vertical_0[section_xy+1] > 0){
        cout << vertical_0[section_xy+1] << "\t";
      }
      else if( i == section_xy+1 && vertical_1[section_xy+1] > 0){
              cout << vertical_1[section_xy+1] << "\t";
      }
      else if( i == section_xy+2 && vertical_2[section_xy+1] > 0){
            cout << vertical_2[section_xy+1] << "\t";
      }
      else if( i == section_xy+3 && vertical_3[section_xy+1] > 0){
              cout << vertical_3[section_xy+1] << "\t";
      }
      else{
        cout << WHITE;
        cout << "0" << "\t";
      }

    }

        if( i == section_xy-1 ){

          if( light_holder[2] == 1 && light_state == true){
            cout << BOLDGREEN;
          }
          else if( light_holder[3] == 1 && light_state == false){
            cout << BOLDYELLOW;
          }
          else{
            cout << BOLDRED;
          }
          cout << light << "\t";
        }

        if( i == section_xy+3){
          if( light_holder[2] == 1 && light_state == true){
            cout << BOLDGREEN;
          }
          else if( light_holder[3] == 1 && light_state == false){
            cout << BOLDYELLOW;
          }
          else{
            cout << BOLDRED;
          }
          cout << light << "\t";
        }

        if( i >= section_xy + 4){
          if( horizontal_1[i] > 0){
            cout << BOLDBLACK;
          }
          else{
            cout << WHITE;
          }
          cout << horizontal_1[i] << "\t";
        }

  }
  cout<< "\n";
  cout<< "\n";

  //print h2 street
  for( int i = sectionBegin; i<road_size-sectionBegin; i++){
    if( horizontal_2[i] > 0){
      cout << BOLDBLACK;
    }
    else{
      cout << WHITE;
    }
    if( i < section_xy ){
      cout << horizontal_2[i] << "\t";
    }

    if( i >= section_xy && i < section_xy + 4){

      cout << BOLDBLACK;

      if( horizontal_2[i] > 0){
        cout << horizontal_2[i] << "\t";
      }
      else if( i == section_xy && vertical_0[section_xy+2] > 0){
        cout << vertical_0[section_xy+2] << "\t";
      }
      else if( i == section_xy+1 && vertical_1[section_xy+2] > 0){
              cout << vertical_1[section_xy+2] << "\t";
      }
      else if( i == section_xy+2 && vertical_2[section_xy+2] > 0){
            cout << vertical_2[section_xy+2] << "\t";
      }
      else if( i == section_xy+3 && vertical_3[section_xy+2] > 0){
              cout << vertical_3[section_xy+2] << "\t";
      }
      else{
        cout << WHITE;
        cout << "0" << "\t";
      }

    }

        if( i == section_xy-1 ){
          if( light_holder[0] == 1 && light_state == true){
            cout << BOLDGREEN;
          }
          else if( light_holder[1] == 1 && light_state == false){
            cout << BOLDYELLOW;
          }
          else{
            cout << BOLDRED;
          }
          cout << light << "\t";
        }

        if( i == section_xy+3){
          if( light_holder[0] == 1 && light_state == true){
            cout << BOLDGREEN;
          }
          else if( light_holder[1] == 1 && light_state == false){
            cout << BOLDYELLOW;
          }
          else{
            cout << BOLDRED;
          }
          cout << light << "\t";
        }

        if( i >= section_xy + 4){
          if( horizontal_2[i] > 0){
            cout << BOLDBLACK;
          }
          else{
            cout << WHITE;
          }
          cout << horizontal_2[i] << "\t";
        }

  }
  cout<< "\n";
  cout<< "\n";


  //print h3 street
  for( int i = sectionBegin; i<road_size-sectionBegin; i++){
    if( horizontal_3[i] > 0){
      cout << BOLDBLACK;
    }
    else{
      cout << WHITE;
    }
    if( i < section_xy ){
      cout << horizontal_3[i] << "\t";
    }

    if( i >= section_xy && i < section_xy + 4){

      cout << BOLDBLACK;

      if( horizontal_3[i] > 0){
        cout << horizontal_3[i] << "\t";
      }
      else if( i == section_xy && vertical_0[section_xy+3] > 0){
        cout << vertical_0[section_xy+3] << "\t";
      }
      else if( i == section_xy+1 && vertical_1[section_xy+3] > 0){
              cout << vertical_1[section_xy+3] << "\t";
      }
      else if( i == section_xy+2 && vertical_2[section_xy+3] > 0){
            cout << vertical_2[section_xy+3] << "\t";
      }
      else if( i == section_xy+3 && vertical_3[section_xy+3] > 0){
              cout << vertical_3[section_xy+3] << "\t";
      }
      else{
        cout << WHITE;
        cout << "0" << "\t";
      }



    }

        if( i == section_xy-1 ){
          if( light_holder[0] == 1 && light_state == true){
            cout << BOLDGREEN;
          }
          else if( light_holder[1] == 1 && light_state == false){
            cout << BOLDYELLOW;
          }
          else{
            cout << BOLDRED;
          }
          cout << light << "\t";
        }

        if( i == section_xy+3){
          if( light_holder[0] == 1 && light_state == true){
            cout << BOLDGREEN;
          }
          else if( light_holder[1] == 1 && light_state == false){
            cout << BOLDYELLOW;
          }
          else{
            cout << BOLDRED;
          }
          cout << light << "\t";
        }

        if( i >= section_xy + 4){
          if( horizontal_3[i] > 0){
            cout << BOLDBLACK;
          }
          else{
            cout << WHITE;
          }
          cout << horizontal_3[i] << "\t";
        }

  }
  cout<< "\n";
  cout<< "\n";

  cout<< WHITE;
  // end printing horizontal streets===================================

  //print south lights =================================================
  for( int i = sectionBegin; i<road_size-sectionBegin; i++){

    if( i > section_xy && i < section_xy + 5 ){

      if( i == section_xy+1 || i == section_xy+2){

        if( light_holder[3] == true && light_state == true){
          cout << BOLDGREEN;
          cout << light << "\t";
        }
        else if(light_holder[0] == true && light_state == false){
          cout << BOLDYELLOW;
          cout << light << "\t";
        }
        else{
          cout << RED;
          cout << light << "\t";
        }

      }
      else{

        if( light_holder[1] == true && light_state == true){
          cout << BOLDGREEN;
          cout << light << "\t";
        }
        else if(light_holder[2] == true && light_state == false){
          cout << BOLDYELLOW;
          cout << light << "\t";
        }
        else{
          cout << RED;
          cout << light << "\t";
        }


      }

    }

    else{
      cout << " " << "\t";
    }
  }

  cout<< "\n";
  cout<< "\n";
  //====================================================================


  //print bottom vertical values =======================================
  for(int i=section_xy+4; i<(road_size-sectionBegin); i++){

    cout << WHITE;

    for(int j=sectionBegin; j<section_xy+1; j++){
      cout<< " " <<"\t";
    }

    cout << RESET;

    if( vertical_0[i] > 0){
      cout << BOLDBLACK;
    }
    else{
      cout << WHITE;
    }
    cout<< vertical_0[i]<< "\t";
    cout << RESET;

    if( vertical_1[i] > 0){
      cout << BOLDBLACK;
    }
    else{
      cout << WHITE;
    }

    cout<< vertical_1[i]<< "\t";

    if( vertical_2[i] > 0){
      cout << BOLDBLACK;
    }
    else{
      cout << WHITE;
    }

    cout<< vertical_2[i]<< "\t";

    if( vertical_3[i] > 0){
      cout << BOLDBLACK;
    }
    else{
      cout << WHITE;
    }

    cout<< vertical_3[i]<< "\t";

    cout << WHITE;

    for(int j=sectionBegin; j<section_xy+1; j++){
      cout<< " " <<"\t";
    }

    cout << RESET;

    cout<< "\n";
    cout<< "\n";
  }
  //========================================================================

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
