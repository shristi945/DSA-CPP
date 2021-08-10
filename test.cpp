#include <bits/stdc++.h>
using namespace std;
     




int main()
{
    vector<int>arr{3,2,3};
    int target = 6;

    int n = arr.size();
    unordered_map<int,int>m;
    vector<int> res;
    for(int i=0;i<n;i++){
        if(m.find(target-arr[i])==m.end()){
            m[arr[i]] = i; 
        }
        else{
            int seenNum = target-arr[i];
            res = {m[seenNum], i};
            break;
        }
    }

    cout<<"["<<res[0]<<","<<res[1]<<"]";
    
    
    return 0;
}