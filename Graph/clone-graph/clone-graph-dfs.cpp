// Problem link: https://leetcode.com/problems/clone-graph/
// Time: O(V + E)
// Space: O(V)

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
	Node* dfs(Node* node, unordered_map<Node*, Node*>& lookup) {
		if(lookup.find(node) != lookup.end()) {
			return lookup[node];
		}
		Node* newNode = new Node(node->val);
		lookup[node] = newNode;
		for(auto v : node->neighbors) {
			newNode->neighbors.push_back(dfs(v, lookup));
		}
		return newNode;
	}

public:
    Node* cloneGraph(Node* node) {
    	if(node == NULL) {
			return node;
		}
        unordered_map<Node*, Node*> lookup;
        return dfs(node, lookup);
    }
};