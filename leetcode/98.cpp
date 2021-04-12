class Solution {
public:
    vector<int> ans;

    bool isValidBST(TreeNode* root) {
        getnode(root);
        for(int i =0; i < ans.size() -1; i++){
            if(ans[i] >= ans[i+1]) return false;
        }
        return true;
    }
        void getnode(TreeNode* root){
        if(root == nullptr) return;
        getnode(root->left);
        ans.push_back(root->val);
        getnode(root->right);
    }

};
