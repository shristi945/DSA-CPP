#include <bits/stdc++.h>
using namespace std;



int waysProperBrackets(int open, int close, int total, vector<bool>vec, int i, int **dp){

    if(open>total || close>total) return 0;
    if(close == total) return 1;
    if(dp[open][close]!=-1){
        return dp[open][close];
    }
    int ans =0;
    if(open == close || vec[i]==true){
        return waysProperBrackets(open+1, close, total, vec, i+1, dp);
    }
    else if(open==total){
        return waysProperBrackets(open, close+1, total, vec, i+1,dp);
    }
    else{
        ans = waysProperBrackets(open+1, close, total, vec, i+1,dp) + 
               waysProperBrackets(open, close+1, total, vec, i+1,dp);
    }
    dp[open][close] = ans;
    return ans;
}



int main(){

    int d;
    cin>>d;
    while(d--){
        int n, k;
        cin>>n>>k;
        vector<bool>vec (2*n,false);
        for(int i =0;i<k;i++){
            int position;
            cin>>position;
            vec[position-1] = true;
        }
        int **dp = new int *[n+1];
        for(int i=0;i<=n;i++){
            dp[i] = new int [n+1];
        }
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                dp[i][j] = -1;
            }
        }
        int open = 0, close = 0; 
        cout<<waysProperBrackets(open, close, n, vec, 0, dp)<<endl;


    }

    return 0;
}