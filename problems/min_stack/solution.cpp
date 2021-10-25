class MinStack {
public:
    stack<int> stk;
    multiset<int> se;
    MinStack() {
    }
    
    void push(int val) {
        stk.push(val);
        se.insert(val);
    }
    
    void pop() {
        auto itr = se.find(stk.top());
        se.erase(itr);
        stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return *se.begin();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */