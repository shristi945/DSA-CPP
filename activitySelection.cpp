#include<bits/stdc++.h>
using namespace std;

bool comp(pair<int,int> &a, pair<int,int> &b){

    if(a.second==b.second){
        return a.first<b.first;
    }
    return a.second<b.second;

}

int main(){

    int n;
    cin>>n;
    vector<pair<int,int>>activity(n);
    for(int i=0;i<n;i++){
        cin>>activity[i].first>>activity[i].second;
    }
    sort(activity.begin(), activity.end(), comp);
    int prev = activity[0].second; int count = 1;
    for(int i=1;i<n;i++){
        if(prev<=activity[i].first){
            prev = activity[i].second;
            count++;
        }
    }
    cout<<count;

    return 0;
}