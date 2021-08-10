#include <bits/stdc++.h>
using namespace std;


int findCost(vector<int> &captain, vector<int>&assistant, int n, int diff, int i, int **dp){
    if(i==n){
        return 0;
    }
    if(dp[diff][i]!=-1){
        return dp[diff][i];
    }
    int ans ;
    if(diff==0){
        ans = assistant[i]+findCost(captain, assistant, n, diff+1,i+1,dp);
    }
    else if(diff==n-i){
        ans = captain[i]+findCost(captain, assistant, n, diff-1,i+1,dp);
    }
    else{
        ans = min(assistant[i]+findCost(captain, assistant, n, diff+1,i+1,dp)
              ,captain[i]+findCost(captain, assistant, n, diff-1,i+1,dp));
    }
    dp[diff][i] = ans;
    return ans; 
}

int main()
{
    int n;
    cin>>n;
    vector<int>captain(n);
    vector<int>assistant(n);
    int **dp=new int *[n+1];
    for(int i=0;i<=n;i++){
        dp[i] = new int [n+1];
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            dp[i][j]=-1;
        }
    }
    for(int i=0;i<n;i++){
        cin>>captain[i]>>assistant[i];
    }
    cout<<findCost(captain, assistant, n,0,0, dp);
    return 0;
}
