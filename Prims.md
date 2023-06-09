we want to visit all the node with smallest cost, what is cost? total sum of the weight
we have two algorithm - prims and krushkal

For Prims - 
    1. Create a adjacency matrix
    2. Start from any edge that has the minimum cost
    3. search in all the connected edge with that edge and select the minimum cost one
    4. repeat it untill we complete all the node

Pseuodocode:
    1. Create a adjacency List
    2. Create a vsited array
    3. Create Priority Queue for finding the next minimum cost edge
    4. loop untill priority queue is empty
    5. each time add every unvisited adjajccent node on the queue
    