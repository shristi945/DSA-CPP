#include<bits/stdc++.h>
using namespace std;

int largestMagicSquare(vector<vector<int>>& grid) {
    int m = grid[0].size();
    int n = grid.size();
    vector<vector<int>> rowPrefixSum(n+1), colPrefixSum(n+1);
    for(int i=0;i<=n;i++){
        rowPrefixSum[i].resize(m+1);
        colPrefixSum[i].resize(m+1);
    }

    for(int j=0;j<m;j++){
        rowPrefixSum[0][j]=grid[0][j];
    }
    for(int i=0;i<n;i++){
        colPrefixSum[i][0]=grid[i][0];
    }

    for(int i=1; i<n;i++){
        for(int j=0;j<m;j++){
            rowPrefixSum[i][j]= rowPrefixSum[i-1][j] + grid[i][j];
        }
    }

    for(int i=0; i<n;i++){
        for(int j=1;j<m;j++){
            colPrefixSum[i][j]= colPrefixSum[i][j-1] + grid[i][j];
        }
    }

    for(int i=0; i<=n;i++){
        for(int j=0;j<=m;j++){
            cout<<rowPrefixSum[i][j]<<" ";
        }
        cout<<endl;
    }

    for(int i=0; i<=n;i++){
        for(int j=0;j<=m;j++){
            cout<<colPrefixSum[i][j]<<" ";
        }
        cout<<endl;
    }

    // int k = min(m,n);
    return 0;
        
}

int main(){

    vector<vector<int>>grid{
        {7,1,4,5,6},
        {2,5,1,6,4},
        {1,5,4,3,2},
        {1,2,7,3,4}
    };
    largestMagicSquare(grid);
    return 0;
}