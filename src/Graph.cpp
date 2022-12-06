#include "Graph.h"
#include <fstream>
#include <iterator>
#include <iostream>
#include <string>
#include <unordered_map>
#include "Airport.h"
#include <ctype.h>
#include "Edge.h"

/**
 * constructor to create the graph and parse the data of airports and routes into it.
 * The graph has the airports as vertices and routes as edges. In this case, we consider
 * the routes between the same source airport and destination airport as a single edge
 * between vertices.
 * @param Airport_File - data file about airport information
 * @param Route_File - data file about route information
 **/
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
        while (getline(Ap_File, word)) {
            std::string ID;
            std::string Name;
            std::string City;
            std::string Country;
            std::string Latitude;
            std::string Longtitude;

            // to count ','
            int count0 = 0;
            // to count '"'
            int count1 = 0;
            for(int i = 0; i < (int) word.size(); i++){
                if(word.at(i) == '"') count1++;
                // count ',' outside the '"' to avoid counting ',' inside the name of the airport, country, or city
                if(word.at(i) == ',' && count1 % 2 == 0) count0++;
                // parse the information of ID
                if(count0 == 0){
                    ID.push_back(word.at(i));
                }
                // parse the information of Name
                if(count0 == 1){
                    Name.push_back(word.at(i));
                }
                // parse the information of city
                if(count0 == 2){
                    if(word.at(i) != '"' && word.at(i) != ',') City.push_back(word.at(i));
                }
                // parse the information of country
                if(count0 == 3){
                    if(word.at(i) != '"' && word.at(i) != ',') Country.push_back(word.at(i));
                }
                // parse the information of latitude
                if(count0 == 6){
                    if(word.at(i) != '"' && word.at(i) != ',') Latitude.push_back(word.at(i));
                }
                // parse the information of longtitude
                if(count0 == 7){
                    if(word.at(i) != '"' && word.at(i) != ',') Longtitude.push_back(word.at(i));
                }
                else continue;
            }
            
            // filter the comma and quotation marks before and after the name
            Name = Name.substr(2, Name.size()-3);

            // convert the string of ID to integer
            int Id = std::stoi(ID);
            // convert the string of latitude to double
            double latitude = std::stod(Latitude);
            // convert the string of longtitude to double
            double longtitude = std::stod(Longtitude);
            // create an object of the airport data we parse
            Airport airport(Id, Name, City, Country, latitude, longtitude);
            // insert the airport as a vertex;
            insertVertex(Id, airport);
            // clear the string 
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
    airports[ID] = airport;   
}


void Graph::insertEdge(Route route, int srcID, int dstID){
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

const std::unordered_map<int, Airport> Graph::getairports() {
   return airports;
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
    // the number of invalid routes
    int invalid = 0;
    if (Route_File.is_open()) {

        /* Reads a line from `wordsFile` into `word` until the file ends. */
        // Route(int AirlineID, std::string Airline, int srcID, int dstID, int stop){
        // BA,1355,SIN,3316,LHR,507,,0,744 777
        // int i = 0;
        while (getline(Route_File, word)) {
            
            // std::cout << "times: " << i++ << std::endl;
            std::vector<std::string> v = split(word, ",");
            if(v[3].find("\\N") != std::string::npos || v[5].find("\\N") != std::string::npos){
                invalid++;
                continue;
            } 
            // i++;
            std::string Airline = v[0];
            std::string AirlineID = v[1];
            std::string srcID = v[3];
            std::string dstID = v[5];
            std::string stop = v[7];

            int AirlineId = 0;
            if(AirlineID.find("\\N") == std::string::npos) AirlineId = std::stoi(AirlineID);
            int srcId = std::stoi(srcID);
            int dstId = std::stoi(dstID);
            int stop_int = std::stoi(stop);
            Route route(AirlineId, Airline, srcId, dstId, stop_int);
            // insertEdge(route, srcId, dstId);
            if(airports.find(srcId) != airports.end() && airports.find(dstId) != airports.end()){
                Airports[srcId] = airports[srcId];
                Airports[dstId] = airports[dstId];
                insertEdge(route, srcId, dstId);
                // num0++;
            }
            
        }

    }
    // std::cout << "the number of invalid routes is " << invalid << std::endl;
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


