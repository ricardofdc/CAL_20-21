//
// Created by ricar on 12/05/2021.
//

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Graph.h"
#include "graphviewer.h"
#include "../Utils/exceptions.h"
#include <tgmath.h>

using namespace std;


#ifndef PROJETO_LOAD_H
#define PROJETO_LOAD_H

#endif //PROJETO_LOAD_H

Graph<unsigned long> parseMap(GraphViewer * gv, string nodesPath, string edgesPath);
