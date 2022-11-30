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

class BFS{
public:
    BFS(const Graph & graph);
    // BFS(const Graph & graph, int airportID);
    std::vector<int> traverseAll(const Graph & graph, int srcID);
    std::vector<int> traverse_with_dest(const Graph & graph, int srcID, int destID);

private:
    //int start_;
    Graph airport_graph_;
    //std::queue<int> BFS_queue;
    //std::vector<bool> visited;
    int number;
    std::unordered_map<int, std::unordered_map<int, Edge>> matrix_;
};
