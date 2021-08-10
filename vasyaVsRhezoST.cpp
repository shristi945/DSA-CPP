#include<bits/stdc++.h>
using namespace std;
struct warrior{
    int a;
    int b;
};

void buildTree(warrior *arr, int *tree, int start, int end, int treeNode){

    if(start==end){
        tree[treeNode] = start;
        return;
    }
    int mid = start+(end-start)/2;
    buildTree(arr, tree, start, mid, 2*treeNode);
    buildTree(arr, tree, mid+1, end, 2*treeNode+1);

    int right = tree[2*treeNode+1];
    int left = tree[2*treeNode];

    if(arr[right].a > arr[left].a){
        tree[treeNode] = right;
    }
    else if(arr[right].a < arr[left].a){
        tree[treeNode] = left;
    }
    else{
        if(arr[right].b<arr[left].b){
            tree[treeNode] = right;
        }
        else if(arr[right].b>arr[left].b){
            tree[treeNode] = left;
        }
        else{
            if(right<left){
                tree[treeNode] = right;
            }
            else{
                tree[treeNode] = left;
            }
        }
    }

    return;
}

int query(warrior *arr, int *tree, int start, int end, int treeNode, int left, int right){

    //completely outside
    if(start>right || end<left){
        int n = 4*(end);
        arr[n].a = -1;
        arr[n].b = -1;
        return n; 
    }
    // completely inside
    if(start>=left && end<=right){
        return tree[treeNode];
    }
    // partially inside partially outside
    int mid = (start+end)/2;
    int ans1 = query(arr, tree, start, mid, 2*treeNode, left, right);
    int ans2 = query(arr, tree, mid+1, end, 2*treeNode+1,left, right);
    
    int ans = -1;
    if(arr[ans1].a > arr[ans2].a){
        ans = ans1;
    }
    else if(arr[ans1].a < arr[ans2].a){
        ans = ans2;
    }
    else{
        if(arr[ans1].b<arr[ans2].b){
            ans = ans1;
        }
        else if(arr[ans1].b>arr[ans2].b){
            ans = ans2;
        }
        else{
            if(ans1<ans2){
                ans = ans1;
            }
            else{
                ans = ans2;
            }
        }
    }
    return ans;
}


int main(){

    int n, q;
    cin>>n;
    warrior *arr = new warrior[n];
    for(int i=0;i<n;i++){
        cin>>arr[i].a;
    }
    for(int i=0;i<n;i++){
        cin>>arr[i].b;
    }
    int *tree = new int[4*n+1];
    for(int i=0;i<=4*n;i++){
        tree[i] = -2;
    }
    
    buildTree(arr, tree, 0, n-1, 1);

    for(int i=0;i<4*n;i++){
        cout<<tree[i]+1<<endl;
    }

    cin>>q;
    while(q--){
        int left, right;
        cin>>left>>right;
        int ans = query(arr, tree, 0, n-1, 1,left-1, right-1);
        cout<<ans+1<<endl;
    }
    return 0;
}