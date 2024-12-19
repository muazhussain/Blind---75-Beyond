// Problem link: https://www.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Position this line where user code will be pasted.
class Solution {
  private:
  	void dfs(int v, vector<vector<int>>& adj, vector<bool>& vis, stack<int>& st) {
  		vis[v] = true;
  		for(int u : adj[v]) {
  			if(!vis[u]) {
  				dfs(u, adj, vis, st);
  			}
  		}
  		st.push(v);
  	}

  	void dfs2(int v, vector<vector<int>>& adjT, vector<bool>& vis) {
  		vis[v] = true;
  		for(int u : adjT[v]) {
  			if(!vis[u]) {
  				dfs2(u, adjT, vis);
  			}
  		}
  	}

  public:
    int kosaraju(vector<vector<int>> &adj) {
        int v = adj.size();
        vector<bool> vis(v, false);
        stack<int> st;
        for(int i = 0; i < v; i++) {
        	if(!vis[i]) {
        		dfs(i, adj, vis, st);
        	}
        }
        vector<vector<int>> adjT(v);
        for(int i = 0; i < v; i++) {
        	vis[i] = false;
        	for(int u : adj[i]) {
        		adjT[u].push_back(i);
        	}
        }
        int res = 0;
        while(!st.empty()) {
        	int node = st.top();
        	st.pop();
        	if(!vis[node]) {
        		res++;
        		dfs2(node, adjT, vis);
        	}
        }
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.kosaraju(adj) << "\n";

        // cout << "~"
        //      << "\n";
    }

    return 0;
}

// } Driver Code Ends