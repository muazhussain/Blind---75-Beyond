// Problem link: https://leetcode.com/problems/subsets-ii/
// Time: (2^len * len(log(len))
// Space: (2^len * len)

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    	int n = nums.size();
    	set<vector<int>> st;
    	for(int i = 0; i < (1 << n); i++) {
    		int temp = i, index = 0;
    		vector<int> subset;
    		while(temp) {
    			if(temp & 1) {
    				subset.push_back(nums[index]);
    			}
    			index++;
    			temp >>= 1;
    		}
    		sort(subset.begin(), subset.end());
    		st.insert(subset);
    	}
    	vector<vector<int>> res;
    	for(auto s : st) {
    		res.push_back(s);
    	}
    	return res;
    }
};