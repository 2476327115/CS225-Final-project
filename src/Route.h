<<<<<<< HEAD
class Route{
    public:
    private:

};
=======
#pragma once
#include <vector>
#include <string>

class Route{
    public:
        Route();
        Route(int AirlineID, std::string Airline, int srcID, int dstID, int stop);
        int getAirlineID();
        int getsrcID();
        int getdstID();
    private:
        int AirlineID_;
        std::string Airline_;
        int srcID_; 
        int dstID_;
        int stop_;
        



};

>>>>>>> main
