// find the middle val of the list, could be odd/even sized
#include <iostream> 

using namespace std;

class Node {
    public:
    int val;
    Node* next;
    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
};

class FindMiddle {
    // approach - use slow-fast pointers, slow by 1 pos, fast by 2 pos. slow will reach mid when fast = null

    Node* head;
    public:
        int findMid(Node* head) {
            Node* slow = head;
            Node* fast = head;

            while(fast != NULL && fast->next != NULL) {
                slow = slow->next;
                fast = fast->next->next;
            }

            return slow->val;
        }
};

int main() {
    return 0;
}