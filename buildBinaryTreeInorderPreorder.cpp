#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    public:
    int data;
    TreeNode* left = NULL;
    TreeNode* right = NULL;
};

TreeNode* buildTreeUtil(vector<int>&in, vector<int>&pre, TreeNode **root){

    if(pre.size()==0)return NULL;
    if(pre.size()==1 && pre[0]==in[0]){
        *root = new TreeNode();
        *root->data = pre[0];
        return root;
    }
    root = new TreeNode();
    int pos = find(in.begin(), in.end(), pre[0])-in.begin();
    vector<int> left_in, left_pre, right_in, right_pre;
    for(int i=0;i<pos;i++){
        left_in.push_back(in[i]);
    }
    for(int i=pos+1;i<in.size();i++){
        right_in.push_back(in[i]);
    }
    int size = left_in.size();
    for(int i=1;i<=size;i++){
        left_pre.push_back(pre[i]);
    }
    for(int i=size+1;i<pre.size();i++){
        right_in.push_back(pre[i]);
    }

    root->left = buildTreeUtil(left_in, left_pre, root->left);
    root->right = buildTreeUtil(right_in, right_pre, root->right);

    return root;

}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

    TreeNode *root = NULL;
    buildTreeUtil(inorder, preorder,&root);
    return root;
        
}

void printInorder(TreeNode* node)
{
    if (node == NULL)
        return;
 
    /* first recur on left child */
    printInorder(node->left);
 
    /* then print the data of node */
    cout<<node->data<<" ";
 
    /* now recur on right child */
    printInorder(node->right);
}

int main(){
    vector<int>in{9,3,15,20,7};
    vector<int>pre{3,9,20,15,7};
    struct TreeNode* root = buildTree(in, pre);
    printInorder(root);

}