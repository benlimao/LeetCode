class MyQueue {
public:
    stack<int> stack1;
    stack<int> stack2;
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        stack1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(empty())
            return -1;
        int tmp = peek();
        stack2.pop();
        return tmp;
    }
    
    /** Get the front element. */
    int peek() {
        if(empty())
            return -1;
        while(stack2.empty())
        {
            while(!stack1.empty())
            {
                int tmp = stack1.top();
                stack1.pop();
                stack2.push(tmp);
            }
        }
        return stack2.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return stack1.empty() && stack2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */
