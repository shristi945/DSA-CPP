#include<bits/stdc++.h>
using namespace std;
int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
    
    vector<pair<int,int>>performance;
    
    priority_queue<int, vector<int>, greater<int>>taken;
    
    for(int i=0;i<n;i++){
        performance.push_back(make_pair(efficiency[i], speed[i]));
    }
    sort(performance.begin(), performance.end(),greater<pair<int,int>>());
    int ts = 0, eff = INT_MAX; int maxPerformance = 0;
    for(int i=0;i<n;i++){
        if(taken.size()<k){
            ts+=performance[i].second;
            eff = min(performance[i].first, eff);
            maxPerformance = max(ts*eff, maxPerformance);
            taken.push(performance[i].second);
        }    
        else if(!taken.empty() && taken.size()== k ){
            int minus = taken.top();
            ts = ts-minus;
            eff = min(eff, performance[i].first);
            ts += performance[i].second;
            maxPerformance = max(maxPerformance,ts*eff);
            taken.pop();
            taken.push(performance[i].second);

        }
    }
    return maxPerformance;
}


int main(){
    int k=4;
    int n=6;
    vector<int> speed {2,10,3,1,5,8};
    vector<int> efficiency{5,4,3,9,7,2};
    cout<<maxPerformance(n, speed, efficiency, k);
    return 0;
}