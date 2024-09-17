// Problem link: https://leetcode.com/problems/merge-two-sorted-lists/
// Time: O(len(list1 + list2)log(len(list1 + list2)))
// Space: O(len(list1 + list2))

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
        vector<int> arr;
        ListNode *temp1 = list1, *temp2 = list2;        
        while(temp1 != NULL) {
            arr.push_back(temp1->val);
            temp1 = temp1->next;
        }
        while(temp2 != NULL) {
            arr.push_back(temp2->val);
            temp2 = temp2->next;
        }
        sort(arr.begin(), arr.end());
        ListNode *head = new ListNode(), *curr = head;
        for(int el : arr) {
            curr->next = new ListNode(el);
            curr = curr->next;
        }
        return head->next;
    }
};