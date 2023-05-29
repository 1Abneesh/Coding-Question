#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode < T > *left;
        BinaryTreeNode < T > *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
int chil_tree(BinaryTreeNode< int >* root){
    if(root == NULL){
        return -1;
    }
    int lft = 0;
    int rit = 0;
    if (root->left != NULL) {
        lft = root->left->data;
    }
     if (root->right != NULL) {
        rit = root->right->data ;
    }

    if (root->data > lft + rit) {
      if (root->left != NULL) {
          root->left->data = root->data;
      }
      if (root->right != NULL) {
          root->right->data = root->data;
      }
    } 
    else {
      root->data = lft + rit;
    }

   int left= chil_tree(root->left);
   int right= chil_tree(root->right);
   if(left !=-1 and right != -1){
            root->data = left + right;
   }
   else if(left !=-1){
        root->data  = left;
   }
   else if(right !=-1){
        root->data  = right;
   }
   return root->data;
}
void changeTree(BinaryTreeNode < int > * root) {
    // Write your code here.
    if (root != NULL) {
        chil_tree(root);
    }
    
}  