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

Node *reverse(Node *start, Node *end)
{
    Node *prev = start;
    Node *curr = start->next;
    while (curr != end)
    {
        Node *forw = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forw;
    }
    start->next->next = curr; // Update start's next next to curr
    start->next = prev;       // Update start's next to prev
    return prev;              // Return prev, which is now the new head of the reversed sublist
}

void PrintList(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << endl;
        head = head->next;
    }
    cout << endl;
}
int sizeOfNode(Node *head)
{
    Node *curr_head = head;
    int count = 0;
    while (curr_head != NULL)
    {
        count += 1;
        curr_head = curr_head->next;
    }
    return count;
}
Node *reverseKGroup(Node *head, int k)
{

    int listSize = sizeOfNode(head);

    if (listSize < k)
    {
        return head;
    }

    Node *dummy = new Node(0);
    dummy->next = head;
    Node *prevTail = dummy;
    Node *currHead = head;

    while (listSize >= k)
    {
        Node *prev = nullptr;
        Node *curr = currHead;
        Node *forw = nullptr;

        for (int i = 0; i < k; i++)
        {
            forw = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forw;
        }

        Node *tail = prevTail->next;
        prevTail->next = prev;
        tail->next = curr;
        prevTail = tail;
        currHead = curr;
        listSize -= k;
    }

    return dummy->next;
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
    int groups;
    cin >> groups;

    Node *l = NULL;
    for (int i = v.size()-1; i >=0; i--)
    {
        Node *newNode = new Node(v[i]);
        newNode->next = l;
        l = newNode;
    }

    // Node *head = reverse_k_nodes(l, groups);
    //   cout<<"Print:"<<endl;
    Node* head=reverseKGroup(l,groups);
    PrintList(head);

    return 0;
}
