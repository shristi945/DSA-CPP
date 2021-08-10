#include<bits/stdc++.h>
using namespace std;

class node{

    public:
    int data;
    node* next;

    node(int val){
        data = val;
        next = NULL;
    }


};

void insertAtEnd(node* &head, int val){

    node * n = new node(val);

    if(head == NULL){
        head = n;
        return;
    }
    
    node * temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = n;
}

node* reverseKnodes(node* &head, int k){

    node* prevptr = NULL;
    node* currptr = head;
    node* nextptr;

    int count = 0;
    while(currptr!=NULL && count<k){
        nextptr = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = nextptr;
        count++;
    }

    if(nextptr!=NULL){
        head->next = reverseKnodes(nextptr, k);
    }
    head = prevptr;
    return prevptr;

}
int length(node* head){
    if(head==NULL)return 0;
    int count = 0;
    while(head!=NULL){
        head =head->next;
        count++;
    }
    return count;

}
node* merge(node* head1, node* head2){
    
    if(head1==NULL and head2==NULL) return NULL;

    node* dummy = new node(0);
    node* ptr1; node* ptr2; node* ptr3 =dummy;
    ptr1 = head1;
    ptr2 = head2;
    while(ptr1!=NULL && ptr2!=NULL)
    {
        if(ptr1->data<=ptr2->data){
            ptr3->next = ptr1;
            ptr1 = ptr1->next;
        }
        else{
            ptr3->next = ptr2;
            ptr2 = ptr2->next;
        }
        ptr3 = ptr3->next;
    }   
    while(ptr1!=NULL){
        ptr3->next = ptr1;
        ptr3 = ptr3->next;
        ptr1 = ptr1->next;
    }

    while(ptr2!=NULL){
        ptr3->next = ptr2;
        ptr3 = ptr3->next;
        ptr2 = ptr2->next;
    }
    return dummy->next;
}

void display(node* head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

int main(){


    node* head1 = NULL;
    node* head2 = NULL;
    insertAtEnd(head1, 1);
    insertAtEnd(head2, 2);
    insertAtEnd(head1, 3);
    insertAtEnd(head1, 4);
    insertAtEnd(head2, 5);
    insertAtEnd(head1, 6);
    display(head1);
    display(head2);
    node* newhead = merge(head1, head2);

    // reverseKnodes(head, 2);
    display(newhead);
    return 0;

}