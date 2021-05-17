//
// Created by ricar on 12/05/2021.
//

#include "load.h"



Graph<int> parseMap(string nodesPath, string edgesPath){
    Graph<int> g = Graph<int>();
    GraphViewer gv;

    ifstream nodesFile(nodesPath);
    ifstream edgesFile(edgesPath);

    if(!nodesFile.is_open()){
        throw GraphLoadFailed(nodesPath);
    }
    if(!edgesFile.is_open()){
        throw GraphLoadFailed(edgesFile);
    }

    int n;
    nodesFile >> n;

    string currLine = "";

    int id;
    int x;
    int y;

    for (int i=0; i<n; i++){
        getline(nodesFile, currLine);
        nodesFile >> id;
        nodesFile >> x;
        nodesFile >> y;

        gv.addNode(id, sf::Vector2f(x, y));
        g.addVertex(i);


    }
}

