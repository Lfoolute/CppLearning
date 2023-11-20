//https://leetcode.cn/problems/target-sum/
//目标和

class Solution {
public:
    int findTargetSumWays(const vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (abs(target) > sum) return 0;
        if ((target + sum) % 2 == 1) return 0;
        //这个背包容量就是最后算总和时应该有的正数大小
        int bagSize = (target + sum) / 2;
        if (bagSize < 0) return 0;
        vector<int> dp(bagSize + 1);
        dp[0] = 1; //这里指的是填满容量0的方法就是啥也不干 1 种方法，这个初始化很有必要
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = bagSize; j >= nums[i]; --j) {
                dp[j] += dp[j - nums[i]];//求背包怎么填满的方法数的模板
            }
        }
        return dp[bagSize];
    }
};