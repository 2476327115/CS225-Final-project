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
        mutable std::unordered_map<int, std::unordered_map<int, Edge>> adjacency_matrix;
        //                        sourseID                destID
        // std::vector<Airport> Airports;
        mutable std::unordered_map<int, Airport> Airports;
        

    public:
        Graph();
        Graph(std::string& Airport_File, std::string& Route_File);
        void parseVertices(const std::string& filename);
        void parseEdges(const std::string& filename);
        void insertVertex(int ID, Airport airport);
        void insertEdge(Route route, int srcID, int dstID);
        std::unordered_map<int, std::unordered_map<int, Edge>> getMatrix();
        std::unordered_map<int, Airport> getAirports();
        // void createGraph();
        
    };