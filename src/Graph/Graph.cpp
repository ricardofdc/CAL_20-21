//
// Created by ricar on 19/05/2021.
//

#include "Graph.h"


/*
 * ================================================================================================
 * Class Vertex
 * ================================================================================================
 */

Vertex::Vertex(unsigned long id): id(id) {}

void Vertex::addEdge(Vertex *d) {
    adj.push_back(new Edge(this, d));
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

double Vertex::getX() const {
    return this->x;
}

void Vertex::setY(double y) {
    this->y = y;
}

double Vertex::getY() const {
    return this->y;
}

/* ================================================================================================
 * Class Edge
 * ================================================================================================
 */

Edge::Edge(Vertex *o, Vertex *d):
        orig(o), dest(d){
    this->distance = sqrt(pow((o->getX()+d->getX()),2) + pow((o->getY()+d->getY()),2));
}

double Edge::getDistance() const {
    return this->distance;
}


/* ================================================================================================
 * Class Graph
 * ================================================================================================
 */

Vertex * Graph::addVertex(const unsigned long &id) {
    Vertex *v = findVertex(id);
    if (v != nullptr)
        return v;
    v = new Vertex(id);
    vertexSet.push_back(v);
    return v;
}

Edge * Graph::addEdge(const unsigned long &sourc, const unsigned long &dest) {
    auto s = findVertex(sourc);
    auto d = findVertex(dest);
    if (s == nullptr || d == nullptr)
        return nullptr;
    Edge *e = new Edge(s, d);
    s->addEdge(d);
    return e;
}

Vertex* Graph::findVertex(const unsigned long &id) const {
    for (auto v : vertexSet)
        if (v->id == INF)
            return v;
    return nullptr;
}

vector<Vertex *> Graph::getVertexSet() const {
    return vertexSet;
}

