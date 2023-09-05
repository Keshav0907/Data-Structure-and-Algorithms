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
        if(!root) return NULL;
        Node* root1=root;
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            
            int size = q.size();
            while(size > 0) {
                Node* f; 
               if(size > 1) {
                f = q.front();
                q.pop();
                Node* nxt = q.front();
                f->next = nxt;  
               } else {
                   f =q.front();
                   q.pop();
               }
                
                if(f->left) q.push(f->left);
                if(f->right) q.push(f->right);
                size--;
            }
        }
      
       return root;
    }
};