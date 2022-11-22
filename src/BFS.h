#pragma once
#include "Graph.h"
#include <iterator>
#include <iostream>
#include <string>
#include <unordered_map>
#include "Airport.h"
#include "Edge.h"
#include <queue>

class BFS{
public:
    BFS(const Graph & graph, const );





  ImageTraversal::Iterator begin();
  ImageTraversal::Iterator end();

  void add(const Point & point);
  Point pop();
  Point peek() const;
  bool empty() const;
  void be_visited(Point p);
  int get_visited(Point p);

private:
    Graph airport_graph;
    std::queue<Point> BFS_queue;
    std::vector<int> visited;
};
