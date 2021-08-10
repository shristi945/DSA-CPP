#include<bits/stdc++.h>
using namespace std;

bool comp(const pair<int,int>&a, const pair<int,int>&b){

    if(a.second!=b.second){
        return a.second>b.second;
    }
    return a.first<b.first;
}

int main(){

    int n,k;
    cin>>n>>k;
    vector<pair<int,int>>pieces(n);
    for(int i=0;i<n;i++){
        cin>>pieces[i].first>>pieces[i].second;
    }
    sort(pieces.begin(),pieces.end(), comp);
    multiset<int>ms;
    int weight;
    for(int i=0;i<k;i++){
        cin>>weight;
        ms.insert(weight);
    }
    long ans = 0;
    for(int i=0;i<n;i++){
        if(ms.empty()){
            break;
        }
        else if(ms.lower_bound(pieces[i].first)!=ms.end()){
            ans += pieces[i].second;
            ms.erase(ms.lower_bound(pieces[i].first));
        }
    }
    cout<<ans;

    return 0;
}