#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *right;
    Node *left;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};
Node *insert(Node *root, vector<int> &vals)
{
    if (vals.empty())
    {
        return NULL;
    }
    queue<Node *> q;
    root = new Node(vals[0]);
    int i = 1;
    q.push(root);
    while (!q.empty() && i < vals.size())
    {
        Node *parent = q.front();
        q.pop();
        if (vals[i])
        {
            parent->left = new Node(vals[i]);
            q.push(parent->left);
        }
        ++i;
        if (vals[i])
        {
            parent->right = new Node(vals[i]);
            q.push(parent->right);
        }
        ++i;
    }
    return root;
}
bool validateBst(Node *root, Node *prev)
{
    if (!root)
    {
        return true;
    }
    if(!validateBst(root->left, prev)){
        return false;
    }
    if(prev && prev->data>=root->data)
    {
        return false;
    }
    prev=root;
    return validateBst(root->right, prev);
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    Node *root = NULL;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    Node *prev = NULL;
    root = insert(root, arr);
    if (validateBst(root,   prev))
    {
        cout<<"True";
    }
    else{
        cout<<"False";
    }
}