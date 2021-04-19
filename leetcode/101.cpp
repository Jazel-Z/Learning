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
    bool isSymmetric(TreeNode* root) {
        return helper(root->left,root->right);
    }

    bool helper(TreeNode* tn1, TreeNode* tn2){
        if(tn1 == nullptr && tn2 == nullptr) return true;
        if((tn1 == nullptr && tn2 != nullptr) || tn1 != nullptr && tn2 == nullptr) return false;

        return  tn1->val == tn2->val && helper(tn1->left, tn2->right) && helper(tn1->right,tn2->left);
        
    }
};