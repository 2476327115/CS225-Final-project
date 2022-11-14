#include <fstream>
#include <iterator>
#include <iostream>
#include <string>
#include <unordered_map>
#include "Dijkstra.h"

int Dijkstra::minWeight(std::unordered_map<int,std::string> dist,std::unordered_map<int,bool> sptSet){
    return 0;
}

std::unordered_map<int,std::string> Dijkstra::dijkstra(int srcID){
    std::unordered_map<int,std::string> dist;
    std::unordered_map<int,bool> sptSet; 
    std::unordered_map<int, Airport>::iterator itr;
    for(itr = Airports.begin();itr!=Airports.end();itr++){
        sptSet[itr->first]=false;
    }
    dist[srcID]=std::to_string(srcID);
    for(int count=0;count<Airports.size()-1;count++){
        int minweight = minWeight(dist,sptSet);
        
    }
}