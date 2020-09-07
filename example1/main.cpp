#include <iostream>
#include "debugger/debugger.h"

using namespace std;

void test(int*, int);

int strlen(char* str, int size) {
      int count = 0;

      while (*str != '\0') {
            ++count;
            ++str;
      }

      return count;
}

void func(int **ptr) {
      static int number = 5;
 	*ptr = &number;
  	number++;
}

int main(int argc, char const *argv[]) {
      /*int a, b;

      cin >> a;
      cout << a;
      cin >> b;
      cout << a << b << endl;*/

      int q = 10;
      int *ptr = &q;
      func(&ptr);
      func(&ptr);
      cout << *ptr << endl;

    /*int arr[5] = {1 , 2 , 3 , 4 , 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    test(arr, size);*/
    
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