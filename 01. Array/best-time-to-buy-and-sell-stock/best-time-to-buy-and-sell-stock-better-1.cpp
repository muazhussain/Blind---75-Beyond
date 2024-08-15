// Problem link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// Time: O(n)
// Space: O(1)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int cur_min = prices[0]; 
        for(int i = 1; i < prices.size(); i++) {
            if(prices[i] > cur_min) {
                profit = max(profit, prices[i] - cur_min);
            }
            cur_min = min(cur_min, prices[i]);
        }
        return profit;
    }
};