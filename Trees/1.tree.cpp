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
int main()
{
    Node *root = create();
    bfs(root);
    cout << "Inorder\n";
    dfs_in(root);
    cout << "\nPreorder\n";
    dfs_pre(root);
    cout << "\npostorder\n";
    dfs_post(root);
    return 0;
}