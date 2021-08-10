#include <bits/stdc++.h>
# define m 1000000007
using namespace std;    


long long int alphaCodes(int * input, int size){
    if(size==1 || size == 0) return 1;
    long long int * dp = new long long int[size+1]();
    dp[0] = 1;
    dp[1] = 1;
    for(int i=2;i<=size;i++){
        dp[i] = dp[i-1];
        if(((input[i-2]*10)+input[i-1])<=26 && ((input[i-2]*10)+input[i-1])>=10){
            dp[i] += dp[i-2];
        }
        dp[i] = dp[i]%m;
    }
    long long int ans = dp[size];
    delete [] dp;
    return ans;
}

int main()
{	int num = 1;
 	vector<int>nums;
    while(num!=0){
        cin>>num;
        nums.push_back(num);
    }
 	for(int j=0;j<nums.size();j++){
        int *input = new int[5000];
        int x = nums[j], i=0;
        if(x!=0){
            while(x){
                input[i++] = x%10;
                x = x/10;
            }
            reverse(input, input + i);
            int size = i;
            // int * dp = new int[size+1]();
            cout<<alphaCodes(input, size)<<endl;
        }
        
    }
    
    return 0;
}
