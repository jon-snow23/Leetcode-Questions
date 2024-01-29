class MyQueue {
public:
    stack<int> st;
    MyQueue() {
    }
    
    void push(int x) {
        st.push(x);
    }
    
    int pop() {
        stack<int> temp;
        int n=st.size();
        for(int i=0;i<(n-1);i++){
            temp.push(st.top());
            st.pop();
        }
        int res=st.top();
        st.pop();
        for(int i=0;i<(n-1);i++){
            st.push(temp.top());
            temp.pop();
        }
        return res;
    }
    
    int peek() {
        stack<int> temp;
        int n=st.size();
        for(int i=0;i<n-1;i++){
            temp.push(st.top());
            st.pop();
        }
        int res=st.top();
        for(int i=0;i<(n-1);i++){
            st.push(temp.top());
            temp.pop();
        }
        return res;
    }
    
    bool empty() {
        return st.empty();
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