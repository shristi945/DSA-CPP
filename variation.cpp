#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){

    int n, k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr, arr+n);
    int count = 0;
    // for(int i=0;i<n;i++){
    //     int j = i+1;
    //     while(i<=j and j<n){
    //         if(abs(arr[i]-arr[j])>=k){
    //             count = count + n-j;
    //             i++;
    //             // if(i==j)j++;
    //         }
    //         else{
    //             j++;
    //         }
    //     }
    // }

    for(int i=0;i<n;i++){
        int left = i+1, right = n-1, mid = left + (right-left)/2, ans = -1;
        while(left<=right && i!=mid){
            int mid = left + (right-left)/2;
            if(abs(arr[i]-arr[mid])>=k){
                ans = mid;
                right = mid;

            }
            else{
                left = mid+1;
            }
        }
        count += n-ans;
    }
    
    cout<<count;
}