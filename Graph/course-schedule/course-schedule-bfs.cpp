// Problem link: https://leetcode.com/problems/course-schedule/
// Time: O(V + E)
// Space: O(V)

class Solution {	
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    	vector<int> indegree(numCourses, 0);
    	vector<vector<int>> adj(numCourses);
    	for(auto pair : prerequisites) {
    		adj[pair[1]].push_back(pair[0]);
    		indegree[pair[0]]++;
    	}
    	queue<int> q;
    	for(int node = 0; node < numCourses; node++) {
    		if(indegree[node] == 0) {
    			q.push(node);
    		}
    	}	
    	int count = 0;
    	while(!q.empty()) {
    		int node = q.front();
    		q.pop();
    		count++;
    		for(int v : adj[node]) {
    			indegree[v]--;
    			if(indegree[v] == 0) {
    				q.push(v);
    			}
    		}
    	}
    	return count == numCourses;
    }
};