#include<bits/stdc++.h>
using namespace std;

int superSeq(string s, string t){
    int n = s.length();
    int m = t.length();
    int ** dp = new int *[n+1];
    for(int i=0;i<=n;i++){
        dp[i] = new int [m+1];
    }
    for(int i=0;i<=n;i++){
        dp[i][0] = i;
    }
    for(int j=1;j<=m;j++){
        dp[0][j] = j;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[n-i]==t[m-j]){
                dp[i][j] = 1+dp[i-1][j-1];
            }
            else{
                dp[i][j] = 1+ min(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[n][m];

}

int main(){

    string s,t;
    cin>>s>>t;

    cout<<superSeq(s,t);


    return 0;
}