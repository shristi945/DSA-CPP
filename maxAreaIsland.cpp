#include<bits/stdc++.h>
using namespace std;
unordered_map<int,int>umap;
vector<int>dx{1,-1,0,0};
vector<int>dy{0,0,1,-1};

bool judge(int i,int j, int n,int m){
    if(i<0 || j<0 || i>=n || j>=m) return false;
    return true;
}

int calculateNewArea(vector<vector<int>> &grid, int i, int j, int n, int m, vector<int> &included ){
    int ans = 0;
    for(int k=0;k<4;k++){
        int tx = i+dx[k];
        int ty = j+dy[k];
        if(judge(tx,ty,n,m) && included[grid[tx][ty]]!=1){
            included[grid[tx][ty]]=1;
            ans += umap[grid[tx][ty]];  
        }
    }
    return ans+1;

}

int markAllIsland(vector<vector<int>> &grid, int i, int j, int n, int m, int index){

    if(i<0 || j<0 || i>=n || j>=m || grid[i][j]!=1) return 0;

    grid[i][j] = index;
    int ans = 1+ markAllIsland(grid, i+1,j,n,m,index) + markAllIsland(grid, i-1,j,n,m,index)+
                 markAllIsland(grid, i,j+1,n,m,index) + markAllIsland(grid, i,j-1,n,m,index);

    return ans;


}

int makeMaxAreaIsland(vector<vector<int>> &grid){

    int n = grid.size();
    int m = grid[0].size();
    int index = 2;
    for(int i=0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(grid[i][j]==1){
                
                int ans = markAllIsland(grid, i, j, n, m , index);
                umap[index] = ans;
                index++;
            }
        }
    }
    
    int ans1 = 0, maxArea = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==0){
                vector<int>included(index, 0);
                ans1 = calculateNewArea(grid, i, j, n ,m, included);
                maxArea = max(maxArea, ans1);
            }
        }
    }
    return maxArea;
}



int main(){

    vector<vector<int>> grid{
        {0,1,0,0},
        {0,1,1,0},
        {0,1,0,0},
        {1,0,1,0}
    };

    cout<<makeMaxAreaIsland(grid)<<endl;
    int n = grid.size();
    int m = grid[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
    for(auto i:umap){
        cout<<i.first<<" "<<i.second<<endl;
    }
    return 0;
}