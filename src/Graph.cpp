#include "Graph.h"
#include <fstream>
#include <iterator>
#include <iostream>
#include <string>
#include <unordered_map>
#include "Airport.h"

Graph::Graph(std::string& Airport_File, std::string& Route_File){
    parseVertices(Airport_File);
    parseEdges(Route_File);
}


void Graph::parseVertices(const std::string& filename){
    std::ifstream Ap_File(filename);
    std::string ID;
    std::string Name;
    std::string City;
    std::string latitude;
    std::string longtitude;
    if (Ap_File.is_open()) {
        std::string word;
        while (getline(Ap_File, word)) {
            std::vector<char> data;
            for(int i = 0; i < (int) word.size(); i++){
                data.push_back(word[i]);
            }
            int count = 0;
            int flag = 0;
            for(count = 0; count < (int) data.size(); count++){
                if(count == 0){
                    while(data[count] != ','){   
                        ID.push_back(data[count]);  
                        count++;         
                    }
                    flag++;
                }
                if(data[count] == '"'){
                    flag++;
                    count++;
                    if(flag == 2){
                        while(data[count] != '"'){   
                            Name.push_back(data[count]);  
                            count++;         
                        }
                    }
                    if(flag == 3){
                        while(data[count] != '"'){   
                            City.push_back(data[count]);  
                            count++;         
                        }
                    }
                    if(flag == 7){
                        while(data[count] != '"'){   
                            latitude.push_back(data[count]);  
                            count++;         
                        }
                    }
                    if(flag == 8){
                        while(data[count] != '"'){   
                            longtitude.push_back(data[count]);  
                            count++;         
                        }
                    }
                }
            }
            int Id = std::stoi(ID);
            Airport airport(Id, Name, City, latitude, longtitude);
            // Airports.push_back(airport);
            insertVertex(Id, airport);
        }
    }
    Ap_File.close();
}

void Graph::parseEdges(const std::string& filename){
    std::ifstream Route_File(filename);
    std::string word;

    std::string Airline;
    std::string AirlineID;
    std::string srcID;
    std::string dstID;
    std::string stop;

    if (Route_File.is_open()) {
        /* Reads a line from `wordsFile` into `word` until the file ends. */
        // Route(int AirlineID, std::string Airline, int srcID, int dstID, int stop){
        // BA,1355,SIN,3316,LHR,507,,0,744 777
        while (getline(Route_File, word)) {
            for(int count = 0; count < (int) word.size(); count++){
                int flag = 0;
                if(word.find("\\N") == std::string::npos) break;
                if(count == 0){
                    while(word[count] != ','){   
                        Airline.push_back(word[count]);  
                        count++;         
                    }
                    flag++;
                    continue;
                }
                if(word[count] != ','){
                    if(flag == 1){
                        while(word[count] != ','){   
                            AirlineID.push_back(word[count]);  
                            count++;         
                        }
                        flag++;
                        continue;

                    }
                    if(flag == 3){
                        while(word[count] != ','){   
                            srcID.push_back(word[count]);  
                            count++;         
                        }
                        flag++;
                        continue;
                    }
                    if(flag == 5){
                        while(word[count] != ','){   
                            dstID.push_back(word[count]);  
                            count++;         
                        }
                        flag++;
                        continue;
                    }
                    if(flag == 6){
                        while(word[count] != ','){   
                            stop.push_back(word[count]);  
                            count++;         
                        }
                        break;
                    }
                    while(word[count] != ','){
                        count++;
                    }

                }
            
            }
            int AirlineId = std::stoi(AirlineID);
            int srcId = std::stoi(srcID);
            int dstId = std::stoi(dstID);
            int stop_int = std::stoi(stop);
            Route route(AirlineId, Airline, srcId, dstId, stop_int);
            insertEdge(route, srcId, dstId);
    
        }
        Route_File.close();
    }
}

void Graph::insertVertex(int ID, Airport airport){
    Airports[ID] = airport;
}

void Graph::insertEdge(Route route, int srcID, int dstID){

}

//std::unordered_map<int, std::unordered_map<int, Edge>> adjacency_matrix;



std::vector<Airport> Graph::findShortestPath(){


}

int minWeight(std::unordered_map<int,std::string> dist,std::unordered_map<int,bool> sptSet){

}

std::unordered_map<int,std::string> Graph::dijkstra(int srcID){
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

