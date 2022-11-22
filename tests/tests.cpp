#include "Graph.h"
#include "Airport.h"
#include "Edge.h"
#include "Route.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

TEST_CASE("parseVertices", "[weight=10]")
{
    auto result = parseVertices("../data/airports.dat");
}
