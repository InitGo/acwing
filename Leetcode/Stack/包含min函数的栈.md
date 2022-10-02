### 包含min函数的栈
- 算法：我们除了维护基本的栈结构之外，还需要维护一个单调栈，来实现返回最小值的操作。
下面介绍如何维护单调栈：
  - 当向栈中压入一个数时，如果该数 ≤ 单调栈的栈顶元素，则将该数同时压入单调栈中；否则，不压入，这是由于栈具有先进后出性质，所以在该数被弹出之前，栈中一直存在一个数比该数小，所以该数一定不会被当做最小数输出。
  - 当我们从栈中弹出一个数时，如果该数等于单调栈的栈顶元素，则同时将单调栈的栈顶元素弹出。
  - 单调栈由于其具有单调性，所以它的栈顶元素，就是当前栈中的最小数。
  
- 时间复杂度
四种操作都只有常数次入栈出栈操作，所以时间复杂度都是 O(1).

```c++
class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> stk, stkmin;
    MinStack() {

    }
    
    void push(int x) {
        stk.push(x);
        if (stkmin.size() && stkmin.top() < x) x = stkmin.top();
        stkmin.push(x);
    }
    
    void pop() {
        stk.pop();
        stkmin.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int min() {
        return stkmin.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */
```