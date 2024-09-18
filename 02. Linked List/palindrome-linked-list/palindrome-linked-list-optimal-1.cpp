// Problem link: https://leetcode.com/problems/palindrome-linked-list/
// Time: O(len(head))
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
private:
    ListNode* reverseLinkedList(ListNode* head) {
        ListNode *prev = NULL, *curr = head;
        while(curr != NULL) {
            ListNode *front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }
        return prev;
    }

public:
    bool isPalindrome(ListNode* head) {
        ListNode *fast = head, *slow = head, *prev = NULL;
        while(fast != NULL && fast->next != NULL) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *temp1 = head;
        ListNode *temp2 = reverseLinkedList(slow);
        if(prev != NULL) {
            prev->next = NULL;
        }
        while(temp1 != NULL) {
            if(temp1->val != temp2->val) {
                return false;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return true;
    }
};