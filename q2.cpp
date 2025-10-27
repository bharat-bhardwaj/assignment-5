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


void countAndDelete(Node*& head, int key) {
    int count = 0;
    Node* temp = head;
    Node* prev = NULL;

    
    while (temp != NULL) {
        if (temp->data == key) {
            count++;
            
            if (prev == NULL) { 
                head = temp->next;
                delete temp;
                temp = head;
            } else { 
                prev->next = temp->next;
                delete temp;
                temp = prev->next;
            }
        } else {
            prev = temp;
            temp = temp->next;
        }
    }
    
    cout << "Count: " << count << endl;
}

int main() {
    
    Node* head = new Node();
    Node* n2 = new Node();
    Node* n3 = new Node();
    Node* n4 = new Node();
    Node* n5 = new Node();
    Node* n6 = new Node();
    Node* n7 = new Node();
    
    head->data = 1; head->next = n2;
    n2->data = 2; n2->next = n3;
    n3->data = 1; n3->next = n4;
    n4->data = 2; n4->next = n5;
    n5->data = 1; n5->next = n6;
    n6->data = 3; n6->next = n7;
    n7->data = 1; n7->next = NULL;

    cout << "Orignl List:\n";
    displayList(head);
    
    int key = 1;
    cout << "\nDeleting all " << key << "...\n";
    
    countAndDelete(head, key);
    
    cout << "Updatd List:\n";
    displayList(head);

    return 0;
}
