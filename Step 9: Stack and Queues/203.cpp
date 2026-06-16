// https://leetcode.com/problems/implement-queue-using-stacks/

class MyQueue {
public:
    stack<int> s1, s2;
    MyQueue() {}

    void push(int x) { 
        s1.push(x); 
    }

    int pop() {
        int element = -1;
        if (!s2.empty())
            element = s2.top();
        else {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
            element = s2.top();
        }
        s2.pop();
        return element;
    }

    int peek() {
        int element = -1;
        if (!s2.empty()) {
            element = s2.top();
        } else {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
            element = s2.top();
        }
        return element;
    }

    bool empty() {
        return s1.empty() && s2.empty();
    }
};