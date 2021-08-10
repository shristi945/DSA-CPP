#include<bits/stdc++.h>
using namespace std;

struct Jobs{
    int startTime;
    int finishTime;
    int profit;
};

bool comp(struct Jobs a,struct Jobs b){

    return a.finishTime<b.finishTime;
}

int bs(int start, int end, Jobs arr[], int i){
    int mid; int ans=-1;
    while(start<=end){
        mid = start+ (end-start)/2;
        if(arr[mid].finishTime<=arr[i].startTime){
            ans = mid;
            start = mid+1;
        }
        else{
            end = mid-1;
        }
    }
    // cout<<"ans: "<<ans<<endl;
    return ans;
}


int main(){
    int n;
    cin>>n;
    Jobs *arr = new Jobs[n];
    for(int i=0;i<n;i++){
        cin>>arr[i].startTime>>arr[i].finishTime>>arr[i].profit;
    }
    vector<int>res(n);
    sort(arr, arr+n, comp);
    // for(int i=0;i<n;i++){
    //     cout<<arr[i].startTime<<" "<<arr[i].finishTime<<" "<<arr[i].profit<<endl;
    // }
    res[0] = arr[0].profit;
    for(int i=1;i<n;i++){
        int j=i-1; int option1=arr[i].profit;int leftConflict=-1; int start=0, end=j;
        leftConflict = bs(start,end,arr,i);
        cout<<leftConflict<<endl;
        if(leftConflict!=-1){
            option1+=res[leftConflict];
        }
        res[i] = max(res[i-1], option1);
    }

    cout<<res[n-1];


    return 0;
}