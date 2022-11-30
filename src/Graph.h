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
        std::unordered_map<int, std::unordered_map<int, Edge>> adjacency_matrix;
        //                        sourseID                destID
        // std::vector<Airport> Airports;
        std::unordered_map<int, Airport> Airports;
        std::vector<std::string> split(std::string str, std::string pattern);
        

    public:
        Graph() {};
        Graph(std::string& Airport_File, std::string& Route_File);
        void parseVertices(const std::string& filename);
        void parseEdges(const std::string& filename);
        void insertVertex(int ID, Airport airport);
        void insertEdge(Route route, int srcID, int dstID);
        void printAirportInfo();
        int getAirportNum();
        const std::unordered_map<int, std::unordered_map<int, Edge>> getMatrix();
        const std::unordered_map<int, Airport> getAirports();
        // void createGraph();
<<<<<<< HEAD
=======

        std::string getAirportName(int id);
        int getAirportId(std::string name);
>>>>>>> main
        
        std::unordered_map<int, std::unordered_map<int, Edge>> getAdjacency_matrix();
        bool operator==(const Graph & other);
    };