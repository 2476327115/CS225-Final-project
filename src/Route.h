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
        void setAirlineID(int airlineId);
        void setAirline(std::string airline);
        void setSrcID(int srcId);
        void setDstID(int dstId);
        void setStop(int s);
        bool operator==(const Route & other) const;
    private:
        int AirlineID_;
        std::string Airline_;
        int srcID_; 
        int dstID_;
        int stop_;
};

