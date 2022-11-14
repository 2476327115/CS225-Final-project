#pragma once
#include <string>
#include <vector>
#include <queue>
#include <string>
#include <utility>
#include <unordered_map>
#include "Graph.h"
#include "Airport.h"
#include "Edge.h"

class Dijkstra {
    public:

    std::unordered_map<int,std::string> dijkstra(int srcID);
    int minWeight(std::unordered_map<int,std::string> dist,std::unordered_map<int,bool> sptSet);

    private:
    

}

