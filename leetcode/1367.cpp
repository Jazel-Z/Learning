class Solution {
public:
    vector<TreeNode*> tar;
    bool isSubPath(ListNode* head, TreeNode* root) {
        bool ans = false;
        getall(root, head->val);
        for( TreeNode* tn : tar){
            ans |= isgood(tn,head);
        }
        return ans;
    }

    void getall(TreeNode* root, int val){
        if(root == nullptr) return;
        if(root->val == val) tar.push_back(root);
        getall(root->left,val);
        getall(root->right,val);
    }
    bool isgood(TreeNode* root, ListNode* head){
        if(root == nullptr) return false;
        if(root->val == head->val){
            if(head->next == nullptr) return true;
            return isgood(root->right, head->next) || isgood(root->left, head->next);
        }
        else{
            return false;
        }
    }

};
