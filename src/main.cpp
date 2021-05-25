#include "UI/menu.h"
#include "Graph/load.h"

#ifndef WIN32

#include <X11/Xlib.h>

#endif

static Graph graph;
GraphViewer *gv = new GraphViewer();
bool showIDs = false;

/**
 * Loads graph of 4x4 grid
 *
 * @return void
 */
void load4x4GridGraph() {
    graph = parseMap("../resources/Mapas/GridGraphs/4x4/nodes.txt", "../resources/Mapas/GridGraphs/4x4/edges.txt");
}

/**
 * Loads graph of 8x8 grid
 *
 * @return void
 */
 void load8x8GridGraph() {
    graph = parseMap("../resources/Mapas/GridGraphs/8x8/nodes.txt", "../resources/Mapas/GridGraphs/8x8/edges.txt");
}

/**
 * Loads graph of 16x16 grid
 *
 * @return void
 */
void load16x16GridGraph() {
    graph = parseMap("../resources/Mapas/GridGraphs/16x16/nodes.txt", "../resources/Mapas/GridGraphs/16x16/edges.txt");
}

/**
 * Shows grid's graph menu
 *
 * @return void
 */
void loadGridGraphsMenu() {
    drawMenu("Looking for parking spots - Load Map - Grid Graphs", {
            {"4x4",   load4x4GridGraph},
            {"8x8",   load8x8GridGraph},
            {"16x16", load16x16GridGraph}
    });
}

/**
 * Loads graph of Aveiro from Portugal
 *
 * @return void
 */
void loadPortugalAveiroGraph() {
    graph = parseMap("../resources/Mapas/PortugalMaps/Aveiro/nodes_x_y_aveiro.txt",
                     "../resources/Mapas/PortugalMaps/Aveiro/edges_aveiro.txt");
}

/**
 * Loads graph of Braga from Portugal
 *
 * @return void
 */
void loadPortugalBragaGraph() {
    graph = parseMap("../resources/Mapas/PortugalMaps/Braga/nodes_x_y_braga.txt",
                     "../resources/Mapas/PortugalMaps/Braga/edges_braga.txt");
}

/**
 * Loads graph of Coimbra from Portugal
 *
 * @return void
 */
void loadPortugalCoimbraGraph() {
    graph = parseMap("../resources/Mapas/PortugalMaps/Coimbra/nodes_x_y_coimbra.txt",
                     "../resources/Mapas/PortugalMaps/Coimbra/edges_coimbra.txt");
}

/**
 * Loads graph of Ermesinde from Portugal
 *
 * @return void
 */
void loadPortugalErmesindeGraph() {
    graph = parseMap("../resources/Mapas/PortugalMaps/Ermesinde/nodes_x_y_ermesinde.txt",
                     "../resources/Mapas/PortugalMaps/Ermesinde/edges_ermesinde.txt");
}

/**
 * Loads graph of Fafe from Portugal
 *
 * @return void
 */
void loadPortugalFafeGraph() {
    graph = parseMap("../resources/Mapas/PortugalMaps/Fafe/nodes_x_y_fafe.txt",
                     "../resources/Mapas/PortugalMaps/Fafe/edges_fafe.txt");
}

/**
 * Loads graph of Gondomar from Portugal
 *
 * @return void
 */
void loadPortugalGondomarGraph() {
    graph = parseMap("../resources/Mapas/PortugalMaps/Gondomar/nodes_x_y_gondomar.txt",
                     "../resources/Mapas/PortugalMaps/Gondomar/edges_gondomar.txt");
}

/**
 * Loads graph of Lisboa from Portugal
 *
 * @return void
 */
void loadPortugalLisboaGraph() {
    graph = parseMap("../resources/Mapas/PortugalMaps/Lisboa/nodes_x_y_lisboa.txt",
                     "../resources/Mapas/PortugalMaps/Lisboa/edges_lisboa.txt");
}

/**
 * Loads graph of Maia from Portugal
 *
 * @return void
 */
void loadPortugalMaiaGraph() {
    graph = parseMap("../resources/Mapas/PortugalMaps/Maia/nodes_x_y_maia.txt",
                     "../resources/Mapas/PortugalMaps/Maia/edges_maia.txt");
}

/**
 * Loads graph of Porto from Portugal
 *
 * @return void
 */
void loadPortugalPortoGraph() {
    graph = parseMap("../resources/Mapas/PortugalMaps/Porto/nodes_x_y_porto.txt",
                     "../resources/Mapas/PortugalMaps/Porto/edges_porto.txt");
}

/**
 * Loads graph of Portugal
 *
 * @return void
 */
void loadPortugalPortugalGraph() {
    graph = parseMap("../resources/Mapas/PortugalMaps/Portugal/nodes_x_y_portugal.txt",
                     "../resources/Mapas/PortugalMaps/Portugal/edges_portugal.txt");
}

/**
 * Loads graph of Viseu from Portugal
 *
 * @return void
 */
void loadPortugalViseuGraph() {
    graph = parseMap("../resources/Mapas/PortugalMaps/Viseu/nodes_x_y_viseu.txt",
                     "../resources/Mapas/PortugalMaps/Viseu/edges_viseu.txt");
}


/**
 * Shows menu of Portugal cities graphs
 *
 * @return void
 */
void loadPortugalMapsMenu() {
    drawMenu("Looking for parking spots - Load Map - Portugal Maps", {
            {"Aveiro",    loadPortugalAveiroGraph},
            {"Braga",     loadPortugalBragaGraph},
            {"Coimbra",   loadPortugalCoimbraGraph},
            {"Ermesinde", loadPortugalErmesindeGraph},
            {"Fafe",      loadPortugalFafeGraph},
            {"Gondomar",  loadPortugalGondomarGraph},
            {"Lisboa",    loadPortugalLisboaGraph},
            {"Maia",      loadPortugalMaiaGraph},
            {"Porto",     loadPortugalPortoGraph},
            {"Portugal",  loadPortugalPortugalGraph},
            {"Viseu",     loadPortugalViseuGraph}
    });
}

/**
 * Loads full graph of Espinho from Portugal
 *
 * @return void
*/
void loadEspinhoFullGraph() {
    graph = parseMap("../resources/Mapas_Espinho/espinho_full_nodes_xy.txt",
                     "../resources/Mapas_Espinho/espinho_full_edges.txt");
}

/**
 * Loads strong graph of Espinho from Portugal
 * @return void
 */
void loadEspinhoStrongGraph() {
    graph = parseMap("../resources/Mapas_Espinho/espinho_strong_nodes_xy.txt",
                     "../resources/Mapas_Espinho/espinho_strong_edges.txt");
}

/**
 * Shows graph's menu for Espinho from Portugal
 *
 * @return void
 */
void loadEspinhoMenu() {
    drawMenu("Looking for parking spots - Load Map - Espinho", {
            {"Full map",   loadEspinhoFullGraph},
            {"Strong map", loadEspinhoStrongGraph}
    });
}

/**
 * Loads full graph of Penafiel from Portugal
 *
 * @return void
 */
void loadPenafielFullGraph() {
    graph = parseMap("../resources/Mapas_Penafiel/penafiel_full_nodes_xy.txt",
                     "../resources/Mapas_Penafiel/penafiel_full_edges.txt");
}

/**
 * Loads strong graph of Penafiel from Portugal
 *
 * @return void
 */
void loadPenafielStrongGraph() {
    graph = parseMap("../resources/Mapas_Penafiel/penafiel_strong_nodes_xy.txt",
                     "../resources/Mapas_Penafiel/penafiel_strong_edges.txt");
}

/**
 * Shows graph's menu for Penafiel from Portugal
 *
 * @return void
 */
void loadPenafielMenu() {
    drawMenu("Looking for parking spots - Load Map - Penafiel", {
            {"Full map",   loadPenafielFullGraph},
            {"Strong map", loadPenafielStrongGraph}
    });
}

/**
 * Loads full graph of Porto from Portugal
 *
 * @return void
 */
void loadPortoFullGraph() {
    graph = parseMap("../resources/Mapas_Porto/porto_full_nodes_xy.txt",
                     "../resources/Mapas_Porto/porto_full_edges.txt");
}

/**
 * Loads strong graph of Porto from Portugal
 *
 * @return void
 */
void loadPortoStrongGraph() {
    graph = parseMap("../resources/Mapas_Porto/porto_strong_nodes_xy.txt",
                     "../resources/Mapas_Porto/porto_strong_edges.txt");
}

/**
 * Shows graph's menu for Porto from Portugal
 *
 * @return void
 */
void loadPortoMenu() {
    drawMenu("Looking for parking spots - Load Map - Porto", {
            {"Full map",   loadPortoFullGraph},
            {"Strong map", loadPortoStrongGraph}
    });
}

/**
 * Loads our custom map
 *
 *  * @return void
 */
void loadCustomMap() {
    graph = parseMap("../resources/Custom_Map/nodes.txt",
                     "../resources/Custom_Map/edges.txt");
}

/**
 * Shows all graph's menu
 *
 * @return void
 */
void loadMapMenu() {
    drawMenu("Looking for parking spots - Load Map", {
            {"Grid Graphs",   loadGridGraphsMenu},
            {"Portugal Maps", loadPortugalMapsMenu},
            {"Espinho",       loadEspinhoMenu},
            {"Penafiel",      loadPenafielMenu},
            {"Porto",         loadPortoMenu},
            {"Custom Map",    loadCustomMap}
    });
}

/**
 * Asks the user for the origin and destination nodes.
 * Then finds one of the nearest car parks to the destination using bfs algorithm.
 * Finally finds the best path between origin and the car park using Dijkstra.
 *
 * @param int & destination
 * @return vector<unsigned long>
 */
vector<unsigned long> getShortestPath(int & destination) {
    int origin;
    vector<unsigned long> path;

    cout << "Please enter origin" << endl;
    cin >> origin;
    cout << "Please enter destination" << endl;
    cin >> destination;

    if(graph.findVertex(origin) == nullptr){
        cout << "Invalid origin ID" << endl << endl;
        return path;
    }

    if(graph.findVertex(destination) == nullptr){
        cout << "Invalid destination ID" << endl << endl;
        return path;
    }

    graph.dijkstraShortestPath(origin);

    vector<unsigned long> exclude;

    // BFS to get nearest car park
    unsigned long carPark = graph.findClosestParkBFS(graph.findVertex(destination), exclude);

    path = graph.getPath(origin, carPark);
    while (path.empty()) {
        cout << endl << "Origin and car park [" << carPark << "] are not connected!" << endl << "Trying next car park." << endl;

        exclude.push_back(carPark);
        carPark = graph.findClosestParkBFS(graph.findVertex(destination), exclude);
        path = graph.getPath(origin, carPark);

        if(exclude.size() == graph.getNumCarPark()){
            cout << "Could not find any path between origin [" << origin << "] and destination [" << destination << "]." << endl;
            return path;
        }
    }
    return path;
}

/**
 * Calls getShortestPath and displays this information using graphviewer.
 *
 * @return void
 */
void dijkstra() {
    int destination;
    vector<unsigned long> path = getShortestPath(destination);
    if(path.empty()){
        return;
    }

    unsigned long previous_id = INF;

    gv->setEnabledNodes(false);
    gv->setEnabledEdgesText(false);
    gv->setZipEdges(false);
    gv->lock();

    // clear graphviewer colors
    for (GraphViewer::Node *node : gv->getNodes()){
        if (graph.findVertex(node->getId())->CarPark()) {
            node->setSize(15);
        } else {
            node->setSize(5);
        }
        node->setColor(sf::Color::Black);
    }
    for (GraphViewer::Edge *edge : gv->getEdges()) {
        edge->setThickness(1);
        edge->setColor(sf::Color::Black);
    }

    cout << "Path: ";

    // change color of result
    for (const unsigned long &id : path) {
        cout << id << " -> ";
        GraphViewer::Node &node = gv->getNode(id);
        node.setColor(sf::Color::Red);
        node.setSize(10);
        if (previous_id != INF) {
            Edge *e = graph.getEdgeFromTo(previous_id, id);
            GraphViewer::Edge &edge = gv->getEdge(e->getId());
            edge.setColor(sf::Color::Red);
            edge.setThickness(3);
        }
        previous_id = id;
    }

    // make start and finnish nodes more noticeable
    GraphViewer::Node &start_node = gv->getNode(path[0]);
    GraphViewer::Node &final_node = gv->getNode(destination);
    GraphViewer::Node &parking_node = gv->getNode(path[path.size() - 1]);
    start_node.setColor(sf::Color::Blue);
    start_node.setSize(25);
    final_node.setColor(sf::Color::Green);
    final_node.setSize(25);
    parking_node.setSize(25);



    gv->unlock();
    gv->setEnabledNodes(true);
    gv->setEnabledEdgesText(true);
    gv->setZipEdges(true);

}

/**
 * Calculates the connectivity of the current loaded map and shows this information using graphviewer.
 *
 * @return void
 */
void connectivity() {
    vector<vector<Vertex *>> components = graph.stronglyConnectedComponents();

    gv->setEnabledNodes(false);
    gv->setEnabledEdgesText(false);
    gv->setZipEdges(false);
    gv->lock();

    // clear graphviewer colors
    for (GraphViewer::Node *node : gv->getNodes()) {
        if (graph.findVertex(node->getId())->CarPark()) {
            node->setSize(15);
        } else {
            node->setSize(5);
        }
        node->setColor(sf::Color::Black);
    }
    for (GraphViewer::Edge *edge : gv->getEdges()) {
        edge->setThickness(2);
        edge->setColor(sf::Color(200,200,200));
    }

    sf::Color color = sf::Color(rand() % 255, rand() % 255, rand() % 255);
    // change color of result
    for (vector<Vertex *> vertexes : components) {
        cout << endl << "Component: ";

        unsigned long previous_id = INF;
        int i=0;
        for (Vertex *vertex : vertexes) {
            i++;
            if(i<25) {
                cout << vertex->getId() << " ; ";
            }
            else if(i==25){
                cout << vertex->getId() << " ... ";
            }
            GraphViewer::Node &node = gv->getNode(vertex->getId());
            node.setColor(color);
            if (previous_id != INF) {
                Edge *e = graph.getEdgeFromTo(vertex->getId(), previous_id);
                if(e) {
                    GraphViewer::Edge &edge = gv->getEdge(e->getId());
                    edge.setColor(color);
                }
            }
            previous_id = vertex->getId();
        }
        sf::Color prev_color = color;
        while (prev_color == color) {
            color = sf::Color(rand() % 255, rand() % 255, rand() % 255);
        }
    }

    cout << endl << endl << "Number of different strongly connected components: " << components.size() << endl;

    gv->unlock();
    gv->setEnabledNodes(true);
    gv->setEnabledEdgesText(true);
    gv->setZipEdges(true);
}


/**
 * Toggles the ids of graphviewer's nodes.
 *
 * @return void
 */
void toggleIDs(){
    gv->setEnabledNodes(false);
    gv->setEnabledEdgesText(false);
    gv->setZipEdges(false);
    gv->lock();

    showIDs = !showIDs;

    for (GraphViewer::Node *node : gv->getNodes()){
        if (graph.findVertex(node->getId())->CarPark()) {
            node->setSize(15);
        } else {
            node->setSize(5);
        }

        if(showIDs){
            node->setLabel(to_string(node->getId()));
            node->setLabelColor(sf::Color::Red);
        }
        else{
            node->setLabel("");
        }
    }

    gv->unlock();
    gv->setEnabledNodes(true);
    gv->setEnabledEdgesText(true);
    gv->setZipEdges(true);
}

/**
 * Shows the algorithm's menu
 *
 * @return void
 */
void algorithmSelMenu() {
    drawMenu("Select the algorithm you wish to apply", {
            {"Find Parking Spot (Dijkstra + BFS)", dijkstra},
            {"Test Graph Connectivity", connectivity},
            {"Toggle Nodes IDs", toggleIDs}
    });
}

/**
 * Shows current loaded map using graphviewer
 *
 * @return void
 */
void startApp() {

    // export info from Graph to Graphviewer
    vector<Vertex *> vertexes = graph.getVertexSet();
    vector<Edge *> edges = graph.getEdgeSet();

    if (vertexes.empty()) {
        cout << "Please load a map before continue!" << endl;
        return;
    }

    long double minX = graph.getMinX();
    long double minY = graph.getMinY();
    long double maxX = graph.getMaxX();
    long double maxY = graph.getMaxY();


    gv->setScale(max(maxX - minX, maxY - minY) / 800);
    gv->setCenter(sf::Vector2f((minY + maxY) / 2, (minX + maxX) / 2));

    for (Vertex *v : vertexes) {
        GraphViewer::Node &node = gv->addNode(v->getId(), sf::Vector2f(v->getY(), minX + maxX - v->getX()));
        node.setSize(5);
        if (v->CarPark()) {
            node.setIcon("../resources/parkSymbol.png");
            node.setSize(15);
        } else {
            node.setSize(5);
        }
        node.setColor(sf::Color::Black);
    }


    for (Edge *e : edges) {
        GraphViewer::Edge &edge = gv->addEdge(e->getId(), gv->getNode(e->getOrig()->getId()),
                                              gv->getNode(e->getDest()->getId()),
                                              GraphViewer::Edge::DIRECTED);
        edge.setThickness(1);
        edge.setColor(sf::Color::Black);
    }

    gv->setEnabledNodes(true);      // Disable node drawing
    gv->setEnabledEdgesText(true);  // Disable edge text drawing

    gv->setZipEdges(true);

    gv->createWindow(800, 800);

    algorithmSelMenu();

    gv->join();

    gv = new GraphViewer();
}

/**
 * Shows main menu.
 *
 * @return int
 */
int main() {
#ifndef WIN32
    XInitThreads();
#endif
    srand(time(nullptr));

    drawMenu("Looking for parking spots - Load Map", {
            {"Load Map", loadMapMenu},
            {"Start App", startApp}
    });

    return 0;
}
