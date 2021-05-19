#include "UI/menu.h"
#include "Graph/load.h"

#ifndef WIN32
    #include <X11/Xlib.h>
#endif

static Graph graph;
enum background {none, espinho_full, espinho_strong, penafiel_full, penafiel_strong, porto_full, porto_strong};
static background bg;

void load4x4GridGraph(){
    graph = parseMap("../resources/Mapas/GridGraphs/4x4/nodes.txt", "../resources/Mapas/GridGraphs/4x4/edges.txt");
    bg = none;
}

void load8x8GridGraph(){
    graph = parseMap("../resources/Mapas/GridGraphs/8x8/nodes.txt", "../resources/Mapas/GridGraphs/8x8/edges.txt");
    bg = none;
}

void load16x16GridGraph(){
    graph = parseMap("../resources/Mapas/GridGraphs/16x16/nodes.txt", "../resources/Mapas/GridGraphs/16x16/edges.txt");
    bg = none;
}

void loadGridGraphsMenu(){
    drawMenu("Looking for parking spots - Load Map - Grid Graphs", {
            {"4x4", load4x4GridGraph},
            {"8x8", load8x8GridGraph},
            {"16x16", load16x16GridGraph}
    });
}

void loadPortugalAveiroGraph(){
    graph = parseMap("../resources/Mapas/PortugalMaps/Aveiro/nodes_x_y_aveiro.txt", "../resources/Mapas/PortugalMaps/Aveiro/edges_aveiro.txt");
    bg = none;
}

void loadPortugalBragaGraph(){
    graph = parseMap("../resources/Mapas/PortugalMaps/Aveiro/nodes_x_y_braga.txt", "../resources/Mapas/PortugalMaps/Aveiro/edges_braga.txt");
    bg = none;
}

void loadPortugalCoimbraGraph(){
    graph = parseMap("../resources/Mapas/PortugalMaps/Aveiro/nodes_x_y_coimbra.txt", "../resources/Mapas/PortugalMaps/Aveiro/edges_coimbra.txt");
    bg = none;
}

void loadPortugalErmesindeGraph(){
    graph = parseMap("../resources/Mapas/PortugalMaps/Aveiro/nodes_x_y_ermesinde.txt", "../resources/Mapas/PortugalMaps/Aveiro/edges_ermesinde.txt");
    bg = none;
}

void loadPortugalFafeGraph(){
    graph = parseMap("../resources/Mapas/PortugalMaps/Aveiro/nodes_x_y_fafe.txt", "../resources/Mapas/PortugalMaps/Aveiro/edges_fafe.txt");
    bg = none;
}

void loadPortugalGondomarGraph(){
    graph = parseMap("../resources/Mapas/PortugalMaps/Aveiro/nodes_x_y_gondomar.txt", "../resources/Mapas/PortugalMaps/Aveiro/edges_gondomar.txt");
    bg = none;
}

void loadPortugalLisboaGraph(){
    graph = parseMap("../resources/Mapas/PortugalMaps/Aveiro/nodes_x_y_lisboa.txt", "../resources/Mapas/PortugalMaps/Aveiro/edges_lisboa.txt");
    bg = none;
}

void loadPortugalMaiaGraph(){
    graph = parseMap("../resources/Mapas/PortugalMaps/Aveiro/nodes_x_y_maia.txt", "../resources/Mapas/PortugalMaps/Aveiro/edges_maia.txt");
    bg = none;
}

void loadPortugalPortoGraph(){
    graph = parseMap("../resources/Mapas/PortugalMaps/Aveiro/nodes_x_y_porto.txt", "../resources/Mapas/PortugalMaps/Aveiro/edges_porto.txt");
    bg = none;
}

void loadPortugalPortugalGraph(){
    graph = parseMap("../resources/Mapas/PortugalMaps/Aveiro/nodes_x_y_portugal.txt", "../resources/Mapas/PortugalMaps/Aveiro/edges_portugal.txt");
    bg = none;
}

void loadPortugalViseuGraph(){
    graph = parseMap("../resources/Mapas/PortugalMaps/Aveiro/nodes_x_y_viseu.txt", "../resources/Mapas/PortugalMaps/Aveiro/edges_viseu.txt");
    bg = none;
}


void loadPortugalMapsMenu(){
    drawMenu("Looking for parking spots - Load Map - Portugal Maps", {
            {"Aveiro", loadPortugalAveiroGraph},
            {"Braga", loadPortugalBragaGraph},
            {"Coimbra", loadPortugalCoimbraGraph},
            {"Ermesinde", loadPortugalErmesindeGraph},
            {"Fafe", loadPortugalFafeGraph},
            {"Gondomar", loadPortugalGondomarGraph},
            {"Lisboa", loadPortugalLisboaGraph},
            {"Maia", loadPortugalMaiaGraph},
            {"Porto", loadPortugalPortoGraph},
            {"Portugal", loadPortugalPortugalGraph},
            {"Viseu", loadPortugalViseuGraph}
    });
}

void loadEspinhoFullGraph(){
    graph = parseMap("../resources/Mapas_Espinho/espinho_full_nodes_xy.txt", "../resources/Mapas_Espinho/espinho_full_edges.txt");
    bg = espinho_full;
}

void loadEspinhoStrongGraph(){
    graph = parseMap("../resources/Mapas_Espinho/espinho_strong_nodes_xy.txt", "../resources/Mapas_Espinho/espinho_strong_edges.txt");
    bg = espinho_strong;
}

void loadEspinhoMenu(){
    drawMenu("Looking for parking spots - Load Map - Espinho", {
            {"Full map", loadEspinhoFullGraph},
            {"Strong map", loadEspinhoStrongGraph}
    });
}

void loadPenafielFullGraph(){
    graph = parseMap("../resources/Mapas_Penafiel/penafiel_full_nodes_xy.txt", "../resources/Mapas_Penafiel/penafiel_full_edges.txt");
    bg = penafiel_full;
}

void loadPenafielStrongGraph(){
    graph = parseMap("../resources/Mapas_Penafiel/penafiel_strong_nodes_xy.txt", "../resources/Mapas_Penafiel/penafiel_strong_edges.txt");
    bg = penafiel_strong;
}

void loadPenafielMenu(){
    drawMenu("Looking for parking spots - Load Map - Penafiel", {
            {"Full map", loadPenafielFullGraph},
            {"Strong map", loadPenafielStrongGraph}
    });
}

void loadPortoFullGraph(){
    graph = parseMap("../resources/Mapas_Porto/porto_full_nodes_xy.txt", "../resources/Mapas_Porto/porto_full_edges.txt");
    bg = porto_full;
}

void loadPortoStrongGraph(){
    graph = parseMap("../resources/Mapas_Porto/porto_strong_nodes_xy.txt", "../resources/Mapas_Porto/porto_strong_edges.txt");
    bg = porto_strong;
}

void loadPortoMenu(){
    drawMenu("Looking for parking spots - Load Map - Porto", {
            {"Full map", loadPortoFullGraph},
            {"Strong map", loadPortoStrongGraph}
    });
}

void loadMapMenu(){
    drawMenu("Looking for parking spots - Load Map", {
            {"Grid Graphs", loadGridGraphsMenu},
            {"Portugal Maps", loadPortugalMapsMenu},
            {"Espinho", loadEspinhoMenu},
            {"Penafiel", loadPenafielMenu},
            {"Porto", loadPortoMenu}
    });
}

void startApp(){

    // export info from Graph to Graphviewer
    vector<Vertex *> vertexes = graph.getVertexSet();
    vector<Edge *> edges = graph.getEdgeSet();

    if(vertexes.empty()){
        cout << "Please load a map before continue!" << endl;
        return;
    }

    long double minX = graph.getMinX();
    long double minY = graph.getMinY();
    long double maxX = graph.getMaxX();
    long double maxY = graph.getMaxY();

    GraphViewer gv;
    gv.setScale(max(maxX-minX, maxY-minY)/800);
    gv.setCenter(sf::Vector2f((minY+maxY)/2, (minX+maxX)/2));

    for(Vertex *v : vertexes){
        gv.addNode(v->getId(), sf::Vector2f(v->getY(), v->getX()));
    }

    for(Edge *e : edges){
        gv.addEdge(e->getId(), gv.getNode(e->getOrig()->getId()), gv.getNode(e->getDest()->getId()),GraphViewer::Edge::DIRECTED );
    }
    /*
    switch (bg) {
        case none:
            gv.clearBackground();
            break;
        case espinho_full:
            gv.setBackground("../resources/Mapas_Espinho/espinho_full.png",sf::Vector2f(0, 800), sf::Vector2f(max(maxX-minX, maxY-minY)/800,max(maxX-minX, maxY-minY)/800));
            break;
        case espinho_strong:
            gv.setBackground("../resources/Mapas_Espinho/espinho_strong_component.png",sf::Vector2f(-3675, -2400), sf::Vector2f(8.9,8.9));
            break;
        case penafiel_full:
            gv.setBackground("../resources/Mapas_Penafiel/penafiel_full.png",sf::Vector2f((minX+maxX)/2, (minY+maxY)/2));
            break;
        case penafiel_strong:
            gv.setBackground("../resources/Mapas_Penafiel/penafiel_strong_component.png",sf::Vector2f((minX+maxX)/2, (minY+maxY)/2));
            break;
        case porto_full:
            gv.setBackground("../resources/Mapas_Porto/espinho_full.png",sf::Vector2f((minX+maxX)/2, (minY+maxY)/2));
            break;
        case porto_strong:
            gv.setBackground("../resources/Mapas_Porto/porto_strong_component.png",sf::Vector2f((minX+maxX)/2, (minY+maxY)));
            break;
    }
    */

    gv.setEnabledNodes(true);      // Disable node drawing
    gv.setEnabledEdgesText(true);  // Disable edge text drawing

    gv.setZipEdges(true);

    gv.createWindow(800,800);
    gv.join();
}

void AlgorithmSelMenu(){
    drawMenu("Select the algorithm you wish to apply", {
            {"Dijkstra", startApp},
            {"Connectivity", startApp},
    });
}

int main() {
    #ifndef WIN32
        XInitThreads();
    #endif

    drawMenu("Looking for parking spots - Load Map", {
            {"Load Map", loadMapMenu},
            {"Look for parking spot", AlgorithmSelMenu}
    });

    return 0;
}
