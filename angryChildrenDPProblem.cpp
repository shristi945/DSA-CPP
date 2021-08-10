#include <bits/stdc++.h>
using namespace std;

int main(){ 

    int n = 10,k = 4;
    // cin>>n>>k;
    vector<int>arr{1,2,3,4,10,20,30,40,100,200};
    // for(int i=0;i<n;i++){
    //     cin>>arr[i];
    // }
    sort(arr.begin(),arr.end());
    int minCost = INT_MAX;
    // 10 20 30 100 200 300 1000
    int prefixSum = arr[0]; int targetCost = 0; int i;
    for(i=1;i<k;i++){
        targetCost += i*arr[i]-prefixSum;
        prefixSum += arr[i];
    }
    minCost = targetCost;
    int first=0; int last=k;
    while(last<n){
        targetCost = targetCost -2*(prefixSum-arr[first])+(k-1)*(arr[first])+(k-1)*(arr[last]);
        minCost = min(minCost, targetCost);
        prefixSum += arr[last] - arr[first]; 
        first++;
        last++;
    }
    
    cout<<minCost;


    return 0;
}