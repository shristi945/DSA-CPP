#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void helper(string str){
    
    map<char, vector<int>> m;
    for(int l=0;l<str.length();l++){
        if(m.find(str[l]) ==m.end()){
            vector<int> v;
            v.push_back(l);
            m[str[l]] = v;
        }
        else{
            m[str[l]].push_back(l);
        }
    }
    map<char, vector<int>>::iterator it;
    int odd_len_count = 0;
    for(it=m.begin();it!=m.end();it++){
        if((it->second.size())%2!=0){
            odd_len_count++;
        }
    }

    if(odd_len_count > 1){
        cout<<-1;
        return;
    }
    else{
        vector<int> res(str.length());
        int start = 0, end = str.length()-1, mid = (end+1)/2;
        
        for(it=m.begin();it!=m.end();it++){
            if((it->second.size())%2!=0){
                res[mid] = it->second[it->second.size()-1];
                it->second.pop_back();
            }
            
            for(int j=0; j<it->second.size();j+=2){
                res[start] = it->second[j];
                res[end] = it->second[(it->second.size())-1-j];
                start++;
                end--;
            }
        }
        for(int k=0;k<res.size();k++){
            cout<<res[k]+1<<" ";
        }
    }
    return;
}

int main(){

    int testcase;
    cin>>testcase;
    while(testcase--){
        string s;
        cin>>s;
        helper(s);
        cout<<endl; 
    }
    return 0;
}