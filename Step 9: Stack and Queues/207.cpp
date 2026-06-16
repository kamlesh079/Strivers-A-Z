// https://leetcode.com/problems/min-stack/

// #####  Using Stack #####
class MinStack {
public:
    stack<pair<int, int>> st;
    MinStack() {
        
    }
    
    void push(int value) {
        if(st.empty())
            st.push({value, value});
        else
            st.push({value, st.top().second < value ? st.top().second : value});
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */


// #####  Using Vector as a Stack #####
class MinStack {
public:
    vector<pair<int, int>> v;
    MinStack() {
        
    }
    
    void push(int val) {
        if(v.empty()){
            v.push_back({val, val});
            return;
        }
        v.push_back({val, v.back().second < val ? v.back().second : val});
    }
    
    void pop() {
        v.pop_back();
        return;
    }
    
    int top() {
        return v.back().first;
    }
    
    int getMin() {
        return v.back().second;
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