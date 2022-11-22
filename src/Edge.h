<<<<<<< HEAD
<<<<<<< HEAD
// to do
=======
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
    //               AirpID
    int weights_;
=======
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
>>>>>>> 6a070200aa616a24ec30e1c6ad5eb52944387adf
};
>>>>>>> jinfan
