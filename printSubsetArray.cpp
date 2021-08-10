#include<bits/stdc++.h>

using namespace std;
void findSubsets(vector<int>arr, int i, int n, vector<int>&subset,int j){
    if(i==n){
        int index = 0;
        while(index<j){
            cout<<subset[index]<<" ";
            ++index;
        }
        cout<<endl;
        return;
    }
    findSubsets(arr, i+1, n, subset,j);
    subset[j] = arr[i];
    findSubsets(arr, i+1, n, subset, j+1);
}

int main(){
    vector<int>arr{1,2,3};
    vector<int>subset(100);
    // print all the subsets

    findSubsets(arr, 0, arr.size(),subset,0);
    return 0;
}