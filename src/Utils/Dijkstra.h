#ifndef CAL_20_21_DIJKSTRA_H
#define CAL_20_21_DIJKSTRA_H

template<class T> classGraph {

Vertex <T> *initSingleSource(constT &orig);

bool relax(Vertex <T> *v, Vertex <T> *w, doubleweight);

};

/**
 * Initializes single-source shortest path data (path, dist).
 * Receives the content of the source vertex and returns a pointer to the source vertex.
 * Used by all single-source shortest path algorithms.
*/
template<class T>
Vertex <T> *Graph<T>::initSingleSource(constT &origin) {
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
template<class T>
bool Graph<T>::relax(Vertex <T> *v, Vertex <T> *w, double weight) {
    if (v->dist + weight < w->dist) {
        w->dist = v->dist + weight;
        w->path = v;
        return true;
    } else
        return false;
}

/**
 * Dijkstra algorithm.
*/
template<classT>
void Graph<T>::dijkstraShortestPath(const T &origin) {
    auto s = initSingleSource(origin);
    MutablePriorityQueue <Vertex<T>> q;
    q.insert(s);
    while (!q.empty()) {
        auto v = q.extractMin();
        for (auto e : v->adj) {
            auto oldDist = e.dest->dist;
            if (relax(v, e.dest, e.weight)) { if (oldDist == INF)q.insert(e.dest); else q.decreaseKey(e.dest); }
        }
    }
}

template<class T>
vector <T> Graph<T>::getPath(const T &origin, const T &dest) const {
    vector <T> res;
    autov = findVertex(dest);
    if (v == nullptr || v->dist == INF) // missing or disconnected
        return res;
    for (; v != nullptr; v = v->path)res.push_back(v->info);
    reverse(res.begin(), res.end());
    return res;
}

template<classT>
voidGraph<T>::unweightedShortestPath(const T &orig) {
    auto s = initSingleSource(orig);
    queue < Vertex < T > * > q;
    q.push(s);
    while (!q.empty()) {
        autov = q.front();
        q.pop();
        for (auto e: v->adj)
            if (relax(v, e.dest, 1))
                q.push(e.dest);
    }
}

template<class T>
void Graph<T>::bellmanFordShortestPath(const T &orig) {
    initSingleSource(orig);
    for (unsigned i = 1; i < vertexSet.size(); i++)
        for (auto v: vertexSet)
            for (auto e: v->adj)
                relax(v, e.dest, e.weight);
    for (auto v: vertexSet)
        for (auto e: v->adj)
            if (relax(v, e.dest, e.weight))
                cout << "Negative cycle!" << endl;
}

#endif //CAL_20_21_DIJKSTRA_H
