#include <bits/stdc++.h>
using namespace std;

vector<int> checkSorted(vector<vector<int>> mat, int n, int m){
    int **dp=new int*[n];
    for(int i=0;i<n;i++){
        dp[i] = new int[m];
    }
    
    for(int j=0;j<m;j++){
        dp[0][j]=1;
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]>=mat[i-1][j]){
                dp[i][j] = dp[i-1][j];
            }
            else{
                dp[i][j] = i+1;
            }
        }
    }
    vector<int>res(n);
    for(int i=0;i<n;i++){
        int mini = INT_MAX;
        for(int j=0;j<m;j++){
            mini = min(dp[i][j], mini);
        }
        res[i] = mini;
    }
    return res;
}


int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> mat( n , vector<int> (m, 0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mat[i][j];
        }
    }
    vector<int>res = checkSorted(mat,n,m);
    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        if(res[r-1]<=l){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
        
    }
    
    return 0;
}
