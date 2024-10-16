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
public:
    Node* cloneGraph(Node* node) {
    	if(node == NULL) {
			return node;
		}
        unordered_map<Node*, Node*> lookup;
        Node* copy = new Node(node->val);
        lookup[node] = copy;
        queue<Node*> q;
        q.push(node);
        while(!q.empty()) {
            Node* curr = q.front();
            q.pop();
            for(auto v : curr->neighbors) {
                if(lookup.find(v) == lookup.end()) {
                    Node* newNode = new Node(v->val);
                    lookup[v] = newNode;
                    q.push(v);
                }
                lookup[curr]->neighbors.push_back(lookup[v]);
            }
        }
        return copy;
    }
};