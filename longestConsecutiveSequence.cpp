#include <iostream>
#include<bits/stdc++.h>
#include <algorithm>
using namespace std;    // std::min 

vector<int> longestConsecutiveIncreasingSequence(int *arr, int n) {
    // Your Code goes here
    int max_len = 1;
    int startc = arr[0];
    int start = arr[0];
    vector<int>res;
    map<int, bool>m;
    for(int i=0; i<n;i++){
        m[arr[i]] = false;
    }
    int i=0;
    while(i<n){
        int num = arr[i];
        if(m[num] == false){
            m[num] = true;
            int right = num+1; startc = num; int lenc = 1;
            while(m.find(right)!=m.end() && m[right] == false ){
                lenc++;
                m[right] = true;
                right++;
            }
            int left = startc-1;
            while(m.find(left)!=m.end() && m[left] == false){
                startc = left;
                lenc++;
                m[left] = true;
                left--;
            }
            if(max_len == lenc){
                int mi = lower_bound(arr, arr+n,start)-arr;
                int li = lower_bound(arr, arr+n,startc)-arr;
                start = arr[min(mi, li)];
            }
            if(max_len<lenc){
                max_len = lenc;
                start = startc;
            }
        } 
        i++;
    }
    for(int i=start;i<=max_len;i++){
        res.push_back(i);
    }
    return res;
}

int main() {
    int size;
    cin >> size;

    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    vector<int> ans = longestConsecutiveIncreasingSequence(arr, size);

    cout << ans[0];
    if (ans.size() > 1) {
        cout << " " << ans[ans.size() - 1];
    }

    delete[] arr;
}