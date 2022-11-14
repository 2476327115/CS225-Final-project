#include <Graph.h>
#include <fstream>
#include <iostream>
using namespace std;

void parseVertices(const std::string& filename){
    std::ifstream Ap_File(filename);
    string ID;
    string Name;
    string City;
    string latitude;
    string longtitude;
    if (Ap_File.is_open()) {
        std::string word;
        while (getline(Ap_File, word)) {
            vector<char> data;
            for(unsigned i = 0; i < word.size(); i++){
                data.push_back(word.at(i));
            }
            unsigned count = 0;
            int flag = 0;
            for(count = 0; count < data.size(); count++){
                if(data[count] == data.front()){
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
            vector<string> temp;
            temp.push_back(ID);
            temp.push_back(Name);
            temp.push_back(City);
            temp.push_back(latitude);
            temp.push_back(longtitude);
        }
    }
}
