#include<bits/stdc++.h>
using namespace std;

void buildTree(int *arr, int *tree, int start, int end, int treeNode){

    if(start==end){
        tree[treeNode] = arr[start];
        return;
    }
    int mid = start+(end-start)/2;
    buildTree(arr, tree, start, mid, 2*treeNode);
    buildTree(arr, tree, mid+1, end, 2*treeNode+1);

    tree[treeNode] = min(tree[2*treeNode], tree[2*treeNode+1]);
}

void updateSegmentTreeLazy(int *tree, int *lazy, int start, int end,int left, int right, 
                           int treeNode,int val){
    if(start>end)return;
    if(lazy[treeNode]!=0){
        tree[treeNode] += lazy[treeNode];
        if(start!=end){
            lazy[2*treeNode] += lazy[treeNode];
            lazy[2*treeNode+1] += lazy[treeNode];
        }
        lazy[treeNode] = 0;

    }

    // completely outside
    if(left>end || right<start)return;

    // completely inside
    if(left<=start && end<=right){
        tree[treeNode]+=val;
        if(start!=end){
            lazy[2*treeNode] += val;
            lazy[2*treeNode+1] += val;
        }
        return;
    }
    // partially inside out
    int mid = (start+end)/2;
    updateSegmentTreeLazy(tree, lazy, start, mid, left, right, 2*treeNode, val);
    updateSegmentTreeLazy(tree, lazy, mid+1, end, left, right, 2*treeNode+1, val);

    tree[treeNode] = min(tree[2*treeNode], tree[2*treeNode+1]);




}

void updateTree(int *arr, int *tree, int start, int end, int treeNode, int idx, int value){
    if(start == end){
        arr[idx] = value;
        tree[treeNode] = value;
        return;
    }
    int mid = (start+end)/2;
    if(idx>mid){
        updateTree(arr, tree, mid+1, end, 2*treeNode+1,idx, value);
    }
    else{
        updateTree(arr, tree, start, mid, 2*treeNode,idx, value);
    }
    tree[treeNode] = min(tree[2*treeNode], tree[2*treeNode+1]);

}

int query(int *tree, int start, int end, int treeNode, int left, int right){

    //completely outside
    if(start>right || end<left){
        return INT_MAX;
    }
    // completely inside
    if(start>=left && end<=right){
        return tree[treeNode];
    }
    // partially inside partially outside
    int mid = (start+end)/2;
    int ans1 = query(tree, start, mid, 2*treeNode, left, right);
    int ans2 = query(tree, mid+1, end, 2*treeNode+1,left, right);

    return min(ans1,ans2);

}

int main(){

    // int n, q;
    // cin>>n;
    // cin>>q;
    int arr[] = {1,3,-2,4};
    // for(int i=0;i<n;i++){
    //     cin>>arr[i];
    // }

    int *tree = new int[12]();
    // for(int i=0;i<2*n;i++){
    //     tree[i]=0;  
    // }
    buildTree(arr, tree, 0, 3, 1);

    cout<<"Original Tree"<<endl;
    for(int i=0;i<12;i++){
        cout<<tree[i]<<" ";  
    }
    
    int *lazy = new int [12]();

    updateSegmentTreeLazy(tree, lazy, 0, 3, 0, 3, 1, 3);
    updateSegmentTreeLazy(tree, lazy, 0, 3, 0, 1, 1, 2);
    
    cout<<"Lazy Propagation Updated"<<endl;
    for(int i=1;i<12;i++){
        cout<<tree[i]<<" ";
    }
    cout<<endl;

    cout<<"Lazy Tree"<<endl;
    for(int i=1;i<12;i++){
        cout<<lazy[i]<<" ";
    }
    cout<<endl;



    // while(q--){
    //     char type;
    //     int left, right, idx, value;
    //     cin>>type;
    //     if(type == 'q'){cout<<"Updated Tree"<<endl;
    //         // printTree(tree,n);
    //         cin>>left>>right;
    //         int ans = query(tree, 0, n-1, 1,left-1, right-1);
    //         cout<<ans;
    //     }
    //     else if(type == 'u'){
    //         cin>>idx>>value;
    //         updateTree(arr, tree, 0, n-1, 1, idx-1, value);
    //         // cout<<"Updated Tree"<<endl;
    //         // printTree(tree,n);

    //     }

    // }
    return 0;
}