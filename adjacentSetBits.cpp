#include<bits/stdc++.h>
#define MAX 100
#define M 1000000007
using namespace std;

int numberOfWays(int dp[][MAX][2], int n, int k, int currIndex, int adjbits, int lastBitAdded){
    if(n==currIndex){
        if(k==adjbits) return 1;
    return 0;
    }
    if(dp[currIndex][adjbits][lastBitAdded]!=-1){
        return dp[currIndex][adjbits][lastBitAdded];
    }
    int noOfWays = 0;
    if(lastBitAdded == 1){
        noOfWays += numberOfWays(dp,n,k,currIndex+1,adjbits+1,1);
        noOfWays += numberOfWays(dp,n,k,currIndex+1,adjbits, 0);
    }
    else{
        noOfWays += numberOfWays(dp,n,k,currIndex+1,adjbits, 1);
        noOfWays += numberOfWays(dp,n,k,currIndex+1,adjbits, 0);
    }
    dp[currIndex][adjbits][lastBitAdded] = noOfWays;
    return noOfWays;
}

int main(){
    int t;
    cin>>t;
    int dataSetNumber=0;
    while(dataSetNumber<t){
        int n;
        int k;
        cin>>dataSetNumber>>n>>k;
        int dp[MAX][MAX][2];
        memset(dp, -1, sizeof(dp));
        int totalWays = numberOfWays(dp,n,k,1,0,0)+numberOfWays(dp,n,k,1,0,1);
        cout<<dataSetNumber<<" "<<totalWays%M<<endl;
    }
    
    return 0;
}