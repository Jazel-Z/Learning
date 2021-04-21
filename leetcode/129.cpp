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
    int ans = 0;
    int sumNumbers(TreeNode* root) {
        dfs(root, {});
        return ans;
    }

    void dfs(TreeNode* root, vector<int> cur){
        if(root->left == nullptr && root->right == nullptr){
            cur.push_back(root->val);
            int n = cur.size();
            for(int i = n-1; i > -1; i--){
                ans += cur[i]*pow(n-i-1);
            }
            return ;
        }
        vector<int> next(cur.begin(), cur.end());
        next.push_back(root->val);
        if(root->left != nullptr) dfs(root->left, next);
        if(root->right != nullptr) dfs(root->right, next);
    }

    int pow(int n){
        int ret = 1;
        for(int i =0; i <n; i++){
            ret *= 10;
        }
        return ret;
    }
};