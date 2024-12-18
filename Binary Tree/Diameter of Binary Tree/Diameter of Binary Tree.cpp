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
	int height(TreeNode* node, int& diameter) {
		if(node == NULL) {
			return 0;
		}
		int left = height(node->left, diameter);
		int right = height(node->right, diameter);
		diameter = max(diameter, left + right);
		return 1 + max(left, right);
	}

public:
    int diameterOfBinaryTree(TreeNode* root) {
 		int diameter = 0;
 		height(root, diameter);
 		return diameter;       
    }
};