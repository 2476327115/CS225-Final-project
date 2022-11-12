#include <Graph.h>
#include <fstream>
#include <iostream>


void insertVertices(const std::string& filename){
    std::ifstream Ap_File(filename);
    string ID;
    string Name;
    string City;
    stirng latitude;
    string longtitude;
    if (Ap_File.is_open()) {
        std::string word;
        while (getline(Ap_File, word)) {
            vector<char> data;
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
            Airports.push_back(ID);
            Airports.push_back(Name);
            Airports.push_back(City);
            Airports.push_back(latitude);
            Airports.push_back(longtitude);
        }
    }
}
