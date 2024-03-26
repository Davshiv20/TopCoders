#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct compare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<ListNode*, vector<ListNode*>, compare> pq;
    
    for (ListNode* list : lists) {
        if (list) pq.push(list);
    }
    
    ListNode* dummy = new ListNode(0);
    ListNode* tail = dummy;
    
    while (!pq.empty()) {
        ListNode* minNode = pq.top();
        pq.pop();
        
        tail->next = minNode;
        tail = minNode;
        
        if (minNode->next) pq.push(minNode->next);
    }
    
    return dummy->next;
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int k;
    cin >> k;
    
    vector<ListNode*> lists(k, nullptr);
    int val;
    
    for (int i = 0; i < k; ++i) {
        cin >> val;
        ListNode* head = nullptr;
        ListNode* current = nullptr;
        while (val != -1) {
            ListNode* newNode = new ListNode(val);
            if (!head) {
                head = newNode;
                current = newNode;
            } else {
                current->next = newNode;
                current = newNode;
            }
            cin >> val;
        }
        lists[i] = head;
    }
    
    ListNode* mergedList = mergeKLists(lists);
    
    printList(mergedList);
    
    return 0;
}