#include<bits/stdc++.h>
using namespace std;
#define n 100

class stack1{

    int *arr;
    int top;

    public:
    stack1(){
        arr = new int [n];
        top=-1;
    }    
    void push(int val){
        if(top==n-1){
            cout<<"stack overflow!"<<endl;
            return;
        }
        top++;
        arr[top] = val;
    }
    int pop(){
        if(top==-1){
            cout<<"stack is empty!"<<endl;
            return -1;
        }
        int ele = arr[top];
        top--;
        return ele;
    }

    int Top(){
        if(top==-1){
            cout<<"stack is empty!";
            return -1;
        }
        return arr[top];
    }

};


int main(){


    stack1 st;
    st.push(1);
    st.push(3);
    st.push(8);
    cout<<st.Top()<<endl;

    return 0;
}