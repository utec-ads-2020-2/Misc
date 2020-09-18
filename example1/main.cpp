#include<stdio.h>
#include <iostream>
#include<math.h>

using namespace std;

int main() {
    double n, p, k;
    while(cin>> n >> p) {
        k = exp(log(p)/n);
        cout << k << endl;
    }
    return 0;
}