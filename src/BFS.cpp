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
BFS::BFS(const Graph & graph){
    airport_graph_ = graph;
    number = airport_graph_.getAirportNum();   
}

std::vector<int> BFS::traverseAll(const Graph & graph, int srcID){
    std::map<int, bool> visited;

    vector<int> airports;

    std::queue<int> BFS_queue;
    visited[srcID] = true;
    BFS_queue.push(srcID);
    airport_graph_ = graph;
    matrix_ = airport_graph_.getAdjacency_matrix();
 
    while(!BFS_queue.empty())
    {
        srcID = BFS_queue.front();
        if(matrix_.count(srcID) <= 0){
            break; 
        }
        airports.push_back(srcID);
        BFS_queue.pop();
        for (auto it: matrix_[srcID]){
            if (visited.find(it.first) == visited.end() ){
                visited[it.first] = true;
                BFS_queue.push(it.first);
            }
            // std::cout << 1 << std::endl;
        }

        // for (auto it: matrix_[srcID]){
        //     if (!visited[it.first]){
        //         visited[it.first] = true;
        //         BFS_queue.push(it.first);
        //     }
        //     std::cout << 1 << std::endl;
        // }
    }
    return airports;
}

std::vector<int> BFS::traverse_with_dest(const Graph & graph, int srcID, int destID){
    std::vector<bool> visited;
    visited.resize(number,false);
    vector<int> airports;

    visited[srcID] = true;
    std::queue<int> BFS_queue;
    BFS_queue.push(srcID);
    airport_graph_ = graph;
    matrix_ = airport_graph_.getAdjacency_matrix();
 
    //vector<int> go_back(number);

    while(!BFS_queue.empty())
    {
        srcID = BFS_queue.front();
        if(matrix_.count(srcID) <= 0){
            break; 
        }
        airports.push_back(srcID);
        int temp = srcID;
        if(srcID == destID){
           //airports.push_back(destID);
           break;
        }
        BFS_queue.pop();
        
        for (auto it: matrix_[srcID]){
            if (!visited[it.first]){
                visited[it.first] = true;
                
                BFS_queue.push(it.first);
                //go_back[it.first] = srcID;
                //airports.push_back(it.first);

            }
        }
    }

    return airports;
}


