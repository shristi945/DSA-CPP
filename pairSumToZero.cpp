#include<bits/stdc++.h>
using namespace std;
int pairSum(int *arr, int n) {
	// Write your code here
    map<int, int>m; int count =0;
    for(int i=0;i<n;i++){
        if(m.find(arr[i])==m.end()){
            m[arr[i]]=1;
            if(arr[i]!=0 and m.find(-arr[i])!=m.end()){
                count = count + m[-arr[i]];
            }
        }
        else{
            m[arr[i]]++;
            if(arr[i]!=0 and m.find(-arr[i])!=m.end()){
                count = count + m[-arr[i]];
            }
        }
    }
    
    if(m.find(0)!=m.end()){
        int n_zero = m[0];
        count = count+ (n_zero*(n_zero-1))/2;
    }
    return count;
}

int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << pairSum(arr, n);

    delete[] arr;
}