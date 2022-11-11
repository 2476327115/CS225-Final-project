#include <string>
#include <vector>
#include <queue>

class Graph {
    private:

    public:
        Graph();
        void addEdge(int airportID1, int airportID2);
        std::vector<Airport> findShortestPath();
};