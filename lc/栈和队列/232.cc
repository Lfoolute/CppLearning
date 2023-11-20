// https://leetcode.cn/problems/implement-queue-using-stacks/
//请你仅使用两个栈实现先入先出队列。队列应当支持一般队列支持的所有操作（push、pop、peek、empty）：

class MyQueue
{
public:
    std::stack<int> staIn;
    std::stack<int> staOut;
    MyQueue()
    {
    }

    void push(int x)
    {
        staIn.push(x);
    }

    int pop()
    {
        if (staOut.empty())
        {
            while (!staIn.empty())
            {
                staOut.push(staIn.top());
                staIn.pop();
            }
        }
        int res = staOut.top();
        staOut.pop();
        return res;
    }

    int peek()
    {
        //复用本项目已经定义好的pop函数(也就是上面那个)
        //有效减少实现相似功能的函数的复制粘贴
        int res = this->pop();
        staOut.push(res);
        return res;
    }

    bool empty()
    {
        return staIn.empty() && staOut.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */