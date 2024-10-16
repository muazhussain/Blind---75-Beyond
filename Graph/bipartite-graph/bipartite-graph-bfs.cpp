// Problem link: https://leetcode.com/problems/is-graph-bipartite/
// Time: O(V + E)
// Space: O(V)

class Solution {
private:
	bool bfs(vector<vector<int>>& graph, int src, vector<int>& color) {
		queue<int> q;
		q.push(src);
		color[src] = 0;
		while(!q.empty()) {
			int node = q.front();
			q.pop();
			for(int v : graph[node]) {
				if(color[v] == -1) {
					color[v] = !color[node];
					q.push(v);
				} else if(color[v] == color[node]) {
					return false;
				}
			}
		}
		return true;
	}

public:
    bool isBipartite(vector<vector<int>>& graph) {
    	int n = graph.size();
    	vector<int> color(n, -1);
    	for(int node = 0; node < n; node++) {
    		if(color[node] == -1) {
    			if(bfs(graph, node, color) == false) {
    				return false;
    			}
    		}
    	}
    	return true;
    }
};