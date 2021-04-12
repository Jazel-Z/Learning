class Solution {
public:
    vector<int> ans;

    vector<int> inorderTraversal(TreeNode* root) {
        getnode(root);
        return ans;
    }

    void getnode(TreeNode* root){
        if(root == nullptr) return;
        getnode(root->left);
        ans.push_back(root->val);
        getnode(root->right);
    }
};
