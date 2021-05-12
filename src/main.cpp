#include <fstream>
#include <string>
#include <sstream>
#include <stdio.h>

#include "graphviewer.h"
#include "UI/menu.h"
#include "Graph/Graph.h"
#include "Graph/load.h"

#ifndef WIN32
    #include <X11/Xlib.h>
#endif

static Graph<int> graph;

void loadGridGraphsMenu(){

}

void loadPortugalMapsMenu(){

}

void loadEspinhoGraph(){

}

void loadPenafielGraph(){

}

void loadPortoGraph(){

}

void loadMapMenu(){
    drawMenu("À procura de estacionamento - Load Map", {
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
