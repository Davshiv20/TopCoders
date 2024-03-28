#include <iostream>
using namespace std;

class ListNode {
public:
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* oddEvenList(ListNode* head) {
    if (!head || !head->next) return head;

    ListNode *oddHead = head;
    ListNode *evenHead = head->next;
    ListNode *odd = oddHead;
    ListNode *even = evenHead;

    while (even && even->next) {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }

    odd->next = evenHead;

    return oddHead;
}

void printList(ListNode *head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int n;
    // cout << "Enter the number of elements: ";
    cin >> n;

    ListNode *head = nullptr;
    ListNode *tail = nullptr;

    // cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        if (!head) {
            head = new ListNode(num);
            tail = head;
        } else {
            tail->next = new ListNode(num);
            tail = tail->next;
        }
    }

    // cout << "Original list: ";
    // printList(head);

    ListNode *reorderedHead = oddEvenList(head);

    // cout << "Reordered list: ";
    printList(reorderedHead);

    while (reorderedHead) {
        ListNode *temp = reorderedHead;
        reorderedHead = reorderedHead->next;
        delete temp;
    }

    return 0;
}
