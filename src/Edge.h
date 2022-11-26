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
    std::unordered_map<int, Route> getRoutes();
    bool operator==(const Edge & other);

    private:
    std::unordered_map<int, Route> Routes_;
    //               AirpID
    int weights_;
    int srcID_;
    int dstID_;

};
