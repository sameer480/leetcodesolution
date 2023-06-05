class Solution {
public:
    int rob(TreeNode* root) {
        std::vector<int> result = robSub(root);
        return std::max(result[0], result[1]);
    }

private:
    std::vector<int> robSub(TreeNode* root) {
        if (root == nullptr)
            return std::vector<int>(2, 0);

        std::vector<int> left = robSub(root->left);
        std::vector<int> right = robSub(root->right);

        std::vector<int> result(2, 0);
        result[0] = std::max(left[0], left[1]) + std::max(right[0], right[1]);
        result[1] = root->val + left[0] + right[0];

        return result;
    }
};
