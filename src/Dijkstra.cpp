#include <fstream>
#include <iterator>
#include <iostream>
#include <string>
#include <set>
#include <unordered_map>
#include "Dijkstra.h"
#include <utility>
typedef std::pair<int,double> PAP; //pair path
Dijkstra::Dijkstra (Graph graph, int srcID, int dstID){
    insertAdjacencymatrix(graph);
    insertAirports(graph);
    g_=graph;
    srcID_=srcID;
    dstID_=dstID; 
}

void Dijkstra::insertAdjacencymatrix(Graph graph){
    this->adjac_matrix=graph.getMatrix(); 
}
void Dijkstra::insertAirports(Graph graph){
    this->Airports_=graph.getAirports();
}

void Dijkstra::insertWeightmatrix(){
    //mutable std::unordered_map<int, std::unordered_map<int, Edge>> adjacency_matrix;
    //mutable std::unordered_map<int, std::unordered_map<int, double>> weight_matrix;
    //mutable std::unordered_map<int, Airport> Airports;
    std::unordered_map<int, Airport>::iterator itr1;
    for(itr1 = Airports_.begin();itr1!=Airports_.end();++itr1){
        int srcid=itr1->first;
        std::unordered_map<int, Edge> tempdest=adjac_matrix[srcid];
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
    std::queue<PAP> priorityQ;
    for(itr = Airports_.begin();itr!=Airports_.end();++itr){
        int tempid=itr->first;
        sptSet[tempid]=false;
        dist[tempid]=std::to_string(srcID)+' ';
        distweight[tempid]=2.0;
    }
    distweight[srcID]=0.0;
    priorityQ.push(PAP(srcID,0.0));
    while (!priorityQ.empty())
    {
        while(!priorityQ.empty()&&sptSet[priorityQ.front().first]==true) priorityQ.pop();
        PAP temppair=priorityQ.front();
        priorityQ.pop();
        int tmepid=temppair.first;
        double tempvalue=distweight[tmepid];
        sptSet[tmepid]=true;
        std::unordered_map<int, double> adjmap=weight_matrix[tmepid];
        std::unordered_map<int, double>::iterator itr1;
        for(itr1=adjmap.begin();itr1!=adjmap.end();++itr1){
            double tempminvalue=weight_matrix[tmepid][itr->first];
            double minvalue=1/(1/tempminvalue+1/tempvalue);
            int i=0;//check change or new push
            if(tempminvalue>minvalue){
                distweight[itr1->first]=minvalue;
                dist[itr1->first]=dist[tmepid]+std::to_string(itr1->first)+' ';
                priorityQ.push(PAP(itr1->first,minvalue));
            }
        }
    }
    return dist;
}

std::string Dijkstra::getshortpath(Graph graph, int srcID, int dstID){
    insertAdjacencymatrix(graph);
    insertAirports(graph);
    g_=graph;
    srcID_=srcID;
    dstID_=dstID; 
    std::unordered_map<int,std::string> result=dijkstra(srcID);
    std::string path=result[dstID];
    return path;
    ///  
}