#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node(int x)
    {
        this->val = x;
        left = NULL;
        right = NULL;
    }
};

void bfs(Node *root)
{
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int n = q.size();
        while (n != 0)
        {
            Node *print = q.front();
            q.pop();
            cout << print->val << " ";
            n--;
            if (print->left != NULL)
            {
                q.push(print->left);
            }
            if (print->right != NULL)
            {
                q.push(print->right);
            }
        }
        cout << "\n";
    }
}

void dfs_pre(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->val << " ";
    dfs_pre(root->left);
    dfs_pre(root->right);
}

void dfs_in(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    dfs_in(root->left);
    cout << root->val << " ";
    dfs_in(root->right);
}

void dfs_post(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    dfs_post(root->left);
    dfs_post(root->right);
    cout << root->val << " ";
}
void df_preo_order_Rec(Node* root){
    stack<Node*> st;
    st.push(root);
    while(!st.empty()){
        Node* ty = st.top();
        st.pop();
        cout<<ty->val<<" ";
        if(ty->right!=NULL){
            st.push(ty->right);
        }
        if(ty->left!=NULL){
            st.push(ty->left);
        }
    }
}
void dfs_inorder_iterative(Node* root){
    stack<Node*> st1;
    Node* cur = root;
    while(cur != NULL || !st1.empty()){
        if(cur != NULL){
            st1.push(cur);
            cur = cur->left;
        }
        else{
            cur = st1.top();
            st1.pop();
            cout << cur->val << " ";
            cur = cur->right;
        }
    }
}


Node *create()
{
    cout << "Enter a value :- ";
    int x;
    cin >> x;
    if (x == -1)
    {
        return 0;
    }
    Node *root = new Node(x);
    cout << "Enter the value for left node: -";
    root->left = create();
    cout << "Enter the value for right noe :-";
    root->right = create();
    return root;
}
int chil_tree(Node* root){
    if(root == NULL){
        return -1;
    }

   int left= chil_tree(root->left);
   int right= chil_tree(root->right);
   if(left !=-1 and right != -1){
            root->val = left + right;
   }
   else if(left !=-1){
        root->val  = left;
   }
   else if(right !=-1){
        root->val  = right;
   }
   return root->val;
}

int main()
{
    Node *root = create();
    chil_tree(root);

    bfs(root);
    // cout << "Inorder\n";
    // dfs_inorder_iterative(root);
    // cout << "\nPreorder\n";
    // df_preo_order_Rec(root);
    // cout << "\npostorder\n";
    // dfs_post(root);
    return 0;
}