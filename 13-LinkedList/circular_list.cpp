// basics about circular linkedlist
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

class CircularList {
    Node* head;
    Node* tail;

    public:

    CircularList() {
        head = tail = NULL;
    }

    void insertAtBegin(int val) {
        Node* newNode = new Node(val);
        if(tail == NULL) {
            head = tail = newNode;
            tail->next = head;
            return;
        }
        newNode->next = head; 
        head = newNode;
        tail->next = head;
    }

    void display() {
        if(head == NULL) return;

        cout << head->val << " ->";
        Node* temp = head->next;
        
        while(temp!=head) {
            cout << temp->val << " ->";
            temp = temp->next;
        }
        cout << temp->val << endl;
    }
};

int main() {
    CircularList newci;

    newci.insertAtBegin(3);
    newci.insertAtBegin(2);
    newci.insertAtBegin(1);

    newci.display();

    return 0;
}