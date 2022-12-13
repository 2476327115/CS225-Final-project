# CS225-Final-project

### The final project in UIUC Fall 2022

## Leading Question 

Our group decided to do the project "Open flight". Our goal is to find the most convenient path and the most important airport based on the given data. Throughout this final project, we used BFS, Dijkstra's algorithm, and PageRank to achieve our goal.

   
## Document and Video

Our team contract, team proposal and FP_Log can be find in `/document` directory.

[Our final presentation Video](https://youtu.be/23VsYPCS8CU)

## Dataset Acquisition

We use data of airport and route:


https://raw.githubusercontent.com/jpatokal/openflights/master/data/airports.dat
https://raw.githubusercontent.com/jpatokal/openflights/master/data/routes.dat

which can be find in `/data` directory.

## How to run the program
The program can be ran by using the 'main' executable:
```
make main
./main
```
The user would then choose the dataset that construct our graph.  
Afterwards, the user would be prompted with instructions on how to run the various operations:
```
[0] Use BFS to traverse all the graph
[1] Use BFS to find shortest path between two airports
[2] Use Dijkstra to find shortest path between two airports
[3] Use pagerank to find the most important airport in the dataset
[4] Use pagerank to find the most important airport in a given range
[9] Quit
```  
The operations may require the user to provide custom inputs i.e. airport ID.  
After computation, the result would be printed out in the terminal.  


## Test Description
Our tests can be ran with
```
make test
./test
```  

## Timeline

Data acquisition and processing (due: 11.6)

Design openflight algorithms and write all the preliminary code except the algorithm(due: 11.13)

Write BFS and Dijkstra’s Algorithm(due: 11.20)

Write Page Rank algorithm and other code completely(due: 11.27)

Write descriptive README and final report(due: 12.4)

Project close-out, inspection and final presentation(due: 12.8)
