#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void insertBegin() {
    int val;
    cout << "Enter value: ";
    cin >> val;
    Node* new_node = new Node();
    new_node->data = val;
    new_node->next = head;
    head = new_node;
    cout << "Node insertd.\n";
}

void insertEnd() {
    int val;
    cout << "Enter value: ";
    cin >> val;
    Node* new_node = new Node();
    new_node->data = val;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    cout << "Node insertd.\n";
}

void insertAfter() {
    int key, val;
    cout << "Enter value to insert: ";
    cin >> val;
    cout << "Enter value to insert after: ";
    cin >> key;

    Node* temp = head;
    while(temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Node not found.\n";
        return;
    }

    Node* new_node = new Node();
    new_node->data = val;
    new_node->next = temp->next;
    temp->next = new_node;
    cout << "Node insertd.\n";
}

void deleteBegin() {
    if (head == NULL) {
        cout << "List is emty.\n";
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
    cout << "Node deletd.\n";
}

void deleteEnd() {
    if (head == NULL) {
        cout << "List is emty.\n";
        return;
    }
    if (head->next == NULL) {
        delete head;
        head = NULL;
        cout << "Node deletd.\n";
        return;
    }
    
    Node* temp = head;
    while(temp->next->next != NULL) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
    cout << "Node deletd.\n";
}

void deleteSpecific() {
    int key;
    cout << "Enter value to delete: ";
    cin >> key;
    
    Node* temp = head;
    Node* prev = NULL;

    if (temp != NULL && temp->data == key) {
        head = temp->next;
        delete temp;
        cout << "Node deletd.\n";
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Node not found.\n";
        return;
    }

    prev->next = temp->next;
    delete temp;
    cout << "Node deletd.\n";
}

void searchNode() {
    int key;
    cout << "Enter value to serch: ";
    cin >> key;
    
    Node* temp = head;
    int pos = 0;
    while (temp != NULL) {
        if (temp->data == key) {
            cout << "Node found at positon " << pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << "Node not found.\n";
}

void displayList() {
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

int main() {
    int ch;
    while (1) {
        cout << "\n--- Singly Linkd List Menu ---\n";
        cout << "1. Insert Begin\n";
        cout << "2. Insert End\n";
        cout << "3. Insert After\n";
        cout << "4. Delete Begin\n";
        cout << "5. Delete End\n";
        cout << "6. Delete Specific\n";
        cout << "7. Search\n";
        cout << "8. Display\n";
        cout << "9. Exit\n";
        cout << "Enter your choise: ";
        cin >> ch;

        switch (ch) {
            case 1: insertBegin(); break;
            case 2: insertEnd(); break;
            case 3: insertAfter(); break;
            case 4: deleteBegin(); break;
            case 5: deleteEnd(); break;
            case 6: deleteSpecific(); break;
            case 7: searchNode(); break;
            case 8: displayList(); break;
            case 9: return 0;
            default: cout << "Invalid choise.\n";
        }
    }
    return 0;
}
