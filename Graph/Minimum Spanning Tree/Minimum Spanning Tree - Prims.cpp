// Problem link: https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<bool> vis(V, false);
        vector<int> par(V);
        int res = 0;
        par[0] = -1;
        pq.push({0, {0, -1}});
        while(!pq.empty()) {
        	auto it = pq.top();
        	pq.pop();
        	int w = it.first;
        	int v = it.second.first;
        	int p = it.second.first;
        	if(!vis[v]) {
        		vis[v] = true;
        		res += w;
        		par[v] = p;
        		for(auto p : adj[v]) {
        			if(!vis[p[0]]) {
        				pq.push({p[1], {p[0], v}});
        			}
        		}
        	}
        }
        return res;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    
cout << "~" << "\n";
}

    return 0;
}


// } Driver Code Ends