#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n1,n2,n3;
    vector<int> v1, v2, v3, res;
    map<int,int> m;
    cin>>n1>>n2>>n3;
    for(int i=0;i<n1;i++){
        int ele;
        cin>>ele;
        v1.push_back(ele);
        m[ele] = 1;
    }
    for(int i=0;i<n2;i++){
        int ele;
        cin>>ele;
        v2.push_back(ele);
        if(m.find(ele) == m.end()){
            m[ele] = 1;
        }
        else{
            m[ele]++;
        }
    }
    for(int i=0;i<n3;i++){
        int ele;
        cin>>ele;
        v3.push_back(ele);
        if(m.find(ele) == m.end()){
            m[ele] = 1;
        }
        else{
            m[ele]++;
        }
    }
    map<int,int>::iterator it;
    for(it=m.begin(); it!=m.end();it++){
        if(it->second >=2){
            res.push_back(it->first);
        }
    }
    cout<<res.size()<<endl;
    for(int i=0; i<res.size();i++){
        cout<<res[i]<<endl;
    }
    
    return 0;
}