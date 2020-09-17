#include <iostream>

#include "element.h"

using namespace std;

template <typename T>
struct Greater {
       bool operator()(T a, T b) {
              return a >= b;
       }
};

template <typename T>
struct Less {
       bool operator()(T a, T b) {
              return a <= b;
       }
};

struct Integer {
       typedef int dataType;
       typedef Less<dataType> Operation;
};

struct Float {
       typedef float dataType;
       typedef Greater<dataType> Operation;
};

struct Double {
       typedef double dataType;
       typedef Less<dataType> Operation;
};

int main(int argc, char const *argv[]) {
       Element<Float> element;

       float first = 5;
       float second = 6;
       element.set(&first);
       cout << element.get() << endl;

       element.set(&second);
       cout << element.get() << endl;

       return EXIT_SUCCESS;
}


