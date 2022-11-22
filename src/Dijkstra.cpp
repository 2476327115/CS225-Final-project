#include <fstream>
#include <iterator>
#include <iostream>
#include <string>
#include <unordered_map>
#include "Dijkstra.h"
Dijkstra::Dijkstra (Graph graph, int srcID, int dstID){

}
void Dijkstra::insertAdjacencymatrix(){
    return ;
}
void Dijkstra::insertAirports(){
    return ;
}
void Dijkstra::insertWeightmatrix(){
    //mutable std::unordered_map<int, std::unordered_map<int, Edge>> adjacency_matrix;
    //mutable std::unordered_map<int, std::unordered_map<int, double>> weight_matrix;
    //mutable std::unordered_map<int, Airport> Airports;
    std::unordered_map<int, Airport>::iterator itr1;
    for(itr1 = Airports_.begin();itr1!=Airports_.end();++itr1){
        int srcid=itr1->first;
        std::unordered_map<int, Edge> tempdest=adjacency_matrix[srcid];
        std::unordered_map<int, Airport>::iterator itr2;
        std::unordered_map<int, double> insertedge;
        for(itr2 = Airports_.begin();itr2!=Airports_.end();++itr2){
            int desid=itr2->first;
            Edge tempedge=tempdest[desid];
            double weight=1/(tempedge.getWeights());
            insertedge[desid]=weight;
        }
        weight_matrix[srcid]=insertedge;
    }
}

int Dijkstra::minWeight(int srcID,std::unordered_map<int,bool> sptSet){
    double min=2.0;
    int minairid=0;
    std::unordered_map<int, Airport>::iterator itr;
    for(itr = Airports_.begin();itr!=Airports_.end();++itr){
        int airid=itr->first;
        if(sptSet[airid]==false&&weight_matrix[srcID][airid]<=min){
            min = weight_matrix[srcID][airid];
            minairid=airid;
        }
    }
    return minairid;
}

std::unordered_map<int,std::string> Dijkstra::dijkstra(int srcID){
    std::unordered_map<int,std::string> dist;
    std::unordered_map<int,double> distweight;
    std::unordered_map<int,bool> sptSet; 
    std::unordered_map<int, Airport>::iterator itr;
    for(itr = Airports_.begin();itr!=Airports_.end();++itr){
        sptSet[itr->first]=false;
        dist[itr->first]=std::to_string(srcID)+' ';
        distweight[itr->first]=2.0;
    }
    distweight[srcID]=0.0;
    for(int count=0;count<((int)Airports_.size())-1;count++){
        int minweightID = minWeight(srcID,sptSet);
        sptSet[minweightID]=true;
        std::unordered_map<int, Airport>::iterator itr1;
        for(itr1 = Airports_.begin();itr1!=Airports_.end();++itr1){
            int airid=itr1->first;
            double temp=1/(1/(distweight[minweightID])+1/(weight_matrix[minweightID][airid]));
            if(!sptSet[airid]&&distweight[minweightID]!=2.0 && temp<distweight[airid]){
            distweight[airid]=temp;
            dist[airid]=dist[airid]+std::to_string(airid)+' ';
            }
        }
    }
    return dist;
}