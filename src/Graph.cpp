#include "Graph.h"
#include <fstream>
#include <iostream>
#include <string>

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
            for(int i = 0; i < word.size(); i++){
                data.push_back(word[i]);
            }
            int count = 0;
            int flag = 0;
            for(count = 0; count < data.size(); count++){
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
            Airport airport(ID, Name, City, latitude, longtitude);
            // Airports.push_back(airport);
            insertVertex(ID, airport);
        }
    }
    Ap_File.close();
}

void Graph::parseEdges(const std::string& filename){
    ifstream Route_File(filename);
    std::string word;
    if (Route_File.is_open()) {
        /* Reads a line from `wordsFile` into `word` until the file ends. */

        BA,1355,SIN,3316,LHR,507,,0,744 777
        while (getline(wordsFile, word)) {
            int count = 0;
            int flag = 0;
            for(count = 0; count < word.size(); count++){
                if(count == 0){
                    while(word[count] != ','){   
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
    Route_File.close();
}
}

void Graph::insertVertex(int ID, Airport airport){
    Airports[ID] = airport;
}

void Graph::insertEdge(int airportID1, int airportID2);

