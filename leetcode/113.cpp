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
    vector<vector<int>> ans;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        helper(root,targetSum,{});
        return ans;
    }

    void helper(TreeNode* root, int targetSum,vector<int>arr){
        if(root == nullptr) return ;
        
        arr.push_back(root->val);
        if(root->left == nullptr && root->right == nullptr && (root->val - targetSum) == 0){
            ans.push_back(arr);
        }
        helper(root->left, targetSum-root->val,arr);
        helper(root->right, targetSum-root->val,arr);

    }
};