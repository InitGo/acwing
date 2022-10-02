class MaxQueue {
public:
    int hh = 0, tt = -1;
    int q[10010];
    MaxQueue() {

    }
    
    int max_value() {
        int res = -1;
        for (int i = hh; i <= tt; i ++ ) 
            res = max(res, q[i]);
        return res;
    }
    
    void push_back(int value) {
        q[ ++ tt] = value;
    }
    
    int pop_front() {
        if (hh <= tt) return q[hh ++ ];
        else return -1;
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */