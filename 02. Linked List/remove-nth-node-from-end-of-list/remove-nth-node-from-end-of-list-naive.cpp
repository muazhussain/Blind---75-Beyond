// Problem link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
// Time: O(2 *length)
// Space: O(1)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *temp = head;
        int len = 0;
        while(temp != NULL) {
            len++;
            temp = temp->next;
        }
        int last = len - n;
        if(last == 0) {
            temp = head;
            head = head->next;
            delete(temp);
        } else {
            temp = head;
            while(last--) {
                if(last) {
                    temp = temp->next;
                }
            }
            ListNode *front = temp->next;
            temp->next = temp->next->next;
            delete(front);
        }
        return head;
    }
};