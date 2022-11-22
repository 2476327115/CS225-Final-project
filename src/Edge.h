<<<<<<< HEAD
#include <Route.h>
#include <vector>
=======
#pragma once
#include "Route.h"
#include <vector>
#include <unordered_map>
>>>>>>> main


// to do
class Edge {
    public:
<<<<<<< HEAD


    
        
    private:
    std::vector<Route> Routes;
    int weights;
};

=======
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
    int srcID_;
    int dstID_;

};
>>>>>>> main
