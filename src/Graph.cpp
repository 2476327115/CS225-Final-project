#include "Graph.h"
#include <fstream>
#include <iterator>
#include <iostream>
#include <string>
#include <unordered_map>
#include "Airport.h"
#include <ctype.h>
#include "Edge.h"

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
    /* format
    507, "London Heathrow Airport", "London", "United Kingdom", "LHR", "EGLL", 51.4706, -0.461941, 83, 0, 
    "E", "Europe/London", "airport", "OurAirports"
    */
    if (Ap_File.is_open()) {
        std::string word;
        // int i = 1;
        while (getline(Ap_File, word)) {
            // std::cout << "times: " << i++ << std::endl;
            std::string ID;
            std::string Name;
            std::string City;
            std::string Country;
            std::string Latitude;
            std::string Longtitude;

            // count ,
            int count0 = 0;
            // count "
            int count1 = 0;
            for(int i = 0; i < (int) word.size(); i++){
                if(word.at(i) == '"') count1++;
                if(word.at(i) == ',' && count1 % 2 == 0) count0++;
                // ID
                if(count0 == 0){
                    ID.push_back(word.at(i));
                }
                // Name
                if(count0 == 1){
                    Name.push_back(word.at(i));
                }
                if(count0 == 2){
                    if(word.at(i) != '"' && word.at(i) != ',') City.push_back(word.at(i));
                }
                if(count0 == 3){
                    if(word.at(i) != '"' && word.at(i) != ',') Country.push_back(word.at(i));
                }
                if(count0 == 6){
                    if(word.at(i) != '"' && word.at(i) != ',') Latitude.push_back(word.at(i));
                }
                if(count0 == 7){
                    if(word.at(i) != '"' && word.at(i) != ',') Longtitude.push_back(word.at(i));
                }
                else continue;
            }
            
            
            Name = Name.substr(2, Name.size()-3);

            
            int Id = std::stoi(ID);
            double latitude = std::stod(Latitude);
            double longtitude = std::stod(Longtitude);
            
            Airport airport(Id, Name, City, Country, latitude, longtitude);
            insertVertex(Id, airport);
            ID.clear();
            Name.clear();
            City.clear();
            Latitude.clear();           
            Longtitude.clear();
        }
    }
    Ap_File.close();

}



void Graph::insertVertex(int ID, Airport airport){
    Airports[ID] = airport;   
}

void Graph::insertEdge(Route route, int srcID, int dstID){
    // if (adjacency_matrix.find(srcID) != adjacency_matrix.end() && adjacency_matrix[srcID].find(dstID) != adjacency_matrix[srcID].end()) {
        
    //     // if srcID and dstID found
    //     // 我没太看明白
    //     // 这里是不是应该加Edge里面的route和改weigh
    //     // 这个条件判断是不是和else里面的一样啊
    //     return;
    // }
    if (adjacency_matrix.find(srcID) == adjacency_matrix.end()) {
        // if srcID not found
        adjacency_matrix[srcID] = std::unordered_map<int, Edge>();
    }
    // adjacency_matrix[srcID][dstID] = Edge(route);
    if(adjacency_matrix[srcID].find(dstID) == adjacency_matrix[srcID].end()){
        // if srcID found, dstID not found
        adjacency_matrix[srcID][dstID] = Edge(route);
    } 
    else {
        adjacency_matrix[srcID][dstID].addRoute(route);
    }

}

int Graph::getAirportNum() {
    return (int) Airports.size();
}

const std::unordered_map<int, std::unordered_map<int, Edge>> Graph::getMatrix() {
   return adjacency_matrix;
}

const std::unordered_map<int, Airport> Graph::getAirports() {
   return Airports;
}

//std::unordered_map<int, std::unordered_map<int, Edge>> adjacency_matrix;

void Graph::printAirportInfo() {
    for (auto air : Airports) {
        std::cout << air.second.getID() << "\t" << air.second.getName() << std::endl;
    }
}


std::unordered_map<int, std::unordered_map<int, Edge>> Graph::getAdjacency_matrix() {
    return adjacency_matrix;
}

void Graph::parseEdges(const std::string& filename) { 
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
        int i = 0;
        while (getline(Route_File, word)) {
            std::cout << "times: " << i++ << std::endl;
            if(word.find("\\N") != std::string::npos) continue;
            std::vector<std::string> v = split(word, ",");

            std::string Airline = v[0];
            std::string AirlineID = v[1];
            std::string srcID = v[3];
            std::string dstID = v[5];
            std::string stop = v[7];

            std::cout << Airline << std::endl;
            std::cout << AirlineID << std::endl;
            std::cout << srcID << std::endl;
            std::cout << dstID << std::endl;
            std::cout << stop << std::endl;

            int AirlineId = std::stoi(AirlineID);
            int srcId = std::stoi(srcID);
            int dstId = std::stoi(dstID);
            int stop_int = std::stoi(stop);
            Route route(AirlineId, Airline, srcId, dstId, stop_int);
            insertEdge(route, srcId, dstId);
        }
    }
    Route_File.close();
}

std::vector<std::string> Graph::split(std::string str,std::string pattern)
{
  std::string::size_type position;
  std::vector<std::string> words;
  str += pattern;
  int size = str.size();
 
  for(int i = 0; i < size; i++){
    position = str.find(pattern,i);
    if((int) position < size){
      std::string s = str.substr(i, position - i);
      words.push_back(s);
      i = position + pattern.size()-1;
    }
  }
  return words;
}


