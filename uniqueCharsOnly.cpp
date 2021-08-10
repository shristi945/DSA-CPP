#include <iostream>
#include<bits/stdc++.h>
using namespace std;
string uniqueChar(string str) {
	// Write your code here

    string res;
    map<char, int>m;
    for(int i=0;i<str.length();i++){
        if (m.find(str[i])==m.end()){
            m[str[i]] = 1;
        }
        else{
            m[str[i]]++;
        }
    }
    for(int i=0;i<str.length();i++){
     if(m[str[i]]!=0){
         res.push_back(str[i]);
         m[str[i]] = 0;
     }   
    }
    return res;
}

int main() {
    string str;
    cin >> str;
    cout << uniqueChar(str);
}