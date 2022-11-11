#pragma once
#include <string>
#include <vector>
#include <queue>
#include <string>
#include <unordered_map>
#include <Airport.h>
#include <Route.h>

class Graph {
    private:
        

    public:
        Graph();
        void insertVertex(const std::string& filename);
        void insertEdges(const std::string& filename);
        void addVertex();
        void addEdge(int airportID1, int airportID2);
        std::vector<Airport> findShortestPath();
};