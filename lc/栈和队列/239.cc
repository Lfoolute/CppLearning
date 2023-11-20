// https://leetcode.cn/problems/sliding-window-maximum/
//给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。
//你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。返回滑动窗口中的最大值 。

class Solution
{
public:
    class Myqueue
    {
    public:
        //利用deque实现单调队列
        std::deque<int> que;

        void pop(int val)
        {
            //弹出的时候，比较元素与队列出口元素，相等就弹出
            //当然要首先判断是否为空
            if (!que.empty() && val == que.front())
                que.pop_front();
        }
        void push(int val)
        {
            // push的时候如果数值大于入口数值元素，将队列后端的数值弹出，直到push的数值小于等于队列入口元素
            //以此保证队列的数值是依次从大到小的
            while (!que.empty() && val > que.back())
                que.pop_back();
            que.push_back(val);
        }
        //因为队列是按照从大到小的顺序排列的，直接返回队列前端也就是front就行
        int front() { return que.front(); }
    };
    std::vector<int> maxSlidingWindow(std::vector<int> &nums, int k)
    {
        Myqueue que;
        std::vector<int> res;
        for (int i = 0; i < k; ++i)
        {
            que.push(nums[i]);
        }
        res.push_back(que.front());
        for (int i = k; i < nums.size(); ++i)
        {
            //这两步是滑动窗口
            que.pop(nums[i - k]);
            que.push(nums[i]);
            //记录对应的最大值
            res.push_back(que.front());
        }
        return res;
    }
};
