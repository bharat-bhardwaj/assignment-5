#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void insertBeg(int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = head;
    head = newNode;
}

void insertEnd(int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = NULL;
    if(head==NULL) {
        head=newNode; return;
    }
    Node* temp=head;
    while(temp->next!=NULL) temp=temp->next;
    temp->next=newNode;
}

void insertAfter(int key,int val) {
    Node* temp=head;
    while(temp!=NULL && temp->data!=key) temp=temp->next;
    if(temp==NULL){ cout<<"Key not found\n"; return; }
    Node* newNode=new Node();
    newNode->data=val;
    newNode->next=temp->next;
    temp->next=newNode;
}

void insertBefore(int key,int val) {
    if(head==NULL){ cout<<"Empty\n"; return; }
    if(head->data==key) { insertBeg(val); return; }
    Node* prev=NULL; Node* temp=head;
    while(temp!=NULL && temp->data!=key){
        prev=temp; temp=temp->next;
    }
    if(temp==NULL){ cout<<"Key not found\n"; return; }
    Node* newNode=new Node();
    newNode->data=val;
    newNode->next=temp;
    prev->next=newNode;
}

void deleteBeg() {
    if(head==NULL){ cout<<"Empty\n"; return; }
    Node* temp=head;
    head=head->next;
    delete temp;
}

void deleteEnd() {
    if(head==NULL){ cout<<"Empty\n"; return; }
    if(head->next==NULL){ delete head; head=NULL; return; }
    Node* temp=head;
    while(temp->next->next!=NULL) temp=temp->next;
    delete temp->next;
    temp->next=NULL;
}

void deleteKey(int key) {
    if(head==NULL){ cout<<"Empty\n"; return; }
    if(head->data==key){ deleteBeg(); return; }
    Node* temp=head;
    while(temp->next!=NULL && temp->next->data!=key) temp=temp->next;
    if(temp->next==NULL){ cout<<"Key not found\n"; return; }
    Node* del=temp->next;
    temp->next=del->next;
    delete del;
}

void search(int key) {
    Node* temp=head;
    int pos=1;
    while(temp!=NULL){
        if(temp->data==key){ cout<<"Found at position "<<pos<<endl; return; }
        temp=temp->next; pos++;
    }
    cout<<"Not found\n";
}

void display() {
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main() {
    insertBeg(10);
    insertEnd(20);
    insertAfter(10,15);
    insertBefore(20,18);
    display();
    deleteKey(15);
    deleteBeg();
    deleteEnd();
    display();
}
//10 15 18 20
//18

