#include "PageRank.h"
#include "Graph.h"
#include <iterator>
#include <iostream>
#include <string>
#include <unordered_map>
#include "Airport.h"
#include "Edge.h"
#include <queue>
#include <vector>
#include <map>

int PageRank::getOutDegree(int srcID){
    return (int) adj_matrix_[srcID].size();
}


std::map<int, double> PageRank::pageRank(const Graph & graph, int time, double damping_factor){
    graph_ = graph;
    adj_matrix_ = graph_.getMatrix();
    airports = graph_.getAirports();
    number_ap = graph_.getAirportNum();
    for(auto it : airports){
        rank_[it.first] = 1.0 / (double) number_ap;
    }
    double damping_value = (1.0 - damping_factor) / (double) number_ap;
    for(auto x : airports){
        for(int i = 0; i < number_ap; i++){
            bool rank = 0.0;
            for(auto y : adj_matrix_){
                // y.first srcID ; y.second destID Edge
                // x.first destID(we want) 
                if(y.second.find(x.first) != y.second.end()){
                    int deg = getOutDegree(y.first);
                    rank += damping_factor * rank_[y.first] / deg;
                }
                rank += damping_value;
                rank_[x.first] = rank;
            }
        }
    }
    return rank_;
}

Airport PageRank::findImportantAP(){
    int max = 0;
    int ap;
    for(auto it : rank_){
        if(it.second > max){
            max = it.second;
            ap = it.first;
        }
    }
    return airports[ap];
}


// void PageRank::get_matrix(const Graph & graph){
//     graph_ = graph;
//     adj_matrix_ = graph_.getMatrix();
//     number_ap = graph_.getAirportNum();
    


//     for(auto &it : adj_matrix_){
//         int deg = getOutDegree(it.first);
//         for(int i = 0; i < number_ap; i++){

//         }
//     }


// }
