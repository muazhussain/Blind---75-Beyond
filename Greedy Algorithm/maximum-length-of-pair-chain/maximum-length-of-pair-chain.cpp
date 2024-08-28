// Problem link:
// Time: O(nlogn)
// Space: O(1)

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [] (const auto &p1, const auto &p2) {
            return p1[1] < p2[1];
        });

        int curr = -1, res = 0;

        for(auto p : pairs) {
        	if(curr < p[0]) {
        		curr = p[1];
        		res++;
        	}
        }
        return res;
    }
};