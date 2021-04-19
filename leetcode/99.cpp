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
    void recoverTree(TreeNode* root) {
        vector<pair<TreeNode*, int>> arr;
        helper(root, arr);
        vector<int> foo; 
        for(int i = 0; i < arr.size()-1; i++){
            if(arr[i].second >= arr[i+1].second) foo.push_back(i);
        }
        if(foo.size() == 1){
            int tmp = arr[foo[0]].first->val;
            arr[foo[0]].first->val = arr[foo[0]+1].first->val;
            arr[foo[0]+1].first->val = tmp;
        }else{
            int tmp = arr[foo[0]].first->val;
            arr[foo[0]].first->val = arr[foo[1]+1].first->val;
            arr[foo[1]+1].first->val = tmp;

        }
        
    }

    void helper(TreeNode* root, vector<pair<TreeNode*, int>>& arr){
        if(root == nullptr) return ;
        helper(root->left, arr);
        arr.push_back(make_pair(root, root->val));
        helper(root->right, arr);
    }
};