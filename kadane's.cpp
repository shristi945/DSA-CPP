#include<bits/stdc++.h>
using namespace std;

int main(){

    vector<int> arr{-6, -1, -2, -4, -5, -2, -8, -2};int curr_sum =0;int best_so_far = INT_MIN;
    for(int i=1;i<arr.size();i++){
        curr_sum += arr[i];
        if(curr_sum>best_so_far){
            best_so_far = curr_sum;
        } 
        if(curr_sum<0){
            curr_sum = 0;
        }
    }
    cout<<best_so_far;

    return 0;

}