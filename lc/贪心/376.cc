// https://leetcode.cn/problems/wiggle-subsequence/
//如果连续数字之间的差严格地在正数和负数之间交替，则数字序列称为 摆动序列 。第一个差（如果存在的话）可能是正数或负数。仅有一个元素或者含两个不等元素的序列也视作摆动序列。

class Solution
{
public:
    int wiggleMaxLength(vector<int> &nums)
    {
        if (nums.size() <= 1)
            return nums.size();
        int curD = 0;
        int preD = 0;
        int res = 1;
        for (int i = 0; i < nums.size() - 1; ++i)
        {
            curD = nums[i + 1] - nums[i];
            if ((curD > 0 && preD <= 0) || (curD < 0 && preD >= 0))
            {
                res++;
                preD = curD;
            }
        }
        return res;
    }
};