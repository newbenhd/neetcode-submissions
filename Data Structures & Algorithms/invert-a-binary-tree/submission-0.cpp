/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr)
            return nullptr;
        vector<TreeNode *> stack; 
        stack.push_back(root);
        while (!stack.empty())
        {
            TreeNode *node = stack.back(); // pre-order dfs
            stack.pop_back();
            TreeNode *temp = node->right;
            node->right = node->left;
            node->left = temp;
            if (node->left != nullptr)
                stack.push_back(node->left);
            if (node->right != nullptr)
                stack.push_back(node->right);
        }
        return root;
    }
};
