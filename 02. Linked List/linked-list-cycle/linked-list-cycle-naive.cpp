// Problem link: https://leetcode.com/problems/linked-list-cycle/
// Time: O(n)
// Space: O(1)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *temp = head;
        map<ListNode*, bool> mark;
        while(temp != NULL) {
            if(mark.find(temp) != mark.end()) {
                return true;
            }
            mark[temp] = true;
            temp = temp->next;
        }
        return false;
    }
};