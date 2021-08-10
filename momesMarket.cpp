#include<bits/stdc++.h>
using namespace std;
int main() {

	// Write your code here
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    // int prefixSum[n];
    vector<int> prefixSum(n);
    prefixSum[0] = arr[0];
    for(int i=1;i<n;i++){ 
        prefixSum[i] = prefixSum[i-1]+arr[i];       
    }
    int q;
    cin>>q;
    while(q--){
        long long x;
        cin>>x;
        long long remX = x; int momoCount = 0;

        long long pos = lower_bound(prefixSum.begin(), prefixSum.end(),x)-prefixSum.begin();
        if(x==prefixSum[pos]){
            cout<<pos+1<<" "<<x-prefixSum[pos]<<endl;
        }
        else{
            cout<<pos<<" "<<x-prefixSum[pos-1]<<endl;
        }
    }
    return 0;
}