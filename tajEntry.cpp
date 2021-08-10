#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> v, res;
    for(int i=0;i<n;i++){
        int ele;
        cin>>ele;
        v.push_back(ele);
    }
    int t = *max_element(v.begin(), v.end()); 
    for(int i=0;i<n;i++){
        int mid;
        int start = 0, end = t; int ans = -1;
        while(start<=end){
            mid = start + (end-start)/2;
            if(i+mid*n>=v[i]){
                ans = mid;
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        res.push_back(i+(ans*n));
    }
    int min_index = n; int min_t = t;
    for(int i=0;i<res.size();i++){
        if(res[i]<min_t){
            min_t = res[i];
            min_index = i;
        }
    }   
    cout<<min_index+1;

	return 0;
}
