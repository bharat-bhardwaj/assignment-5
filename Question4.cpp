#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head=NULL;

void insertEnd(int val) {
    Node* newNode=new Node();
    newNode->data=val;
    newNode->next=NULL;
    if(head==NULL){ head=newNode; return; }
    Node* temp=head;
    while(temp->next!=NULL) temp=temp->next;
    temp->next=newNode;
}

void reverseList() {
    Node* prev=NULL;
    Node* curr=head;
    Node* next=NULL;
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    head=prev;
}

void display() {
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL\n";
}

int main() {
    insertEnd(1);
    insertEnd(2);
    insertEnd(3);
    insertEnd(4);
    display();
    reverseList();
    display();
}
/*1->2->3->4->NULL
4->3->2->1->NULL*/