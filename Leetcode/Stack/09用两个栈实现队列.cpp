#include <bits/stdc++.h>

using namespace std;

class CQueue {
public:
    stack<int> stk, cache;
    void copy(stack<int>& a, stack<int>& b) {
        while (a.size()) {
            b.push(a.top());
            a.pop();
        }
    }
    CQueue() {

    }
    
    void appendTail(int value) {
        stk.push(value);
    }
    
    int deleteHead() {
        if (!stk.size()) return -1;
        copy(stk, cache);
        int x = cache.top();
        cache.pop();
        copy(cache, stk);
        return x;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */