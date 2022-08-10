/* Given a Undirected Graph with V vertices and E edges, Find the level of node X. if X does not exist in the graph then print -1.
Note: Traverse the graph starting from vertex 0. 

Example 1:
         0     level 0
        /  \
       1    2   level 1
      / \    \
     3   4    5  level 2
     
X = 4
Output:
2

You dont need to read input or print anything. Your task is to complete the function nodeLevel() which takes two integers V and X denoting the number of vertices 
and the node, and another adjacency list adj as input parameters and returns the level of Node X. If node X isn't present it returns -1.

Expected Time Complexity: O(V + E)
Expected Auxiliary Space: O(V) */

//code
class Solution
{
	public:
	//Function to find the level of node X.
	int nodeLevel(int V, vector<int> adj[], int X) 
	{
	    // code here
	    
	    vector<int> vis(V, 0);
	    int level = 0;
	    queue<int> q;
	    q.push(0); 
	    vis[0] = 1;
	   
	    while(!q.empty()){
	        int size = q.size();
	
	        while(size){
	            int top = q.front();
	            q.pop();
	            // if we found node x, return level;
	            if(top == X)return level;
	            
	            for(auto it: adj[top]){
	                if(!vis[it])
	                   q.push(it);
	                   vis[it] = 1;
	            }
	            size--;
	        }
	        // after each level, increment the level
	        level++;
	       
	        
	    }
	    return -1;
	}
};
