#include <string>

class Graph {
    private:
        struct Airport
        {
            int id_;
            std::string name_;
            std::string city_;
            std::string latitude_;
            std::string longitude_;
            Airport(int id, std::string name, std::string city, std::string latitude, std::string longitude) {
                id_ = id;
                name_ = name;
                city_ = city;
                latitude_ = latitude;
                longitude_ = longitude;
            }
        };

        Graph() {
            // constructor
        }
        
};