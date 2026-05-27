#include <iostream>

using namespace std;

// You are given a doubly linked list, which contains nodes that have a next pointer, a previous pointer, and an additional child pointer. This child pointer may or may not point to a separate doubly linked list, also containing these special nodes. These child lists may have one or more children of their own, and so on, to produce a multilevel data structure as shown in the example below.
// Given the head of the first level of the list, flatten the list so that all the nodes appear in a single-level, doubly linked list. Let curr be a node with a child list. The nodes in the child list should appear after curr and before curr.next in the flattened list.
// Return the head of the flattened list. The nodes in the list must have all of their child pointers set to null.

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node(int val) {
        this->val = val;
    }
};

Node* flatten(Node* head) {
    if(head == NULL) return head;

    Node* curr = head;
    while(curr != NULL) {
        // before next, first check if child node
        if(curr->child != NULL) {
            //flatten the child nodes
            Node* next = curr->next;
            curr->next = flatten(curr->child);
            curr->next->prev = curr;
            curr->child = NULL;

            // find the tail
            while(curr->next != NULL) {
                curr = curr->next;
            }
            // attach the tail with next ptr
            if(next != NULL) {
                curr->next = next;
                next->prev = curr;
            }
        }
        curr = curr->next;
    }

    return head;
}

int main() {
    return 0;
}