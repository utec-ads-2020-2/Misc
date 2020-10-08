#ifndef DISJOINT_H
#define DISJOINT_H

#include <iostream>
#include <unordered_map>

#include "node.h"

using namespace std;

class DisjointSet {
    private:
        unordered_map<int, Node*> nodes;

        Node* findSet(int data);
        Node* findSet(Node* node);

    public:
        DisjointSet() {};
        void makeSet(int data);
        bool unionSet(int data1, int data2);
        int find(int data);
        ~DisjointSet();
};

#endif