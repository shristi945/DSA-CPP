#include<bits/stdc++.h>
using namespace std;
int main() {

	// Write your code here
    int t;
    cin>>t;
    while(t--){
        int n;
        long long k;
        cin>>n;
        cin>>k;
        long long arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr, arr+n);
        int start = 0, end = arr[n-1], mid, ans = -1;
        while(start<=end){
            long long person = 0;
        	mid = start+(end-start)/2;
            for(int i=0;i<n;i++){
                if(arr[i]>=mid){
                    person = person+(arr[i]/mid);
                }
                if(person>=k){
                    ans = mid;
                    start = mid+1;
                    break;
                }
            }       
            if(person<k){
                end = mid-1;
            }
        }
        cout<<ans<<endl;
    }
}