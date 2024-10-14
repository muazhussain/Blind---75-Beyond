// Problem link: https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1
// Time: O(V + E)
// Space: O(V)

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  private:
  	void dfs(int node, vector<vector<int>>& adj, vector<int>& ls, vector<bool>& vis) {
  		vis[node] = true;
  		ls.push_back(node);
  		for(int v : adj[node]) {
  			if(!vis[v]) {
  				dfs(v, adj, ls, vis);
  			}
  		}
  	}
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(vector<vector<int>>& adj) {
    	int n = adj.size();
    	vector<bool> vis(n, false);
    	vector<int> ls;
        dfs(0, adj, ls, vis);
    	return ls;
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V); // Use vector of vectors instead of array of vectors.

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        Solution obj;
        vector<int> ans = obj.dfsOfGraph(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends