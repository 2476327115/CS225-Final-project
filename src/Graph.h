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
        std::unordered_map<int, Airport> Airports;
        std::vector<std::string> split(std::string str, std::string pattern);
        

    public:
        //default constructor
        Graph() {};

        // constructor to create the graph and parse the data of airports and routes into it.
        // The graph has the airports as vertices and routes as edges. In this case, we consider the routes between 
        // the same source airport and destination airport as a single edge between vertices.
        // @param Airport_File - data file about airport information
        // @param Route_File - data file about route information
        Graph(std::string& Airport_File, std::string& Route_File);

        // parse the data of airport information into the graph
        // @param filename - data file for data parsing
        void parseVertices(const std::string& filename);

        // parse the data of route information into the graph
        // @param filename - data file for data parsing
        void parseEdges(const std::string& filename);

        // insert a new airport as vertex into the graph by adding it into the map of airport 
        // @param ID - data file for data parsing
        // @param airport - data file for data parsing
        void insertVertex(int ID, Airport airport);
        void insertEdge(Route route, int srcID, int dstID);
        void printAirportInfo();
        int getAirportNum();
        const std::unordered_map<int, std::unordered_map<int, Edge>> getMatrix();
        const std::unordered_map<int, Airport> getAirports();
        // void createGraph();

        std::string getAirportName(int id);
        int getAirportId(std::string name);
        
        std::unordered_map<int, std::unordered_map<int, Edge>> getAdjacency_matrix();
        bool operator==(const Graph & other);
    };