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

int Route::getsrcID(){
    return srcID_;
}

int Route::getdstID(){
    return dstID_;
}

int Route::getAirlineID(){
    return AirlineID_;
}