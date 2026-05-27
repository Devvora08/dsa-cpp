#include <iostream>

using namespace std;

// Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.
// k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.
// You may not alter the values in the list's nodes, only nodes themselves may be changed.

// Input: head = [1,2,3,4,5], k = 3
// Output: [3,2,1,4,5]

class ListNode {
      public:
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// approach:

// check if K nodes exist
// recursively reverse rest of k group 
// reverse the current group and connect

ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* temp = head;
    int cnt = 0;
    while(cnt < k) {
        if(temp == NULL) {
            return head;
        }
        temp = temp->next;
        cnt++;
    }
    ListNode* prev = reverseKGroup(temp, k);
    
    temp = head, cnt = 0;
    while(cnt < k) {
        ListNode* next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
        cnt++;
    }
    return prev;
}

int main() {
    return 0;
}