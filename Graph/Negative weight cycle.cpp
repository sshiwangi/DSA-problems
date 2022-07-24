/* Given a weighted directed graph with n nodes and m edges. Nodes are labeled from 0 to n-1, the task is to check if it contains a negative weight cycle or not.
Note: edges[i] is defined as u, v and weight.
 
Example 1:

Input: n = 3, edges = {{0,1,-1},{1,2,-2},
{2,0,-3}}
Output: 1
Explanation: The graph contains negative weight
cycle as 0->1->2->0 with weight -1,-2,-3.

Expected Time Complexity: O(n*m)
Expected Space Compelxity: O(n) */

//code
class Solution{
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    // Code here
        vector<int> dist(n, INT_MAX);
        
        dist[0] = 0;
        //iterate V-1 times
        for(int i = 0; i<n-1; i++){ 
            for(auto it: edges){ // iterate across all edges
                if(dist[it[0]] != INT_MAX && dist[it[0]] + it[2] < dist[it[1]]){ // do the relaxation
                    dist[it[1]] = dist[it[0]] + it[2];
                }
            }
        }
        // do one more relaxation
        for(auto it: edges){
            // if we can still get shorter distance, then there will be a negative cycle
            if(dist[it[0]]+it[2] < dist[it[1]]) return 1;
        }
        return 0;
      
	}
};
