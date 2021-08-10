#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int countSubsequence(string s){
    int n = s.length();
    int *dp = new int[n+1];
    unordered_map<char,int>m;
    dp[0] = 1;
    for(int i=0;i<s.length();i++){

        if(m.find(s[i])==m.end()){
            dp[i+1] = 2*dp[i];
            
        }
        else{
            dp[i+1] = 2*dp[i] -(dp[m[s[i]]]);
        }
        m[s[i]]=  i;
    }
    return dp[n]%MOD;

}


int main(){


    int t;
    cin>>t;

    while(t--){
        
        string s;
        cin>>s;
        cout<<countSubsequence(s)<<endl;


    }
    return 0;
}