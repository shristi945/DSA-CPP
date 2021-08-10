#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
int main()
{
    int n;
    cin>>n;
    int *a = new int[n];
    for(int i =0;i<n;i++){
        cin>>a[i];
    }
    int **dp = new int *[n];
    for(int i=0;i<n;i++){
    	dp[i] = new int[100];
    }
    for(int i=0;i<n;i++){
        dp[i][a[i]] = 1;
        for(int j=i-1;j>=0;j--){
            if(a[j]<a[i]){
                for(int g=1;g<=100;g++){
                    int ng = gcd(a[i],g);
                    dp[i][ng] += dp[j][g];
                }
            }
        }
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        ans += dp[i][1];
    }
    cout<<ans;
    return 0;
}
