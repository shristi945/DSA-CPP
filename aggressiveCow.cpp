#include<bits/stdc++.h>
using namespace std;
int main() {

	// Write your code here
    int t;
    cin>>t;
    while(t--){
        int n, c;
        cin>>n>>c;
        long long arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr, arr+n);
        long long start = 0, end = arr[n-1]-arr[0];
        long long ans = -1;
        while(start<=end){
            long long mid = start+(end-start)/2; int cowCount = c-1; long long position = arr[0];
            for(int i=1;i<n;i++){
                if(cowCount>0 && arr[i]-position >= mid){
                    cowCount --;
                    position = arr[i];
                }
                if(cowCount == 0){
                    break;
                }
            }
            if(cowCount == 0){
                ans = mid;
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        cout<<ans<<endl;
        }
}