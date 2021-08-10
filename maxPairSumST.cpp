#include<bits/stdc++.h>
using namespace std;
struct node{
    int fmax;
    int smax;
};

void buildTree(int *arr, node *tree, int start, int end, int treeNode){

    if(start==end){
        tree[treeNode].fmax = arr[start];
        tree[treeNode].smax = 0;
        return;
    }
    int mid = start+(end-start)/2;
    buildTree(arr, tree, start, mid, 2*treeNode);
    buildTree(arr, tree, mid+1, end, 2*treeNode+1);

    tree[treeNode].fmax = max(tree[2*treeNode].fmax, tree[2*treeNode+1].fmax);
    tree[treeNode].smax = min(max(tree[2*treeNode].fmax, tree[2*treeNode+1].smax),
                              max(tree[2*treeNode].smax, tree[2*treeNode+1].fmax));
}

void updateTree(int *arr, node *tree, int start, int end, int treeNode, int idx, int value){
    if(start == end){
        arr[idx] = value;
        tree[treeNode].fmax = value;
        tree[treeNode].smax = 0;
        return;
    }
    int mid = (start+end)/2;
    if(idx>mid){
        updateTree(arr, tree, mid+1, end, 2*treeNode+1,idx, value);
    }
    else{
        updateTree(arr, tree, start, mid, 2*treeNode,idx, value);
    }
    tree[treeNode].fmax = max(tree[2*treeNode].fmax, tree[2*treeNode+1].fmax);
    tree[treeNode].smax = min(max(tree[2*treeNode].fmax, tree[2*treeNode+1].smax),
                              max(tree[2*treeNode].smax, tree[2*treeNode+1].fmax));

}

node query(node *tree, int start, int end, int treeNode, int left, int right){

    //completely outside
    if(start>right || end<left){
        node * emptyNode = (node*) (malloc(sizeof(node)));
        emptyNode->fmax = 0;
        emptyNode->smax = 0;
        return (*emptyNode);
    }
    // completely inside
    if(start>=left && end<=right){
        return tree[treeNode];
    }
    // partially inside partially outside
    int mid = (start+end)/2;
    node ans1 = query(tree, start, mid, 2*treeNode, left, right);
    node ans2 = query(tree, mid+1, end, 2*treeNode+1,left, right);
    
    node* rootNode = (node*) (malloc(sizeof(node)));

    int max1 = max(ans1.fmax, ans2.fmax);
    int max2 = min(max(ans1.fmax, ans2.smax), max(ans1.smax, ans2.fmax));

    rootNode->fmax = max1;
    rootNode->smax = max2;

    return (*rootNode);

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
    //     cout<<tree[i].fmax<<" "<<tree[i].smax<<endl;
    // }

    cin>>q;
    while(q--){
        char type;
        int left, right, idx, value;
        cin>>type;
        if(type == 'q'){
            cin>>left>>right;
            node ans = query(tree, 0, n-1, 1,left-1, right-1);
            cout<<(ans.fmax)+(ans.smax)<<endl;
        }
        else if(type == 'u'){
            cin>>idx>>value;
            updateTree(arr, tree, 0, n-1, 1, idx-1, value);
            // cout<<"Updated Tree: "<< endl;
            // for(int i=0;i<4*n;i++){
            // cout<<tree[i].fmax<<" "<<tree[i].smax<<endl;
            // }
        }
    }
    return 0;
}