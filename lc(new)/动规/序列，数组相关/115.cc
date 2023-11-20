//https://leetcode.cn/problems/distinct-subsequences/submissions/
//不同的子序列


class Solution {
public:
    int numDistinct(const string& s, const string& t) {
        int n = s.size();
        int m = t.size();
        //dp[i][j]：以i-1为结尾的s子序列中出现以j-1为结尾的t的个数为dp[i][j]
        vector<vector<uint64_t>> dp(n + 1, vector<uint64_t>(m + 1, 0));
        //dp[i][0] 表示：以i-1为结尾的s可以随便删除元素，出现空字符串的个数 初始化为 1 
        //dp[0][j] 表示：空字符串s可以随便删除元素，出现以j-1为结尾的字符串t的个数 初始化为 0
        //dp[0][0] 初始化为 1
        for (int i = 0; i <= n; ++i) dp[i][0] = 1;
        //两种情况：
        //1. 当s[i - 1] 与 t[j - 1]相等时，dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        //2. 当s[i - 1] 与 t[j - 1]不相等时，dp[i][j]只有一部分组成，不用s[i - 1]来匹配，即：dp[i - 1][j]
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                }
                else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n][m];
    }
};