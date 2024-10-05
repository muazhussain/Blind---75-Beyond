// Problem link: https://leetcode.com/problems/palindrome-partitioning/
// Time: O(2^n * n)
// Space: O(number_of_palindrome_substring * average_length)

class Solution {
private:
	bool isPalindrome(string s, int start, int end) {
		while(start < end) {
			if(s[start] != s[end]) {
				return false;
			}
			start++;
			end--;
		}
		return true;
	}

	void palindromePartition(int index, string s, vector<string>& current, vector<vector<string>>& res) {
		if(index == s.size()) {
			res.push_back(current);
			return;
		}
		for(int i = index; i < s.size(); i++) {
			if(isPalindrome(s, index, i) == true) {
				current.push_back(s.substr(index, i - index + 1));
				palindromePartition(i + 1, s, current, res);
				current.pop_back();
			}
		}
	}

public:
    vector<vector<string>> partition(string s) {
        vector<string> current;
        vector<vector<string>> res;
        palindromePartition(0, s, current, res);
        return res;
    }
};