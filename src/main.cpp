#include "UI/menu.h"
#include "Graph/load.h"

#ifndef WIN32

#include <X11/Xlib.h>

#endif

static Graph graph;
GraphViewer * gv = new GraphViewer();

void load4x4GridGraph() {
    graph = parseMap("../resources/Mapas/GridGraphs/4x4/nodes.txt", "../resources/Mapas/GridGraphs/4x4/edges.txt");
}

void load8x8GridGraph() {
    graph = parseMap("../resources/Mapas/GridGraphs/8x8/nodes.txt", "../resources/Mapas/GridGraphs/8x8/edges.txt");
}

void load16x16GridGraph() {
    graph = parseMap("../resources/Mapas/GridGraphs/16x16/nodes.txt", "../resources/Mapas/GridGraphs/16x16/edges.txt");
}

void loadGridGraphsMenu() {
    drawMenu("Looking for parking spots - Load Map - Grid Graphs", {
            {"4x4",   load4x4GridGraph},
            {"8x8",   load8x8GridGraph},
            {"16x16", load16x16GridGraph}
    });
}

void loadPortugalAveiroGraph() {
    graph = parseMap("../resources/Mapas/PortugalMaps/Aveiro/nodes_x_y_aveiro.txt",
                     "../resources/Mapas/PortugalMaps/Aveiro/edges_aveiro.txt");
}

void loadPortugalBragaGraph() {
    graph = parseMap("../resources/Mapas/PortugalMaps/Aveiro/nodes_x_y_braga.txt",
                     "../resources/Mapas/PortugalMaps/Aveiro/edges_braga.txt");
}

void loadPortugalCoimbraGraph() {
    graph = parseMap("../resources/Mapas/PortugalMaps/Aveiro/nodes_x_y_coimbra.txt",
                     "../resources/Mapas/PortugalMaps/Aveiro/edges_coimbra.txt");
}

void loadPortugalErmesindeGraph() {
    graph = parseMap("../resources/Mapas/PortugalMaps/Aveiro/nodes_x_y_ermesinde.txt",
                     "../resources/Mapas/PortugalMaps/Aveiro/edges_ermesinde.txt");
}

void loadPortugalFafeGraph() {
    graph = parseMap("../resources/Mapas/PortugalMaps/Aveiro/nodes_x_y_fafe.txt",
                     "../resources/Mapas/PortugalMaps/Aveiro/edges_fafe.txt");
}

void loadPortugalGondomarGraph() {
    graph = parseMap("../resources/Mapas/PortugalMaps/Aveiro/nodes_x_y_gondomar.txt",
                     "../resources/Mapas/PortugalMaps/Aveiro/edges_gondomar.txt");
}

void loadPortugalLisboaGraph() {
    graph = parseMap("../resources/Mapas/PortugalMaps/Aveiro/nodes_x_y_lisboa.txt",
                     "../resources/Mapas/PortugalMaps/Aveiro/edges_lisboa.txt");
}

void loadPortugalMaiaGraph() {
    graph = parseMap("../resources/Mapas/PortugalMaps/Aveiro/nodes_x_y_maia.txt",
                     "../resources/Mapas/PortugalMaps/Aveiro/edges_maia.txt");
}

void loadPortugalPortoGraph() {
    graph = parseMap("../resources/Mapas/PortugalMaps/Aveiro/nodes_x_y_porto.txt",
                     "../resources/Mapas/PortugalMaps/Aveiro/edges_porto.txt");
}

void loadPortugalPortugalGraph() {
    graph = parseMap("../resources/Mapas/PortugalMaps/Aveiro/nodes_x_y_portugal.txt",
                     "../resources/Mapas/PortugalMaps/Aveiro/edges_portugal.txt");
}

void loadPortugalViseuGraph() {
    graph = parseMap("../resources/Mapas/PortugalMaps/Aveiro/nodes_x_y_viseu.txt",
                     "../resources/Mapas/PortugalMaps/Aveiro/edges_viseu.txt");
}


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

void loadEspinhoFullGraph() {
    graph = parseMap("../resources/Mapas_Espinho/espinho_full_nodes_xy.txt",
                     "../resources/Mapas_Espinho/espinho_full_edges.txt");
}

void loadEspinhoStrongGraph() {
    graph = parseMap("../resources/Mapas_Espinho/espinho_strong_nodes_xy.txt",
                     "../resources/Mapas_Espinho/espinho_strong_edges.txt");
}

void loadEspinhoMenu() {
    drawMenu("Looking for parking spots - Load Map - Espinho", {
            {"Full map",   loadEspinhoFullGraph},
            {"Strong map", loadEspinhoStrongGraph}
    });
}

void loadPenafielFullGraph() {
    graph = parseMap("../resources/Mapas_Penafiel/penafiel_full_nodes_xy.txt",
                     "../resources/Mapas_Penafiel/penafiel_full_edges.txt");
}

void loadPenafielStrongGraph() {
    graph = parseMap("../resources/Mapas_Penafiel/penafiel_strong_nodes_xy.txt",
                     "../resources/Mapas_Penafiel/penafiel_strong_edges.txt");
}

void loadPenafielMenu() {
    drawMenu("Looking for parking spots - Load Map - Penafiel", {
            {"Full map",   loadPenafielFullGraph},
            {"Strong map", loadPenafielStrongGraph}
    });
}

void loadPortoFullGraph() {
    graph = parseMap("../resources/Mapas_Porto/porto_full_nodes_xy.txt",
                     "../resources/Mapas_Porto/porto_full_edges.txt");
}

void loadPortoStrongGraph() {
    graph = parseMap("../resources/Mapas_Porto/porto_strong_nodes_xy.txt",
                     "../resources/Mapas_Porto/porto_strong_edges.txt");
}

void loadPortoMenu() {
    drawMenu("Looking for parking spots - Load Map - Porto", {
            {"Full map",   loadPortoFullGraph},
            {"Strong map", loadPortoStrongGraph}
    });
}

void loadCustomMap() {
    graph = parseMap("../resources/Custom_Map/nodes.txt",
                     "../resources/Custom_Map/edges.txt");
}

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

vector<unsigned long> getShortestPath() {
    int origin, destination;
    vector<unsigned long> path;

    cout << "Please enter origin" << endl;
    cin >> origin;
    cout << "Please enter destination" << endl;
    cin >> destination;
    graph.dijkstraShortestPath(origin);
    path = graph.getPath(origin, destination);
    while (path.empty()){
        cout << "Origin and destination are not connected!" << endl << endl;
        cout << "Please enter origin" << endl;
        cin >> origin;
        cout << "Please enter destination" << endl;
        cin >> destination;
        graph.dijkstraShortestPath(origin);
        path = graph.getPath(origin, destination);
    }
    return path;
}

void dijkstra() {
    vector<unsigned long> path = getShortestPath();

    unsigned long previous_id = INF;

    gv->setEnabledNodes(false);
    gv->setEnabledEdgesText(false);
    gv->setZipEdges(false);
    gv->lock();

    // clear graphviewer colors
    for(GraphViewer::Node * node : gv->getNodes()){
        node->setSize(5);
        node->setColor(sf::Color::Black);
    }
    for(GraphViewer::Edge *edge : gv->getEdges()) {
        edge->setThickness(1);
        edge->setColor(sf::Color::Black);
    }

    // change color of result
    for (const unsigned long &id : path){
        cout << "Node: " << id << endl;
        GraphViewer::Node &node = gv->getNode(id);
        node.setColor(sf::Color::Red);
        node.setSize(10);
        if(previous_id != INF) {
            Edge *e = graph.getEdgeFromTo(previous_id, id);
            GraphViewer::Edge &edge = gv->getEdge(e->getId());
            edge.setColor(sf::Color::Red);
            edge.setThickness(3);
        }
        previous_id = id;
    }

    // make start and finnish nodes more noticeable
    GraphViewer::Node &start_node = gv->getNode(path[0]);
    GraphViewer::Node &final_node = gv->getNode(path[path.size()-1]);
    start_node.setColor(sf::Color::Blue);
    start_node.setSize(25);
    final_node.setColor(sf::Color::Green);
    final_node.setSize(25);

    gv->unlock();
    gv->setEnabledNodes(true);
    gv->setEnabledEdgesText(true);
    gv->setZipEdges(true);

}

void connectivity(){
    if (graph.isConnected())
        cout << "true" << endl;
    else
        cout << "false" << endl;
}

void algorithmSelMenu() {
    drawMenu("Select the algorithm you wish to apply", {
            {"Dijkstra",     dijkstra},
            {"Connectivity", connectivity},
    });
}

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
        GraphViewer::Node& node = gv->addNode(v->getId(), sf::Vector2f(v->getY(), minX + maxX - v->getX()));
        node.setSize(5);
        node.setColor(sf::Color::Black);
    }


    for (Edge *e : edges) {
        GraphViewer::Edge& edge = gv->addEdge(e->getId(), gv->getNode(e->getOrig()->getId()), gv->getNode(e->getDest()->getId()),
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

int main() {
#ifndef WIN32
    XInitThreads();
#endif

    drawMenu("Looking for parking spots - Load Map", {
            {"Load Map",              loadMapMenu},
            {"Look for parking spot", startApp}
    });

    return 0;
}
