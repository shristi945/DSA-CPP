#include<bits/stdc++.h>
using namespace std;
int helper(string s1, string s2, int i, int j, int **dp){
    if(i==0 && j==0) return 0;
    if(i==0 && j>0){
        return j;
    }
    if(j==0 && i>0){
        return i;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int ans =0;
    if(s1[s1.length()-i]==s2[s2.length()-j]){
        ans = helper(s1, s2, i-1, j-1,dp);
    }
    else{
        int ans1 = 1+helper(s1,s2,i-1,j-1,dp);
        int ans2 = 1+helper(s1, s2, i-1, j,dp);
        int ans3 = 1+helper(s1, s2, i, j-1,dp);
        ans = min(ans1, min(ans2, ans3));
    }
    dp[i][j] = ans;
    return ans;
}

int editDistance(string s1, string s2)
{
	//Write your code here
    int m=s1.length(), n=s2.length();
    int **dp = new int *[m+1];
    for(int k=0;k<=m;k++){
        dp[k] = new int[n+1];
    }
    for(int i=0;i<=m;i++){
        dp[i][0] = i;
    }
    for(int j=0;j<=n;j++){
        dp[0][j] = j;
    }
    
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s1[m-i] == s2[n-j]){
                dp[i][j] = dp[i-1][j-1];
            }
            else{
            	dp[i][j] = min(1+dp[i-1][j-1],min(1+dp[i][j-1], 1+dp[i-1][j]) );   
            }
        }
    }
    for(int i =0;i<=m;i++){
        for(int j=0;j<=n;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[m][n];
    
}


int main()
{
	string s1;
	string s2;
    s1 = "abc";
    s2 = "dc";
	// cin >> s1;
	// cin >> s2;
    int m = s1.length();
    int n = s2.length();
    int **dp = new int *[m+1];
    for(int k=0;k<=m;k++){
        dp[k] = new int[n+1];
    }
    for(int i =0;i<=m;i++){
        for(int j=0;j<=n;j++){
            dp[i][j]=-1;    
        }
    }
    cout<<helper(s1,s2,m,n,dp);
	// cout << editDistance(s1, s2) << endl;
}