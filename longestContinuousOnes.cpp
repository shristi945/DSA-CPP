#include<bits/stdc++.h>
using namespace std;

bool checkZeroOnes(string s) {
    int flag ; int c1 = 0, c0=0;int maxl1 = INT_MIN, maxl0 = INT_MIN;
    if(s[0]=='1'){
        flag = 1; c1++;
    }
    if(s[0]=='0'){
        flag = 0;c0++;
    }
    for(int i=1;i<s.length(); i++){
        if(s[i]=='1'&&flag==1){
            c1++;
        }
        else if(s[i]=='0'&& flag == 0){
            c0++;
        }
        else if(s[i]=='0'&& flag ==1){
            if(c1>maxl1){
                maxl1 = c1;
            }
            c1=0;
            c0++;
            flag=0;
        }
        else if(s[i]=='1' && flag==0){
            if(c0>maxl0){
                maxl0 = c0;
            }
            c0 = 0;
            c1++;
            flag = 1;
        }
    }
    if(flag==0){
        if(c0>maxl0){
            maxl0 = c0;
        }
    }
    else{
        if(c1>maxl1){
            maxl1 = c1;
        }
    }
    if(maxl1 > maxl0) return true;
    return false;
        
}

int main(){

    string s = "110100010";
    cout<<checkZeroOnes(s);

    return 0;
}