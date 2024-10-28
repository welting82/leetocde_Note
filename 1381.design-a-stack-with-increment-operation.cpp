/*
 * @lc app=leetcode id=1381 lang=cpp
 *
 * [1381] Design a Stack With Increment Operation
 */

// @lc code=start
class CustomStack {
public:
    vector<int> tbl;
    int idx = -1;
    CustomStack(int maxSize) {
        tbl.resize(maxSize,0);
    }
    
    void push(int x) {
        if(idx < (int)tbl.size() - 1) tbl[++idx] = x;
        return;
    }
    
    int pop() {
        return (idx == -1)?-1:tbl[idx--];
    }
    
    void increment(int k, int val) {
        for(int i = 0; i < k; i++)
        {
            if(i > idx) break;
            tbl[i] += val;
        }
        return;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
// @lc code=end
