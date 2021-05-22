//
// Created by ricar on 19/05/2021.
//

#include <algorithm>
#include "Graph.h"


/*
 * ================================================================================================
 * Class Vertex
 * ================================================================================================
 */

Vertex::Vertex(unsigned long id, long double x, long double y): id(id), x(x), y(y) {}

void Vertex::addEdge(Edge *e) {
    adj.push_back(e);
}

bool Vertex::operator<(Vertex & vertex) const {
    return this->dist < vertex.dist;
}

unsigned long Vertex::getId() const {
    return this->id;
}

vector<Edge* >  Vertex::getAdj() const {
    return this->adj;
}

void Vertex::setX(double x) {
    this->x = x;
}

long double Vertex::getX() const {
    return this->x;
}

void Vertex::setY(double y) {
    this->y = y;
}

long double Vertex::getY() const {
    return this->y;
}

/* ================================================================================================
 * Class Edge
 * ================================================================================================
 */

Edge::Edge(unsigned long id, Vertex *o, Vertex *d):
        id(id), orig(o), dest(d){
    this->distance = sqrt(pow((o->getX()+d->getX()),2) + pow((o->getY()+d->getY()),2));
}

long double Edge::getDistance() const {
    return this->distance;
}

unsigned long Edge::getId() const {
    return this->id;
}

Vertex *Edge::getOrig() const {
    return this->orig;
}

Vertex *Edge::getDest() const {
    return this->dest;
}


/* ================================================================================================
 * Class Graph
 * ================================================================================================
 */

Vertex * Graph::addVertex(unsigned long id, long double x, long double y) {
    Vertex *v = findVertex(id);
    if (v != nullptr)
        return v;
    v = new Vertex(id, x, y);
    vertexSet.push_back(v);

    if(x<minX) minX = x;
    if(x>maxX) maxX = x;
    if(y<minY) minY = y;
    if(y>maxY) maxY = y;

    return v;
}

Edge * Graph::addEdge(unsigned long id, unsigned long sourc, unsigned long dest) {
    auto s = findVertex(sourc);
    auto d = findVertex(dest);
    if (s == nullptr || d == nullptr)
        return nullptr;
    Edge *e = new Edge(id, s, d);
    s->addEdge(e);
    edgeSet.push_back(e);
    return e;
}

Vertex* Graph::findVertex(unsigned long id) const {
    for (auto v : vertexSet)
        if (v->id == id)
            return v;
    return nullptr;
}

vector<Vertex *> Graph::getVertexSet() const {
    return vertexSet;
}

vector<Edge *> Graph::getEdgeSet() const {
    return edgeSet;
}

long double Graph::getMinX() const {
    return minX;
}

long double Graph::getMaxX() const {
    return maxX;
}

long double Graph::getMinY() const {
    return minY;
}

long double Graph::getMaxY() const {
    return maxY;
}

/**
 * Initializes single-source shortest path data (path, dist).
 * Receives the content of the source vertex and returns a pointer to the source vertex.
 * Used by all single-source shortest path algorithms.
*/
Vertex *Graph::initSingleSource(const unsigned long &origin) {
    for (auto v : vertexSet) {
        v->dist = INF;
        v->path = nullptr;
    }
    auto s = findVertex(origin);
    s->dist = 0;
    return s;
}

/**
 * Analyzes an edge in single-source shortest path algorithm.
 * Returns true if the target vertex was relaxed (dist, path).
 * Used by all single-source shortest path algorithms.
*/
bool Graph::relax(Vertex *v, Vertex *w, long double weight) {
    if (v->dist + weight < w->dist) {
        w->dist = v->dist + weight;
        w->path = v->path;
        return true;
    } else
        return false;
}

///**
// * Analyzes an edge in single-source shortest path algorithm.
// * Returns true if the target vertex was relaxed (dist, path).
// * Used by all single-source shortest path algorithms.
//*/
//bool Graph::relax(Vertex *v, Vertex *w, long double weight) {
//    if (v->dist + weight < w->dist) {
//        w->dist = v->dist + weight;
//        w->path = v->path;
//        return true;
//    } else
//        return false;
//}

/**
 * Dijkstra algorithm.
*/
void Graph::dijkstraShortestPath(const int &origin) {
    auto s = initSingleSource(origin);
    MutablePriorityQueue<Vertex> q;
    q.insert(s);
    while (!q.empty()) {
        auto v = q.extractMin();
        for (auto e : v->adj) {
            auto oldDist = e->dest->dist;
            if (relax(v, e->dest, e->distance)) { if (oldDist == INF)q.insert(e->dest); else q.decreaseKey(e->dest); }
        }
    }
}

vector<int> Graph::getPath(const int &origin, const int &dest) const {
    vector<int> res;
    auto v = findVertex(dest);
    if (v == nullptr || v->dist == INF) // missing or disconnected
        return res;
    for (; v != nullptr; v = v->path->orig) //TODO: VERIFICAR ISTO -> "v->path->orig"  NO DO STOR TAVA "v->path"
        res.push_back(v->id);

    reverse(res.begin(), res.end());
    return res;
}

void Graph::unweightedShortestPath(const int &orig) {
    auto s = initSingleSource(orig);
    queue<Vertex *> q;
    q.push(s);
    while (!q.empty()) {
        auto v = q.front();
        q.pop();
        for (auto e: v->adj)
            if (relax(v, e->dest, 1))
                q.push(e->dest);
    }
}

void Graph::bellmanFordShortestPath(const int &orig) {
    initSingleSource(orig);
    for (unsigned i = 1; i < vertexSet.size(); i++)
        for (auto v: vertexSet)
            for (auto e: v->adj)
                relax(v, e->dest, e->distance);
    for (auto v: vertexSet)
        for (auto e: v->adj)
            if (relax(v, e->dest, e->distance))
                cout << "Negative cycle!" << endl;
}
