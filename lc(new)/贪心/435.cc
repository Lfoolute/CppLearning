//https://leetcode.cn/problems/non-overlapping-intervals/
//无重叠区间

class Solution
{
public:
	int eraseOverlapIntervals(vector<vector<int>> &intervals) {
		//按照右边界排序
        sort(intervals.begin(), intervals.end(), 
            [](const auto &a, const auto &b)
				  { return a[1] < b[1]; });
		//count统计非交叉区间的总数目
        int count = 1;
		int end = intervals[0][1];
        //右边界排序之后
        //局部最优：悬选取有边界较小的区间，从左向右遍历，留个下一区间的空间尽量大
		for (int i = 1; i < intervals.size(); ++i) {
			//出现了非交叉区间
            if (end <= intervals[i][0]) {
				end = intervals[i][1];
				count++;
			}
		}
        //总区间数减去非交叉区间个数就是需要移除的区间数
		return intervals.size() - count;
	}
};
