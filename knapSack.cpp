#include<bits/stdc++.h>
using namespace std;


int helper(int *weight, int *value, int n, int W, int i, int **dp){
    if(i==n)return 0; 
    int ans;
    if(dp[i][W]!=-1){
        return dp[i][W];
    }
    if(weight[i]<=W){
        ans = max(value[i]+helper(weight, value, n, W-weight[i],i+1, dp), 
                  helper(weight, value, n, W,i+1,dp));
    }
    else{
        ans = helper(weight, value, n, W,i+1,dp);
    }
    dp[i][W] = ans;
    return ans;
    
}

int knapsack(int* weight, int* value, int n, int maxWeight) {
	// Write your code here
    int **dp=new int *[n+1];
    for(int i=0;i<=n;i++){
        dp[i] = new int [maxWeight+1];
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=maxWeight;j++){
            dp[i][j] = -1;
        }
    }
    return helper(weight, value, n, maxWeight,0, dp);
}

int knapsackI(int* weight, int* value, int n, int maxWeight){
    int **dp=new int *[n+1];
    for(int i=0;i<=n;i++){
        dp[i] = new int [maxWeight+1];
    }

    for(int i=0;i<=n;i++){
        dp[i][0] = 0;
    }
    for(int j=0;j<=maxWeight;j++){
        dp[0][j] = 0;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=maxWeight;j++){
            if(weight[i-1]<=j){
                dp[i][j] = max(value[i-1]+dp[i-1][j-weight[i-1]], dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][maxWeight];


}

int main() {
    int n;
    cin >> n;
    int* wt = new int[n];
    int* val = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> wt[i];
    }

    for (int j = 0; j < n; j++) {
        cin >> val[j];
    }

    int w;
    cin >> w;

    cout << knapsackI(wt, val, n, w) << "\n";

    delete[] wt;
    delete[] val;
}