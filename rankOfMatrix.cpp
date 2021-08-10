#include <bits/stdc++.h>
using namespace std; 



int main(){

    vector<vector<int>>mat{
        {20, -21, 14},
        {-19, 4, 19},
        {22, -47, 24},
        {-19, 4, 19}
    };
    int n = mat.size();
    int m = mat[0].size();

    vector<vector<int>>mapp(n*m, vector<int>(3));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            mapp[0] = mat[i][j];
            mapp[1] = i;
            mapp[2] = j;        }
    }

    for(auto it: mapp){
        cout<<it[0]<<
    }

    vector<vector<int>>rank(n, vector<int>(m,0));
    
    for(auto it = mapp.begin(); it!=mapp.end();it++){
        int i=it->second.first;
        int j=it->second.second;
        int max_rank = 0;    
        for(int v = 0; v<n;v++){
            max_rank = max(max_rank, rank[v][j]);
        }
        for(int h = 0; h<m;h++){
            max_rank = max(max_rank, rank[i][h]);
        }
        rank[i][j] = max_rank+1;
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<rank[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}