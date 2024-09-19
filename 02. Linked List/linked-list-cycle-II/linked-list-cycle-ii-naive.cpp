// Problem link: https://leetcode.com/problems/linked-list-cycle-ii/
// Time: O(len)
// Space: O(len)

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
    ListNode *detectCycle(ListNode *head) {
		ListNode *temp = head;
		map<ListNode*, int> lookup;
		int idx = 0;
		while(temp != NULL) {
			if(lookup.find(temp) != lookup.end()) {
				return temp;
			}
			lookup[temp] = idx;
			idx++;
			temp = temp->next;
		} 
		return NULL;
    }
};