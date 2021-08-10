#include<bits/stdc++.h>
using namespace std;

int main(){

    string s, t;
    cin>>s>>t;

    unordered_map<char, int>m;
    for(int i=0;i<s.length();i++){
        if(m.find(s[i])==m.end()){
            m[s[i]] = i;
        }
    }
    int prev = -1;
    for(int i=0;i<t.length();i++){
        if(m.find(t[i])!= m.end()){
            if(m[t[i]]<prev){
                return false;
            }
            prev = m[t[i]];
        }
        else{
            return false;
        }
    }
    return true;


    return 0;
}