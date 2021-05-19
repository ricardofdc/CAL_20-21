//
// Created by ricar on 12/05/2021.
//

#include "load.h"


Graph parseMap(string nodesPath, string edgesPath) {
    cout << endl << "Start map loading..." << endl;

    Graph g = Graph();

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
    long double x;
    long double y;

    // parse nodes
    for (int i = 0; i < n; i++) {
        getline(nodesFile, currLine);
        //cout << currLine << endl;

        id = stoul(currLine.substr(1, currLine.find_first_of(",")));
        currLine = currLine.substr(currLine.find_first_of(",") + 1);

        x = stold(currLine.substr(currLine.find_last_of(",") + 1));
        currLine = currLine.substr(0, currLine.find_last_of(","));

        y = stold(currLine.substr(0, currLine.find_first_of(")")));

        g.addVertex(id, x, y);
    }

    getline(edgesFile, currLine);
    n = stoi(currLine);

    unsigned long id_ini;
    unsigned long id_final;

    //parse edges
    for(unsigned long i=0; i<n; i++){
        getline(edgesFile, currLine);

        id_ini = stoul(currLine.substr(1, currLine.find_first_of(",")));
        currLine = currLine.substr(currLine.find_first_of(",") + 1);

        id_final = stoul(currLine.substr(0, currLine.find_first_of(")")));

        g.addEdge(i, id_ini, id_final);
    }

    cout << endl << "End map loading." << endl;
    return g;
}


