#include "Edge.h"
#include <unordered_map>

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
    weights_++;
    srcID_ = Route.getsrcID();
    dstID_ = Route.getdstID();
}

void Edge::addRoute(Route Route){
    if(Route.getsrcID() != srcID_ || Route.getdstID() != dstID_) return;
    int AirlineID = Route.getAirlineID();
    if(Routes_.find(AirlineID) != Routes_.end()) return;
    Routes_[AirlineID] = Route;
    weights_++;
}

int Edge::getWeights(){
    return weights_;
}
void Edge::calculateWeights(){
    weights_ = Routes_.size();
}