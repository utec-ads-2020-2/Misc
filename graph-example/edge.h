#ifndef EDGE_H
#define EDGE_H

#include "vertex.h"

template<typename G>
class Edge {    
    typedef typename G::EE E;
    typedef typename G::vertex vertex;

    vertex* vertexes[2];

public:
    E data;

    template<typename, typename>
    friend class Graph; 
};

#endif