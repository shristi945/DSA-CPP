#include <bits/stdc++.h>
using namespace std; 

int getProfit(vector<int>&prices,int n, int ongoing, int k, int i,int ***dp ){

    if(n==i) return 0;

    int option2=0, option3=0;
    if(dp[i][k][ongoing]!=-1){
        return dp[i][k][ongoing];
    }
    // ignore this price
    int option1 = getProfit(prices, n, ongoing, k, i+1, dp);
    if(ongoing){
        // if ongoing transaction, looking for sell price
        option2 = getProfit(prices, n, 0, k-1, i+1,dp)+prices[i];
    }
    else{
        if(k>0){
            // if no ongoing process, looking for buy price
            option2 = getProfit(prices, n, 1,k,i+1,dp)-prices[i];
        }
        else{
            option3 = getProfit(prices,n,0,k,i+1,dp);
        }
    }
    dp[i][k][ongoing] = max(option1, max(option2, option3));
    return dp[i][k][ongoing];

}

int main(){
    int t;
    cin>>t;
    while(t--){
        int k,n;
        cin>>k>>n;
        vector<int>prices(n);
        for(int i=0;i<n;i++){
            cin>>prices[i];
        }
        int ongoing = 0;
        int ***dp = new int **[n+1];
        for(int i=0;i<=n;i++){
            dp[i] = new int *[k+1];
            for(int j=0;j<=k;j++){
                dp[i][j] = new int [2];
            }
        }
        for(int i=0;i<=n;i++){
            for(int j=0;j<=k;j++){
                for(int l=0;l<2;l++){
                    dp[i][j][l]=-1;
                }
            }
        }
        int ans = getProfit(prices, n,ongoing, k, 0, dp);
        for(int i = 0; i <=n; i++)
        {
            for(int j=0; j <=k; j++)
                delete[] dp[i][j];
            delete[] dp[i];
        }
        delete[] dp;
        cout<< ans;
    }
    
    return 0;
}

