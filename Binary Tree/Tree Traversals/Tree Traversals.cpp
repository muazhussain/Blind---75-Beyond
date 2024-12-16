// Problem link: https://www.naukri.com/code360/problems/981269

/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
vector<vector<int>> getTreeTraversal(TreeNode *root){
    vector<int> preOrder;
    vector<int> inOrder;
    vector<int> postOrder;
	vector<vector<int>> res;
    stack<pair<TreeNode*, int>> st;
    if(root == NULL) {
    	res.push_back(preOrder);
    	res.push_back(inOrder);
    	res.push_back(postOrder);
    	return res;
    }
    st.push({root, 1});
    while(!st.empty()) {
    	auto it = st.top();
    	st.pop();
    	TreeNode* node = it.first;
    	if(it.second == 1) {
    		preOrder.push_back(node->data);
    		it.second++;
    		st.push(it);
    		if(node->left != NULL) {
    			st.push({node->left, 1});
    		}
    	} else if(it.second == 2) {
    		inOrder.push_back(node->data);
    		it.second++;
    		st.push(it);
    		if(node->right != NULL) {
    			st.push({node->right, 1});
    		}
    	} else {
    		postOrder.push_back(node->data);
    	}
    }
	res.push_back(inOrder);
    res.push_back(preOrder);
    res.push_back(postOrder);
    return res;
}