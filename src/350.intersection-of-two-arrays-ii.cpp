/*
 * @lc app=leetcode id=350 lang=cpp
 *
 * [350] Intersection of Two Arrays II
 */

// @lc code=start
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        int idx1 = 0, idx2 = 0;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());

        while(idx1 < nums1.size() && idx2 < nums2.size())
        {
            if(nums1[idx1] == nums2[idx2])
            {
                res.push_back(nums1[idx1]);
                idx1++,idx2++;
            }
            else if(nums1[idx1] > nums2[idx2]) idx2++;
            else idx1++;
        }

        return res;
    }
};
// @lc code=end
/*
[1,2,2,1]\n
[2,2]\n
[4,9,5]\n
[9,4,9,8,4]\n
*/
