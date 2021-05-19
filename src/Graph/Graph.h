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
constexpr auto INF_DOUBLE = std::numeric_limits<long double>::max();
constexpr auto NEG_INF_DOUBLE = std::numeric_limits<long double>::min();

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
    long double x;   //for graphviewer
    long double y;   //for graphviewer

    vector<Edge* > adj;  // outgoing edges

    bool visited;  // for path finding
    Edge *path; // for path finding
    long double dist;   // for path finding
    int queueIndex = 0; // required by MutablePriorityQueue


    Vertex(unsigned long id, long double x, long double y);
    void addEdge(Edge *e);
    bool operator<(Vertex & vertex) const; // required by MutablePriorityQueue

public:
    unsigned long getId() const;
    vector<Edge* > getAdj() const;
    void setX(double x);
    void setY(double y);
    long double getX() const;
    long double getY() const;
    friend class Graph;
    friend class MutablePriorityQueue<Vertex>;
};

/* ================================================================================================
 * Class Edge
 * ================================================================================================
 */

class Edge {
    unsigned long id;
    Vertex * orig;
    Vertex * dest;
    long double distance;

    Edge(unsigned long id, Vertex *o, Vertex *d);

public:
    friend class Graph;
    friend class Vertex;
    long double getDistance() const;
    unsigned long getId() const;
    Vertex * getOrig() const;
    Vertex * getDest() const;
};

/* ================================================================================================
 * Class Graph
 * ================================================================================================
 */

class Graph {
    vector<Vertex *> vertexSet;
    vector<Edge *> edgeSet;
    long double minX = INF_DOUBLE;
    long double maxX = NEG_INF_DOUBLE;
    long double minY = INF_DOUBLE;
    long double maxY = NEG_INF_DOUBLE;

public:
    Vertex* findVertex(unsigned long id) const;
    vector<Vertex *> getVertexSet() const;
    vector<Edge *> getEdgeSet() const;
    Vertex *addVertex(unsigned long id, long double x, long double y);
    Edge *addEdge(unsigned long id, unsigned long sourc, unsigned long dest);
    long double getMinX() const;
    long double getMaxX() const;
    long double getMinY() const;
    long double getMaxY() const;
};


#endif /* GRAPH_H_ */
