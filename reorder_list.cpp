#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
void printList(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
void reorder_list(Node *head)
{

    // if (!head || !head->next || !head->next->next)
    //     return;
    Node *slow = head;
    Node *fast = head;
    Node *temp = head;
    Node *left = head;
    // Node *dummy = NULL;
    // dummy->next = head;
    while (fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node *prev = NULL;
    Node *curr = slow->next;

    slow->next = NULL;
    while (curr)
    {
        Node *forw = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forw;
    }
    Node *first = head;
    Node *second = prev;
    while (first && second)
    {
        Node *nextFirst = first->next;
        Node *nextSecond = second->next;
        first->next = second;
        second->next = nextFirst;

        first = nextFirst;
        second = nextSecond;
    }
    // if (left)
    //     temp->next = left;
    // if (prev)
    //     temp->next = prev;
}
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    Node *l = NULL;
    for (int i = 0; i < n; i++)
    {
        Node *newNode = new Node(a[i]);
        newNode->next = l;
        l = newNode;
    }

    reorder_list(l);
    printList(l);
}