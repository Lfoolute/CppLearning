// https://leetcode.cn/problems/swap-nodes-in-pairs/
//给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。
class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        //在头节点之前设置虚节点，很有用，学习
        ListNode *preHead = new ListNode();
        preHead->next = head;
        ListNode *cur = preHead;
        while (cur->next != NULL && cur->next->next != NULL)
        {
            ListNode *tmp1 = cur->next;
            ListNode *tmp2 = cur->next->next->next;

            cur->next = cur->next->next;  //步骤1
            cur->next->next = tmp1;       //步骤2
            cur->next->next->next = tmp2; //步骤3

            cur = cur->next->next; // cur前进2位，为下一对做准备
        }
        //返回的是虚节点的下一位才是头节点
        return preHead->next;
    }
};
