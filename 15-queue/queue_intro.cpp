#include <queue>
#include <vector>
#include <iostream>
#include <deque>

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

class Queue_ds {
    public:
    Node* head;
    Node* tail;

    Queue_ds() {
        head = tail = NULL;
    }

    // methods
    void push(int val) {
        // push from tail
        Node* newNode = new Node(val);
        if(head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }

    }

    void pop() {    
        // pop from head
        if(this->empty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;

        delete temp;
    }

    int front() {
        // return head.next
        if(this->empty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return head->val;
    }

    bool empty() {  
        // return size == 0
        return head == NULL;
    }

    void display() {
        Node* temp = head;
        while(temp != NULL) {
            cout << temp->val << "->";
            temp = temp->next;
        }
        cout << "NULL" <<endl;
    }
};

int main() {
    Queue_ds q;

    q.push(5);
    q.push(10);
    q.push(15);

    q.display();
    q.pop();
    q.pop();

    q.display();

    deque<int> dq;
    
    dq.push_back(1);
    dq.push_front(2);
    
    for(int i : dq) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}