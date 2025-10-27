#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};


void displayList(Node* head) {
    Node* temp = head;
    if (temp == NULL) {
        cout << "List is emty.\n";
        return;
    }
    cout << "List: ";
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}


Node* reverseList(Node* head) {
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;

    while (current != NULL) {
        next = current->next; 
        current->next = prev; 
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}

int main() {
    
    Node* head = new Node();
    Node* n2 = new Node();
    Node* n3 = new Node();
    Node* n4 = new Node();
    
    head->data = 1; head->next = n2;
    n2->data = 2; n2->next = n3;
    n3->data = 3; n3->next = n4;
    n4->data = 4; n4->next = NULL;

    cout << "Orignl List:\n";
    displayList(head);

    head = reverseList(head);
    
    cout << "\nReversd List:\n";
    displayList(head);

    return 0;
}
