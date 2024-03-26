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
bool palindromeOrNot(Node *list)
{
    if (list == NULL || list->next == NULL)
    {
        return true;
    }
    Node *temp = list;
    Node *fast = list;
    Node *slow = temp;
    while (fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node *p = slow->next;
    slow->next = NULL;
    Node *prev = NULL;
    Node *forw;
    while (p)
    {
        forw = p->next;
        p->next = prev;
        prev = p;
        p = forw;
    }
    while (prev and temp)
    {
        if (prev->data != temp->data)
        {
            return false;
        }
        prev = prev->next;
        temp = temp->next;
    }
    return true;
}
int main()
{
    int n;
    cin >> n;
    vector<int> list(n);
    for (int i = 0; i < n; i++)
    {
        cin >> list[i];
    }
    Node *l = NULL;
    for (int i = n - 1; i >= 0; i--)
    {
        Node *newNode = new Node(list[i]);
        newNode->next = l;
        l = newNode;
    }
    if (palindromeOrNot(l))
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }
}