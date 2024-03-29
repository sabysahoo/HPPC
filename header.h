int readInput(std::string file_name, int road_size, int total_cars, int vertical_0[], int vertical_1[], int vertical_2[], int vertical_3[], int horizontal_0[], int horizontal_1[], int horizontal_2[], int horizontal_3[] );

int getRoadSize(std::string file_name);

void printRoadTop(int vertical_0[], int vertical_1[], int vertical_2[], int vertical_3[], int horizontal_0[], int horizontal_1[] ,int horizontal_2[] , int horizontal_3[],  int road_size, bool light_holder[], bool light_state);

void printRoadData(int vertical_0[], int vertical_1[], int vertical_2[], int vertical_3[], int horizontal_0[], int horizontal_1[] ,int horizontal_2[] , int horizontal_3[], int road_size);

int* countNum(int array[], int road_size);

void debugCars(int vertical_0[], int vertical_1[], int vertical_2[], int vertical_3[], int horizontal_0[], int horizontal_1[], int horizontal_2[], int horizontal_3[], int road_size);


int findCeil(int arr[], int r, int l, int h);

int myRand(int arr[], int freq[], int n);

int makeInputRightTurns(int road_size, int total_cars, int vertical_0[], int vertical_3[], int horizontal_0[], int horizontal_3[]);

int makeInputLeftTurns(int road_size, int total_cars, int vertical_1[], int vertical_2[], int horizontal_1[], int horizontal_2[]);
