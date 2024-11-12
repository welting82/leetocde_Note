/*
 * @lc app=leetcode id=1352 lang=cpp
 *
 * [1352] Product of the Last K Numbers
 */

// @lc code=start
class ProductOfNumbers {
public:
    vector<int> tbl;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        tbl.push_back(num);
    }
    
    int getProduct(int k) {
        int sum = 1, idx = tbl.size() - 1;
        while(idx > -1 && k > 0)
        {
            sum *= tbl[idx--];
            if(sum == 0) break;
            k--;
        }
        return sum;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
// @lc code=end
/*
*/
