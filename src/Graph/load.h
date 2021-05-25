#ifndef PROJETO_LOAD_H
#define PROJETO_LOAD_H


#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <ctgmath>
#include "graphviewer.h"
#include "../Utils/exceptions.h"
#include "Graph.h"

using namespace std;

Graph parseMap(string nodesPath, string edgesPath);

#endif //PROJETO_LOAD_H
