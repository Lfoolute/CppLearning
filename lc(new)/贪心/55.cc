//https://leetcode.cn/problems/jump-game/
//跳跃游戏

//从前往后覆盖
class Solution {
public:
    bool canJump(const vector<int>& nums) {
        if (nums.size() == 1) return true;
        int cover = 0;
        for (int i = 0; i <= cover; ++i) {
            cover = max(cover, i + nums[i]);
            if (cover >= nums.size() - 1) 
                return true;
        }
        return false;
    }
};

//从后往前
class Solution {
public:
    bool canJump(const vector<int>& nums) {
        if (nums.size() == 1) return true;
        int count = 1;
        for (int i = nums.size() - 2; i >= 0; --i) {
            if (nums[i] >= count) 
                count = 1;
            else 
                count++;
        }
        return count > 1 ? false:true;
    }
};

//https://leetcode.cn/problems/jump-game-ii/
//跳跃游戏2


//贪心
//主要的思想还是通过计算最大的覆盖范围来确定最小跳跃次数
//在目前可覆盖的范围内尽可能地寻找下一个最大覆盖范围
//这样每次跳跃的条件都是处在目前这一段最大覆盖范围的基础上
//从而以最小的跳跃步数实现最大的覆盖范围
class Solution {
public:
    int jump(const vector<int>& nums) {
        int res = 0;
        if (nums.size() == 1) return res;
        int curCover = 0;
        int nextCover = 0;
        for (int i = 0; i < nums.size() - 1; ++i) {
            nextCover = max(nextCover, nums[i] + i);
            if (i == curCover) {
                curCover = nextCover;
                res++;
            }
        }
        return res;
    }
};