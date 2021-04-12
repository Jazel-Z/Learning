#define rep(i,n,j) for(int i = n; i < j; i++)

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        return getnext(1,n);
    }

    vector<TreeNode*>getnext(int m , int n){
        if(m > n){
            return {nullptr};
        }
        if(m == n){
            return {new TreeNode(n)};
        }
        vector<TreeNode*> ans;

        rep(i,m,n+1){
            vector<TreeNode*> le = getnext(m,i-1);
            vector<TreeNode*> ri = getnext(i+1,n);
            for(TreeNode* lef : le){
                for(TreeNode* rig : ri ){
                    TreeNode* tmp = new TreeNode(i);
                    tmp->left = lef;
                    tmp->right = rig;
                    ans.push_back(tmp);
                }
            }
        }
        
        return ans;
    }
};
