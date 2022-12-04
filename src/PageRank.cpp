#include "PageRank.h"
#include "Graph.h"
#include <iostream>
#include <string>
#include <unordered_map>
#include "Airport.h"
#include "Edge.h"
#include <queue>
#include <vector>
#include <algorithm>


int PageRank::getOutDegree(int srcID) {
    return (int) adj_matrix_[srcID].size();
}


std::unordered_map<int, double> PageRank::pageRank(const Graph & graph, int time, double damping_factor) {
    graph_ = graph;
    adj_matrix_ = graph_.getMatrix();
    airports = graph_.getAirports();
    number_ap = graph_.getAirportNum();
    for(auto it : airports){
        rank_[it.first] = 1.0 / (double) number_ap;
        // rank_[it.first] = 1.0;
    }
    // double damping_value = (1.0 - damping_factor) / (double) number_ap;
    // int n1 = 1;
    double damping_value = (1.0 - damping_factor);
    for(int i = 0; i < time; i++){
        // int n2 = 0;
        for(auto x : airports){
            double rank = 0.0;
            for(auto y : adj_matrix_){
                // y.first srcID ; y.second destID Edge
                // x.first destID(we want) 
                if(y.second.find(x.first) != y.second.end()) {

                    int deg = getOutDegree(y.first);
                    //          destID             srcID
                    // std::cout << x.first << " " << y.first << " " << deg << " " << std::endl;
                    rank += damping_factor * rank_[y.first] / (double) deg;
                    // std::cout << x.first << " " <<rank <<" ghjgh"<< std::endl;
                }
                

            rank += damping_value;
            rank_[x.first] = rank;
            }
            // std::cout << "finsh " << n1 << "   " << n2++ << " airport check" << std::endl;
        }
        // std::cout << "finsh " << n1++ << " iteration check" << std::endl;
    }
    return rank_;
}

Airport PageRank::findImportantAP() {
    int max = 0;
    int ap;
    for(auto it : rank_) {
        if(it.second > max){
            max = it.second;
            ap = it.first;
        }
    }
    return airports[ap];
}

std::vector<int> PageRank::getRank_AP() {
    std::vector<std::pair<int, double>> rank;
    std::vector<int> rankAP;
    for(auto &it : rank_){
        rank.push_back(it);
    }
    std::sort(rank.begin(), rank.end(), cmp);
    for(auto &it : rank){
        // std::cout << it.first << " " << it.second << std::endl;
        rankAP.push_back(it.first);
    }
    
    return rankAP;
}

