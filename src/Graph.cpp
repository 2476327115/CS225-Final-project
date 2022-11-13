#include "Graph.h"
#include <fstream>
#include <iostream>
#include <string>


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
            for(int i = 0; i < word.size(); i++){
                data[i].push_back(word);
            }
            int count = 0;
            int flag = 0;
            for(count = 0; count < data.size(); count++){
                if(data[count] == data.begin()){
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
            Airport airport(ID, Name, City, latitude, longtitude);
            // Airports.push_back(airport);
            insertVertex(ID, airport);

            // Airports.push_back(ID);
            // Airports.push_back(Name);
            // Airports.push_back(City);
            // Airports.push_back(latitude);
            // Airports.push_back(longtitude);
        }
    }
}

void Graph::parseEdges(const std::string& filename){
    ifstream wordsFile(filename);
    std::string word;
    if (wordsFile.is_open()) {
        /* Reads a line from `wordsFile` into `word` until the file ends. */
        while (getline(wordsFile, word)) {
            
    }
}
}

void Graph::insertVertex(int ID, Airport airport){
    Airports[ID] = airport;
}

void Graph::insertEdge(int airportID1, int airportID2);

