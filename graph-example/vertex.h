#ifndef VERTEX_H
#define VERTEX_H

template<typename V, typename E>
class Graph; 

template <typename G>
class Vertex {
    typedef typename G::VV V;
    typedef typename G::EdgeSeq EdgeSeq;

    EdgeSeq edges;

public:
    int id;
    V data;

    template<typename, typename>
    friend class Graph; 
};

#endif