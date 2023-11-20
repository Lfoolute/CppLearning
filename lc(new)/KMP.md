自己太菜了，没看懂卡哥的KMP算法代码实现的讲解。

对我来说最难的是模式串的前缀表构建的**代码实现**

手算前缀表和代码实现前缀表根本就是两个东西。

借助了以下几个博客和视频，每个都看了N遍理解了代码实现前缀表的方法：

[最浅显易懂的 KMP 算法讲解_哔哩哔哩_bilibili](https://www.bilibili.com/video/BV1AY4y157yL?spm_id_from=333.337.search-card.all.click&vd_source=ca55d2e75893b2101729a61ca9a283a8)

[KMP算法之求next数组代码讲解_哔哩哔哩_bilibili](https://www.bilibili.com/video/BV16X4y137qw/?spm_id_from=333.788.recommend_more_video.-1&vd_source=ca55d2e75893b2101729a61ca9a283a8)

[KMP算法----代码实现篇_Huberyxiao的博客-CSDN博客_kmp算法 代码](https://blog.csdn.net/Huberyxiao/article/details/105458280)

自己实现的代码(太菜了，用的for循环，思路和卡哥的代码也不一样)：

```C++
/*
LeetCode 第28题模式串匹配
首先说明，这个代码一点也不精简，可以改进成while循环精简一些，但是这么写方便我理解，LeetCode已经通过。
*/
class Solution {
public:
void get_next(int* next,string& needle)
{
    /*记录某子串的最长相等前后缀*/
    int len=0;
    /*next数组保存包含这个下标元素以及之前元素形成的子串的最长相等前后缀*/
    next[0]=0;
    /*利用递推的方法，遍历一遍模式串构建模式串的next数组*/
    /*强烈建议随便找个模式串，跟着for循环走一遍*/
    for(int i=1;i<needle.size();++i)
    {
        /*
        当 当前元素 等于 当前元素前边子串中的 最长相等前后缀的  下一个元素  时，
        此时的子串最长相等前后缀长度+1，并更新next数组对应的值
        */
        if(needle[i]==needle[len])
        {
            ++len;
            next[i]=len;
        }
        /*当  当前元素  不等于  当前元素  前边子串的  最长相等前后缀的  下一个元素  时*/
        else
        {
            /*
            如果  当前元素的  前边子串的  最长相等前后缀   长度是0了，
            在满足上边else语句的前提下，
            包含  当前元素的  子串的  最长相等前后缀长度  也只能是0
            */
            if(len==0)
            {
                next[i]=len;
            }
            /*如果  当前元素的  前边子串的  最长相等前后缀的长度  不等于0
            在满足else的条件的情况下
            我们就要寻找  当前元素的  前边子串的  更短一些的  相等前后缀*/
            else
            {
                /*
                next[len-1]的意思就是找到  最长相等前后缀中的  前缀这个子串，
                 看这个子串中的  最长相等前后缀的长度  是多少，赋值给len
                */
                len=next[len-1];
                /*因为我用的是for循环，这里不--i的话，下次循环i就跑了，别问为啥不用while循环，太菜，理解不了*/
                --i;
            }
        }
    }
}
    int strStr(string haystack, string needle) {
    /*  kmp大法，冲！*/
    const int size=needle.size();
    int next[size];
    get_next(next,needle);//通过这个函数获取模式串的next数组
    int j=0;
    /*KMP算法的精髓就是只遍历一次主串即可，所以是线性时间复杂度*/
    for(int i=0;i<haystack.size();++i)
    {
        /*
        当两个串对应元素相等时，其实应该是++i，++j，
        但是我这里是for循环，他进入下一个循环之前会自己++i，所以这个语句里我就没有++i
        */
        if(haystack[i]==needle[j])
        {
            ++j;
        }
        /*当对应元素不相等时，利用next数组跳转模式串的指针，
        注意这个时候我们得--i，因为模式串跳转之后还得和i指针的元素对比，那下一次for循环又要++i了，所以我们要--i
         */
        else if(haystack[i]!=needle[j]&&j!=0)
        {
            j=next[j-1];
            --i;
        }
        /*对应元素不相等，且j==0，这没啥好说的，和模式串的第一个元素都配不上，i++，但是是for循环，i++交给for循环做*/
        else
        {
          
        }
        /*一个和上述条件语句独立的语句，如果满足条件，说明匹配上了，返回最开始匹配的下标*/
        if(j==needle.size())
        {
            return i-j+1;
        }
    }
    /*如果没进入上述if语句，说明没匹配上，返回-1*/
    return -1;
    }
};
```

