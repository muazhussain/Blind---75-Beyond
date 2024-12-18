// Problem link:

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
	int dfsHeight(TreeNode* node) {
		if(node == NULL) {
			return 0;
		}	
		int left = dfsHeight(node->left);
		int right = dfsHeight(node->right);
		if(left == -1 || right == -1) {
			return -1;
		}
		if(abs(left - right) > 1) {
			return -1;
		}
		return max(left, right) + 1;
	}

public:
    bool isBalanced(TreeNode* root) {
        return dfsHeight(root) != -1;
    }
};