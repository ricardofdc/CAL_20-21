//
// Created by ricar on 12/05/2021.
//

#include "load.h"


Graph<unsigned long> parseMap(string nodesPath, string edgesPath) {
    Graph<unsigned long> g;

    ifstream nodesFile(nodesPath);
    ifstream edgesFile(edgesPath);

    if (!nodesFile.is_open()) {
        throw GraphLoadFailed(nodesPath);
    }
    if (!edgesFile.is_open()) {
        throw GraphLoadFailed(edgesPath);
    }

    int n;

    string currLine = "";
    getline(nodesFile, currLine);
    n = stoi(currLine);

    unsigned long id;
    double x;
    double y;

    // parse nodes
    for (int i = 0; i < n; i++) {
        getline(nodesFile, currLine);
        //cout << currLine << endl;

        id = stoul(currLine.substr(1, currLine.find_first_of(",")));
        currLine = currLine.substr(currLine.find_first_of(",") + 1);

        x = stod(currLine.substr(currLine.find_last_of(",") + 1));
        currLine = currLine.substr(0, currLine.find_last_of(","));

        y = stod(currLine.substr(0, currLine.find_first_of(")")));

        Vertex<unsigned long> *vertex = g.addVertex(id);
        vertex->setX(x);
        vertex->setY(y);
    }

    getline(edgesFile, currLine);
    n = stoi(currLine);

    unsigned long id_ini;
    unsigned long id_final;
    double dist;
    GraphViewer::Node * ini_node;
    GraphViewer::Node * final_node;

    //parse edges
    for(int i=0; i<n; i++){
        getline(edgesFile, currLine);
        //cout << currLine << endl;

        id_ini = stoul(currLine.substr(1, currLine.find_first_of(",")));
        currLine = currLine.substr(currLine.find_first_of(",") + 1);

        id_final = stoul(currLine.substr(0, currLine.find_first_of(")")));

        cout << id_ini << "," << id_final << endl;

        ini_node = & gv->getNode(id_ini);

        final_node = & gv->getNode(id_final);

        gv->addEdge(i, * ini_node, * final_node);
    }

    return g;
}


