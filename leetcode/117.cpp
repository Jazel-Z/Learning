/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL) return NULL;
        queue<Node*> q;
        q.push(root);
        q.push(new Node(1001));
        while(!q.empty()){
            Node* tmp = q.front();
            q.pop();
            if(tmp->val == 1001) continue;
            if(q.front()->val == 1001){
                if(tmp->left != NULL)   q.push(tmp->left) ;
                if(tmp->right != NULL)   q.push(tmp->right) ;
                q.push(new Node(1001));
                tmp->next = NULL;
            }else{
                if(tmp->left != NULL)   q.push(tmp->left) ;
                if(tmp->right != NULL)   q.push(tmp->right) ;
                tmp->next = q.front();
            }
        }

        return root;
    }
};