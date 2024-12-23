#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <cmath>
#include <sstream>
#include <iostream>
#include <limits.h>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <bitset>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};