#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int main() {
    
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<pair<int, int>>interval;
        for(int i=0;i<n;i++){
            int ele1, ele2;
            cin>>ele1>>ele2;
            interval.push_back(make_pair(ele1, ele2));
        }
        sort(interval.begin(), interval.end());
        int ans;
        for(int i=0;i<m;i++){
            int q;
            cin>>q;
            int position = lower_bound(interval.begin(), interval.end(), make_pair(q,0))-interval.begin();
            if(position == 0){
                if(q==interval[position].first) ans = 0;
                else { ans = interval[0].first-q;}
            }
            else if(position>=interval.size()){
                if (interval[position].second>q){
                    ans = 0;
                }
                else{
                    ans = -1;
                }
            }
            else if(interval[position].first == q){
                ans = 0;
            }
            else if(interval[position-1].second<=q){
                ans = interval[position].first-q;
            }
            else if(interval[position-1].second>q){
                ans = 0;
            }
            cout<< ans<<endl;
        }
        
    }
    return 0;
}