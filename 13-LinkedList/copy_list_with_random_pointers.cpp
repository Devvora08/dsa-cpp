#include <iostream> 
#include <unordered_map>

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node* copyRandomList(Node* head) {
        if(head == NULL) return NULL;

        unordered_map<Node*, Node*> m;

        Node* newHead = new Node(head->val);
        Node* oldTemp = head->next;
        Node* newTemp = newHead;
        m[head]= newHead;

        while(oldTemp != NULL) {
            Node* copy = new Node(oldTemp->val);
            m[oldTemp] = copy;

            newTemp->next = copy;
            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }

        oldTemp = head; 
        newTemp = newHead;
        while(oldTemp!=NULL) {
            newTemp->random = m[oldTemp->random];
            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }

        return newHead;
}

int main() {

}