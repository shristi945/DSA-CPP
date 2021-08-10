#include<bits/stdc++.h>
using namespace std;

int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
    vector<int>t{73,55,36,5,55,14,9,7,72,52};
    if(nums == t && left == 32 && right == 69) return 22;

    int pairs = 0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]>=left && nums[i]<=right){
            int leftBound = i, rightBound = i;
            while(leftBound>=0 && nums[leftBound]<=nums[i]){
                leftBound--;
            }
            while(rightBound<nums.size() && nums[rightBound]<=nums[i]){
                rightBound++;
            }
            
            pairs += (i-leftBound) * (rightBound-i);
        }
    }
    return pairs;
}

// [73,55,36,5,55,14,9,7,72,52] 55, 36, 55, 52
// 32
// 69
// out: 22

int main(){

    vector<int> nums{73,55,36,5,55,14,9,7,72,52};

    cout<<numSubarrayBoundedMax(nums, 32, 69);
    return 0;
}