#include <bits/stdc++.h>
using namespace std;


int perimeter(vector<vector<int>>grid, int i, int l, int d, int r) {
    int c1=(l+r)/2, c2=(l+r)/2;int sum=0;bool expand = true;
    while(i<=d){
        if(c1==c2){
            sum+=grid[i][c1];
        }
        else{
            sum+=grid[i][c1]+grid[i][c2];
        }
        if(c1==l)expand=false;
        if(expand){
            c1--;c2++;
        }
        else{
            c1++;c2--;
        }
        i++;
    }
    return sum;
}


vector<int> solve(vector<vector<int>>grid){
    set<int>s;
    int n = grid.size();
    int m = grid[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int l=j, r=j;int d=i;
            while(l>=0 && r<m && d<n){
                int tot=perimeter(grid, i, l, d, r);
                l--;r++;d+=2;
                s.insert(tot);
            }
        }
    }
    if (s.size() < 3)
        return vector<int>(s.rbegin(), s.rend());
    return vector<int>(s.rbegin(), next(s.rbegin(), 3));
}


int main(){
    vector<vector<int>>grid{
        {3,4,5,1,3},
        {3,3,4,2,3},
        {20,30,200,40,10},
        {1,5,5,4,1},
        {4,3,2,2,5}
        // {7,7,7}
    };
    
    vector<int>res = solve(grid);
    for(int i =0;i<res.size();i++){
        cout<<res[i]<<" ";
    }

    return 0;
}