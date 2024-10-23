// Problem link: https://leetcode.com/problems/roman-to-integer/
// Time: O(n)
// Space: O(1)

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> table = {
        	{'I', 1},
        	{'V', 5},
        	{'X', 10},
        	{'L', 50},
        	{'C', 100},
        	{'D', 500},
        	{'M', 1000},
        };
        int n = s.size();
        int num = table[s[n - 1]];
        for(int i = n - 2; i >= 0; i--) {
        	if(table[s[i]] < table[s[i + 1]]) {
        		num -= table[s[i]];
        	} else {
        		num += table[s[i]];
        	}
        }
        return num;
    }
};