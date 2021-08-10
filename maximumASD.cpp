#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    int sum = 0; int M =  1000000007;
    vector<int> origDiff(n);
    for(int i =0;i<n;i++){
        origDiff[i] = abs(nums1[i]-nums2[i]);
        sum += abs(nums1[i]-nums2[i]);
    }
    sort(nums1.begin(), nums1.end());
    vector<int>best(n);
    for(int i=0;i<n;i++){
        int j = lower_bound(nums1.begin(), nums1.end(), nums2[i])-nums1.begin();
        if(j!=n && j!=0)
            best[i] = min(abs(nums1[j]-nums2[i]), abs(nums1[j-1]-nums2[i]));
        else if(j==0)
            best[i]= abs(nums1[j]-nums2[i]);
        else if(j==n)
            best[i]=abs(nums1[j-1]-nums2[i]);
    }
    
    for(int i=0;i<n;i++){
        best[i] = origDiff[i]-best[i];
    }
    
    return (sum-(*max_element(best.begin(), best.end())));
}

int main(){
    vector<int> nums1 = {1, 10, 4, 4, 2, 7};
    vector<int> nums2 = {9, 3, 5, 1, 7, 4};
    cout<<minAbsoluteSumDiff(nums1, nums2);
}