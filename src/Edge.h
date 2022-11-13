#pragma once
#include "Route.h"
#include <vector>


// to do
class Edge {
    public:
    Edge();
    Edge(std::vector<Route> Routes, int weights);
    int getWeights();
    void calculateWeights();
 
    private:
    std::vector<Route> Routes_;
    int weights_;
};

