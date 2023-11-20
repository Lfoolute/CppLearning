https://leetcode.cn/problems/maximum-length-of-repeated-subarray/
//最长重复子数组



class Solution {
public:
    int findLength(const vector<int>& nums1, const vector<int>& nums2) {
        //这里两个维度上都增加一行作用很大，防止[0,j]和[i,0]等尴尬的位置不能从负数位置加过来
        vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));
        int res = 0;
        for (int i = 1; i <= nums1.size(); ++i) {
            for (int j = 1; j <= nums2.size(); ++j) {
                if (nums1[i - 1] == nums2[j - 1]) 
                    //就像是一维的连续递增子数组升级为二维
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > res) res= dp[i][j];
            }
        }
        return res;
    }
};


//dp[i][j]都是由dp[i - 1][j - 1]推出。那么压缩为一维数组，也就是dp[j]都是由dp[j - 1]推出
//相当于可以把上一层dp[i - 1][j]拷贝到下一层dp[i][j]来继续用。
//此时内层循环需要从后向前，避免重复
class Solution {
public:
    int findLength(const vector<int>& nums1, const vector<int>& nums2) {
        vector<int> dp(nums2.size() + 1, 0);
        int res = 0;
        for (int i = 1; i <= nums1.size(); ++i) {
            for (int j = nums2.size(); j > 0; --j) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[j] = dp[j - 1] + 1;
                }
                else {
                    dp[j] = 0;
                }
                if (dp[j] > res) res= dp[j];
            }
        }
        return res;
    }
};