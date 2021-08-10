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
int Keypad(int num,string output[]){
    
    if(num==0){
        output[0] = "";
        return 1;
    }
    string pd=dial(num%10);
    int smallInput = num/10;
    int smallOutputSize = Keypad(smallInput,output);
    for(int i=0; i<smallOutputSize; i++){
        for(int j=1;j<pd.size();j++){
            output[i+j*smallOutputSize] = output[i];
        }
    }
    int k=0;
    for(int i=0;i<pd.size();i++){
        for(int j=0;j<smallOutputSize;j++){
            output[k] = output[k]+pd[i];
            k++; 
        }
    }
    return pd.size()*smallOutputSize;
}


int main(){
    int n;
    cin>>n;
    string* output = new string [1000];
    int count = Keypad(n, output);
    for(int i=0;i<count;i++){
        cout<<output[i]<<" ";
    }
    return 0;
}