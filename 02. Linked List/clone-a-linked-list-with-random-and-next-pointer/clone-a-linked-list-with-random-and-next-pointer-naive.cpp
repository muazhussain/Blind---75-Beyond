// Problem link: https://leetcode.com/problems/copy-list-with-random-pointer/
// Time: O(len)
// Sapce: O(len)

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
 		Node *temp = head;
 		unordered_map<Node*, Node*> lookup;
 		while(temp != NULL) {
 			Node *newNode = new Node(temp->val);
 			lookup[temp] = newNode;
 			temp = temp->next;
 		}
 		temp = head;
 		while(temp != NULL) {
 			Node *curr = lookup[temp];
 			curr->next = lookup[temp->next];
 			curr->random = lookup[temp->random];
 			temp = temp->next;
 		} 
 		return lookup[head];
    }
};