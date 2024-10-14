// Problem link: https://leetcode.com/problems/course-schedule/
// Time: O(V + E)
// Space: O(V)

class Solution {
private:
	bool detectCycle(int node, vector<vector<int>>& adj, vector<bool>& nodeVis, vector<bool>& dfsVis) {
		nodeVis[node] = true;
		dfsVis[node] = true;
		for(int v : adj[node]) {
			if(!nodeVis[v]) {
				if(detectCycle(v, adj, nodeVis, dfsVis)) {
					return true;
				}
			} else if(dfsVis[v]) {
				return true;
			}
		}
		dfsVis[node] = false;
		return false;
	}
	
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    	vector<vector<int>> adj(numCourses);
    	for(auto pair : prerequisites) {
    		adj[pair[1]].push_back(pair[0]);
    	}
    	vector<bool> nodeVis(numCourses, false);
    	vector<bool> dfsVis(numCourses, false);
    	for(int node = 0; node < numCourses; node++) {
    		if(!nodeVis[node]) {
    			bool res = detectCycle(node, adj, nodeVis, dfsVis);
    			if(res == true) {
    				return false;
    			}
    		}
    	}
    	return true;
    }
};