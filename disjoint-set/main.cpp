#include <iostream>

#include "disjoint.h"

using namespace std;

int main(int argc, char *argv[]) {
    cout << "===========================================================" << endl;
    cout << "\tDisjoint Set Practice" << endl;
    cout << "===========================================================" << endl << endl;

    DisjointSet ds;
    for (int i = 0; i < 7; i++) {
        ds.makeSet(i + 1);
    }

    printf("Union\n");
    cout << ds.unionSet(1, 2) << endl;
    cout << ds.unionSet(2, 3) << endl;
    cout << ds.unionSet(4, 5) << endl;
    cout << ds.unionSet(6, 7) << endl;
    cout << ds.unionSet(5, 6) << endl;
    cout << ds.unionSet(3, 7) << endl;
    cout << ds.unionSet(5, 2) << endl;

    printf("\nFind\n");
    for (int i = 0; i < 7; i++) {
        const int element = i + 1;
        printf("%d: %d\n", element, ds.find(element));
    }

    return EXIT_SUCCESS;
}