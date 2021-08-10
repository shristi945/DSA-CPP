#include <bits/stdc++.h>
using namespace std;

int vis[56][56];
int xx[4] = {0,-1,1,0};
int yy[4] = {1,0,0,-1};

int judge(int x, int y, int n)
{
    if(x>=0 && x<n && y>=0 && y<n)
        return 1;
    else
        return 0;
}

int dfs(int x, int y, vector<vector<int>> &cake, int n){
    if(!judge(x,y,n)) return 0;
    vis[x][y] = 1; int smallAns=0;
    for(int i=0;i<4;i++){
        int tx = x+xx[i];
        int ty = y+yy[i];
        if(judge(tx, ty, n) && !vis[tx][ty] && cake[tx][ty]==1 ){
            smallAns += dfs(tx, ty, cake,n);
        }
    }
    return smallAns+1;

}


int getBiggestPieceSize(vector<vector<int>> &cake, int n) {
    // Write your code here
    int maxi = 0;
    memset(vis,0,sizeof(vis));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!vis[i][j] and cake[i][j]==1){
                int ans = dfs(i, j, cake, n);
                maxi = max(maxi,ans);
            }
        }
    }

    return maxi;

}

int main(){

    int n;
    cin>>n;
    vector<vector<int>>cake(n, vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>cake[i][j];
        }
    }    

    cout<< getBiggestPieceSize(cake, n);


    return 0;
}