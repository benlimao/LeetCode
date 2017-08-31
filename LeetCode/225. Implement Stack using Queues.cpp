class MyStack {
public:
    /** Initialize your data structure here. */
    queue<int> q1;
    queue<int> q2;
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q1.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        if(empty())
            return -1;
        int tmp;
        if(q2.empty())
        {
            while(q1.size() > 1)
            {
                tmp = q1.front();
                q1.pop();
                q2.push(tmp);
            }
            tmp = q1.front();
            q1.pop();
            return tmp;
        }
        else
        {
            while(q2.size() > 1)
            {
                tmp = q2.front();
                q2.pop();
                q1.push(tmp);
            }
            tmp = q2.front();
            q2.pop();
            return tmp;
        }
    }
    
    /** Get the top element. */
    int top() {
        if(empty())
            return -1;
        if(q2.empty())
            return q1.back();
        if(q1.empty())
            return q2.back();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.empty() && q2.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */
