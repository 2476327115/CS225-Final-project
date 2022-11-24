#pragma once
#include <string>

class Airport {
    private:
        int id_;
        std::string name_;
        std::string city_;
        std::string latitude_;
        std::string longitude_;
    public:
        Airport();
        Airport(int id, std::string name, std::string city, float latitude, float longitude);
        Airport(const Airport& other);
        int getID();
        std::string getName();
        std::string getCity();
        bool operator==(const Airport & other) const;
        Airport operator=(const Airport & other);
    
};
