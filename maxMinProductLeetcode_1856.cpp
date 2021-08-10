#include <bits/stdc++.h>
using namespace std;

int maxSumMinProduct(vector<int>& nums) {
    long long MOD = 1e9+7;
    long long prefixSum[nums.size()+1];
    int n = nums.size();
    prefixSum[0] = 0;
    for(int i=1;i<=n;i++){
        prefixSum[i] = prefixSum[i-1]+nums[i-1];
    }
    int left [n], right[n];
    stack<int> s1,s2;
    for(int i=0;i<n;i++){
        while(!s1.empty() && nums[i]<=nums[s1.top()])
        {
            s1.pop();
        }
        if(s1.empty()){
            left[i]=-1;
        }
        else{
            left[i]=s1.top();
        }
        s1.push(i);
    }
    for(int i=n-1;i>=0;i--){
        while(!s2.empty() && nums[i]<=nums[s2.top()]){
            s2.pop();
        }
        if(s2.empty()){
            right[i]=n;
        }
        else{
            right[i]=s2.top();
        }
        s2.push(i);
    }

    long long maxi=0;
    for(int i=0;i<n;i++){
        long long sum = (prefixSum[right[i]]-prefixSum[left[i]+1]);
        long long prod = (sum * nums[i]);
        maxi = max(maxi, prod);
    }
    return (int)maxi%MOD;
}


int main()
{
    vector<int> nums{2,3,3,1,2};

    cout<<maxSumMinProduct(nums);

    return 0;
}