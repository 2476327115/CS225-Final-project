# CS225 Final Project report

## Leading Question 

Our group decided to do the project "Open flight". Our goal is to find the most convenient path and the most important airport based on the given data. Throughout this final project, we used BFS, Dijkstra's algorithm, and PageRank to achieve our goal.
   
## Data Parsing

We first downloaded the OpenFlights data set of airports and routes in dat file (airports.dat and routes.dat). Each line inlcudes the information of an airport or a route. In the airport dataset, each line representing an airport contains Airport ID, Name, City, Country, IATA, ICAO, Latitude, Longitude, Altitude, Timezone, DST, Tz database time zone, Type, Source. In the route dataset, each line representing a route contains Airline, Airline ID, Source airport, Source airport ID, Destination airport, Destination Airport ID, Codeshare, Stops and Equipment. 

For airport dataset, in order to parse the data correctly, we parsed each line each character by character and splited each piece of information of an airport by counting the comma outside the pairs of quotations marks to avoid counting the comma inside its name, city, or country. We then convert this data to several strings and convert the strings of ID, latitude, longitude to number  to construct the airport objects. There is an unordered_map which maps the airport ID into the object of itself as vertices of the graph. When inserting edges, we use the similar method to parse the information of each route into the graph. Since we are counting the number of routes between the source airport and the destination airport as the weight of edge, we incremented the weight of the edge as we added the corresponding route. We used the unordered_map as the adjacenct matrix to store the routes with their corresponding source and destination airports. After parsing all the information from the route and airport dataset, we created a graph class that helps insert all the airports as vertices and routes as edges into the graph. 

To optimize the graph and reduce the time complexity of the algorithms we use, especially PageRank, we disregard the routes with missing information or contains NULL, considering that they are no longer executed. We still parse the airport which may contains missing information only for statistics but won't be used in practical implementation. Also, we have one unordered_map which contains all the airports from the airport dataset and the other which contains the airports found in both airport data set and route dataset. The airports found in both airport data set and route dataset have another unordered_map to help host the adjacent airports and its path. Finally, we created a graph that includes all the useful and valid information of the airports as vertices and routes as edges with their weights and the tool to find the adjacent vertices with the corresponding routes.

We have wrote several test cases to test the correctness of this graph data structure.  We initially uses the small sample test cases("TEST insertVertex #0" and "TEST insertVertex #1”) to check whether we could insert the vertices correctly. Then we use some small dataset("TEST insertEdge" and "TEST parseFile # small dataset") to check whether we insert the route and make the adjacency matrix correctly. We check the route corresponding with the source and destination airports respectively.  Finally, we use the test case which uses the actual dataset to check whether we create the graph data structure correctly. To check whether it works, we count the number of invalid information and the useful information of airports and routes and add up together, using the total number to compare with the exact number of lines in the data set. The total amount of routes is the same as the the number of lines.

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

## Answer to Leading Question

## Conclusion




# video (plans)

## Your Goals(1-2)
    

## Your Development and Conclusions(5-8)
   

## Your big Conclusions(1-2)