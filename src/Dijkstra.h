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
    Dijkstra (Graph graph, int srcID, int dstID);
    std::vector<Airport> findShortestPath();
    std::unordered_map<int,std::string> dijkstra(int srcID);
    int minWeight(int srcID,std::unordered_map<int,bool> sptSet);
    void insertWeightmatrix();
    void insertAdjacencymatrix();
    void insertAirports();

    private:

    mutable std::unordered_map<int, std::unordered_map<int, Edge>> adjacency_matrix;
    mutable std::unordered_map<int, std::unordered_map<int, double>> weight_matrix;
    mutable std::unordered_map<int, Airport> Airports_;
    int NumAirports;

};

