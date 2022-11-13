#pragma once
#include <string>
#include <vector>
#include <queue>
#include <string>
#include <utility>
#include <unordered_map>
#include "Airport.h"
#include "Edge.h"

class Graph {
    private:
    // 
        std::unordered_map<Airport, std::unordered_map<Airport, Edge>> adjacency_matrix;
        // std::vector<Airport> Airports;
        std::unordered_map<int, Airport> Airports;
        
        

    public:
        Graph();
        Graph(std::string& Airport_File, std::string& Route_File);
        void parseVertices(const std::string& filename);
        void parseEdges(const std::string& filename);
        void insertVertex(int ID, Airport airport);
        void insertEdge(int airportID1, int airportID2);
        // void createGraph();

        std::vector<Airport> findShortestPath();
};