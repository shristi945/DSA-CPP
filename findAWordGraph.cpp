#include <bits/stdc++.h>
using namespace std;
char str[]={'C','O','D','I','N','G','N','I','N','J','A'};

bool isSafe(vector<vector<char>> &board, vector<vector<int>>visited, int next_x, int next_y, int n,int m){
    if(next_x<n && next_y<m && next_x>=0 && next_y>=0 && visited[next_x][next_y]==0)
        return true;
    return false;

}


bool dfs(vector<vector<char>> &board, vector<vector<int>> visited, int n, int m, int index, int i, int j){

    if(index == strlen(str)-1 && str[index]==board[i][j]){
        return true;
    }

    // row moves
    int x[] = {-1, -1, -1,  0, 0,  1, 1, 1};
    // col moves
    int y[]= {-1,  0,  1, -1, 1, -1, 0, 1};

    if(str[index]==board[i][j]){
        visited[i][j] = 1;
        for(int k=0;k<8;k++){
            int next_x = i+x[k];
            int next_y = j+y[k];

            if(isSafe(board, visited, next_x,next_y, n,m)){
                if(dfs(board, visited, n,m,index+1, next_x,next_y)==true)
                    return true;
            }
        }
        //backtrack
        visited[i][j] = 0;
    }

    return false;
}


bool hasPath(vector<vector<char>> &board, int n, int m){
    // visited initialization
    vector<vector<int>> visited(n,vector<int>(m,0));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(dfs(board,visited,n,m,0,i,j)==true)
                return true;
        }
    }
    return false;

}

int main(){
    vector<vector<char>>board{
        {'A', 'J', 'N', 'I','N','G','N','I','D','O','C'}

        //1 11
        //AJNINGNIDOC
    };
    int n=1,m=11;

    cout<<hasPath(board, n,m);

    return 0;
}