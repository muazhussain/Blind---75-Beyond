// Problem link: https://leetcode.com/problems/maximum-depth-of-binary-tree/

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
	int dfs(TreeNode* node, int height) {
		if(node == NULL) {
			return height;
		}
		int left = dfs(node->left, height);
		int right = dfs(node->right, height);
		return max(left, right) + 1;
	}

public:
    int maxDepth(TreeNode* root) {
    	return dfs(root, 0);	
    }
};