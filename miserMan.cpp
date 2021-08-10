#include<bits/stdc++.h>
using namespace std;
int busToChoose(int mat[100][100], int n, int m, int i, int j, int **dp){

    if(i==n){
        return 0;
    }
    if(j==m || j<0){
        return INT_MAX;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int ans1;
    ans1 = mat[i][j]+min(busToChoose(mat,n,m,i+1,j,dp), 
    min(busToChoose(mat,n,m,i+1,j-1,dp), busToChoose(mat,n,m,i+1,j+1,dp)));
    dp[i][j] = ans1;
    return ans1;
}
int main(){
    int n, m;
    cin>>n>>m;
    int mat[100][100];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mat[i][j];
        }
    }
    int min_cost = INT_MAX;
    int **dp=new int*[n+1];
    for(int i=0;i<=n;i++){
        dp[i] = new int[m+1];
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            dp[i][j] = -1;
        }
    }
    for(int j=0;j<m;j++){
        int x = busToChoose(mat, n, m, 0, j, dp);
        min_cost = min(min_cost, x);
    }
    cout<<min_cost;
    return 0;
}