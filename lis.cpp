#include<bits/stdc++.h>
using namespace std;

int lis(int *arr, int n){
    int *dp = new int[n];
    dp[0] = 1;
    for(int i=1;i<n;i++){
        int including_max = 1;
        for(int j=i-1;j>=0;j--){
            if(arr[j]<=arr[i]){
                including_max = max(1+dp[j],including_max);
            }
        }
        dp[i] = including_max;
    }
    int best = 0;
    for(int i=0;i<n;i++){
        if(best<dp[i]){
            best = dp[i];
        }
    }
    delete [] dp;
    return best;
    // return 0;
}

int main() {

    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<lis(arr, n);

}