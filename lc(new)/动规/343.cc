//https://leetcode.cn/problems/integer-break/
//整数拆分
//这道题第一次做的时候是用数学方法(要说的话就是贪心)做的，但是要理解其原理的话需要做数学推导，属于是误打误撞做出来
//比较标准的做法还是动态规划

//动规五部曲
//1.确定dp数组：dp[i]表示分拆数字i可以得到的最大乘积
//2.确定递推公式：两种渠道得到dp[i]最大乘积
//  或者是j * (i - j)
//  或者是j * dp[i - j]
//  dp[i] = max(dp[i], max((i - j) * j, dp[i - j] * j));
//3.dp的初始化：准确的说，dp[0]和dp[1]都是无法初始化的，这里从2开始初始化dp[2]=1
//4.确定遍历顺序:dp[i] 是依靠 dp[i - j]的状态，所以遍历i一定是从前向后遍历，先有dp[i - j]再有dp[i]。
//5.举例推导dp数组

class Solution {
public:
    int integerBreak(int n) {
        vector<int> maxSum(n + 1);
        maxSum[2] = 1;
        for (int i = 3; i <= n; ++i) {
            for (int j = 1; j < i - 1; ++j) {
                maxSum[i] = max(maxSum[i], max((i - j) * j, maxSum[i - j] * j));
            }
        }
        return maxSum[n];
    }
};
