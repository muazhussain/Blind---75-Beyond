// Problem link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// Time: O(n^2)
// Space: O(1)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for(int i = 0; i < prices.size() - 1; i ++) {
            for(int j = i + 1; j < prices.size(); j++) {
                if(prices[j] > prices[i]) {
                    profit = max(profit, prices[j] - prices[i]);
                }
            }
        }
        return profit;
    }
};