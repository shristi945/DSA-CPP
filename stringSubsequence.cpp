#include <iostream>
#include<bits/stdc++.h>
using namespace std;
void stringSubsequence(string s, string output){
    if(s.length()==0){
        cout<<output<<endl;
        return;
    }
    // excluding
    stringSubsequence(s.substr(1), output);

    // including
    string newOutput = output+s[0];
    stringSubsequence(s.substr(1), newOutput);

}

int main(){
    string s = "abc";
    stringSubsequence(s, "");
    return 0;
}