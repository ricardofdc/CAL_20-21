//
// Created by ricar on 19/05/2021.
//

#include "Graph.h"


/*
 * ================================================================================================
 * Class Vertex
 * ================================================================================================
 */

/**
 * Vertex constructor.
 *
 * @param unsigned long id
 * @param long double x
 * @param long double y
 * @return Vertex
 */
Vertex::Vertex(unsigned long id, long double x, long double y) : id(id), x(x), y(y) {}

/**
 * Adds edge to vertex.
 *
 * @param Edge *e
 * @return void
 */
void Vertex::addEdge(Edge *e) {
    adj.push_back(e);
}

/**
 * Operator overload '<', compares distances.
 *
 * @param Vertex & vertex
 * @return bool
 */
bool Vertex::operator<(Vertex &vertex) const {
    return this->dist < vertex.dist;
}

/**
 * Returns vertex's id.
 *
 * @return unsigned long
 */
unsigned long Vertex::getId() const {
    return this->id;
}

/**
 * Returns vertex's adjacent edges.
 *
 * @return vector<Edge *>
 */
vector<Edge *> Vertex::getAdj() const {
    return this->adj;
}

/**
 * Sets vertex's X.
 *
 * @param double x
 * @return void
 */
void Vertex::setX(double x) {
    this->x = x;
}

/**
 * Gets vertex's X.
 *
 * @return long double
 */
long double Vertex::getX() const {
    return this->x;
}

/**
 * Sets vertex's Y.
 *
 * @param double y
 * @return void
 */
void Vertex::setY(double y) {
    this->y = y;
}

/**
 * Gets vertex's Y.
 *
 * @return long double
 */
long double Vertex::getY() const {
    return this->y;
}

/**
 * Returns true if this vertex is a car park and returns false otherwise.
 *
 * @return bool
 */
bool Vertex::CarPark() {
    return this->isCarPark;
}


/* ================================================================================================
 * Class Edge
 * ================================================================================================
 */

/**
 * Edge constructor.
 *
 * @param unsigned long id
 * @param Vertex *origin
 * @param Vertex *destination
 * @return Edge
 */
Edge::Edge(unsigned long id, Vertex *o, Vertex *d) :
        id(id), orig(o), dest(d) {
    this->distance = sqrt(pow((o->getX() + d->getX()), 2) + pow((o->getY() + d->getY()), 2));
}

/**
 * Gets edge's distance.
 *
 * @return long double
 */
long double Edge::getDistance() const {
    return this->distance;
}

/**
 * Gets edge's id.
 *
 * @return unsigned long
 */
unsigned long Edge::getId() const {
    return this->id;
}

/**
 * Gets edge's origin.
 *
 * @return Vertex *
 */
Vertex *Edge::getOrig() const {
    return this->orig;
}

/**
 * Gets edge's destination.
 *
 * @return Vertex *
 */
Vertex *Edge::getDest() const {
    return this->dest;
}


/* ================================================================================================
 * Class Graph
 * ================================================================================================
 */

/**
 * Adds new vertex to graph.
 * There is a 1 in 20 chance of this vertex being set as a car park.
 *
 * @param unsigned long id
 * @param long double x
 * @param long double y
 * @return Vertex *
 */
Vertex *Graph::addVertex(unsigned long id, long double x, long double y) {
    Vertex *v = findVertex(id);
    if (v != nullptr)
        return v;
    v = new Vertex(id, x, y);
    int random = rand() % 20;
    if (random == 0) {
        v->isCarPark = true;
        numCarPark++;
    }
    vertexSet.push_back(v);

    if (x < minX) minX = x;
    if (x > maxX) maxX = x;
    if (y < minY) minY = y;
    if (y > maxY) maxY = y;


    return v;
}

/**
 * Adds new edge to graph.
 *
 * @param unsigned long id
 * @param unsigned long source
 * @param unsigned long destination
 * @return Edge *
 */
Edge *Graph::addEdge(unsigned long id, unsigned long sourc, unsigned long dest) {
    auto s = findVertex(sourc);
    auto d = findVertex(dest);
    if (s == nullptr || d == nullptr)
        return nullptr;
    Edge *e = new Edge(id, s, d);
    s->addEdge(e);
    s->allAdj.push_back(e);
    d->allAdj.push_back(e);
    edgeSet.push_back(e);
    return e;
}

/**
 * Finds vertex on graph.
 *
 * @param unsigned long id
 * @return Vertex *
 */
Vertex *Graph::findVertex(unsigned long id) const {
    for (auto v : vertexSet)
        if (v->id == id)
            return v;
    return nullptr;
}

/**
 * Returns vertexSet.
 *
 * @return vector<Vertex *>
 */
vector<Vertex *> Graph::getVertexSet() const {
    return vertexSet;
}

/**
 * Returns edge from one vertex to another.
 *
 * @param const unsigned long &from
 * @param const unsigned long &to
 * @return Edge *
 */
Edge *Graph::getEdgeFromTo(const unsigned long &from, const unsigned long &to) const {
    for (auto e : edgeSet) {
        if (e->orig->id == from && e->dest->id == to)
            return e;
    }
    return nullptr;
}

/**
 * Returns edgeSet.
 *
 * @return vector<Edge *>
 */
vector<Edge *> Graph::getEdgeSet() const {
    return edgeSet;
}

/**
 * Returns minX.
 *
 * @return long double
 */
long double Graph::getMinX() const {
    return minX;
}

/**
 * Returns maxX.
 *
 * @return long double
 */
long double Graph::getMaxX() const {
    return maxX;
}

/**
 * Returns minY.
 *
 * @return long double
 */
long double Graph::getMinY() const {
    return minY;
}

/**
 * Returns maxY.
 *
 * @return long double
 */
long double Graph::getMaxY() const {
    return maxY;
}

/**
 * Returns number of car parks in graph.
 *
 * @return unsigned int
 */
unsigned int Graph::getNumCarPark() const {
    return numCarPark;
}

/**
 * Initializes single-source shortest path data (path, dist).
 * Receives the content of the source vertex and returns a pointer to the source vertex.
 * Used by all single-source shortest path algorithms.
 *
 * @param const unsigned long &origin
 * @return Vertex *
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
 *
 * @param Vertex *v
 * @param long double distance
 * @return bool
*/
bool Graph::relax(Vertex *v, Vertex *w, long double distance) {
    if (v->dist + distance < w->dist) {
        w->dist = v->dist + distance;
        w->path = v;
        return true;
    } else
        return false;
}

/**
 * Dijkstra algorithm.
 *
 * @param const unsigned long &origin
 * @return void
 */
void Graph::dijkstraShortestPath(const unsigned long &origin) {
    Vertex *s = initSingleSource(origin);
    MutablePriorityQueue<Vertex> q;
    q.insert(s);
    while (!q.empty()) {
        Vertex *v = q.extractMin();
        for (Edge *e : v->adj) {
            auto oldDist = e->dest->dist;
            if (relax(v, e->dest, e->distance)) {
                if (oldDist == INF)
                    q.insert(e->dest);
                else
                    q.decreaseKey(e->dest);
            }
        }
    }
}

/**
 * Gets shortest path between origin and destination.
 *
 * @param const unsigned long &origin
 * @param const unsigned long &destination
 * @return vector<unsigned long>
 */
vector<unsigned long> Graph::getPath(const unsigned long &origin, const unsigned long &dest) const {
    vector<unsigned long> res;
    auto v = findVertex(dest);
    if (v == nullptr || v->dist == INF) // missing or disconnected
        return res;
    for (; v != nullptr; v = v->path) {
        res.push_back(v->id);
    }

    reverse(res.begin(), res.end());
    return res;
}

/**
 * Depth-first search algorithm.
 *
 * @param bool post_order
 * @return vector<vector<Vertex *>>
 */
vector<vector<Vertex *>> Graph::dfs(bool post_order) const {

    vector<vector<Vertex *>> res;

    for (auto v : vertexSet)
        v->visited = false;

    for (auto v : vertexSet) {
        if (!v->visited) {
            vector<Vertex *> vec;
            if (post_order) {
                dfsVisitPostOrder(v, vec);
            } else {
                dfsVisit(v, vec);
            }
            res.push_back(vec);
        }
    }

    return res;
}

/**
 * Sets vertex as visited.
 *
 * @param Vertex *v
 * @param vector<Vertex *> &vec
 * @return void
 */
void Graph::dfsVisit(Vertex *v, vector<Vertex *> &vec) const {
    v->visited = true;

    for (Edge *e : v->adj) {
        Vertex *w = e->dest;
        if (!w->visited) {
            dfsVisit(w, vec);
        }
    }
    vec.push_back(v);
}

/**
 * Sets vertex as visited.
 *
 * @param Vertex *v
 * @param vector<Vertex *> &vec
 * @return void
 */
void Graph::dfsVisitPostOrder(Vertex *v, vector<Vertex *> &vec) const {
    v->visited = true;

    if (v->adj.size() == 0) {
        vec.push_back(v);
    } else {
        for (Edge *e : v->adj) {
            vec.push_back(v);
            Vertex *w = e->dest;
            if (!w->visited) {
                dfsVisitPostOrder(w, vec);
            }
        }
    }
}

/**
 * Returns strongly connected components.
 *
 * @return vector<vector<Vertex *>>
 */
vector<vector<Vertex *>> Graph::stronglyConnectedComponents() {
    vector<vector<Vertex *>> g = dfs(false);

    Graph gr;

    for (vector<Vertex *> vertexes : g) {
        for (Vertex *v : vertexes) {
            gr.addVertex(v->id, v->x, v->y);
        }
    }

    for (Edge *e : edgeSet)
        gr.addEdge(e->getId(), e->getDest()->getId(), e->getOrig()->getId());

    reverse(gr.vertexSet.begin(), gr.vertexSet.end());

    for (Vertex *v : gr.vertexSet) {
        sort(v->adj.begin(), v->adj.end(), [gr](Edge *lhs, Edge *rhs) {
            int index1 = std::distance(gr.vertexSet.begin(), find(gr.vertexSet.begin(), gr.vertexSet.end(), lhs->dest));
            int index2 = std::distance(gr.vertexSet.begin(), find(gr.vertexSet.begin(), gr.vertexSet.end(), rhs->dest));
            return index1 < index2;
        });
    }

    return gr.dfs(true);
}

/**
 * Uses the breadth-first search algorithm to get the closest car park to the destination.
 *
 * @param Vertex *dest
 * @param vector<unsigned long> exclude
 * @return unsigned long
 */
unsigned long Graph::findClosestParkBFS(Vertex *dest, vector<unsigned long> exclude) {
    for (auto v : vertexSet) {
        v->visited = false;
    }
    queue<Vertex *> q;
    q.push(dest);
    dest->visited = true;
    while (!q.empty()) {
        Vertex *v = q.front();
        q.pop();
        if (v->isCarPark && !(find(exclude.begin(), exclude.end(), v->id) != exclude.end())) {
            return v->id;
        }
        for (Edge *e : v->allAdj) {
            Vertex *nextVertex = (e->orig->id == v->id) ? e->dest : e->orig;
            if (!nextVertex->visited) {
                q.push(nextVertex);
                nextVertex->visited = true;
            }
        }
    }
}

