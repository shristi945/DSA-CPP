#include<bits/stdc++.h>
using namespace std;

vector<int> numberOfBoxes(vector<int> &start, vector<int>&end, int n){
    vector<int>dp(n+1);
    dp[1] = start[1];
    for(int i=2;i<=n;i++){
        dp[i] = start[i]-end[i-1]+dp[i-1];
    }
    vector<int>res(n+1);
    for(int i=1;i<=n;i++){
        res[dp[i]] ++; 
    }
    for(int i=n-1;i>=0;i--){
        res[i]+= res[i+1];
    }
    return res;
}

int main(){
    int  n, m, l,r,q,x;
    cin>>n>>m;
    vector<int>start(n+1);
    vector<int>end(n+1);
    while(m--){
        cin>>l>>r;
        start[l]++;
        end[r]++;
    }
    vector<int>res = numberOfBoxes(start,end,n);
    cin>>q;
    while(q--){
        cin>>x;
        cout<<res[x]<<endl;
    }

    return 0;
}