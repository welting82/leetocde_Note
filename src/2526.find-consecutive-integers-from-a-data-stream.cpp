/*
 * @lc app=leetcode id=2526 lang=cpp
 *
 * [2526] Find Consecutive Integers from a Data Stream
 */

// @lc code=start
class DataStream {
public:
    int val, cnt, K;
    DataStream(int value, int k) {
        cnt = 0;
        K = k;
        val = value;
    }
    
    bool consec(int num) {
        cnt = (num == val)? cnt + 1: 0;
        return cnt >= K;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */
// @lc code=end

