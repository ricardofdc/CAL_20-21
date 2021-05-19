#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>
#include <queue>
#include <limits>
#include <iostream>
#include <cmath>
#include "MutablePriorityQueue.h"

using namespace std;

constexpr auto INF = std::numeric_limits<unsigned long>::max();

class Vertex;
class Edge;
class Graph;

/*
 * ================================================================================================
 * Class Vertex
 * ================================================================================================
 */


class Vertex {
    unsigned long id;
    double x;   //for graphviewer
    double y;   //for graphviewer

    vector<Edge* > adj;  // outgoing edges

    bool visited;  // for path finding
    Edge *path; // for path finding
    double dist;   // for path finding
    int queueIndex = 0; // required by MutablePriorityQueue


    Vertex(unsigned long id);
    void addEdge(Vertex *d);
    bool operator<(Vertex & vertex) const; // required by MutablePriorityQueue

public:
    unsigned long getId() const;
    vector<Edge* > getAdj() const;
    void setX(double x);
    void setY(double y);
    double getX() const;
    double getY() const;
    friend class Graph;
    friend class MutablePriorityQueue<Vertex>;
};

/* ================================================================================================
 * Class Edge
 * ================================================================================================
 */

class Edge {
    Vertex * orig;
    Vertex * dest;
    double distance;

    Edge(Vertex *o, Vertex *d);

public:
    friend class Graph;
    friend class Vertex;
    double getDistance() const;
};

/* ================================================================================================
 * Class Graph
 * ================================================================================================
 */

class Graph {
    vector<Vertex *> vertexSet;

public:
    Vertex* findVertex(const unsigned long &id) const;
    vector<Vertex *> getVertexSet() const;
    Vertex *addVertex(const unsigned long &id);
    Edge *addEdge(const unsigned long &sourc, const unsigned long &dest);
};


#endif /* GRAPH_H_ */
