//https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
//买卖股票的最佳时机含手续费

//贪心做法
class Solution {
public:
    int maxProfit(const vector<int>& prices, int fee) {
        int res = 0;
        int minPri = prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] < minPri) {
                minPri = prices[i];
            }
            if (prices[i] > minPri + fee ) {
                res += prices[i] - minPri - fee;
                minPri = prices[i] - fee;//这里很关键
            }
        }
        return res;
    }
};


//动规做法
class Solution {
public:
    int maxProfit(const vector<int>& prices, int fee) {
        int holdStack = (-1) * prices[0];
        int salStack = 0;
        for (int i = 0; i < prices.size(); ++i) {
            int preHoldStack = holdStack;
            holdStack = max(holdStack, salStack - prices[i]);
            salStack = max(salStack, preHoldStack + prices[i] - fee);
        }
        return salStack;
    }
};
