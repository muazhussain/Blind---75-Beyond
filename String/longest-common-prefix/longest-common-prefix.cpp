// Problem link: https://leetcode.com/problems/longest-common-prefix/
// Time: O(n * minLen)
// Space: O(1)

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int minLen = INT_MAX;
        for(string str : strs) {
        	minLen = min(minLen, (int) str.size());
        }
        int n = strs.size();
        string res = "";
        for(int i = 0; i < minLen; i++) {
        	char c = strs[0][i];
        	bool isMatch = true;
        	for(string str : strs) {
        		if(c != str[i]) {
        			isMatch = false;
        			break;
        		}
        	}
        	if(isMatch) {
        		res += c;
        	} else {
        		break;
        	}
        }
        return res;
    }
};