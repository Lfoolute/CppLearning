//https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/
//买卖股票的最佳时机 II

class Solution {
public:
    int maxProfit(const vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
        dp[0][0] -= prices[0];//当前现金为负是可能的
        dp[0][1] = 0;
        //dp[i][0]为第i天持有股票的状态下的现金数目
        //dp[i][1]为第i天不持有股票的状态下的现金数目
        for (int i = 1; i < prices.size(); ++i) {
            //第i天持有股票即dp[i][0]， 那么可以由两个状态推出来:
            //  --第i-1天就持有股票，那么就保持现状，所得现金就是昨天持有股票的所得现金 即：dp[i - 1][0]
            //  --第i天买入股票，所得现金就是昨天不持有股票的所得现金减去 今天的股票价格 即：dp[i - 1][1] - prices[i]
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);

            //第i天不持有股票即dp[i][1]的情况， 依然可以由两个状态推出来:
            //  --第i-1天就不持有股票，那么就保持现状，所得现金就是昨天不持有股票的所得现金 即：dp[i - 1][1]
            //  --第i天卖出股票，所得现金就是按照今天股票佳价格卖出后所得现金即：prices[i] + dp[i - 1][0]
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
        }
        return max(dp[prices.size() - 1][0], dp[prices.size() - 1][1]);
    }
};