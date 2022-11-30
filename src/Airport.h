#pragma once
#include <string>

class Airport {
    private:
        int id_;
        std::string name_;
        std::string city_;
        std::string country_;
        double latitude_;
        double longitude_;
    public:
        Airport();
<<<<<<< HEAD
        Airport(int id, std::string name, std::string city, float latitude, float longitude);
=======
        Airport(int id, std::string name, std::string city, std::string country_, double latitude, double longitude);
>>>>>>> main
        Airport(const Airport& other);
        int getID();
        std::string getName();
        std::string getCity();
        bool operator==(const Airport & other) const;
        Airport operator=(const Airport & other);
    
};
