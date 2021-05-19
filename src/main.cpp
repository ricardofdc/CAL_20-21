#include "UI/menu.h"
#include "Graph/load.h"

#ifndef WIN32
    #include <X11/Xlib.h>
#endif

static GraphViewer gv;

void load4x4GridGraph(){
    parseMap(&gv, "../resources/Mapas/GridGraphs/4x4/nodes.txt", "../resources/Mapas/GridGraphs/4x4/edges.txt");
}

void load8x8GridGraph(){
    parseMap(&gv, "../resources/Mapas/GridGraphs/8x8/nodes.txt", "../resources/Mapas/GridGraphs/8x8/edges.txt");
}

void load16x16GridGraph(){
    parseMap(&gv, "../resources/Mapas/GridGraphs/16x16/nodes.txt", "../resources/Mapas/GridGraphs/16x16/edges.txt");
}

void loadGridGraphsMenu(){
    drawMenu("Looking for parking spots - Load Map - Grid Graphs", {
            {"4x4", load4x4GridGraph},
            {"8x8", load8x8GridGraph},
            {"16x16", load16x16GridGraph}
    });
}

void loadPortugalAveiroGraph(){
    parseMap(&gv, "../resources/Mapas/PortugalMaps/Aveiro/nodes_x_y_aveiro.txt", "../resources/Mapas/PortugalMaps/Aveiro/edges_aveiro.txt");
}

void loadPortugalBragaGraph(){
    parseMap(&gv, "../resources/Mapas/PortugalMaps/Aveiro/nodes_x_y_braga.txt", "../resources/Mapas/PortugalMaps/Aveiro/edges_braga.txt");
}

void loadPortugalCoimbraGraph(){
    parseMap(&gv, "../resources/Mapas/PortugalMaps/Aveiro/nodes_x_y_coimbra.txt", "../resources/Mapas/PortugalMaps/Aveiro/edges_coimbra.txt");
}

void loadPortugalErmesindeGraph(){
    parseMap(&gv, "../resources/Mapas/PortugalMaps/Aveiro/nodes_x_y_ermesinde.txt", "../resources/Mapas/PortugalMaps/Aveiro/edges_ermesinde.txt");
}

void loadPortugalFafeGraph(){
    parseMap(&gv, "../resources/Mapas/PortugalMaps/Aveiro/nodes_x_y_fafe.txt", "../resources/Mapas/PortugalMaps/Aveiro/edges_fafe.txt");
}

void loadPortugalGondomarGraph(){
    parseMap(&gv, "../resources/Mapas/PortugalMaps/Aveiro/nodes_x_y_gondomar.txt", "../resources/Mapas/PortugalMaps/Aveiro/edges_gondomar.txt");
}

void loadPortugalLisboaGraph(){
    parseMap(&gv, "../resources/Mapas/PortugalMaps/Aveiro/nodes_x_y_lisboa.txt", "../resources/Mapas/PortugalMaps/Aveiro/edges_lisboa.txt");
}

void loadPortugalMaiaGraph(){
    parseMap(&gv, "../resources/Mapas/PortugalMaps/Aveiro/nodes_x_y_maia.txt", "../resources/Mapas/PortugalMaps/Aveiro/edges_maia.txt");
}

void loadPortugalPortoGraph(){
    parseMap(&gv, "../resources/Mapas/PortugalMaps/Aveiro/nodes_x_y_porto.txt", "../resources/Mapas/PortugalMaps/Aveiro/edges_porto.txt");
}

void loadPortugalPortugalGraph(){
    parseMap(&gv, "../resources/Mapas/PortugalMaps/Aveiro/nodes_x_y_portugal.txt", "../resources/Mapas/PortugalMaps/Aveiro/edges_portugal.txt");
}

void loadPortugalViseuGraph(){
    parseMap(&gv, "../resources/Mapas/PortugalMaps/Aveiro/nodes_x_y_viseu.txt", "../resources/Mapas/PortugalMaps/Aveiro/edges_viseu.txt");
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
    parseMap(&gv, "../resources/Mapas_Espinho/espinho_full_nodes_xy.txt", "../resources/Mapas_Espinho/espinho_full_edges.txt");
    gv.setBackground("../resources/Mapas_Espinho/espinho_full.png");
}

void loadEspinhoStrongGraph(){
    parseMap(&gv, "../resources/Mapas_Espinho/espinho_strong_nodes_xy.txt", "../resources/Mapas_Espinho/espinho_strong_edges.txt");
    gv.setBackground("../resources/Mapas_Espinho/espinho_strong_component.png");
}

void loadEspinhoMenu(){
    drawMenu("Looking for parking spots - Load Map - Espinho", {
            {"Full map", loadEspinhoFullGraph},
            {"Strong map", loadEspinhoStrongGraph}
    });
}

void loadPenafielFullGraph(){
    parseMap(&gv, "../resources/Mapas_Penafiel/penafiel_full_nodes_xy.txt", "../resources/Mapas_Penafiel/penafiel_full_edges.txt");
    gv.setBackground("../resources/Mapas_Penafiel/penafiel_full.png");
}

void loadPenafielStrongGraph(){
    parseMap(&gv, "../resources/Mapas_Penafiel/penafiel_strong_nodes_xy.txt", "../resources/Mapas_Penafiel/penafiel_strong_edges.txt");
    gv.setBackground("../resources/Mapas_Penafiel/penafiel_strong_component.png");
}

void loadPenafielMenu(){
    drawMenu("Looking for parking spots - Load Map - Penafiel", {
            {"Full map", loadPenafielFullGraph},
            {"Strong map", loadPenafielStrongGraph}
    });
}

void loadPortoFullGraph(){
    parseMap(&gv, "../resources/Mapas_Porto/porto_full_nodes_xy.txt", "../resources/Mapas_Porto/porto_full_edges.txt");
    gv.setBackground("../resources/Mapas_Porto/porto_full.png");
}

void loadPortoStrongGraph(){
    parseMap(&gv, "../resources/Mapas_Porto/porto_strong_nodes_xy.txt", "../resources/Mapas_Porto/porto_strong_edges.txt");
    gv.setBackground("../resources/Mapas_Porto/porto_strong_component.png");
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
    gv.setEnabledNodes(false);      // Disable node drawing
    gv.setEnabledEdgesText(false);  // Disable edge text drawing

    gv.setZipEdges(true);

    gv.createWindow(600,600);
    gv.join();
}

int main() {
    #ifndef WIN32
        XInitThreads();
    #endif

    gv.setCenter(sf::Vector2f(300, 300));

    drawMenu("Looking for parking spots - Load Map", {
            {"Load Map", loadMapMenu},
            {"Look for parking spot", startApp}
    });
    
    return 0;
}
