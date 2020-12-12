## EE599 Final Project - TrojanMap

# Part1: Autocomplete

In this part, I use the function "strncmp", to find all the possible result for the input.
Since I need to go over the stored data, I think the time complexity is O(n), where n is the data size.

# Part2: GetPosition

In this part, I use the function "strcmp", to find the excact position, and return the position latitude and longtitude.
I also go over the stored data, so the time complexity is O(n).

# Part3: CalculateShortestPath(Dijkstra)

In this part, I use the Dijkstra algorithm to find the shortest path. It is just like grow a tree from the start.
When reaching the destination, the function will return the shortest path, or there is no path from start to destination.
I use a map called "visited" to store all the node from the start, each time I found the node is closest to the start, I will store it in "visited".
Because I need to get the shortest path, not just the distance, every time I update my tree, I also record the prev of each node to remember the path.
The time complexity of Dijkstra is O(V*E), which V is the number of vertices and E is the number of edges.
Since I don't know how many edges are stored in the map, if all vertices have a edge, the time complexity is O(n^3) for n vertices and n(n-1)/2 edges.

# Part4: Travelling Trojan(Brute force and 2-opt)

In this part, I use brute force and 2-opt to get the result.
For brute force, I generate all permutation by using DFS, and then calculation the path to find the shortest distance.
The time complexity is O(N!). It takes a long time (almost 5 minutes) to get the result when input is 10.

2-opt is a heuristics algorithm. The idea of 2-opt is continuely changing two edges of the map, and record the better result.
It is much faster than the brute force, when the input is 10, it only takes a few seconds to get the result.

Here is the Pseudo code of swaping two edge:
1. take route[0] to route[i-1] and add them in order to new_route
2. take route[i] to route[k] and add them in reverse order to new_route
3. take route[k+1] to end and add them in order to new_route

But 2-opt cannot guarantee to get the global optimal result. The algorithm may end at a local optimal result.
I set the repeating time of 2-opt to O(N^3) to get a better result. I have try O(N^2), but most time, it will stop at a local optimal.
O(N^3) is not a good time complexity for large N, but compared to O(N!), it is much better.

# Part5: Discussion, conclusion and lessons learned.

In this project, I have learn a lot about the graph algorithm. Most of the time I spend is on the Travel Salesman Problem.
I think there can be some optimization about the Brute force, but I fail to implement it.
For example, if the input N=3, the route "A, B, C", route "B, C, A" and route "C, A, B" are the same path.
But in my algorithm, I generate the permutation by DFS.
So I take the these paths and calculate the distance seperately, this situation waste a lot of time.

For the 2-opt algorithm, the problem is sometimes it will stuck in a local optimum.
To avoid this situation, I need to increase the repeating time.
Finally, I use O(N^3) to get a better result, but the time complexity is not good.





