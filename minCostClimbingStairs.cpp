#include<bits/stdc++.h>
using namespace std;

int minCostClimbing(vector<int>&arr, int i){
    
    if(i==arr.size()-1 || i==arr.size()-2){
        return 0;
    }

    int ans = min(minCostClimbing(arr, i+1)+arr[i+1], 
              minCostClimbing(arr, i+2)+arr[i+2]);

    return ans;
}

int main(){
    vector<int>arr{10, 15, 20};
    
    cout<<minCostClimbing(arr, -1);

    return 0;
}