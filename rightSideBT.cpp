#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data) : data(data), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    vector<int> rightView(Node *root)
    {
        vector<int> result;
        if (root == nullptr)
        {
            return result;
        }

        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            int n = q.size();
            for (int i = 0; i < n; i++)
            {
                Node *curr = q.front();
                q.pop();
                if (i == n - 1)
                {
                    result.push_back(curr->data);
                }
                if (curr->left != nullptr)
                {
                    q.push(curr->left);
                }
                if (curr->right != nullptr)
                {
                    q.push(curr->right);
                }
            }
        }

        return result;
    }
};

Node *buildTree(const string &str)
{
    if (str.empty() || str[0] == 'N')
    {
        return nullptr;
    }

    stringstream ss(str);
    vector<string> ip;
    string temp;
    while (ss >> temp)
    {
        ip.push_back(temp);
    }

    Node *root = new Node(stoi(ip[0]));
    queue<Node *> q;
    q.push(root);
    size_t i = 1;
    while (!q.empty() && i < ip.size())
    {
        Node *currNode = q.front();
        q.pop();
        string currVal = ip[i];
        if (currVal != "N")
        {
            currNode->left = new Node(stoi(currVal));
            q.push(currNode->left);
        }
        i++;
        if (i >= ip.size())
        {
            break;
        }
        currVal = ip[i];
        if (currVal != "N")
        {
            currNode->right = new Node(stoi(currVal));
            q.push(currNode->right);
        }
        i++;
    }

    return root;
}

int main()
{
    // int t;
    // cin >> t;
    // cin.ignore();
    // while (t-- > 0) {
    string s;
    getline(cin, s);
    Node *root = buildTree(s);
    Solution tree;
    vector<int> arr = tree.rightView(root);
    for (int x : arr)
    {
        cout << x << " ";
    }
    cout << endl;
}
