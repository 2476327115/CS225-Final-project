## Leading Question 
   
   Our group decide to the porject "Open flight" Our goul is to find any shortest ath algorithm to find preferred routes and make a graphical output on projected onto a world map. To find the weight for the graph, we use the airport data to compute the distance and use that as the weight. It is very useful and applicable. Finding the shortest path algorithms of routes and make the output graphically can help people find the shortest and preferred routes. Working on the datasets of the open flights can help us better understand connectivity and human geography. Throughout this final project, we will use BFS, Dijkstra's algorithm, etc to resolve the problems.

## Dataset Acquisition

We use data of airport and route: 
https://raw.githubusercontent.com/jpatokal/openflights/master/data/airports.dat
https://raw.githubusercontent.com/jpatokal/openflights/master/data/routes.dat

## Data Format

Our data comes from https://openflights.org/data.html. It is entered into the program via the .dat file format. We will transform the dataset into object-facing programming objects via Graph Algorithm to facilitate later utilization and processing.

## Data Correction

The two inputs will be the departure airport and the landing airport. First, we will use the data of airports to check whether those two airport exist. If the departure airport or landing airport doesn't exist, we will return messages like "can't find departure airport" or "can't find landing airport". If those two airports exist, we will check whether the route exists between two airports using the data of routes. If a direct flight route between the two airports doesn't exist, it will search transit airports using route data. If there are no transit airports exist in the route, we return messages like "no route exists".

## Data Storage

We represent class Graph as class Edge and class Vertex. We use stack when DFS and queue when BFS to store the temporary data. We will to priority queue and vecter when doing Dijkstra's algorithm.

## Algorithm 

The findShortestPath function will input the AirportID of the two airports, calculate the path through the airport with the shortest flight distance from the first airport to the second airport by Dijkstra's algorithm, and RETURN the path. (Big O: O(|E| + |V|*log|V|) where E represent number of Edges, V represent number of Vertex)

The generateProjection is a void function which take no input. the png file which contains projection of airport and flight on the world map which be written into local storage. (Big O: O(n))

The generateGraph is a void function which will be used in the constructor. The function is a void function with no input. It will read through the .dat file and write the data from dataset to graph. The weight of the graph is the distance between 2 airport. (Big O: O(n))


## Timeline

data acquisition and processing (due: 11.6)

design write openflight algorithms(due: 11.13)

write code completely(due: 11.27)

Write descriptive README and final report(due: 12.4)

Project close-out, inspection and final presentation(due: 12.8)
