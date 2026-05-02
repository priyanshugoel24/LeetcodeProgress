// Last updated: 02/05/2026, 22:46:54
class MinStack {
public:
    stack<pair<int,int>> st;

    MinStack() {
        
    }
    
    void push(int val) {
        
        if(st.empty()){
            st.push({val, val});
            return;
        }

        int currMin = st.top().second;

        if(val < currMin){
            currMin = val;
        }

        st.push({val, currMin});
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        int top = st.top().first;
        return top;
    }
    
    int getMin() {
        
        return st.top().second;
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