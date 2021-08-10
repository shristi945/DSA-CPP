#include<bits/stdc++.h>
using namespace std;
int minCountRec(int n, int *dp){
    if(n==0) return 0;
    int minCount = INT_MAX; int smallans = -1; int smallOutput;
    for(int i=1;i*i<=n;i++){
        if(dp[n-(i*i)]>0){
            smallOutput = 1+dp[n-(i*i)];
        }
        else{
            smallans = minCountRec(n-(i*i), dp);
            dp[n-(i*i)] = smallans;
            smallOutput = 1+smallans;
        }

        minCount = min(minCount, smallOutput);
        
    }
    return minCount;
}


int main(){
    int n;
    cin>>n;
    int *dp=new int [n+1];
    cout<<minCountRec(n,dp);
    return 0;
}