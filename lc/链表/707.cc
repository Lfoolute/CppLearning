// https://leetcode.cn/problems/design-linked-list/
//实现链表功能

class MyLinkedList
{
private:
    struct LinkedNode
    {
        int val;
        LinkedNode *next;
        LinkedNode() : val(0), next(nullptr) {}
        LinkedNode(int x) : val(x), next(nullptr) {}
        LinkedNode(int x, LinkedNode *next) : val(x), next(next) {}
    };

    LinkedNode *virhead;
    int list_size;

public:
    MyLinkedList()
    {
        virhead = new LinkedNode(0);
        list_size = 0;
    }

    int get(int index)
    {
        if (index > (list_size - 1) || index < 0)
            return -1;
        LinkedNode *cur = virhead->next;
        while (index--)
        {
            cur = cur->next;
        }
        return cur->val;
    }

    void addAtHead(int val)
    {
        LinkedNode *newnode = new LinkedNode(val);
        newnode->next = virhead->next;
        virhead->next = newnode;
        list_size++;
    }

    void addAtTail(int val)
    {
        LinkedNode *cur = virhead;
        while (cur->next != NULL)
        {
            cur = cur->next;
        }
        LinkedNode *newnode = new LinkedNode(val, NULL);
        cur->next = newnode;
        list_size++;
    }

    void addAtIndex(int index, int val)
    {
        if (index <= 0)
            addAtHead(val);
        else if (index < list_size)
        {
            LinkedNode *cur = virhead;
            while (index--)
            {
                cur = cur->next;
            }
            LinkedNode *tmp = new LinkedNode(val);
            tmp->next = cur->next;
            cur->next = tmp;
            list_size++;
        }
        else if (index == list_size)
        {
            addAtTail(val);
        }
        else
            return;
    }

    void deleteAtIndex(int index)
    {
        if (list_size == 0 || index < 0 || index > (list_size - 1))
            return;
        LinkedNode *cur = virhead;
        while (index--)
        {
            cur = cur->next;
        }
        LinkedNode *tmp = cur->next;
        cur->next = cur->next->next;
        delete tmp;
        list_size--;
    }
};
