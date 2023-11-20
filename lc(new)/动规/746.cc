//https://leetcode.cn/problems/min-cost-climbing-stairs/
//使用最小花费爬楼梯

class Solution {
public:
    int minCostClimbingStairs(const vector<int>& cost) {
        vector<int> dp(cost.size());
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i < cost.size(); ++i) {
            dp[i] = min(dp[i - 2], dp[i - 1]) + cost[i];
        }
        return min(dp[cost.size() - 2] ,dp[cost.size() - 1]);
    }
};