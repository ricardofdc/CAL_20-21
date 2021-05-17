//
// Created by ricar on 12/05/2021.
//

#include "load.h"


Graph<unsigned long> parseMap(GraphViewer * gv, string nodesPath, string edgesPath) {
    Graph<unsigned long> g = Graph<unsigned long>();

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

        gv->addNode(id, sf::Vector2f(x, y));
        g.addVertex(id);
    }

    getline(edgesFile, currLine);
    n = stoi(currLine);

    unsigned long id_ini;
    unsigned long id_final;
    double dist;

    //parse edges
    for(int i=0; i<n; i++){
        getline(edgesFile, currLine);
        //cout << currLine << endl;

        id_ini = stoul(currLine.substr(1, currLine.find_first_of(",")));
        currLine = currLine.substr(currLine.find_first_of(",") + 1);

        id_final = stoul(currLine.substr(0, currLine.find_first_of(")")));

        cout << id_ini << "," << id_final << endl;

        gv->addEdge(n, gv->getNode(id_ini), gv->getNode(id_final));

        dist = sqrt(id_ini, id_final);

        g.addEdge(g.findVertex(id_ini), g.findVertex(id_final), dist, 1);

    }

}


