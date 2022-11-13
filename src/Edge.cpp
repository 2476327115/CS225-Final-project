#include "Edge.h"

int Edge::getWeights(){
    return weights;
}
void Edge::calculateWeights(){
    weights = Routes.size();
}