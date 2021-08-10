#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;

void dfs(vector<vector<int>> &edges, int start, unordered_set<int>* component, vector<bool> &vis){
    vis[start] = true;
    component->insert(start); 

    for(int i=0;i<edges[start].size();i++){
        int next = edges[start][i];
        if(!vis[next]){
            dfs(edges, next, component, vis);
        }
        
    }
}


unordered_set<unordered_set<int>*>* getComponents(vector<vector<int>> &edges, int n){

    vector<bool> vis(n, false);
    unordered_set<unordered_set<int>*>* output = new unordered_set<unordered_set<int>*>();
    for(int i=0;i<n;i++){
        if(!vis[i]){
            unordered_set<int>* component = new unordered_set<int>();
            dfs(edges, i, component, vis);
            output->insert(component);
        }
    }   
    return output;
}

int main(){

    int t;
    cin>>t;
    while(t--){
        int n,m,q;
        vector<vector<int>>mat(n, vector<int>(m,0));
        for(int i=0;i<q;i++){
            int x,y;
            cin>>x>>y;
            mat[x-1][y-1] = 1;
        }

        vector<int> xx {-2, -2, -1, -1, 1, 2, 2, 1};
        vector<int> yy {-1, 1, -2, 2, -2, -1, 1, 2};
        vector<vector<int>>edges(m);
        int count = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==1){
                    for(int k = 0;k<8;k++){
                        int tx = i+xx[k];
                        int ty = j+yy[k];
                        if(judge(tx,ty,n,m) && mat[tx][ty]==1){
                            edges[count].push_back(count+1);
                            count++;
                        }
                    }
                }
            }
        }







    }



    return 0;
}