// https://leetcode.cn/problems/remove-nth-node-from-end-of-list/
//给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。

//快慢指针
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *cur = new ListNode(0);
        cur->next = head;
        ListNode *pre = head;
        ListNode *flag = head->next;
        while (pre != NULL)
        {
            pre = pre->next;
            n--;
            if (n < 0)
                cur = cur->next;
        }
        cur->next = cur->next->next;
        return (cur->next == flag) ? cur->next : head;
    }
};

//这里的递归很牛逼
class Solution
{
public:
    int cur = 0;
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (head == NULL)
            return NULL;
        head->next = removeNthFromEnd(head->next, n);
        cur++;
        if (n == cur)
            return head->next;
        return head;
    }
};