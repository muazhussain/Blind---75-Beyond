// Problem link: https://leetcode.com/problems/intersection-of-two-linked-lists/
// Time: O(len(headA + headB))
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
private:
    ListNode *findCollision(ListNode *headA, ListNode *headB, int len1, int len2) {
        ListNode *temp1 = headA, *temp2 = headB;
        if(len1 > len2) {
            int diff = len1 - len2;
            while(diff--) {
                temp1 = temp1->next;
            }
        } else {
            int diff = len2 - len1;
            while(diff--) {
                temp2 = temp2->next;
            }
        }
        while(temp1 != NULL && temp2 != NULL) {
            if(temp1 == temp2) {
                return temp1;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return NULL;
    }

public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1 = 0, len2 = 0;
        ListNode *temp1 = headA, *temp2 = headB;
        while(temp1 != NULL) {
            len1++;
            temp1 = temp1->next;
        }
        while(temp2 != NULL) {
            len2++;
            temp2 = temp2->next;
        }
        ListNode *res = findCollision(headA, headB, len1, len2);
        return res;
        return NULL;
    }
};