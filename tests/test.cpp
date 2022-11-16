#include <catch2/catch_test_macros.hpp>

#include "Graph.h"

TEST_CASE("TEST GRAPH") {
    std::string airportFilename = "Airport_test.dat";
    std::string routeFilename = "Route_test.dat";
    Graph graph = Graph(airportFilename, routeFilename);
}