#include<bits/stdc++.h>
using namespace std;

bool hasPath(int **adjMatrix, int v1, int v2, int n, vector<bool> visited){
    if(adjMatrix[v1][v2]==1)return true;

    int sv = v1;
    visited[sv] =true;
    for(int i=sv;i<n;i++){
        if(adjMatrix[sv][i]==1 && visited[i]!=true){
            if(i==v2){
                return true;
            }
            return hasPath(adjMatrix,i, v2, n,visited);
        }
    }

    return false;
}


int main(){ 

    int V, E;
    cin>>V>>E;
    int **adjMatrix = new int *[V];
    for(int i=0;i<V;i++){
        adjMatrix[i] = new int [V];
        for(int j=0;j<V;j++){
            adjMatrix[i][j] = 0;
        }
    }
    int v1, v2;
    for(int i=0;i<E;i++){
        cin>>v1>>v2;
        adjMatrix[v1][v2] = 1;
        adjMatrix[v2][v1] = 1;
    }
    cin>>v1>>v2;
    vector<bool>visited(V, false);
    cout<<hasPath(adjMatrix, v1,v2, V, visited);


    return 0;
}