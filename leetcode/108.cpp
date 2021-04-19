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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 2){
            TreeNode* root = new TreeNode(nums[1]);
            root->left = new TreeNode(nums[0]);
            return root;
        }
        if(nums.size() == 1) return new TreeNode(nums[0]);
        TreeNode* root = new TreeNode();
        if(nums.size() % 2 == 0){
            vector<int>vleft(nums.begin(), nums.begin()+nums.size()/2-1);
            vector<int>vright(nums.begin()+nums.size()/2, nums.end());
            root->val = nums[nums.size()/2 -1];
            root->left = sortedArrayToBST(vleft);
            root->right = sortedArrayToBST(vright);
        }else{
            vector<int>vleft(nums.begin(), nums.begin()+ (nums.size()+1)/2-1);
            vector<int>vright(nums.begin()+(nums.size()+1)/2,nums.end());
            root->val = nums[(nums.size()+1)/2-1];
            root->left = sortedArrayToBST(vleft);
            root->right = sortedArrayToBST(vright);
        }
        return  root;
    }
};