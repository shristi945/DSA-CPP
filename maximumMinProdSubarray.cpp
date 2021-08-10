#include<bits/stdc++.h>
using namespace std;

int maxminprodSubarray(vector<int>nums){
    vector<int>dp(nums.size());
    for(int i=0;i<nums.size();i++){
        int j=i-1, k=i+1; int sumSubarray =nums[i];
        while(j>=0 && nums[j]>=nums[i]){
            sumSubarray += nums[j--];
        }
        while(k<nums.size() && nums[k]>=nums[i]){
            sumSubarray += nums[k++];
        }
        int x = sumSubarray*nums[i];
        dp[i] = x;
    }
    return *max_element(dp.begin(), dp.end());
}



int main(){

    vector<int>nums{2,3,3,1,2};
    cout<<maxminprodSubarray(nums);

    return 0;
}