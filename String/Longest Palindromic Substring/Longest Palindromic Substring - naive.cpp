// Problem link: https://leetcode.com/problems/longest-palindromic-substring/
// Time: O(n^3)
// Space: O(1)

class Solution {
private:
	bool isPalindrome(string s) {
		return string(s.rbegin(), s.rend()) == s;
	}

public:
    string longestPalindrome(string s) {
        int n = s.size();
        string res = "";
        for(int i = 0; i < n; i++) {
        	for(int j = i; j < n; j++) {
        		if(isPalindrome(s.substr(i, j - i + 1)) == true && res.size() < (j - i + 1)) {
        			res = s.substr(i, j - i + 1);
        		}
        	}
        }
        return res;
    }
};