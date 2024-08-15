// Problem link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// Time: O(2^n)
// Space: O(n)

class Solution {

private:
    int solve(vector<int>& prices, int start, int end) {
        if(end <= start) {
            return 0;
        }

        int profit = 0;

        for(int i = start; i < end; i++) {
            for(int j = i + 1; j <= end; j++) {
                if(prices[j] > prices[i]) {
                    int left_profit = solve(prices, start, i - 1);
                    int right_profit = solve(prices, j + 1, end);
                    int cur_profit = prices[j] - prices[i] + left_profit + right_profit;
                    cout << left_profit << endl;
                    cout << right_profit << endl;
                    cout << cur_profit << endl;
                    profit = max(profit, cur_profit);
                }
            }
        }
        return profit;
    }

public:
    int maxProfit(vector<int>& prices) {
        return solve(prices, 0, prices.size() - 1);
    }
};