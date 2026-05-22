// classical - reverse a given linkedlist
// approach - use 3 pointers - prev, current, next
#include <iostream>

using namespace std;

class Node
{
public:
    int val;
    Node *next;

    Node(int v)
    {
        this->val = v;
        this->next = NULL;
    }
};

// approach - 4 step
// prev = null, current = head, next = null
// 1. next = current.next, 2. current.next = prev, 3. next = curr.next, curr.next = prev, prev = curr, cur = next
// till current = null. at end, 4. prev = head

// code will be summed up to its actual leetcode question
class ReverseList {
    Node* head;
    
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;

    Node* reverse(Node* head) {
        while (current!= NULL)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        return prev;
    }
    
};

int main() {
    return 0;
}