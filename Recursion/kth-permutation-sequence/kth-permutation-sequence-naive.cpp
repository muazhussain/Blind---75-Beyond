// Problem link: https://leetcode.com/problems/permutation-sequence/
// Time: O(n! * n)
// Space: O(n! * n)

class Solution {
private:
	void generatePermutation(vector<bool>& used, vector<int>& curr, int n, vector<vector<int>>& list) {
		if(curr.size() == n) {
			list.push_back(curr);
			return;
		}
		for(int i = 1; i <= n; i++) {
			if(!used[i - 1]) {
				used[i - 1] = true;
				curr.push_back(i);
				generatePermutation(used, curr, n, list);
				used[i - 1] = false;
				curr.pop_back();
			}
		}
	}

public:
    string getPermutation(int n, int k) {
    	vector<bool> used(n, false);
    	vector<int> curr;
    	vector<vector<int>> list;
    	generatePermutation(used, curr, n, list);
    	string res = "";
    	for(int el : list[k - 1]) {
    		res += to_string(el);
    	}
    	return res;
    }
};