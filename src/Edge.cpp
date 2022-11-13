#include "Edge.h"

Edge::Edge(std::vector<Route> Routes, int weights) {
    Routes_ = Routes;
    weights_ = weights;
}

int Edge::getWeights(){
    return weights_;
}
void Edge::calculateWeights(){
    weights_ = Routes_.size();
}