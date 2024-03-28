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

Node *insert(Node *root, const vector<string> &vals)
{

    //     if (vals[i] != "N")
    //     {
    //         parent->left = new Node(stoi(vals[i]));
    //         q.push(parent->left);
    //     }
    //     ++i;

    //     if (i < vals.size() && vals[i] != "N")
    //     {
    //         parent->right = new Node(stoi(vals[i]));
    //         q.push(parent->right);
    //     }
    //     ++i;
    // }

    // return root;
    if (vals.empty())
    {
        return NULL;
    }
    queue<Node *> q;
    root = new Node(stoi(vals[0]));
    q.push(root);
    int i = 1;
    while (!q.empty() && i < vals.size())
    {
        Node *parent = q.front();
        q.pop();
        if (vals[i] != "N")
        {
            parent->left = new Node(stoi(vals[i]));
            q.push(parent->left);
        }
        ++i;
        if (i < vals.size() && vals[i] != "N")
        {
            parent->right = new Node(stoi(vals[i]));
            q.push(parent->right);
        }
        ++i;
    }
    return root;
}

void inorderTraversal(Node *root)
{
    if (!root)
        return;

    cout << root->data << " ";
    inorderTraversal(root->left);
    inorderTraversal(root->right);
}

int main()
{
    string ip;
    getline(cin, ip);
    stringstream st(ip);
    vector<string> ans;
    string temp;

    while (st >> temp)
    {
        ans.push_back(temp);
    }

    Node *root = insert(nullptr, ans);

    cout << "Inorder Traversal of the constructed tree: ";
    inorderTraversal(root);

    return 0;
}
