#include<bits/stdc++.h>
using namespace std;

int helper(int *arr, int n, int sum , int i,int **dp){
    
    if(i==n){
        if(sum==0){
            return 1;
        }
        else{
            return 0;
        }
    }
    if(dp[i][sum]!=0){
        return dp[i][sum];
    }
    int ans1=0, ans2= 0;
    ans1 = helper(arr, n, sum-arr[i], i+1, dp);
    ans2 = helper(arr, n, sum, i+1,dp);
    int ans = max(ans1, ans2);
    dp[i][sum] = ans;
    return ans;
    
    
}

bool isSubsetPresent(int *arr, int n, int sum)
{
    //Write your code here
    int ** dp = new int *[n];
    for(int i =0;i<n;i++){
        dp[i] = new int [sum+1];
    }
    for(int i =0;i<n;i++){
        for(int j=0;j<=sum;j++){
            dp[i][j]=0;
        }
    }
    helper(arr, n, sum, 0, dp);
    
}

int main()
{
    int n, sum;
    cin >> n;

    int *arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cin >> sum;

    if (isSubsetPresent(arr, n, sum))
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }

    delete[] arr;
}