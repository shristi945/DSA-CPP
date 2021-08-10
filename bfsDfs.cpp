#include<bits/stdc++.h>
using namespace std;
void dfs(int **edge, int n, int sv, bool *visited){
    cout<<sv<<" ";
    visited[sv]=true;
    for(int i=0;i<n;i++){
        if(edge[sv][i]==1 && visited[i]!=true){
            dfs(edge, n, i,visited);
        }
    }


}

void bfs(int **edge, int n,int sv, bool *visited){

    queue<int>q;

    q.push(sv);
    visited[sv]=true;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        cout<<curr<<" ";
        for(int i=0;i<n;i++){
            if(i==curr) continue;
            if(edge[curr][i]==1 && visited[i]!=true){
                q.push(i);
                visited[i]=true;
            }
        }
    }
    delete [] visited;
}
void dfsHelper(int **edge, int n){
    bool *visited = new bool[n];
    for(int i=0;i<n;i++){
        visited[i]=false;
    }
    for(int i=0;i<n;i++){
        if(!visited[i]){
            dfs(edge, n, i, visited);
        }
    }
    delete [] visited;
}

void bfsHelper(int **edge, int n){
    
    bool *visited = new bool[n];
    for(int i=0;i<n;i++){
        visited[i]=false;
    }
    for(int i=0;i<n;i++){
        if(!visited[i]){
            bfs(edge, n, 0, visited);
        }
    }
    delete [] visited;
}


int main(){
    int n, e, r,c;
    cin>>n>>e;
    int **edge = new int *[n];
    for(int i=0;i<n;i++){
        edge[i] = new int [n];
        for(int j=0;j<n;j++){
            edge[i][j]=0;
        }
    }
    for(int i=0;i<e;i++){
        cin>>r>>c;
        edge[r][c] = 1;
        edge[c][r] = 1;
    }
    cout<<"DFS"<<endl;
    dfsHelper(edge, n);
    cout<<endl;
    cout<<"BFS"<<endl;
    bfsHelper(edge, n);

    return 0;
}