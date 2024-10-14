// Problem link: https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1
// Time: O(V + E)
// Space: O(V)

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  private:
  	void bfs(vector<vector<int>>& adj, vector<int>& ls, vector<bool>& vis) {
  		queue<int> q;
  		q.push(0);
  		vis[0] = true;
  		while(!q.empty()) {
  			int node = q.front();
			ls.push_back(node);
  			q.pop();
  			for(int v : adj[node]) {
  				if(!vis[v]) {
  					q.push(v);
  					vis[v] = true;
  				}
  			}
  		}
  	}

  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(vector<vector<int>> &adj) {
    	int n = adj.size();
        vector<int> ls;
        vector<bool> vis(n, false);
        bfs(adj, ls, vis);
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

        // Now using vector of vectors instead of array of vectors
        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        Solution obj;
        vector<int> ans = obj.bfsOfGraph(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends