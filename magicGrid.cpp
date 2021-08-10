#include <iostream>
using namespace std;

int getMinimumStrength(int** grid, int m, int n) {
	// Write your code here
    int ** dp = new int*[m];
    for(int i=0;i<m;i++){
        dp[i] = new int[n];
    }
    dp[m-1][n-1] = 1;
    for(int i=m-2;i>=0;i--){
        int x =  dp[i+1][n-1]-grid[i+1][n-1];
        if(x>=1){
            dp[i][n-1] = x;
        }
        else{
            dp[i][n-1] = 1;
        }
    }
    for(int j=n-2;j>=0;j--){
        int x =  dp[m-1][j+1]-grid[m-1][j+1];
        if(x>1){
            dp[m-1][j] = x;
        }
        else{
            dp[m-1][j] = 1;
        }
    }
    for(int i=m-2;i>=0;i--){
        for(int j=n-2;j>=0;j--){
            int right = 1;int down = 1;
            if(dp[i][j+1]-grid[i][j+1]>=1){
                right = dp[i][j+1]-grid[i][j+1];
            }
            if(dp[i+1][j]-grid[i+1][j]>=1){
                down = dp[i+1][j]-grid[i+1][j];
            }
            dp[i][j] = min(right,down);
        }
    }
    return dp[0][0];
}

int main()
{ 
    int ** input = new int *[2];
    input[0] = new int[2];
    input[1] = new int[2];
    // input[2] = new int[4];
    input[0][0] = 0;
    input[0][1] = 1;
    // input[0][2] = -3;
    // input[0][3] = 1;
    input[1][0] = 2;
    input[1][1] = 0;
    // input[1][2] = 0;
    // input[1][3] = -2;
    // input[2][0] = 1;
    // input[2][1] = -2;
    // input[2][2] = -3;
    // input[2][3] = 0;
    // cout<<min_cost(input,0,0,2,2)<<endl;
    cout<<getMinimumStrength(input,2,2);
}