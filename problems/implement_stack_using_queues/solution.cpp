class MyStack {
public:
    /** Initialize your data structure here. */
    queue < int > q1;
    queue < int > q2;
    int p;
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        q2.push(x);
        p = x;
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        queue < int > temp = q1;
        q1 = q2;
        q2 = temp;
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int t = q1.front();
        q1.pop();
        if (!q1.empty()) {
            p = q1.front();
        }
        return t;
    }

    /** Get the top element. */
    int top() {
        return p;
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */