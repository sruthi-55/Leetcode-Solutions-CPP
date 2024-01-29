class MyQueue {
public:
    stack<int> st1;
    stack<int> st2;
    int peekEl = -1;
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        if(st1.empty())
            peekEl = x;
        st1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
		//O(n) only when st2 is empty()
        if(st2.empty()) {
            while(!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }    
        }
        
        int x = st2.top();
        st2.pop();
        return x;
    }
    
    /** Get the front element. */
    int peek() {
        return st2.empty() ? peekEl : st2.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return st1.empty() && st2.empty();
    }
};


