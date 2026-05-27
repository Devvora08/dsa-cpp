#include <iostream>

using namespace std;

class ListNode {
    public:
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* swapPairs(ListNode* head) {
    if(head == NULL || head->next == NULL) return head;

    ListNode* prev = NULL;
    ListNode* first = head;
    ListNode* second = first->next;

    while(first != NULL && second != NULL) {
        ListNode* third = second->next;
        second->next = first;
        first->next = third;

        if(prev != NULL) {
            prev->next = sec;
        } else head = second;

        // update
        prev = first;
        first = third;
        if(third != NULL) {
            second = third->next;
        } else {
            second = NULL;
        }
    }
    return head;
}

int main() {
    return 0;
}