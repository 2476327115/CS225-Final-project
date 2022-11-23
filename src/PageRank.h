#pragma once
#include "Graph.h"
#include <iterator>
#include <iostream>
#include <string>
#include <unordered_map>
#include "Airport.h"
#include "Edge.h"
#include <queue>
#include <vector>
#include <map>

class PageRank{
    public:
        void get_matrix(const Graph & graph);
        //       idx, apID 
        std::map<int, int> index;
        int getOutDegree(int srcID);
        std::map<int, double> pageRank(const Graph & graph, int time, double damping_factor);
        Airport findImportantAP();


    private:
        Graph graph_;
        std::unordered_map<int, std::unordered_map<int, Edge>> adj_matrix_;
        std::unordered_map<int, Airport> airports; 
        std::vector<std::vector<int>> matrix;
        int number_ap;
        //      apID, rank
        std::map<int, double> rank_;
        
};

