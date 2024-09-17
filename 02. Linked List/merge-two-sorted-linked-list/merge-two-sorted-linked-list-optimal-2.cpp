// Problem link: https://leetcode.com/problems/merge-two-sorted-lists/
// Time: O(len(list1 + list2))
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *temp1 = list1, *temp2 = list2;        
        ListNode *head = new ListNode(), *curr = head;
        while(temp1 != NULL && temp2 != NULL) {
            if(temp1->val < temp2->val) {
                curr->next = temp1;
                temp1 = temp1->next;
            } else {
                curr->next = temp2;
                temp2 = temp2->next;
            }
            curr = curr->next;
        }
        if(temp1 != NULL) {
            curr->next = temp1;
        }
        if(temp2 != NULL) {
            curr->next = temp2;
        } 
        return head->next;
    }
};