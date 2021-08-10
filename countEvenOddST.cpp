#include<bits/stdc++.h>
using namespace std;
struct node{
    int even;
    int odd;
};

void buildTree(int *arr, node *tree, int start, int end, int treeNode){

    if(start==end){
        if(arr[start]%2==0){
            tree[treeNode].even = 1;
            tree[treeNode].odd = 0;

        }
        else{
            tree[treeNode].even = 0;
            tree[treeNode].odd = 1;
        }
        
        return;
    }
    int mid = start+(end-start)/2;
    buildTree(arr, tree, start, mid, 2*treeNode);
    buildTree(arr, tree, mid+1, end, 2*treeNode+1);

    tree[treeNode].even = tree[2*treeNode].even+ tree[2*treeNode+1].even;
    tree[treeNode].odd =  tree[2*treeNode].odd + tree[2*treeNode+1].odd;
    return;
}

void updateTree(int *arr, node *tree, int start, int end, int treeNode, int idx, int value){
    if(start == end){
        arr[idx] = value;
        if(value%2==0){
            tree[treeNode].even = 1;
            tree[treeNode].odd = 0;            
        }
        else{
            tree[treeNode].even = 0;
            tree[treeNode].odd = 1;
        }
        return;
    }
    int mid = (start+end)/2;
    if(idx>mid){
        updateTree(arr, tree, mid+1, end, 2*treeNode+1,idx, value);
    }
    else{
        updateTree(arr, tree, start, mid, 2*treeNode,idx, value);
    }
    tree[treeNode].even = tree[2*treeNode].even+ tree[2*treeNode+1].even;
    tree[treeNode].odd =  tree[2*treeNode].odd + tree[2*treeNode+1].odd;
    return;

}

node query(node *tree, int start, int end, int treeNode, int left, int right){

    //completely outside
    if(start>right || end<left){
        node  emptyNode;
        emptyNode.even = 0;
        emptyNode.odd = 0;
        return emptyNode;
    }
    // completely inside
    if(start>=left && end<=right){
        return tree[treeNode];
    }
    // partially inside partially outside
    int mid = (start+end)/2;
    node ans1 = query(tree, start, mid, 2*treeNode, left, right);
    node ans2 = query(tree, mid+1, end, 2*treeNode+1,left, right);
    

    node rootNode;

    rootNode.even = ans1.even+ans2.even;
    rootNode.odd = ans1.odd+ans2.odd;

    return rootNode;
}


int main(){

    int n, q;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    node *tree = new node[4*n];
    
    buildTree(arr, tree, 0, n-1, 1);

    // for(int i=0;i<4*n;i++){
    //     cout<<tree[i].even<<" "<<tree[i].odd<<endl;
    // }

    cin>>q;
    while(q--){
        int type;
        int left, right, idx, value;
        cin>>type;
        if(type == 1){
            cin>>left>>right;
            node ans = query(tree, 0, n-1, 1,left-1, right-1);
            cout<<ans.even<<endl;
        }
        else if(type == 2){
            cin>>left>>right;
            node ans = query(tree, 0, n-1, 1,left-1, right-1);
            cout<<ans.odd<<endl;
        }
        else if(type == 0){
            cin>>idx>>value;
            updateTree(arr, tree, 0, n-1, 1, idx-1, value);
            // cout<<"Updated Tree: "<< endl;
            // for(int i=0;i<4*n;i++){
            // cout<<tree[i].even<<" "<<tree[i].odd<<endl;
            // }
        }
    }
    return 0;
}