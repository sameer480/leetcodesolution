#include <iostream>
#include <algorithm>
#include <climits>

// struct TreeNode {
//     int val;
//     TreeNode* left;
//     TreeNode* right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
// };

class Solution {
    int maxPathSum_util(TreeNode* root, int& result) {
        if (!root)
            return 0;

        int left = maxPathSum_util(root->left, result);
        int right = maxPathSum_util(root->right, result);

        int max_straight = std::max(std::max(left, right) + root->val, root->val);
        int max_caseVal = std::max(max_straight, left + right + root->val);
        result = std::max(max_caseVal, result); // CASE-3

        return max_straight;
    }

public:
    int maxPathSum(TreeNode* root) {
       
        int result = INT_MIN;
        maxPathSum_util(root, result);
        return result;
    }
};
