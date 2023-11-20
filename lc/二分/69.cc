// https://leetcode.cn/problems/sqrtx/
//给你一个非负整数 x ，计算并返回 x 的 算术平方根 。由于返回类型是整数，结果只保留整数部分 ，小数部分将被舍去 。

class Solution
{
public:
    int mySqrt(int x)
    {
        if (x == 1)
            return 1;
        int l = 0;
        int r = x;
        //二分边界
        while (r - l > 1)
        {
            int mid = l + (r - l) / 2;
            // if (x < mid * mid)
            if (x / mid < mid) //为了防止溢出
                r = mid;
            else
                l = mid;
        }
        //返回较小的左边界
        return l;
    }
};

//解2
class Solution
{
public:
    int mySqrt(int x)
    {
        int l = 1;
        int r = x;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            int tmp = x / mid;
            if (tmp < mid)
                r = mid - 1;
            else if (tmp > mid)
                l = mid + 1;
            else
                return mid;
        }
        return r;
    }
};
