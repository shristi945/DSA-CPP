#include<bits/stdc++.h>
using namespace std;
int LCS(string s1, string s2,int i,int j,int **dp){
    if(s1.length()==i||s2.length()==j){
        return 0;
    }
    int ans=0;
    if(dp[i][j]>0){
        return dp[i][j];
    }
    if(s1[i]==s2[j]){
        ans =  1+LCS(s1, s2, i+1,j+1,dp);
        dp[i][j] = ans;
        return ans;
    }
    int ans1 = LCS(s1,s2,i+1,j,dp);
    int ans2 = LCS(s1,s2,i,j+1,dp);
    ans = max(ans1, ans2);
    dp[i][j] = ans;
    return ans;

}
int main(){
    string str1 ="abcdefghijklmnopqrstuvwxyz";
    string str2 = "zgwabcdegqwdhiklmnopqadsrtuwevxzgwe";
    int **dp = new int*[str1.length()];
    for(int i =0;i<str1.length();i++){
        dp[i] = new int[str2.length()];
    }
    cout<<26-LCS(str1, str2, 0,0,dp);
    return 0;
}