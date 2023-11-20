//https://leetcode.cn/problems/sort-list/comments/
//排序链表

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* tmp = head;
        int length = 0;
        while (tmp) {
            ++length;
            tmp = tmp->next;
        }

        for (int i = 1; i < length; i *= 2) {
            ListNode* cur = dummyHead->next;
            ListNode* tail = dummyHead;

            while (cur) {
                ListNode* left = cur;
                ListNode* right = cut(left, i);
                cur = cut(right, i);

                tail->next = merge(left, right);
                while (tail->next) {
                    tail = tail->next;
                }
            }
        }
        return dummyHead->next;
    }
private:
    ListNode* cut(ListNode* head, int n) {
        ListNode* tmp = head;
        while (--n && tmp) {
            tmp = tmp->next;
        }
        if (tmp == nullptr) return nullptr;
        ListNode* next = tmp->next;
        tmp->next = nullptr;
        return next;
    }
    ListNode* merge(ListNode* l1, ListNode* l2) {
        //标准的两个list的归并排序
        //需要熟记掌握
        ListNode* dummyHead = new ListNode(0);
        ListNode* tmp = dummyHead;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                tmp->next = l1;
                tmp = tmp->next;
                l1 = l1->next;
            }
            else {
                tmp->next = l2;
                tmp = tmp->next;
                l2 = l2->next;
            }
        }
        tmp->next = l1 ? l1 : l2;
        return dummyHead->next;
    }
};