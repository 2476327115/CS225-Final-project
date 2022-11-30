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
// #include <pair>

class PageRank{
    public:
        PageRank() {};
        // void get_matrix(const Graph & graph);
        //       idx, apID 
        std::unordered_map<int, int> index;
        int getOutDegree(int srcID);

        std::unordered_map<int, double> pageRank(const Graph & graph, int time, double damping_factor);
        Airport findImportantAP();
        std::vector<int> getRank_AP();
        // static bool compare(std::pair<int, double> &a, std::pair<int, double> &b);
        struct compare {
            bool operator() (const std::pair<int, double> &a, const std::pair<int, double> &b) const {
                return a.second > b.second;
            }
        } cmp;

       


    private:
        
        Graph graph_;
        std::unordered_map<int, std::unordered_map<int, Edge>> adj_matrix_;
        std::unordered_map<int, Airport> airports; 
        std::vector<std::vector<int>> matrix;
        int number_ap;
        //      apID, rank
        std::unordered_map<int, double> rank_;
        // bool compare(std::pair<>)
        
};

