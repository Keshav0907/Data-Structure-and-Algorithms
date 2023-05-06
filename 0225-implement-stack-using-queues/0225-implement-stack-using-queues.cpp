class MyStack {
    queue<int> q1,q2;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        if(!q1.empty()) {
            q1.push(x);
        } else {
            q2.push(x);
        }
    }
    
    int pop() {
        int front = -1;
        if(q1.empty()) {
            
            while(!q2.empty()) {
                front = q2.front();
                q2.pop();
                if(q2.empty()) {
                    // return front;
                    break;
                }
                q1.push(front);
            }
             
        } else {
            
             while(!q1.empty()) {
                front = q1.front();
                q1.pop();
                if(q1.empty()) {
                    // return front;
                    break;
                }
                q2.push(front);
            }
            
        }
        return front;
    }
    
    int top() {
        int front = -1;
         if(q1.empty()) {
            
            while(!q2.empty()) {
                front = q2.front();
                q2.pop();
                                q1.push(front);
                if(q2.empty()) {
                    // return front;
                    break;
                }

            }
             
        } else {
            
             while(!q1.empty()) {
                front = q1.front();
                q1.pop();
                 q2.push(front);
                if(q1.empty()) {
                    // return front;
                    break;
                }
               
            }
            
        }
        return front;
    }
    
    bool empty() {
        return q1.empty() && q2.empty();
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