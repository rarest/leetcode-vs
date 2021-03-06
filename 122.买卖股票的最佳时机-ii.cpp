/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit = 0;
        for(int i = 1; i < n; i++) {
            profit += max(0, prices[i] - prices[i-1]);
        }    
        return profit;
    }

    int maxProfit1(vector<int>& prices) {
        int n = prices.size();
        int dp[n][2];
        dp[0][0] = 0; dp[0][1] = -prices[0];
        for(int i = 1; i < n; i++) {
            dp[i][0] = std::max(dp[i-1][0], dp[i-1][1] + prices[i]);
            dp[i][1] = std::max(dp[i-1][0] - prices[i], dp[i-1][1]);
        }
        return dp[n-1][0];
    }

    int maxProfit2(vector<int>& prices) {
        int n = prices.size();
        int dp[2];
        dp[0] = 0; dp[1] = -prices[0];
        for(int i = 1; i < n; i++) {
            dp[0] = std::max(dp[0], dp[1] + prices[i]);
            dp[1] = std::max(dp[0] - prices[i], dp[1]);
        }
        return dp[0];
    }
};
// @lc code=end

