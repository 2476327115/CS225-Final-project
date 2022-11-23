#include "BFS.h"
#include "Graph.h"
#include <vector>
#include <unordered_map>
#include <queue>
#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;
BFS::BFS(const Graph & graph){
    airport_graph_ = graph;
    number = airport_graph_.getAirportNum();   
}

std::vector<int> BFS::traverseAll(const Graph & graph, int srcID){
    visited.resize(number,false);
    vector<int> airports;

    visited[srcID] = true;
    BFS_queue.push(srcID);
    airport_graph_ = graph;
    matrix_ = airport_graph_.getAdjacency_matrix();
 
    while(BFS_queue.empty() != true)
    {
        // Dequeue a vertex from queue and print it
        srcID = BFS_queue.front();
        if(matrix_.count(srcID) <= 0){
            break; 
        }
        airports.push_back(srcID);
        BFS_queue.pop();

        // Get all adjacent vertices of the dequeued
        // vertex s. If a adjacent has not been visited,
        // then mark it visited and enqueue it
        for (auto it: matrix_[srcID]){
            if (!visited[it.first]){
                visited[it.first] = true;
                BFS_queue.push(it.first);
                airports.push_back(it.first);

            }
        }
    }
    return airports;
}

// std::vector<int> BFS::traverse_with_dest(const Graph & graph, int srcID, int destID){
    
// }


