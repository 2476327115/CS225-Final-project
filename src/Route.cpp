#include "Route.h"
Route::Route(){
    AirlineID_ = 0;
    Airline_ = "";
    srcID_ = 0; 
    dstID_ = 0;
    stop_ = 0;
}

Route::Route(int AirlineID, std::string Airline, int srcID, int dstID, int stop){
    AirlineID_ = AirlineID;
    Airline_ = Airline ;
    srcID_ = srcID; 
    dstID_ = dstID;
    stop_ = stop;
}

void Route::setAirlineID(int airlineId) {
    AirlineID_ = airlineId;
}

void Route::setAirline(std::string airline) {
    Airline_ = airline;
}

void Route::setDstID(int dstId) {
    dstID_ = dstId;
}

void Route::setSrcID(int srcId) {
    srcID_ = srcId;
}

void Route::setStop(int stop) {
    stop_ = stop;
}

int Route::getsrcID(){
    return srcID_;
}

int Route::getdstID(){
    return dstID_;
}

int Route::getAirlineID(){
    return AirlineID_;
}

bool Route::operator==(const Route & other) const {
    if(AirlineID_ != other.AirlineID_) return false;
    if(Airline_ != other.Airline_) return false;
    if(srcID_ != other.srcID_) return false;
    if(dstID_ != other.dstID_) return false;
    if(stop_ != other.stop_) return false;
    return true;
}