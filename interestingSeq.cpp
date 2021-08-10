#include<bits/stdc++.h>
using namespace std;
int main() {
    
    int n, k, l;
    cin>>n>>k>>l;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int maxValue = *max_element(arr.begin(), arr.end());
    int minValue = *min_element(arr.begin(), arr.end());
    int minCost = 1000001;
    for(int i=minValue; i<=maxValue;i++){
        int inc = 0, dec = 0;int inc_count = 0, dec_count = 0;
        for(int j=0;j<n;j++){
            if(arr[j]<i){
                inc += arr[j]; inc_count++;
            }
            else if(arr[j]>i){
                dec += arr[j]; dec_count++;
            }
        }
        if(dec<=inc){
        	int cost = (dec_count*k)+(inc_count-dec_count)*l;
            minCost = min(minCost, cost);
    	}
    }
    cout<<minCost<<endl;

	
}