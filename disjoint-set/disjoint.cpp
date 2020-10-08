#include "disjoint.h"

void DisjointSet::makeSet(int data) {
    auto node = new Node(data);
    this->nodes[data] = node;
}

bool DisjointSet::unionSet(int data1, int data2) {
    auto parent1 = findSet(data1);
    auto parent2 = findSet(data2);

    if (parent1 != parent2) {
        if (parent1->rank >= parent2->rank) {
            parent1->rank = (parent1->rank == parent2->rank) ? parent1->rank + 1 : parent1->rank;
            parent2->parent = parent1;
        } else {
            parent1->parent = parent2;
        }

        return true;
    }

    return false;
}

int DisjointSet::find(int data) {
    auto parent = findSet(data);
    return parent->data;
}

Node* DisjointSet::findSet(int data) {
    return findSet(this->nodes[data]);
}

Node* DisjointSet::findSet(Node* node) {
    auto current = node;
    while (current != current->parent) {
        current = current->parent;
    }

    node->parent = current;
    return current;
}

DisjointSet::~DisjointSet() {
    for (auto it = nodes.begin(); it != nodes.end(); ++it) {
        auto node = it->second;
        nodes.erase(it);
        delete node;
    }
}