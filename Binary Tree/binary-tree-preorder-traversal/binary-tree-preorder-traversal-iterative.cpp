// Problem link:
// Time: O(n)
// Space: O(n)

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
public:
    vector<int> preorderTraversal(TreeNode* root) {
    	vector<int> res;
        if(root == NULL) {
            return res;
        }
    	stack<TreeNode*> st;
    	TreeNode *node;
    	st.push(root);
    	while(!st.empty()) {
            node = st.top();
            res.push_back(node->val);
            st.pop();
            if(node->right != NULL) {
                st.push(node->right);
            }
            if(node->left != NULL) {
                st.push(node->left);
            }
    	}
    	return res; 
    }
};