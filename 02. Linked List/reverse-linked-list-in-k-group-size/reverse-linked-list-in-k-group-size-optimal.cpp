// Problem link: https://leetcode.com/problems/reverse-nodes-in-k-group/ 
// Time: 
// Space:

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
    void reverseLinkedList(ListNode* head) {
        ListNode *curr = head, *prev = NULL;
        while(curr != NULL) {
            ListNode *front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }
    }

    ListNode* findKthNode(ListNode* head, int k) {
        ListNode *temp = head;
        while(temp != NULL && k > 1) {
            temp = temp->next;
            k--;
        }
        return temp;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *temp = head, *prevLast = NULL;
        while(temp != NULL) {
            ListNode *kthNode = findKthNode(temp, k);
            if(kthNode == NULL) {
                if(prevLast != NULL) {
                    prevLast->next = temp;
                }
                break;
            }
            ListNode *nextNode = kthNode->next;
            kthNode->next = NULL;
            reverseLinkedList(temp);
            if(temp == head) {
                head = kthNode;
            } else {
                prevLast->next = kthNode;
            }
            prevLast = temp;
            temp = nextNode;
        }
        return head;
    }
};