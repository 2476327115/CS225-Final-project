# CS225-Final-project

### The final project in UIUC Fall 2022

## Leading Question 
   
   Our group decide to the porject "Open flight" Our goul is to find any shortest ath algorithm to find preferred routes and make a graphical output on projected onto a world map. To find the weight for the graph, we use the airport data to compute the distance and use that as the weight. It is very useful and applicable. Finding the shortest path algorithms of routes and make the output graphically can help people find the shortest and preferred routes. Working on the datasets of the open flights can help us better understand connectivity and human geography. Throughout this final project, we will use BFS, Dijkstra's algorithm, etc to resolve the problems.
   
   
## Document

Our team contract, team proposal and FP_Log can be find in `/document` directory.

## Dataset Acquisition

We use data of airport and route:


https://raw.githubusercontent.com/jpatokal/openflights/master/data/airports.dat
https://raw.githubusercontent.com/jpatokal/openflights/master/data/routes.dat

which can be find in `/data` directory.

## Data Parsing

We first downloaded the OpenFlights data set of airports and routes in dat file (airports.dat and routes.dat). Each line inlcudes the information of an airport or a route. In the airport dataset, each line representing an airport contains Airport ID, Name, City, Country, IATA, ICAO, Latitude, Longitude, Altitude, Timezone, DST, Tz database time zone, Type, Source. In the route dataset, each line representing a route contains Airline, Airline ID, Source airport, Source airport ID, Destination airport, Destination Airport ID, Codeshare, Stops and Equipment. 

For airport dataset, in order to parse the data correctly, we parsed each line each character by character and splited each piece of information of an airport by counting the comma outside the pairs of quotations marks to avoid counting the comma inside its name, city, or country. We then convert this data to several strings and convert the strings of ID, latitude, longitude to number  to construct the airport objects. There is an unordered_map which maps the airport ID into the object of itself as vertices of the graph. When inserting edges, we use the similar method to parse the information of each route into the graph. Since we are counting the number of routes between the source airport and the destination airport as the weight of edge, we incremented the weight of the edge as we added the corresponding route. We used the unordered_map as the adjacenct matrix to store the routes with their corresponding source and destination airports. After parsing all the information from the route and airport dataset, we created a graph class that helps insert all the airports as vertices and routes as edges into the graph. 

To optimize the graph and reduce the time complexity of the algorithms we use, especially PageRank, we disregard the routes with missing information or contains NULL, considering that they are no longer executed. We still parse the airport which may contains missing information only for statistics but won't be used in practical implementation. Also, we have one unordered_map which contains all the airports from the airport dataset and the other which contains the airports found in both airport data set and route dataset. The airports found in both airport data set and route dataset have another unordered_map to help host the adjacent airports and its path. Finally, we created a graph that includes all the useful and valid information of the airports as vertices and routes as edges with their weights and the tool to find the adjacent vertices with the corresponding routes.

## BFS
For BFS, it contain two main effects: it can travel through the vertices(airports) of the graph or the airports between two specific airports and returns a vector that stores the srcID of the vertices (airports) it travels. In addition, it can find the shortest pass which is only decided by the number of transfer steps. Since not all the vertices are connected, the BFS won't travel through all the airports of data. 

The purpose of the function bfsGetShortstep is to use BFS to find the shortest path that is judged only by the number of aircraft turns. And note that only the first shortest path found is taken as a result. BFS uses Queue to traverse the entire graph. The test traverses the airports close to the airport. If the number of transits of the tested path is smaller than the number of transits of the stored path, then it is re-stored. Other cases remain the same.

We wrote several test cases. We made small data sets "Airport_test_small.dat" and "Route_test_small.dat" which contain the airports and routes we made up to test BFS functions. The first test case ("BFS # small dataset") is that we test the airports the function travels. It will print the airports that are traveled. We will check whether it matches the expected result. Also, we will check the number of airports that are traveled. 

The second test case ("TEST BFS with dest # small dataset") tests whether the vector will end at the destID if there's no disconnection between the specific two airports. Also, it tests a case that contains a disconnection between two airports. It should return a message and the vector shouldn't end with destID.

The third test case ("TEST construct graph # real data") tests BFS in the actual data set we used. We count the number of airports the function travels. Since there are some airports that aren't connected, so the number of traveled airports shouldn't equal the total number of airports in the data set.

The shortest pass by step test cases("TEST bfsshortest step # small dataset" and "TEST bfsshortest step # real data") The test case uses a small dataset written by our group as well as an actual dataset to test whether the results are correct. The results were perfect as we expected.

## Dijkstra's Algorithms
In our group's final project, we mainly use Dijkstra's Algorithms to find the shortest path from the starting airport to the ending airport. The result of this function is a path of string-type characters. For example, from airport 1 to airport 3, the result of Dijkstra's Algorithms is "1 2 3". This means that to get from airport 1 to airport 3 requires a transfer from airport 2. And each airport is separated by a space.

The core Dijkstra's Algorithm gets the paths from the starting airport to all other airports and generates an unordered_map storing <int,string>. The path from the starting airport to the desired end airport is then found in the unordered_map. In the program, a queue is used to store the next airport to be checked. The top airport of the queue is the base airport, and all the neighboring airports of the base airport are checked. The path (string), weight (double), and number of aircraft transfers (int) from the starting airport to all available airports are stored in multiple unordered_map. The key conditions are that the currently checked paths are smaller than the stored paths in terms of the number of connections, and that the number of paths can be swapped if there are more paths with the same number of connections. In other cases, the current stored paths remain unchanged. The whole algorithm should ensure that each airport can only be the base airport once, but can be checked and replaced to the shortest path as an approaching airport many times.

The test case is a good illustration of the ultimate goal of Dijkstra's Algorithms, we use "TEST shortest path # small dataset" and "Find shortest path # real data". The path results match what we expect.

## PageRank
Page Rank algorithm aims to evaluate the importance of the airports connected in the graph. It works by counting the number of the routes to an airport to determine a rough estimate of how important the airport is. The underlying assumption is that more important airports are able to receive more routes from other airports. 

We use $PR(u) = 1-d+d\sum\limits_{v \in B_u} \frac{PR(v)}{L(v)}$ as the formula to calculate PaegRank. $d$ is the damping factor which is normally 0.85. $PR(v)$ is the page rank value for airport $v$. $L(v)$ is the number of routes from airport $v$. $B_u$ is the set containing all airports linking to airport u). 

To implement this algorithm, we have two unordered_map. One has the airportID as keys and the corresponding airport object . The other is the adjacency matrix of the given graph. In the adjacent matrix, the key is the source airport ID and the value is another unordered_map which has the destination airport ID as keys and the Edge between the source and destination as value. Thus, to get the out degree, which is the number of routes from the given airports, we can just calculate the size of value of the adjacency matrix, which is what getOutDegree(int srcID) does. Before we start the Page Rank, we normalize the initial page rank value of each airport to $\frac{1}{Airports.size()}$ so that the sum of the page rank value should be 1. Then, using the formula of the Page Rank algorithms, each value will be the product of the damping factor with $\sum\limits_{v \in B_u} \frac{PR(v)}{L(v)}$ plus $1-d$. The PageRank computations require iterations, which uses the collection to adjust the approximate PageRank value to make it more closely reflect the theoretical true value. After iterations, the result should approach a stable state, which can be the final rank of the importance of the airports.

To test the PageRank algorithm. We first use the sample test case. We created a sample graph with several airports and tried to calculate the rank of their importance. Because the graph is pretty small, we can get the rank order and conclude that 1 is the airport ID of the important airport because it has the greatest incoming edges. To make sure we are on the right track, we used the page rank calculator online to get the rank order of the graph. The result of our implementation of PageRank is the same as expected. Then, we use the small subset of the real data set to test the PageRank algorithms and we also get the same as expected value that Houari Boumediene Airport is the most important airport since it has the most incoming edges. Then, we use the whole data set and we found that our most important airport is Hartsfield Jackson Atlanta International Airport and we get the rank of ten most important airports, which is roughly similar to reality in 2014. Since the time complexity is pretty high and data is huge, we only run ten iterations for the Page Rank, which means the result we get from our implementation cannot be precise enough, but we roughly get the right result of the rank. 

## Timeline

Data acquisition and processing (due: 11.6)

Design openflight algorithms and write all the preliminary code except the algorithm(due: 11.13)

Write BFS and Dijkstra’s Algorithm(due: 11.20)

Write Page Rank algorithm and other code completely(due: 11.27)

Write descriptive README and final report(due: 12.4)

Project close-out, inspection and final presentation(due: 12.8)
