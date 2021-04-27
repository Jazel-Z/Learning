/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class CBTInserter {
public:
    CBTInserter(TreeNode* root) {
        head = root;
        q.push(root);
        while(q.front()->left != NULL){
            q.push(q.front()->left);
            if(q.front()->right != NULL)q.push(q.front()->right);
            else break;
            q.pop();
        }
    }
    
    int insert(int v) {
        if(q.front()->left != NULL && q.front()->right != NULL){
            q.pop();
        }
        if(q.front()->left == NULL){
            q.front()->left = new TreeNode(v);
            q.push(q.front()->left);
            return q.front()->val;
        }
        if(q.front()->right == NULL){
            q.front()->right = new TreeNode(v);
            q.push(q.front()->right);
            return q.front()->val;
        }
        return -1;
    }
    
    TreeNode* get_root() {
        return head;
    }
    TreeNode* head;
    queue<TreeNode*> q;

};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */