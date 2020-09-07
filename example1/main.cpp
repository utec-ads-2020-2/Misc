#include <iostream>
#include "debugger/debugger.h"

using namespace std;

void test(int*, int);

int main(int argc, char const *argv[]) {
      int arr[5] = {1 , 2 , 3 , 4 , 5};
      int size = sizeof(arr) / sizeof(arr[0]);

      test(arr, size);
    
   	return EXIT_SUCCESS;
}

void test(int* ptr, int size) {
    int* temp = ptr;

    Debugger<int> debugger(ptr, size);
    debugger.out(*ptr, ptr);
    debugger.out(*ptr++, ptr);
    debugger.out(*++ptr, ptr);
    debugger.out(++*ptr, ptr);
    debugger.out((*ptr)++, ptr);
    debugger.out(*ptr, ptr);
}