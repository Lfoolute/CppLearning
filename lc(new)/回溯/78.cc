//https://leetcode.cn/problems/subsets/
//子集问题
//https://leetcode.cn/problems/subsets-ii/
//子集 2


////////////////子集问题////////////////////
class Solution {
private:
    std::vector<int> path;
    std::vector<std::vector<int>> res;
    void backTracking(const std::vector<int>& nums, int index) {
        res.push_back(path);
        //这里就是收集子集的，放在if上面是防止自己没收进去
        //两遍都是这个地方没搞明白，想清楚子集是按照怎样的一个顺序列出来的
        if (index >= nums.size()) return;//这里的终止条件可以不写，当i>nums.size()时，因为for循环的限制进不来的
        for (int i = index; i < nums.size(); ++i) {
            path.push_back(nums[i]);
            backTracking(nums, i + 1);
            path.pop_back();
        }
    }
public:
    std::vector<std::vector<int>> subsets(const std::vector<int>& nums) {
        backTracking(nums, 0);
        return res;
    }
}

/////////////////子集2///////////////
//在for循环中去重
class Solution
{
public:
	vector<vector<int>> subsetsWithDup(vector<int> &nums) {
		sort(nums.begin(), nums.end());
		backTracking(nums, 0);
		return res;
	}
private:
	vector<vector<int>> res;
	vector<int> path;
	void backTracking(const vector<int> &nums, int index) {
		res.push_back(path);
		if (index >= nums.size())
			return;
		for (int i = index; i < nums.size(); ++i) {
			if (i > index && nums[i] == nums[i - 1])
			//这里 i>index 需要特别注意，之前写的是 i>=1 就有问题；
			//该位置和组合2那道题的去重同理
			{
				continue;
			}
			path.push_back(nums[i]);
			backTracking(nums, i + 1);
			path.pop_back();
		}
	}
};

//使用used容器去重
class Solution {
public:
    std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        std::vector<bool> used(nums.size(), false);
        backTracking(nums, 0, used);
        return res;
    }
private:
    std::vector<int> path;
    std::vector<std::vector<int>> res;
    void backTracking(const std::vector<int>& nums, int index, std::vector<bool> used) {
        res.push_back(path);
        if (index >= nums.size()) return;
        for (int i = index; i < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums [i - 1] && !used[i - 1]) continue;
            path.push_back(nums[i]);
            used[i] = true;
            backTracking(nums, i + 1, used);
            used[i] = false;
            path.pop_back();
        }
    }
};