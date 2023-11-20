// https://leetcode.cn/problems/reverse-words-in-a-string/submissions/
//给你一个字符串 s ，请你反转字符串中 单词 的顺序。

class Solution
{
public:
    void revs(std::string &s, int start, int end)
    {
        for (int i = start, j = end; i < j; ++i, --j)
        {
            std::swap(s[i], s[j]);
        }
    }

    //除去多余空格
    void remExtraSpace(std::string &s)
    {
        int slow = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] != ' ')
            {
                if (slow != 0)
                    s[slow++] = ' ';
                //连续一段的字符串
                while (i < s.size() && s[i] != ' ')
                    s[slow++] = s[i++];
            }
        }
        s.resize(slow);
    }

    std::string reverseWords(std::string &s)
    {
        remExtraSpace(s);
        revs(s, 0, s.size() - 1);
        int start = 0;
        for (int i = 0; i <= s.size(); ++i)
        {
            if (i == s.size() || s[i] == ' ')
            {
                revs(s, start, i - 1);
                start = i + 1;
            }
        }
        return s;
    }
};
