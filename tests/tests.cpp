#include <catch2/catch_test_macros.hpp>

#include "Graph.h"
#include "Edge.h"
#include <iostream>
#include <unordered_map>
#include <Dijkstra.h>
#include <vector>

TEST_CASE("TEST insertVertex #0", "[Graph]") {
    Graph graph = Graph();
    Airport airport0 = Airport(0, "airport0", "city0", 0, 0);
    graph.insertVertex(0, airport0);
    std::unordered_map<int, Airport> target;
    target.insert({0, airport0});
    REQUIRE(graph.getAirports() == target);
}

TEST_CASE("TEST insertVertex #1", "[Graph]") {

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


TEST_CASE("TEST insertEdge", "[Graph]") {
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

    REQUIRE(edge0.getRoutes() == target0);
    REQUIRE(edge1.getRoutes() == target1);
}


TEST_CASE("TEST parseFile small", "[Graph]") {
    std::string airport_file = "../tests/Airport_test_small.dat";
    std::string route_file = "../tests/Route_test_small.dat";
    Graph graph = Graph(airport_file, route_file);

    std::cout << graph.getAdjacency_matrix().size() << std::endl;

    for (auto iter0 : graph.getAdjacency_matrix()) {
        for (auto iter1 : iter0.second) {
            for (auto iter2 : iter1.second.getRoutes()) {
                std::cout << iter0.first << "\t" << iter1.first << "\t" << iter2.first << "\t" 
                << iter2.second.getsrcID() << "\t" <<iter2.second.getdstID() << std::endl;
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
    REQUIRE (graph.getAdjacency_matrix()[1][4].getWeights() == 0);
    REQUIRE (graph.getAdjacency_matrix()[2][1].getWeights() == 2);
    REQUIRE (graph.getAdjacency_matrix()[2][3].getWeights() == 1);
    REQUIRE (graph.getAdjacency_matrix()[2][4].getWeights() == 0);
    REQUIRE (graph.getAdjacency_matrix()[3][0].getWeights() == 0);
    REQUIRE (graph.getAdjacency_matrix()[3][1].getWeights() == 1);
    REQUIRE (graph.getAdjacency_matrix()[3][2].getWeights() == 1);
    REQUIRE (graph.getAdjacency_matrix()[4][0].getWeights() == 0);
    REQUIRE (graph.getAdjacency_matrix()[4][1].getWeights() == 0);
    REQUIRE (graph.getAdjacency_matrix()[4][2].getWeights() == 0);
    REQUIRE (graph.getAdjacency_matrix()[4][3].getWeights() == 0);
}


TEST_CASE("TEST shortest path", "[Dijkstra]") {
    std::string airport_file = "../tests/Airport_test_small.dat";
    std::string route_file = "../tests/Route_test_small.dat";
    Graph graph = Graph(airport_file, route_file);
    std::cout<<" graph ok " ;
    Dijkstra dijkstra = Dijkstra(graph);

    std::unordered_map<int, std::unordered_map<int, Edge>> temp=graph.getAdjacency_matrix();
    std::unordered_map<int, std::unordered_map<int, Edge>>::iterator itr1;
    for(itr1 = temp.begin();itr1!=temp.end();++itr1){
        //std::cout<<itr1->first<<"---";
        std::unordered_map<int, Edge> temp2=itr1->second;
        for(auto itr2:temp2){
            std::cout<<itr1->first<<"---"<<itr2.first<<"---";
            std::cout<<(itr2.second).getWeights()<<std::endl;
        }  
    }

    std::unordered_map<int, std::unordered_map<int, double>> temp1=dijkstra.getadjacmatrix();
    std::unordered_map<int, std::unordered_map<int, double>>::iterator itr3;
    for(itr3 = temp1.begin();itr3!=temp1.end();++itr3){
        std::unordered_map<int, double> temp3=itr3->second;
        for(auto itr4:temp3){
            std::cout<<itr3->first<<"~~~"<<itr4.first<<"~~~";
            std::cout<<itr4.second<<std::endl;
        }  
    }

    std::cout<<" Dijkstra ok " ;
    std::string str0 = dijkstra.getshortpath(graph, 0, 3);
    //std::string str1 = dijkstra.getshortpath(graph, 0, 1);
    REQUIRE(str0 == "Airport0 Airport1 Airport3");
    //REQUIRE(str1 == "Airport0 Airport1");
}



// TEST_CASE("TEST find important airport", "[PageRank]") {
//     std::string airport_file = "../tests/Airport_test_small.dat";
//     std::string route_file = "../tests/Route_test_small.dat";
//     Graph graph = Graph(airport_file, route_file);
//     PageRank pg = PageRank();
//     std::unordered_map<int, double> m = pg.pageRank(graph, 10, 0.85);
//     std::unordered_map<int, double> target;
//     std::pg.getRank_AP();
//     target.insert({0, 0.515});
//     target.insert({1, 1.292});
//     target.insert({2, 1.164});
//     target.insert({3, 1.011});
//     target.insert({4, 0.150});
//     REQUIRE(m == target);

// }

// TEST_CASE("BFS") {
    
// }

