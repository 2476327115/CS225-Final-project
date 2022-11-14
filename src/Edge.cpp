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
}

void Edge::addRoute(Route Route){
    int AirlineID = Route.getAirlineID();
    if(Routes_.contains(AirlineID)) return;
    Routes_[AirlineID] = Route;
    weights_++;
}

int Edge::getWeights(){
    return weights_;
}
void Edge::calculateWeights(){
    weights_ = Routes_.size();
}