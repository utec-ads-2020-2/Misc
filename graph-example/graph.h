#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <list>

#include "vertex.h"
#include "edge.h"

using namespace std;

template<typename V, typename E>
class Graph {
    public:
        typedef V VV;
        typedef E EE;
        typedef Graph<V, E> self;
        typedef Vertex<self> vertex;
        typedef Edge<self> edge;
        typedef vector<vertex*> VertexSeq;
        typedef list<edge*> EdgeSeq;
        typedef typename VertexSeq::iterator VertexIte;
        typedef typename EdgeSeq::iterator EdgeIte;

    private:
        VertexSeq nodes;
        VertexIte ni;
        EdgeIte ei;

    public:
        Graph() = default;
        ~Graph() {}

        /**
         * Creates a new vertex in the graph with some data 
         * @param data vertex data
         * @return true if inserted, false if the vertex is already in the graph
         **/
        //bool insertVertex(V data);

        /**
         * Creates a new vertex in the graph with some data and an ID
         * @param id a unique identifier within the vertexes
         * @param data vertex data
         * @return true if inserted, false if the vertex is already in the graph
         **/
        bool insertVertex(int id, V data);

        /**
         * Creates a new edge in the graph with some data
         * @param start data of start vertex
         * @param end data of the end vertex
         * @param data value of the edge
         * @param direction true if has direction, false if it is a two side direction (non directed graph)
         * @return true if inserted, false if the edge is already in the graph
         **/
        bool createEdge(V start, V end, E data, bool direction = false);

        /**
         * Deletes a vertex in the graph
         * @param data data to be searched and deleted
         * @return true if deleted, false if the vertex is not in the graph 
         **/
        bool deleteVertex(V data);

        /**
         * Deletes a vertex in the graph by the identifier
         * @param id the identifier of a vertex
         * @return true if deleted, false if the vertex is not in the graph 
         **/
        bool deleteVertex(int id);

        /**
         * Deletes an edge in the graph, it is not possible to search by the edge value, 
         * since it can be repeated
         * @param start data of start vertex
         * @param end data of the end vertex
         * @return true if deleted, false if the edge is not in the graph 
         **/
        bool deleteEdge(V start, V end);

        /**
         * Gets the value of the edge from the start and end vertexes
         * @param start data of start vertex
         * @param end data of the end vertex
         * @return value stored in the edge between the vertexes
         **/
        E& operator()(V start, V end);
        const E& operator()(V start, V end) const;

         /**
         * Gets the value of the vertex from the identifier
         * @param id the identifier of a vertex
         * @return value stored in the vertex
         **/
        V& operator[](int id);
        const V& operator[](int id) const;

        /**
         * Calculates the density of the graph
         * @return the density as float
         **/
        float density() const;

        /**
         * Calculates the density of the graph
         * @param threshold the threshold that defines if it is dense or not
         * @return true if it is dense and false if it is disperse
         **/
        bool isDense(float threshold = 0.5) const;

        /**
         * Detect if the graph is connected
         * @return true if it is connected and false if there is at least one missing connection
         **/
        bool isConnected() const;

        /**
         * Detect if the graph is strongly connected (only for directed graphs)
         * @return true if it is strongly connected 
         * @throw exception if this method is called from a nondirected graph
         **/
        bool isStronglyConnected() const throw();

         /**
         * Detect if the graph is bipartite
         * @return true if it is bipartite 
         **/
        bool isBipartite() const;

        /**
         * If the graph is empty
         * @return true if there are no vertexes, false if the graph has at least one vertex
         **/
        bool empty();

        /**
         * Clears the graph
         **/
        void clear();
};

typedef Graph<string, double> graph;

#endif