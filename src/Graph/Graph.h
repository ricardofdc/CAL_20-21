#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>
#include <queue>
#include <limits>
#include <iostream>
#include <cmath>
#include <algorithm>
#include "MutablePriorityQueue.h"
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

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

    vector<Edge *> adj;  // outgoing edges
    vector<Edge *> allAdj; // outgoing + ingoing edges

    bool visited;  // for path finding
    Vertex *path; // for path finding
    long double dist;   // for path finding
    int queueIndex = 0; // required by MutablePriorityQueue
    int dfsNum = 0;
    bool isCarPark = false;

    Vertex(unsigned long id, long double x, long double y);
    void addEdge(Edge *e);
    bool operator<(Vertex &vertex) const; // required by MutablePriorityQueue

public:
    unsigned long getId() const;
    void setX(double x);
    void setY(double y);
    long double getX() const;
    long double getY() const;
    vector<Edge *> getAdj() const;
    bool CarPark();
    friend class Graph;
    friend class MutablePriorityQueue<Vertex>;
};

/* ================================================================================================
* Class Edge
* ================================================================================================
*/

class Edge {
    unsigned long id;
    Vertex *orig;
    Vertex *dest;
    long double distance;

    Edge(unsigned long id, Vertex *o, Vertex *d);

public:
    friend class Graph;
    friend class Vertex;
    long double getDistance() const;
    unsigned long getId() const;
    Vertex *getOrig() const;
    Vertex *getDest() const;
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
    unsigned int numCarPark = 0;

public:
    Vertex *findVertex(unsigned long id) const;
    vector<Vertex *> getVertexSet() const;
    vector<Edge *> getEdgeSet() const;
    Edge *getEdgeFromTo(const unsigned long &from, const unsigned long &to) const;
    Vertex *addVertex(unsigned long id, long double x, long double y);
    Edge *addEdge(unsigned long id, unsigned long sourc, unsigned long dest);
    long double getMinX() const;
    long double getMaxX() const;
    long double getMinY() const;
    long double getMaxY() const;
    unsigned int getNumCarPark() const;
    Vertex *initSingleSource(const unsigned long &origin);
    bool relax(Vertex *v, Vertex *w, long double distance);
    void dijkstraShortestPath(const unsigned long &origin);
    vector<unsigned long> getPath(const unsigned long &origin, const unsigned long &dest) const;
    vector<vector<Vertex *>> dfs(bool post_order) const;
    void dfsVisit(Vertex *v, vector<Vertex *> &vec) const;
    void dfsVisitPostOrder(Vertex *v, vector<Vertex *> &vec) const;
    vector<vector<Vertex *>> stronglyConnectedComponents();
    unsigned long findClosestParkBFS(Vertex *dest, vector<unsigned long> exclude);
};


#endif /* GRAPH_H_ */
