// https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/
//给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串的第一个匹配项的下标（下标从 0 开始）。如果 needle 不是 haystack 的一部分，则返回  -1 。

class Solution
{
public:
    //初始化前缀表next
    void getNext(int *next, const std::string &s)
    {
        int j = 0;
        next[0] = 0;
        for (int i = 1; i < s.size(); ++i)
        {
            while (j > 0 && s[i] != s[j])
            {
                j = next[j - 1];
            }
            if (s[i] == s[j])
            {
                j++;
            }
            next[i] = j;
        }
    }
    int strStr(std::string haystack, std::string needle)
    {
        if (needle.size() == 0)
            return 0;
        //动态申请一个数组，后面记得delete
        int *next = new int[needle.size()];
        getNext(next, needle);
        int j = 0;
        for (int i = 0; i < haystack.size(); ++i)
        {
            while (j > 0 && needle[j] != haystack[i])
            {
                j = next[j - 1];
            }
            if (haystack[i] == needle[j])
            {
                j++;
            }
            if (j == needle.size())
            {
                delete[] next;
                return (i - needle.size() + 1);
            }
        }
        delete[] next;
        return -1;
    }
};

// https://leetcode.cn/problems/repeated-substring-pattern/submissions/
//给定一个非空的字符串 s ，检查是否可以通过由它的一个子串重复多次构成。

class Solution
{
public:
    bool repeatedSubstringPattern(const std::string &s)
    {
        //利用化前缀表next
        int sz = s.size();
        if (sz == 1)
            return false;
        int *next = new int[sz];
        next[0] = 0;
        int j = 0;
        for (int i = 1; i < s.size(); ++i)
        {
            while (j > 0 && s[i] != s[j])
            {
                j = next[j - 1];
            }
            if (s[i] == s[j])
            {
                j++;
            }
            next[i] = j;
        }
        int res = sz % (sz - next[sz - 1]);
        delete[] next;
        return (res == 0 && j != 0) ? true : false;
    }
};
