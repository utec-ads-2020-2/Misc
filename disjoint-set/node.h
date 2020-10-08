#ifndef NODE_H
#define NODE_H

struct Node {
    int rank;
    int data;
    Node* parent;

    Node(int data) : data(data), rank(0), parent(this) {};
};

#endif