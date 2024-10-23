// Problem link: https://leetcode.com/problems/string-to-integer-atoi/
// Time: O(n)
// Space: O(1)

class Solution {
public:
    int myAtoi(string s) {
    	long long num = 0;
    	int index = 0;
    	int n = s.size();
    	while(s[index] == ' ') {
    		index++;
    	}
    	bool isNeg = false;
    	if(s[index] == '-') {
    		isNeg = true;
    		index++;
    	} else if(s[index] == '+') {
    		index++;
    	}
    	while(s[index] == '0') {
    		index++;
    	}
    	while(isdigit(s[index])) {
    		if(num > INT_MAX) {
    			if(isNeg) {
    				return INT_MIN;
    			}
    			return INT_MAX;
    		}
    		num *= 10;
    		num += (s[index] - '0');
    		index++;
    	}
    	if(isNeg) {
    		num *= -1;
    	}
    	if(num > INT_MAX) {
    		return INT_MAX;
    	} else if(num < INT_MIN) {
    		return INT_MIN;
    	}
    	return (int) num;
    }
};