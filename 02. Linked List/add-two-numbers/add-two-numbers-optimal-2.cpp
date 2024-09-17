// Problem link: https://leetcode.com/problems/add-two-numbers/
// Time: O(len(l1 + l2))
// Space: O(max(l1 + l2))

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *temp1 = l1, *temp2 = l2;
        ListNode *head = new ListNode(), *curr = head;
        int carry = 0;
        while(temp1 != NULL || temp2 != NULL) {
        	int sum = carry;
            if(temp1 != NULL) {
                sum += temp1->val;
            }
            if(temp2 != NULL) {
                sum += temp2->val;
            }
        	carry = sum / 10;
        	curr->next = new ListNode(sum % 10);
        	curr = curr->next;
            if(temp1 != NULL) {
                temp1 = temp1->next;
            }
            if(temp2 != NULL) {
                temp2 = temp2->next;
            }
        }
        if(carry != 0) {
            curr->next = new ListNode(carry);
        }
        return head->next;
    }
};