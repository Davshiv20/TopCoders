#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node(int x){
            data=x;
            next=NULL;
        }
};

Node* mergeTwoSortedLists(Node* l1,Node* l2)
{
    if(!l1) return l2;
    if(!l2) return l1; 
    Node* merge=NULL;
    if(l1->data<=l2->data)
    {
        merge=l1;
        merge->next=mergeTwoSortedLists(l1->next,l2);
    }
    else{
        merge=l2;
        merge->next=mergeTwoSortedLists(l1,l2->next);
    }
}
void printMergedList(Node* node)
{
    while(node!=NULL)
    {
        cout<<node->data<<"->";
        node=node->next;
    }
    cout<<"NULL"<<endl;
}
int main(){
    int n,m;
    cin>>n;
    vector<int>list1(n);
    for(int i=0;i<n;i++)
    {
        cin>>list1[i];
    }
    cin>>m;
    vector<int>list2(m);
    for(int i=0;i<m;i++)
    {
        cin>>list2[i];
    }
     Node* l1 = nullptr;
    for (int i = n - 1; i >= 0; --i) {
        Node* newNode = new Node(list1[i]);
        newNode->next = l1;
        l1 = newNode;
    }

    // Creating the second sorted linked list
    Node* l2 = nullptr;
    for (int i = m - 1; i >= 0; --i) {
        Node* newNode = new Node(list2[i]);
        newNode->next = l2;
        l2 = newNode;
    }

    Node* mergedList = mergeTwoSortedLists(l1, l2);

    // Print the merged sorted list
    printMergedList(mergedList);

    // Clean up memory
    // while (mergedList) {
    //     Node* temp = mergedList;
    //     mergedList = mergedList->next;
    //     delete temp;
    // }

    // return 0;

}