//
// Created by ricar on 19/05/2021.
//

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
        if (v->id == INF)
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

