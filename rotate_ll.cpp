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
int sze(Node *head)
{
    Node *curr = head;
    int count = 0;
    while (curr)
    {
        count += 1;
        curr = curr->next;
    }
    return count;
}
Node *rotateRight(Node *head, int k)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    int size = sze(head);
    k = k % size;
    int n = size - k;

    Node *curr = head;
    Node *dummy = new Node(0);
    dummy->next = head;
    Node *prev = NULL;
    Node *forw;
    for (int i = 0; i < n; i++)
    {
        forw = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forw;
    }
    Node *curr2 = prev;
    curr = forw;
    while (prev->next != NULL)
    {
        prev = prev->next;
    }
    Node *prev2 = NULL;
    for (int i = n; i < size; i++)
    {
        forw = curr->next;
        curr->next = prev2;
        prev2 = curr;
        curr = forw;
    }
    prev->next = prev2;
    Node *forw2;
    Node *prev3 = NULL;
    for (int i = 0; i < size; i++)
    {
        forw2 = curr2->next;
        curr2->next = prev3;
        prev3 = curr2;
        curr2 = forw2;
    }
    head = prev3;
    return head;
}
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
int main()
{
    vector<int> v;
    while (true)
    {
        int x;
        cin >> x;
        if (x == -1)
        {
            break;
        }

        v.push_back(x);
    }
    int k;
    cin >> k;
    int num = v.size();
    Node *l = NULL;
    for (int i = num-1; i >= 0; i--)
    {
        Node *newNode = new Node(v[i]);
        newNode->next = l;
        l = newNode;
    }
    int size = sze(l);
    cout << "Given linked list:" << endl;
    printList(l);
    Node *head = rotateRight(l, size - k);
    cout << "Rotated Linked list:" << endl;
    printList(head);
}
