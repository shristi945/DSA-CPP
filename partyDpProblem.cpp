#include <bits/stdc++.h>
using namespace std;
vector<int> cost(103); vector<int> fun(103);
vector<vector<int> > dp(103,vector<int>(505,-1));
int N,B; 
int solve(int b, int i){
    
    if(i==N+1){
        return 0;
    }
    if(dp[b][i]!=-1){
        return dp[b][i];
    }
    int ans;
    if(b>=cost[i]){
        ans = max(solve(b,i+1), solve(b-cost[i],i+1)+fun[i]);
    }
    else{
        ans = solve(b,i+1);
    }
    dp[b][i] = ans;
    return ans;
}
int main()
{
    cin>>B>>N;
    while(B||N){
    
        for(int i=1;i<=N;i++){
            cin>>cost[i]>>fun[i];
        }
        for(int i=0;i<=B;i++){
            for(int j=0;j<=N;j++){
                dp[i][j] = -1;
            }
        }
        int res; 
        res = solve(B,0);
        int i;
        for(i=0;i<=B;i++){
            if(solve(i,0)==res){
                break;
            }
        }
        cout<<i<<" "<<res<<endl;
        cin>>B>>N;
    }
 
    return 0;
}
