#pragma once
#include "Route.h"
#include <vector>
#include <unordered_map>


// to do
class Edge {
    public:
    Edge();
    Edge(std::unordered_map<int, Route> Routes, int weights);
    int getWeights();
    void calculateWeights();
 
    private:
    std::unordered_map<int, Route> Routes_;
    int weights_;
};

