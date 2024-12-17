// Problem link: https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL) {
        	return res;
        }
        queue<pair<TreeNode*, pair<int, int>>> q;
        map<int, multiset<pair<int, int>>> mp;
        q.push({root, {0, 0}});
        while(!q.empty()) {
        	auto it = q.front();
        	q.pop();
        	TreeNode* node = it.first;
        	int line = it.second.first;
        	int level = it.second.second;
            if(mp.find(line) == mp.end()) {
                mp[line] = {{level, node->val}};
            } else {
                mp[line].insert({level, node->val});
            }
            if(node->left != NULL) {
                q.push({node->left, {line - 1, level + 1}});
            }
            if(node->right != NULL) {
                q.push({node->right, {line + 1, level + 1}});
            }
        }
        for(auto it : mp) {
            vector<int> temp = {};
            for(auto p : it.second) {
                temp.push_back(p.second);
            }
            res.push_back(temp);
        }
        return res;
    }
};