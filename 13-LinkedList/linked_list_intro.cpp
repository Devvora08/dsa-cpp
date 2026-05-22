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

class LinkedList
{
    Node *head;
    Node *tail;

public:
    LinkedList()
    {
        head = tail = NULL;
    }
    void display()
    {
        Node *temp = head;

        while (temp != NULL)
        {
            cout << temp->val << " -> ";
            temp = temp->next;
        }

        cout << "NULL" << endl;
    }

    void push_back(int val)
    {
        // base case if list = 0
        if(head == NULL) push_front(val);

        Node* newNode = new Node(val);
        newNode->next = NULL;
        // approach - replace the tail node with new node as tail
        Node* temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        // temp is now pointing to last element
        temp->next = newNode;
        tail = newNode;
    }

    void pop_back()
    {
        if(head == NULL) {
            return;
        }
        if(head == tail) {
            delete head;
            head = tail = NULL;
            return;
        }
        Node* temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        delete tail;
        tail = temp;
        tail->next = NULL;
    }

    void push_front(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
            return;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    void pop_front()
    {
        if (head == NULL)
        {
            return;
        }

        Node *temp = head;
        head = head->next;

        if (head == NULL)
        {
            tail = NULL;
        }

        delete temp;
    }

    void insert_middle(int val, int pos)
    {
        if (pos < 0)
        {
            cout << "Invalid pos" << endl;
            return;
        }

        if (pos == 0)
        {
            push_front(val);
            return;
        }

        Node *temp = head;
        for (int i = 0; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        Node *newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void remove_pos(int val) {
        if(head == NULL) return;

        Node* temp = head;
        int pos = 0;
        while(temp != NULL && temp->val != val) {
            temp = temp->next;
            pos++;
        }

        if(temp == NULL) return;

        if(pos == 0) {
            pop_front();
            return;
        }

        if(temp->next == NULL) {
            pop_back();
            return;
        }

        Node* prev = head;

        for(int i = 0; i < pos-1; i++) {
            prev = prev->next;
        }

        // now we have prev, and temp
        prev->next = temp->next;
        delete temp;
    }

    int search(int key)
    {
        Node *temp = head;
        if (head == NULL)
            return -1;
        int counter = 0;

        while (temp != NULL)
        {
            if (temp->val == key)
                return counter;

            temp = temp->next;
            counter++;
        }

        return -1;
    }
};

int main()
{
    LinkedList ll;

    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    ll.push_back(4);
    ll.push_back(5);

    ll.display();

    ll.remove_pos(4);
    ll.display();
    

    return 0;
}