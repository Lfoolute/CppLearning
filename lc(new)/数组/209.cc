// https://leetcode.cn/problems/minimum-size-subarray-sum/
//给定一个含有 n 个正整数的数组和一个正整数 target 。找出该数组中满足其和 ≥ target 的长度最小的 连续子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。如果不存在符合条件的子数组，返回 0 。

class Solution
{
public:
    int minSubArrayLen(int target, std::vector<int> &nums)
    {
        int left = 0;
        int right = 0;
        int sum = 0;
        int len = 0;
        //这里res初始值设置的方法很常见，需要会用
        int res = INT_MAX;
        while (right < nums.size())
        {
            sum += nums[right];
            while (sum >= target)
            {
                len = right - left + 1;
                res = len < res ? len : res;
                sum -= nums[left++];
            }
            right++;

            //滑动的思想，但写出来很拧巴，而且有一定问题
            // if (sum == target)
            // {
            // 	if (len == 0)
            // 	{
            // 		len = right - left;
            // 		sum -= nums[left++];
            // 	}
            // 	else
            // 	{
            // 		len = std::min(len, right - left);
            // 		sum -= nums[left++];
            // 	}
            // }
            // else if (sum < target)
            // 	sum += nums[right++];
            // else
            // 	sum -= nums[left++];
        }
        return res < INT_MAX ? res : 0;
    }
};
