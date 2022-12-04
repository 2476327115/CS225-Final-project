#include "BFS.h"
#include "Graph.h"
#include <vector>
#include <unordered_map>
#include <queue>
#include <iostream>
#include <sstream>
#include <fstream>
#include <map>
using namespace std;
BFS::BFS(const Graph &graph)
{
    airport_graph_ = graph;
    number = airport_graph_.getAirportNum();
}

std::vector<int> BFS::traverseAll(const Graph &graph, int srcID)
{
    
    std::map<int, bool> visited; // create map to record visited vertices   
    vector<int> airports; // the return vector
    std::queue<int> BFS_queue; //create queue for BFS
    matrix_ = airport_graph_.getAdjacency_matrix(); // get unordered map adjacency_matrix of the graph 

    // Check whether the source airport is valid. If not, return the empty vector and warn that 
    // "Airport isn't found!!!" on the terminal
    if(matrix_.find(srcID) == matrix_.end()) {
        std::cout << "Airport isn't found!!!" << std::endl;
        return airports;
    }

    visited[srcID] = true; //mark index srcId as "visited", change false to true
    BFS_queue.push(srcID);//enqueue the srcID as start
    airport_graph_ = graph; // get graph
    
    
    while (!BFS_queue.empty())
    {
        srcID = BFS_queue.front(); //start from the front of the queue
        airports.push_back(srcID); // push the vertex into return vector
        BFS_queue.pop(); // Dequeue this vertex from queue

        for (auto it : matrix_[srcID]) // Get all the adjacent vertices of that dequeued vertex. 
        {
            if (visited.find(it.first) == visited.end())
            {
                visited[it.first] = true; //if there are adjacent vertices that haven't been visited, mark it as "visited"
                BFS_queue.push(it.first);//and enqueue it
            }
        }
    }
    std::cout << "the number of airports we traverse is " << airports.size() << std::endl;
    return airports; //return vector
}

 std::vector<int> BFS::traverse_with_dest(const Graph &graph, int srcID, int destID)
 {   
    

    std::map<int, bool> visited; // create map to record visited vertices   
    std::vector<int> airports; // the return vector
    std::queue<int> BFS_queue; //create queue for BFS
    matrix_ = airport_graph_.getAdjacency_matrix(); // get unordered map adjacency_matrix of the graph 
    
    // Check whether the source airport is valid. If not, return the empty vector and warn that 
    // "Airport isn't found!!!" on the terminal
    if(matrix_.find(srcID) == matrix_.end()) {
        std::cout << "Airport isn't found!!!" << std::endl;
        return airports;
    }

    visited[srcID] = true; //mark index srcId as "visited", change false to true
    BFS_queue.push(srcID);//enqueue the srcID as start
    airport_graph_ = graph; // get graph
    
    
        
    while (!BFS_queue.empty())
    {
        srcID = BFS_queue.front(); //start from the front of the queue
        airports.push_back(srcID); // push the vertex into return vector
        BFS_queue.pop(); // Dequeue this vertex from queue
        if (srcID == destID) // if the current srcID is equal to the destID, BFS stop and return vector
         {
            return airports;
        }

        for (auto it : matrix_[srcID]) // Get all the adjacent vertices of that dequeued vertex. 
        {
            if (visited.find(it.first) == visited.end())
            {
                visited[it.first] = true; //if there are adjacent vertices that haven't been visited, mark it as "visited"
                BFS_queue.push(it.first); //and enqueue it
            }
        }

        if(airports.back() != destID){
            std::cout << "the source and destination airport are not connected !! "<< std::endl;
        }
    }
    return airports; //return vector
 }
