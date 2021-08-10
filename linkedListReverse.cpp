#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
};


void printLL(Node* n){
    while(n!=NULL){
        cout<<n->data<<" ";
        n = n->next;
    }
}

Node* reverseLL(Node* n){
    if (n == NULL) return NULL;
    if(n->next == NULL) return n;
    Node* p = n, *q = n, *r = n->next;
    while(r->next!=NULL){
        q = r;
        r = r->next;
        q->next = p;
        p=q;
    }
    r->next = q;
    n->next = NULL;
    n = r;
    return n;
}

vector<Node*> midPoint(Node* n){
    Node* slow = n, *fast = n; Node* count = new Node();
    count->data = 0; count->next = NULL;
    while(fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
        count->data += 1;
    }
    if(fast!=NULL && fast->next ==NULL){
        count->data = count->data*2+1;
    }
    else if(fast==NULL){
        count->data = count->data*2;
    }
    vector<Node*> v;
    v.push_back(slow);
    v.push_back(fast);
    v.push_back(count);
    return v;
}

bool palindrome(Node* n){
    Node* head = n;
    vector<Node*> v = midPoint(n);
    Node* newHead = reverseLL(v[0]);
    v[0]->next = NULL;
    Node* temp1 = head, *temp2 = newHead;
    while(temp1 && temp2){
        if(temp1->data!=temp2->data)
            return false;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return true;
    
}

Node* removeNthFromEnd(Node* head, int n){
    vector<Node*> v = midPoint(head);
    int total_count = v[2]->data;
    if(n==0)return head;
    int x = total_count - n;
    if(x==0) return head->next;
    x = x-1;
    Node *nh = head;
    while(x--){
        nh = nh->next;
    }
    nh->next = nh->next->next;
    return head;
}

int main(){

    Node* head = NULL;
    Node* second = NULL;
    Node* third = NULL;
    Node* fourth = NULL;
    Node* fifth = NULL;

    head = new Node();
    second = new Node();
    third = new Node();
    fourth = new Node();
    fifth = new Node();

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = NULL;

    // third->data = 3;
    // third->next = fourth;

    // fourth->data = 2;
    // fourth->next = fifth;

    // fifth->data = 1;
    // fifth->next = NULL;

    printLL(head);
    // cout<<endl;
    // Node* newHead = reverseLL(head);
    // cout<<"After reversal"<<endl;
    // printLL(newHead);
    cout<<endl;
    vector<Node*>v;
    v = midPoint(head); 
    cout<<"MidPoint:"<<v[0]->data<<endl;
    cout<<"Length:"<<v[2]->data<<endl;
    cout<<"midValue:"<<v[0]->data<<endl;
    cout<<palindrome(head)<<endl;
    // cout<<"After removing k node from last"<<endl;
    // Node *nh = removeNthFromEnd(head, 1);
    // printLL(nh);
    return 0;
}