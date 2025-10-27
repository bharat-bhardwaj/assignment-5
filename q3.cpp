#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};


Node* findMiddle(Node* head) {
    if (head == NULL) {
        return NULL;
    }

    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return slow;
}

int main() {
    
    Node* head = new Node();
    Node* n2 = new Node();
    Node* n3 = new Node();
    Node* n4 = new Node();
    Node* n5 = new Node();
    
    head->data = 1; head->next = n2;
    n2->data = 2; n2->next = n3;
    n3->data = 3; n3->next = n4;
    n4->data = 4; n4->next = n5;
    n5->data = 5; n5->next = NULL;
    
    cout << "List: 1 -> 2 -> 3 -> 4 -> 5 -> NULL\n";
    
    Node* middle = findMiddle(head);
    
    if (middle != NULL) {
        cout << "Output: " << middle->data << endl;
    } else {
        cout << "List is emty.\n";
    }

    
    Node* n6 = new Node();
    n5->next = n6;
    n6->data = 6; n6->next = NULL;
    
    cout << "\nList: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> NULL\n";
    middle = findMiddle(head);
    if (middle != NULL) {
        cout << "Output: " << middle->data << endl;
    }

    return 0;
}
