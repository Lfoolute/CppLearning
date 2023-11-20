//https://leetcode.cn/problems/increasing-subsequences/
//递增子序列

class Solution {
public:
    std::vector<std::vector<int>> findSubsequences(const std::vector<int>& nums) {
        if (nums.size() == 1) return {};
        path.clear();
        res.clear();
        backTracking(nums, 0);
        return res;
    }
private:
    std::vector<int> path;
    std::vector<std::vector<int>> res;
    void backTracking(const std::vector<int>& nums, int index) {
        //这里没加return是因为要把树上的节点都收进去
        if (path.size() >= 2) {
            res.push_back(path);
        }
        //这里的used只负责本层的遍历去重，每一层会重新定义一次
        std::unordered_set<int> used;
        for (int i = index; i < nums.size(); ++i) {
            //去重
            if ((!path.empty() && nums[i] < path.back()) || used.find(nums[i]) != used.end())
                continue;
            used.insert(nums[i]);
            path.push_back(nums[i]);
            backTracking(nums, i + 1);
            path.pop_back();
        }
    }
};

//当需要查重的数据量比较少时，可用数组来代替哈希的set或map，
//优化如下
class Solution {
public:
    std::vector<std::vector<int>> findSubsequences(const std::vector<int>& nums) {
        if (nums.size() == 1) return {};
        path.clear();
        res.clear();
        backTracking(nums, 0);
        return res;
    }
private:
    std::vector<int> path;
    std::vector<std::vector<int>> res;
    void backTracking(const std::vector<int>& nums, int index) {
        if (path.size() >= 2) {
            res.push_back(path);
        }
        int used[201] = {0};//为什么201个，题目的数值范围在-100~100，刚好覆盖
        for (int i = index; i < nums.size(); ++i) {
            if ((!path.empty() && nums[i] < path.back()) || used[nums[i] + 100] == 1)
                continue;
            used[nums[i] + 100] = 1;
            path.push_back(nums[i]);
            backTracking(nums, i + 1);
            path.pop_back();
        }
    }
};
