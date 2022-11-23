#include <catch2/catch_test_macros.hpp>

#include "Graph.h"
#include "Edge.h"
#include <iostream>
#include <unordered_map>

TEST_CASE("TEST insertVertex") {

    Graph graph = Graph();
    Airport airport0 = Airport(0, "airport0", "city0", 0, 0);
    Airport airport1 = Airport(1, "airport1", "city1", 0, 0);
    graph.insertVertex(0, airport0);
    graph.insertVertex(1, airport1);

    std::unordered_map<int, Airport> target;
    target.insert({0, airport0});
    target.insert({1, airport1});
    REQUIRE(graph.getAirports() == target);
}
TEST_CASE("TEST insertEdge") {
    Graph graph = Graph();
    Route route0 = Route(0, "airline0", 0, 1, 0);
    Route route1 = Route(1, "airline1", 1, 0, 0);
    graph.insertEdge(route0, 0, 1);
    graph.insertEdge(route1, 1, 0);
    Edge edge0 = graph.getAdjacency_matrix()[0][1];
    Edge edge1 = graph.getAdjacency_matrix()[1][0];
    std::unordered_map<int, Route> target0;
    std::unordered_map<int, Route> target1;
    target0.insert({0, route0});
    target1.insert({1, route1});
    REQUIRE(edge0.getRoutes() == target0 && edge1.getRoutes() == target1);
}

TEST_CASE("TEST parseFile small") {
    std::string airport_file = "Airport_test_small.dat";
    std::string route_file = "Route_test_small.dat";
    Graph graph = Graph(airport_file, route_file);

    for (auto iter0 : graph.getAdjacency_matrix()) {
        for (auto iter1 : iter0.second) {
            for (auto iter2 : iter1.second.getRoutes()) {
                std::cout << iter0.first << "\t" << iter1.first << "\t" << iter2.first << "\t" 
                << iter2.second.getsrcID() << iter2.second.getdstID() << std::endl;
            }
        }
    }

    REQUIRE (graph.getAdjacency_matrix()[0][1].getWeights() == 1);
    REQUIRE (graph.getAdjacency_matrix()[0][2].getWeights() == 1);
    REQUIRE (graph.getAdjacency_matrix()[0][3].getWeights() == 0);
    REQUIRE (graph.getAdjacency_matrix()[0][4].getWeights() == 0);
    REQUIRE (graph.getAdjacency_matrix()[1][0].getWeights() == 1);
    REQUIRE (graph.getAdjacency_matrix()[1][2].getWeights() == 1);
    REQUIRE (graph.getAdjacency_matrix()[1][3].getWeights() == 1);
    REQUIRE (graph.getAdjacency_matrix()[2][1].getWeights() == 2);
    REQUIRE (graph.getAdjacency_matrix()[2][3].getWeights() == 1);
    REQUIRE (graph.getAdjacency_matrix()[3][0].getWeights() == 0);
    REQUIRE (graph.getAdjacency_matrix()[3][1].getWeights() == 1);
    REQUIRE (graph.getAdjacency_matrix()[3][2].getWeights() == 1);
}

TEST_CASE("TEST shortest path") {
    std::string airport_file = "Airport_test_small.dat";
    std::string route_file = "Route_test_small.dat";
    Graph graph = Graph(airport_file, route_file);

}

TEST_CASE("TEST page rank") {

}