#include<bits/stdc++.h>
using namespace std;

int main(){
    int n=7, k=10, x=8;
    // cin>>n>>k>>x;
    vector<int>nums {31,20,25,25,11,28,27};
    vector<int>arr(1001);
    for(int i=0;i<n;i++){
        // cin>>nums[i];
        arr[nums[i]]++;
    }
    sort(nums.begin(), nums.end());
    while(k--){
        int flag = 0;vector<int>temp(1001);
        for(int i=0;i<nums.size();i++){
            int numToZor = 0; int remaining = 0;
            if(flag==0 && arr[nums[i]]%2 == 0){
                numToZor = arr[nums[i]]/2;
                remaining = arr[nums[i]]-numToZor;
                flag = 0;
            }
            else if(flag==1 && arr[nums[i]]%2 == 0){
                numToZor = arr[nums[i]]/2;
                remaining = arr[nums[i]]-numToZor;
                flag = 1;
            }
            else if(flag==0 && arr[nums[i]]%2 != 0){
                numToZor = (arr[nums[i]]+1)/2;
                remaining = arr[nums[i]]-numToZor;
                flag = 1;
            }
            else if(flag==1 && arr[nums[i]]%2 != 0){
                numToZor = ((arr[nums[i]]+1)/2)-1;
                remaining = arr[nums[i]]-numToZor;
                flag = 0;
            }
            int newNum = nums[i]^x;
            temp[newNum] += numToZor;
            temp[nums[i]] += remaining;
        }

        arr.erase(arr.begin(), arr.end());
        arr = temp;
        temp.erase(temp.begin(),temp.end());

    }
    
    int mini = 0, maxi = 0;
    for(int i=1000;i>=0;i--){
        if(arr[i]>0){
            cout<<i<<" ";break;
        }
    }
    for(int i=0;i<=1000;i++){
        if(arr[i]>0){
            cout<<i;break;
        }
    }

    return 0;
    
}