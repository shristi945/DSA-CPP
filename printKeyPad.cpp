#include <iostream>
#include<bits/stdc++.h>
using namespace std;

string dial(int key){
    unordered_map<int,string>m;
    m[0]="";
    m[1]="";
    m[2]="abc";
    m[3]="def";
    m[4]="ghi";
    m[5]="jkl";
    m[6]="mno";
    m[7]="pqrs";
    m[8]="tuv";
    m[9]="wxyz";
    return m[key];
}

void pk(int num, string output){
    if(num==0){
        cout<<output<<endl;
        return;
    }

    string text = dial(num%10);
    for(int i=0;i<text.size();i++){
        pk(num/10, text[i]+output);
    }

}

void printKeypad(int num){
    pk(num, "");
}

int main(){
    int n;
    cin>>n;
    printKeypad(n);
    return 0;
}