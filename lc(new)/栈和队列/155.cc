//https://leetcode.cn/problems/min-stack/
//实现支持push、pop、top的能检索最小元素的栈

class MinStack {
public:
	MinStack() {
		head = nullptr;
	}

	void push(int x) {
		if (head == NULL)
			head = new Node(x, x);
		else {
			int temp = x < head->min ? x : head->min;
			Node* cur = new Node(x, temp);
			cur->next = head;
			head = cur;
		}
	}

	void pop() {
		head = head->next;
	}

	int top() {
		return head->val;
	}

	int getMin() {
		return head->min;
	}
private:
	struct  Node{
		int val;
		int min;
		Node* next;

		Node(int x, int y) :val(x), min(y), next(nullptr) {}
	};
	Node* head;
};