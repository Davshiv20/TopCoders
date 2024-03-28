#include <iostream>
#include <queue>
#include <algorithm> // for max function
using namespace std;

// Definition of Node class
class Node {
public:
    int data;
    Node *left;
    Node *right;
    Node(int data) : data(data), left(nullptr), right(nullptr) {}
};

// Function to insert a node into BST
Node* insert(Node* root, int data) {
    if (!root) {
        return new Node(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

// Function to calculate height of a binary tree
int height(Node* root) {
    if (!root)
        return 0;
    return 1 + max(height(root->left), height(root->right));
}

// Function to calculate diameter of a binary tree
int diameter(Node* root) {
    if (!root)
        return 0;
    
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    
    int leftDiameter = diameter(root->left);
    int rightDiameter = diameter(root->right);
    
    return max({leftHeight + rightHeight + 1, leftDiameter, rightDiameter});
}

int main() {
    // Input
    int val;
    Node* root = nullptr;
   // cout << "Enter the node values (enter -1 to terminate input):" << endl;
    while (true) {
        cin >> val;
        if (val == -1)
            break;
        root = insert(root, val);
    }

    // Calculate diameter of the binary tree
    int treeDiameter = diameter(root);
    cout << treeDiameter << endl;

    // Clean up
    // To delete the entire tree, a separate function is needed to free the memory allocated to each node.
    // This is typically implemented using a post-order traversal of the tree.
    // For simplicity, we skip cleanup in this example.

    return 0;
}
