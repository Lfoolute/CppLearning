// https://leetcode.cn/problems/maximum-subarray/
//给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int res = INT_MIN;
        int n = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            n += nums[i];
            if (n > res)
                res = n;
            if (n <= 0)
                n = 0;
        }
        return res;
    }
};