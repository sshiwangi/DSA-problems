/* Eulerian Path is a path in graph that visits every edge exactly once. Eulerian Circuit is an Eulerian Path which starts and ends on the same vertex. 
The task is to find that there exists the Euler Path or circuit or none in given undirected graph with V vertices and adjacency list adj.

Example 1:

Input: 

Output: 2
Explanation: The graph contains Eulerian circuit
Example 2:

Input: 

Output: 1
Explanation: The graph contains Eulerian path.
 

Your Task:
You don't need to read or print anything. Your task is to complete the function isEulerCircuilt() which takes number of vertices in the graph denoting as V and 
adjacency list of graph denoting as adj and returns 1 if graph contains Eulerian Path, 2 if graph contains Eulerian Circuit 0 otherwise.
 
Expected Time Complexity: O(V+E) where E is the number of edges in graph.
Expected Space Complexity: O(V)
 
Constraints:
1 ≤ V, E ≤ 104 */

//code
class Solution{
public:
	int isEularCircuit(int V, vector<int>adj[]){
	    // Code here
	    vector<int> degree(V,0);
	    // storing degree of each node
	    for(int i = 0; i<V; i++){
	        vector<int> temp = adj[i];
	        for(int j = 0; j<temp.size(); j++){
	            degree[temp[j]]++;
	        }
	    }
	    int countOdd = 0;
	    for(int i = 0; i<V; i++){
	        // if degree is odd
	        if(degree[i]%2 != 0) countOdd++;
	    }
	    if(countOdd == 0)return 2; // if no of nodes having odd degree is 0, it is an euler circuit
	    else if(countOdd == 2)return 1; // if no of nodes having odd degree is 2, it is an euler path
	    else return 0; // if it is neither of them
	}
};
