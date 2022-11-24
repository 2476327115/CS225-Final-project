#include "Edge.h"
#include <unordered_map>
#include <iostream>

Edge::Edge(){
    weights_ = 0;
}

Edge::Edge(std::unordered_map<int, Route> Routes, int weights) {
    Routes_ = Routes;
    weights_ = weights;
}

Edge::Edge(Route Route){
    int AirlineID = Route.getAirlineID();
    Routes_[AirlineID] = Route;
    weights_ = 1;
    srcID_ = Route.getsrcID();
    dstID_ = Route.getdstID();
}

void Edge::addRoute(Route Route){
    if(Route.getsrcID() != srcID_ || Route.getdstID() != dstID_) return;
    int AirlineID = Route.getAirlineID();
    // if(Routes_.find(AirlineID) != Routes_.end()) return;
    Routes_[AirlineID] = Route;
    weights_++;
    // std::cout << weights_ << std::endl;
}

int Edge::getWeights(){
    return weights_;
}
void Edge::calculateWeights(){
    weights_ = Routes_.size();
}

std::unordered_map<int, Route> Edge::getRoutes() {
    return Routes_;
}

bool Edge::operator==(const Edge & other) {
    return Routes_ == other.Routes_ && weights_ == other.weights_ && srcID_ == other.srcID_ && dstID_ == other.dstID_;
}