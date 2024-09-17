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
        while(temp1 != NULL && temp2 != NULL) {
        	int sum = temp1->val + temp2->val + carry;
        	carry = sum / 10;
        	curr->next = new ListNode(sum % 10);
        	curr = curr->next;
        	temp1 = temp1->next;
        	temp2 = temp2->next;
        }
        while(temp1 != NULL) {
        	int sum = temp1->val + carry;
        	carry = sum / 10;
        	curr->next = new ListNode(sum % 10);
        	curr = curr->next;
        	temp1 = temp1->next;
        }
        while(temp2 != NULL) {
        	int sum = temp2->val + carry;
        	carry = sum / 10;
        	curr->next = new ListNode(sum % 10);
        	curr = curr->next;
        	temp2 = temp2->next;
        }
        if(carry != 0) {
            curr->next = new ListNode(carry);
        }
        return head->next;
    }
};