class MinStack {
    stack<long long> st;
    long long mini;
public:
    MinStack() {
        while(!st.empty()) st.pop();
        mini = INT_MAX;
    }
    
    void push(int val) {
        long long value = val;
        if(st.empty()) {
            mini = val;
            st.push(value);
        } else {
            
            if(val < mini) {
                st.push(2*value*1LL - mini);
                mini = val;
            } else {
                st.push(value);
            }
            
        }
    }
    
    void pop() {
        if(st.empty()) return;
        long long ele = st.top();
        st.pop();
        if(ele < mini) {
            mini = 2*mini - ele;
        }
    }
    
    int top() {
        if(st.empty()) return -1;
        
        long long ele = st.top();
        if(ele < mini) {
            return mini;
        }
        return ele;
    }
    
    int getMin() {
        return mini;
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