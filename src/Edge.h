#pragma once
#include "Route.h"
#include <vector>
#include <unordered_map>


// to do
class Edge {
    public:
    Edge();
    Edge(Route Route);
    Edge(std::unordered_map<int, Route> Routes, int weights);
    void addRoute(Route Route);
    int getWeights();
    void calculateWeights();
 
    private:
    std::unordered_map<int, Route> Routes_;
    int weights_;
    int srcID_;
    int dstID_;
};

