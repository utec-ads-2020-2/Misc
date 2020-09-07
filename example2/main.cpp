#include <iostream>

using namespace std;

#define SIZE 5

struct Point {
    float x, y;

    Point() : x(11), y(12) {}
};

int main(int argc, char const *argv[]) {
    int value = 1;
    int arr[SIZE] = {1 , 2 , 3 , 4 , 5};
    Point point;

    // The actual address of a variable in memory cannot be known before runtime
    int* hvalue = new int(1);
    int* harr = new int[SIZE];
    harr[0] = 1;
    harr[1] = 2;
    harr[2] = 3;
    harr[3] = 4;
    harr[4] = 5;
    Point* hpoint = new Point();

    delete hvalue;
    delete[] harr;
    delete hpoint;
     
   	return EXIT_SUCCESS;
}