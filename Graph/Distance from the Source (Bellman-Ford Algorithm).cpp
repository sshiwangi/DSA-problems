/* Given a weighted, directed and connected graph of V vertices and E edges, Find the shortest distance of all the vertex's from the source vertex S.
Note: The Graph doesn't contain any negative weight cycle.
E = [[0,1,9]]
S = 0
Output:
0 9
Explanation:
Shortest distance of all nodes from
source is printed.

Your Task:
You don't need to read input or print anything. Your task is to complete the function bellman_ford() which takes a number of vertices V 
and an E-sized list of lists of three integers where the three integers are u,v, and w; denoting there's an edge from u to v, which has a weight of w as input parameters
and returns a list of integers where the ith integer denotes the distance of an ith node from the source node. If some node isn't possible to visit, 
then its distance should be 100000000(1e8).

Expected Time Complexity: O(V*E).
Expected Auxiliary Space: O(V). */

//code
class Solution{
	public:
	/*  Function to implement Dijkstra
    *   adj: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector <int> bellman_ford(int V, vector<vector<int>> adj, int S) {
        // Code here
        int inf = 1e8;
        vector<int> dist(V, inf);
        
        dist[S] = 0;
        //iterate V-1 times
        for(int i = 1; i<=V-1; i++){ 
            for(auto it: adj){ // iterate across all edges
                if(dist[it[0]] + it[2] < dist[it[1]]){ // do the relaxation
                    dist[it[1]] = dist[it[0]] + it[2];
                }
            }
        }
        return dist;
    }
};

 
