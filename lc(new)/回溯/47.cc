//https://leetcode.cn/problems/permutations-ii/
//全排列2

//这里涉及到两种去重
//树层去重和树枝去重
//https://programmercarl.com/0047.%E5%85%A8%E6%8E%92%E5%88%97II.html#%E6%8B%93%E5%B1%95
class Solution {
public:
    std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums) {
        res.clear();
        path.clear();
        std::vector<bool> used(nums.size(), false);
        std::sort(nums.begin(), nums.end());
        backTracking(nums, used);
        return res;
    }
private:
    std::vector<std::vector<int>> res;
    std::vector<int> path;
    void backTracking(const std::vector<int>& nums, std::vector<bool>& used) {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {

            if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) continue;
            if (used[i] == false) {
                path.push_back(nums[i]);
                used[i] = true;
                backTracking(nums, used);
                path.pop_back();
                used[i] = false;
            }
        }
    }
};