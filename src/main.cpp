#include <fstream>
#include <string>
#include <sstream>
#include <stdio.h>


#include "UI/menu.h"
#include "Graph/Graph.h"
#include "Graph/load.h"

#ifndef WIN32
    #include <X11/Xlib.h>
#endif

static Graph<unsigned long> graph;
static GraphViewer gv;

void load4x4GridGraph(){

}

void load8x8GridGraph(){

}

void load16x16GridGraph(){

}

void loadGridGraphsMenu(){
    drawMenu("Looking for parking spots - Load Map - Grid Graphs", {
            {"4x4", load4x4GridGraph},
            {"8x8", load8x8GridGraph},
            {"16x16", load16x16GridGraph}
    });
}

void loadPortugalAveiroGraph(){

}

void loadPortugalBragaGraph(){

}

void loadPortugalCoimbraGraph(){

}

void loadPortugalErmesindeGraph(){

}

void loadPortugalFafeGraph(){

}

void loadPortugalGondomarGraph(){

}

void loadPortugalLisboaGraph(){

}

void loadPortugalMaiaGraph(){

}

void loadPortugalPortoGraph(){

}

void loadPortugalPortugalGraph(){

}

void loadPortugalViseuGraph(){

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

void loadEspinhoGraph(){
    graph = parseMap(&gv, "../resources/Mapas_Espinho/espinho_strong_nodes_xy.txt", "../resources/Mapas_Espinho/espinho_strong_edges.txt");
}

void loadPenafielGraph(){

}

void loadPortoGraph(){

}

void loadMapMenu(){
    drawMenu("Looking for parking spots - Load Map", {
            {"Grid Graphs", loadGridGraphsMenu},
            {"Portugal Maps", loadPortugalMapsMenu},
            {"Espinho", loadEspinhoGraph},
            {"Penafiel", loadPenafielGraph},
            {"Porto", loadPortoGraph}
    });
}

void startApp(){

}

int main() {
    #ifndef WIN32
        XInitThreads();
    #endif

    drawMenu("Looking for parking spots - Load Map", {
            {"Load Map", loadMapMenu},
            {"Look for parking spot", startApp}
    });
    
    return 0;
}
