// https://leetcode.cn/problems/wiggle-subsequence/
//如果连续数字之间的差严格地在正数和负数之间交替，则数字序列称为 摆动序列 。第一个差（如果存在的话）可能是正数或负数。仅有一个元素或者含两个不等元素的序列也视作摆动序列。


//贪心做法
class Solution
{
public:
    int wiggleMaxLength(vector<int> &nums) {
        if (nums.size() <= 1)
            return nums.size();
        int curD = 0;
        int preD = 0;//这里是假设首元素之前还有一个相同的元素，便于统计最左边的峰值
        int res = 1;//这里是默认最右边有一个峰值
        for (int i = 0; i < nums.size() - 1; ++i) {
            curD = nums[i + 1] - nums[i];
            if ((curD > 0 && preD <= 0) || (curD < 0 && preD >= 0)) {
                res++;
                preD = curD;
            }
        }
        return res;
    }
};


//动规做法
class Solution {
public:
    //dp[i][0]==考虑前i个数，第i个数作为山峰的摆动子序列的最长长度
    //dp[i][1]==考虑前i个数，第i个数作为山谷的摆动子序列的最长长度
    int dp[1005][2];//dp[][0]判断山峰状态，dp[][1]判断山谷状态
    int wiggleMaxLength(const vector<int>& nums) {
        memset(dp, 0, sizeof(dp));
        dp[0][0] = dp[0][1] = 1;
        for (int i = 1; i < nums.size(); ++i) {
            dp[i][0] = dp[i][1] = 1;
            for (int j = 0; j < i; ++j) {
                if (nums[j] > nums[i]) {
                    dp[i][1] = max(dp[i][1], dp[j][0] + 1);
                }
            }
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    dp[i][0] = max(dp[i][0], dp[j][1] + 1);
                }
            }
        }
        return max(dp[nums.size() - 1][0], dp[nums.size() - 1][1]);
    }
};