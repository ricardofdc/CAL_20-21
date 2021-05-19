/*
 * Graph.h.
 * For implementation of the minimum cost flow algorithm.
 * See TODOs for code to add/adapt.
 * FEUP, CAL, 2017/18.
 */
#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>
#include <queue>
#include <limits>
#include <iostream>
#include <cmath>
#include "MutablePriorityQueue.h"

using namespace std;

constexpr auto INF = std::numeric_limits<double>::max();

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

	vector<Edge *> outgoing;
	vector<Edge *> incoming;

	bool visited;  // for path finding
	Edge *path; // for path finding
	double dist;   // for path finding
	int queueIndex = 0; // required by MutablePriorityQueue


	Vertex(unsigned long id);
	void addEdge(Edge *e);
	bool operator<(Vertex & vertex) const; // required by MutablePriorityQueue

public:
    unsigned long getId() const;
	vector<Edge *> getIncoming() const;
	vector<Edge *> getOutgoing() const;
	void setX(double x);
	void setY(double y);
	double getX() const;
	double getY() const;
	friend class Graph;
	friend class MutablePriorityQueue<Vertex>;
};


Vertex::Vertex(unsigned long id): id(id) {}

void Vertex::addEdge(Edge *e) {
	outgoing.push_back(e);
	e->dest->incoming.push_back(e);
}

bool Vertex::operator<(Vertex & vertex) const {
	return this->dist < vertex.dist;
}

unsigned long Vertex::getId() const {
	return this->id;
}

vector<Edge *>  Vertex::getIncoming() const {
	return this->incoming;
}

vector<Edge *>  Vertex::getOutgoing() const {
	return this->outgoing;
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

class Edge {
	Vertex * orig;
	Vertex * dest;
	double distance;

	Edge(Vertex *o, Vertex *d, double distance);

public:
	friend class Graph;
	friend class Vertex;
	double getDistance() const;
};

Edge::Edge(Vertex *o, Vertex *d, double distance):
	orig(o), dest(d), distance(distance){}

double Edge::getDistance() const {
	return this->distance;
}


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
	double distance = sqrt(pow((s->getX()+d->getX()),2) + pow((s->getY()+d->getY()),2));
	Edge *e = new Edge(s, d, distance);
	s->addEdge(e);
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




#endif /* GRAPH_H_ */
