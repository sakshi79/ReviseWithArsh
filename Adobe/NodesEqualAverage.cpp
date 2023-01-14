// Question link: https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/

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
    int res = 0;
    int sub_sum(TreeNode *root, int &n)
    {
        if(!root)
            return 0;
        if(root->left)
            n++;
        if(root->right)
            n++;   
        int left = sub_sum(root->left, n);
        int right = sub_sum(root->right, n);
        return root->val + left + right;
    }
    void num_nodes(TreeNode *root)
    {
        if(!root)
            return;
        int n = 1;
        if(root->val == (sub_sum(root, n)/n))
            res++;
        num_nodes(root->left);
        num_nodes(root->right);  
        return;      
    }
public:
    int averageOfSubtree(TreeNode* root) {
        num_nodes(root);
        return res;
    }
};
