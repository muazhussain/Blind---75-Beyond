// Problem link: https://leetcode.com/problems/intersection-of-two-linked-lists/
// Time: O(len(headA + headB))
// Space: O(max(len(headA), len(headB)))

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        map<ListNode*, bool> lookup;
        ListNode *temp = headA;
        while(temp != NULL) {
            lookup[temp] = true;
            temp = temp->next;
        }
        temp = headB;
        while(temp != NULL) {
            if(lookup[temp] == true) {
                return temp;
            }
            temp = temp->next;
        }
        return NULL;
    }
};