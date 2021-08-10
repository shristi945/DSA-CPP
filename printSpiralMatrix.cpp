#include<bits/stdc++.h>
using namespace std;

int main(){
    int n=4, m=4;
    int mat[100][100];
    mat[0][0] = 1;
    mat[0][1] = 2;
    mat[0][2] = 3;
    mat[0][3] = 4;
    mat[1][0] = 5;
    mat[1][1] = 6;
    mat[1][2] = 7;
    mat[1][3] = 8;
    mat[2][0] = 9;
    mat[2][1] = 10;
    mat[2][2] = 11;
    mat[2][3] = 12;
    mat[3][0] = 13;
    mat[3][1] = 14;
    mat[3][2] = 15;
    mat[3][3] = 16;
    int visited[4][4];
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            visited[i][j] = false;
        }
    }
    int i=0,j=0;
    while(visited[i][j]!=true){
        while(visited[i][j]!=true && j<m){
            // print right
            cout<<mat[i][j]<<" ";
            visited[i][j] = true;
            j++;
        }
        i++; j--;
        cout<<endl;
        while(visited[i][j]!=true && i<n){
            // print down
            cout<<mat[i][j]<<" ";
            visited[i][j] = true;
            i++;
        }
        i--;j--;
        cout<<endl;
        while(visited[i][j]!=true && j>=0){
            // print left
            cout<<mat[i][j]<<" ";
            visited[i][j] = true;
            j--;
        }
        j++;i--;
        cout<<endl;
        while(visited[i][j]!=true && i>=0){
            // print up
            cout<<mat[i][j]<<" ";
            visited[i][j] = true;
            i--;
        }
        i++;j++;
    }

    return 0;
}