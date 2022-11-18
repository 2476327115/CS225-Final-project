#include "Edge.h"
#include <unordered_map>

Edge::Edge(std::unordered_map<int, Route> Routes, int weights) {
    Routes_ = Routes;
    weights_ = weights;
}

int Edge::getWeights(){
    return weights_;
}
void Edge::calculateWeights(){
    weights_ = Routes_.size();
}