#include<bits/stdc++.h>
using namespace std;
vector<int>res;
unordered_map<int, int>m;
// vector<int> getPath(int **adjMatrix, int v1, int v2, int n, vector<bool> visited){
//     if(v1==v2){
//         res.push_back(v1);
//         return res;
//     }
    
//     visited[v1] =true;
//     for(int i=0;i<n;i++){
//         if(adjMatrix[v1][i]==1 && visited[i]!=true){
//             visited[i] = true;
//             vector<int>smallOutput = getPath(adjMatrix,i, v2, n,visited);
//             if(smallOutput.size()>0){
//                 res.push_back(v1);
//                 return res;
//             }


//         }
//     }


//     return {};
// }


vector<int> getPathBfs(int **adjMatrix, int v1, int v2, int n, vector<bool>visited){

    queue<int>q;
    q.push(v1);
    visited[v1]=true;
    if(v1==v2){
        res.push_back(v1);
        return res;
    }
    bool flag =false;
    while(!q.empty()){
        
        int curr = q.front();
        q.pop();
        for(int i=0;i<n;i++){
            if(i==curr) continue;
            if(adjMatrix[curr][i]==1 && visited[i]!=true && i!=v2){
                q.push(i);
                m[i] = curr;
                visited[i]=true;
            }
            else if(adjMatrix[curr][i]==1 && visited[i]!=true && i==v2){
                res.push_back(i);
                int key = curr;
                while(key!=v1){
                    res.push_back(key);
                    key = m[key];
                }
                res.push_back(v1);
                flag = true;
                break;
            }
        }
        if(flag==true) break;
    }
    return res;
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
    
    vector<int>path = getPathBfs(adjMatrix, v1,v2, V, visited);
    for(int i = 0;i<path.size();i++){
        cout<<path[i]<<" ";
    }


    return 0;
}