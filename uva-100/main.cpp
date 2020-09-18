#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

void orderInput(int&, int&);
int getMaxCycle(int, int);
int threeNPlusOne(long);

int main() {
    int start, end;
    while ((scanf("%d %d", &start, &end)) == 2) {
        int maxCycle = getMaxCycle(start, end);
        printf("%d %d %d\n", start, end, maxCycle);
    }

    return EXIT_SUCCESS;
}

void orderInput(int& start, int& end) {
    if (end < start) {
        swap(start, end);
    }
}

int getMaxCycle(int start, int end) {
    orderInput(start, end);

    int maxCycle = 0;
    for (int i = start; i <= end; i++) {
        int cycle = threeNPlusOne(i);
        if (cycle > maxCycle) {
            maxCycle = cycle;
        }
    }

    return maxCycle;
}

int threeNPlusOne(long number) {
    int count = 1;
    while (number != 1) {
        count++;
        number = (number % 2 == 0) ?  number / 2 : 3 * number + 1;
    }

    return count;
}