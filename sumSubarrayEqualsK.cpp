#include<bits/stdc++.h>
using namespace std;

int subarraySum(vector<int>& nums, int k) {
    int sum =0;int count =0;
    vector<int> ls;
    ls.push_back(nums[0]);
    for(int i=1;i<nums.size();i++){
        ls.push_back(ls[i-1]+nums[i]);
    }
    for(int i=0;i<nums.size();i++){
        for(int j=i;j<nums.size();j++){
            if(i==0){
                sum = ls[j];
                if(sum==k)count++;
            }
            else{
                sum = ls[j]-ls[i-1];
                if(sum==k)count++;
            }
        }
    }
    return count;
}

int subarraySum2(vector<int>& nums, int k){
    int curr_sum = 0; unordered_map<int, int>m; int count = 0;
    m[0] = 1;
    for(int i=0;i<nums.size();i++){ 
        curr_sum += nums[i];
        if(m.find(curr_sum-k)!=m.end()){
            count += m[curr_sum-k];
        }
        if(m.find(curr_sum)==m.end()){
            m[curr_sum] = 1;
        }
        else{
            m[curr_sum]++;
        }

    }
    return count;
}

int main(){

    vector<int> nums;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int ele;
        cin>>ele;
        nums.push_back(ele);
    }
    int k;
    cin>>k;

    cout<<subarraySum2(nums, k);


    return 0;
}