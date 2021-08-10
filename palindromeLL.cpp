#include<bits/stdc++.h>
using namespace std;

class ListNode{
    public:
        int val;
        ListNode* next;
};


void printLL(ListNode* n){
    while(n!=NULL){
        cout<<n->val<<" ";
        n = n->next;
    }
}

bool isPalindrome(ListNode* head) {
        
    if( head == NULL) return false;
    if(head->next == NULL) return true;
    
    ListNode* slow = head;
    ListNode* fast = head;
    
    // find middle
    while(fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
    }
    
    // reverse 2nd half
    ListNode *prev = NULL; 
    while (slow) {
        ListNode* temp = slow->next; 
        slow->next = prev; 
        prev = slow;
        slow = temp; 
    }
    
    // check for palindrome 
    while (head && prev) {
        if (head->val != prev->val) return false; 
        head = head->next; 
        prev = prev->next; 
    }
    return true; 
    
}


int main(){

    ListNode* head = NULL;
    ListNode* second = NULL;
    ListNode* third = NULL;
    ListNode* fourth = NULL;
    ListNode* fifth = NULL;

    head = new ListNode();
    second = new ListNode();
    third = new ListNode();
    fourth = new ListNode();
    fifth = new ListNode();

    head->val = 1;
    head->next = second;

    second->val = 2;
    second->next = NULL;
    // third->val = 3;
    // third->next = fourth;

    // fourth->val = 2;
    // fourth->next = fifth;

    // fifth->val = 1;
    // fifth->next = NULL;

    printLL(head);
    cout<<endl;

    cout<<isPalindrome(head);

    return 0;
}