// brief about doubly linkedlist
#include <iostream>

using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        this->data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

class DoublyList {
    Node* head;
    Node* tail;
    
    public:
    DoublyList() {
        head = tail = NULL;
    }

    void push_front(int val) {
        Node* newNode = new Node(val);
        if(head == NULL) {
            head = tail = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    void push_back(int val) {
        Node* newNode = new Node(val);
        if(head == NULL) {
            this->push_front(val);
        }
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }

    void pop_front() {
        if(head == NULL) return;
        Node* temp = head;

        head = head->next;
        if(head->prev != NULL) head->prev = NULL;
        temp->next = NULL;

        delete temp;
    }

    void pop_back() {
        if(head == NULL) return;
        Node* temp = tail;
        tail = tail->prev;
        if(tail != NULL) tail->next = NULL;
        temp->prev = NULL;

        delete temp;
    }    

    void display_from_front() {
        Node* temp = head;
        while(temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void display_from_back() {
        Node* temp = tail;
        while(temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->prev;
        }
        cout << "NULL" << endl;
    }
};

int main() {

    DoublyList dll;
    dll.push_front(5);
    dll.push_front(4);
    dll.push_front(3);
    dll.push_front(2);
    dll.push_front(1);

    dll.push_back(6);
    dll.push_back(7);

    dll.display_from_front();

    dll.pop_front();
    dll.pop_front();

    dll.display_from_front();

    dll.pop_back();
    dll.pop_back();

    dll.display_from_front();
    dll.display_from_back();

    return 0;
}