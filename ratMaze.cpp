#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void mazeHelp(int maze[][20], int n, int ** solution, int x, int y){
    // if reached destination
    if(x==n-1 && y==n-1){
        solution[x][y]=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<solution[i][j]<<" ";
            }
        }
        cout<<endl;
        return;
    }

    // if see a blockage->0/out of maze cell 
    if(x>=n || y >= n || x< 0 || y < 0 || maze[x][y]==0 || solution[x][y]==1) return;

    solution[x][y] = 1;
    mazeHelp(maze, n, solution, x, y+1); // right
    mazeHelp(maze, n, solution, x+1, y); // down
    mazeHelp(maze, n, solution, x-1, y); // left
    mazeHelp(maze, n, solution, x, y-1); // up

    solution[x][y] = 0;
    
}

void ratInAMaze(int maze[][20], int n){

    int** solution = new int*[n];
    for(int i=0;i<n;i++){
        solution[i] = new int[n]();
    }   
    mazeHelp(maze, n, solution, 0, 0);
}

int main(){
    int n = 3;
    int maze[20][20];
    for(int i = 0; i < n ;i++){
        for(int j = 0; j < n; j++){
                cin >> maze[i][j];
        }		
    }
    ratInAMaze(maze, n);
    return 0;
}