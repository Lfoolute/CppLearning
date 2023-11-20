//https://leetcode.cn/problems/partition-equal-subset-sum/
//分割等和子集

//01背包解法 动规五部曲
//1. dp[j] 表示： 容量为j的背包，所背的物品价值可以最大为dp[j]。
////////////在本题中，dp[j]表示 背包总容量是j，最大可以凑成j的子集总和为dp[j]。
//2. 确定递推公式：背包中放入数值，物品的重量为nums[i]，其价值也是nums[i]
////////////在本题中，dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
//3. dp数组初始化：dp[0] = 0;
//               如果题目给的价值都是正整数那么非0下标都初始化为0就可以了，如果题目给的价值有负数，那么非0下标就要初始化为负无穷。
//               目的是让dp数组在递归过程中取得最大的价值，而不是被初始值覆盖
////////////在本题中，只包含正整数的非空数组，所以非0下标的元素初始化为0就可以了。
//4. 确定遍历顺序：
////////////如果使用一维dp数组，物品遍历的for循环放在外层，遍历背包的for循环放在内层，且内层for循环倒序遍历！
//5. 举例推导dp数组
////////////dp[j]的数值一定是小于等于j的。
////////////如果dp[j] == j说明，集合中的子集总和正好可以凑成总和j，理解这一点很重要。
class Solution {
public:
    bool canPartition(const vector<int>& nums) {
        if (nums.size() == 1) return false;
        int sum = 0;
        for (auto n : nums) {
            sum += n;
        }
        if (sum % 2 == 1) return false;
        int target = sum / 2;
        vector<int> dp(10001, 0);
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = target; j >= nums[i]; --j) {
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }
        return dp[target] == target ? true : false;
    }
};