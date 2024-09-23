// Problem link: https://leetcode.com/problems/copy-list-with-random-pointer/
// Time: O(len)
// Sapce: O(1)

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
 		while(temp != NULL) {
 			Node *copy = new Node(temp->val);
            copy->next = temp->next;
            temp->next = copy;
            temp = temp->next->next;
 		}
 		temp = head;
        temp = head;
        while(temp != NULL) {
            Node *copy = temp->next;
            copy->random = temp->random != NULL ? temp->random->next : NULL;
            temp = temp->next->next;
        }
        Node *newHead = new Node(INT_MIN);
        Node *res = newHead;
        temp = head;
        while(temp != NULL) {
            res->next = temp->next;
            res = res->next;
            temp->next = temp->next->next;
            temp = temp->next;
        }
        return newHead->next;
    }
};