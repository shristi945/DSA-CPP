// #include<bits/stdc++.h>
// #define MAX 1005
// using namespace std;

// int findShortestSubSeq(string s, string v, int i, int j){
//     // cout<<i<<" "<<j<<endl;
    
//     if(j>=v.length()){
//         return 1;
//     }
    
//     if(i==s.length()){
//         return MAX;
//     }
    
//     int o1 = findShortestSubSeq(s,v,i+1,j);

//     int index;
//     for(int index=0;index<v.length();index++){
//         if(v[index]==s[i]){
//             break;
//         }
//     }
//     if(index==v.length()){
//         return 1;
//     }

//     return min(o1,1+findShortestSubSeq(s,v,i+1, index+1));


// }


// int main(){

//     string s = "babab";
//     string v = "babba";

//     int ans = findShortestSubSeq(s,v, 0,0);

//     if (ans >= MAX)
//        ans = -1;
//     cout << ans << endl;


//     return 0;
// }


#include<bits/stdc++.h>

#define MAX 1005

using namespace std;

int findShortestSubSeq(string s, string v, int i, int j,int dp[1002][1002],int next[1002][1002]){
    
    // cout<<i<<" "<<j<<endl;
    if(j==v.length()){
        return 1;
    }
    if(i==s.length()){
        return MAX;
    }

if(dp[i][j]!=-1){
    return dp[i][j];
}
    int option1=findShortestSubSeq(s,v,i+1,j,dp,next);
   int index=next[i][j];
  
    if(index==-1){
        dp[i][j]= 1;
        return dp[i][j];
    }

    return dp[i][j]=min(option1,1+findShortestSubSeq(s,v,i+1, index+1,dp,next));
    
    
    
}

int solve(string s, string v) {
    // Write your code here
   
   
     int dp[1002][1002];
     for(int i=0;i<=1000;i++)
     {
         for(int j=0;j<=1000;j++)
         {
             dp[i][j]=-1;
         }
     }
      int next[1002][1002];
     for(int i=0;i<s.length();i++)
     {
         int prev=-1;
         for(int j=v.length()-1;j>=0;j--)
         {
              if(s[i]==v[j])
             {
                 prev=j;
             }
             next[i][j]=prev;
            
         }
     }
     
    int ans=0;
	ans = findShortestSubSeq(s,v,0,0,dp,next);
    
    return ans;
    
    
}

int main(){

    string s = "babab";
    string v = "babba";

    int ans = solve(s,v);
    cout<<ans;

    return 0;
}