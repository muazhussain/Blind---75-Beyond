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
        ListNode *fast = head, *slow = head;
        while(fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *newHead = reverseLinkedList(slow->next);
        ListNode *first = head, *second = newHead;
        while(second != NULL) {
            if(first->val != second->val) {
                newHead = reverseLinkedList(newHead);
                return false;
            }
            first = first->next;
            second = second->next;
        }
        newHead = reverseLinkedList(newHead);
        return true;
    }
};