class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> stk;
    multiset<int> se;
    MinStack() {
        
    }
    
    void push(int x) {
        stk.push(x);
        se.insert(x);
    }
    
    void pop() {
        int x = stk.top();
        auto it = se.find(x);
        se.erase(it);
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
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */