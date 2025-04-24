#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
        int val;
        Node* left;
        Node* right;
        Node(int v){
            val = v;
            left=right=nullptr;
        }
};

bool isCompleteBinaryTree(Node* root) {
    if (root == nullptr)
        return true;

    queue<Node*> q;
    q.push(root);
    bool end = false; 

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        // Check left child
        if (current->left) {
            if (end) 
                return false;
            q.push(current->left);
        } 
       else {
         
            // If left child is missing,
         	// mark the end
            end = true;
        }

        // Check right child
        if (current->right) {
            if (end) 
                return false;
          
            q.push(current->right);
        } 
       else {
         
            // If right child is missing,
         	// mark the end
            end = true;
        }
    }

       return true; 
    }
    
    
    bool isMaxHeap(Node* root){
        if(!root) return true;
        if(root->left){
            if(root->val < root->left->val)
               return false;
        }
        if(root->right){
            if(root->val < root->right->val)
               return false;
        }
        bool a = isMaxHeap(root->left);
        bool b = isMaxHeap(root->right);
        if(!a || !b) return false;
        return true;
    }

    bool isHeap(Node* tree) {
        // code here
        return isCompleteBinaryTree(tree) && isMaxHeap(tree);
    }
int main() {
    
    return 0;
}
