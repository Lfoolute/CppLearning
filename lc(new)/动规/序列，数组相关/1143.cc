//https://leetcode.cn/problems/longest-common-subsequence/
//最长公共子序列

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));
        for (int i = 1; i <= text1.size(); ++i) {
            for (int j = 1; j <= text2.size(); ++j) {
                //公共子序列的状态可以继承前i - 1或j - 1个的状态，所以有两种情况
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[text1.size()][text2.size()];
    }
};