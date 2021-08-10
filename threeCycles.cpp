#include <bits/stdc++.h>
using namespace std;

int main() {
    // Write your code here

    int n, m;
    // vector<vector<int>>edges{
    //     {0,1},
    //     {1,2},
    //     {2,4},
    //     {0,4},
    //     {1,4},
    //     {0,3},
    //     {3,4}
    // };
    cin>>n>>m;
    
    vector<vector<int>>edges(n,vector<int>(m, 0));
    for(int i=0;i<m;i++){
        int v1, v2;
        cin>>v1>>v2;
        
        edges[v1][v2]=1;
        edges[v2][v1]=1;
    }
    int c = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(edges[i][j] == 1){
                for(int k=0;k<n;k++){
                    if(k!=i && edges[j][k]==1 && edges[k][i]==1){
                        c++;
                    }
                }
            }
        }
    }
    cout<<c/6;
    return 0;
}