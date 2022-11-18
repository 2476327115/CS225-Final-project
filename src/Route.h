#pragma once
#include <vector>
#include <string>

class Route{
    public:
        Route();
        Route(int AirlineID, std::string Airline, int srcID, int dstID, int stop);
    private:
        int AirlineID_;
        std::string Airline_;
        int srcID_; 
        int dstID_;
        int stop_;
        



};

