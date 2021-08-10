#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &edges, int start, unordered_set<int>* component, vector<bool> &vis){
    vis[start] = true;
    component->insert(start); 

    for(int i=0;i<edges[start].size();i++){
        int next = edges[start][i];
        if(!vis[next]){
            dfs(edges, next, component, vis);
        }
        
    }
}


unordered_set<unordered_set<int>*>* getComponents(vector<vector<int>> &edges, int n){

    vector<bool> vis(n, false);
    unordered_set<unordered_set<int>*>* output = new unordered_set<unordered_set<int>*>();
    for(int i=0;i<n;i++){
        if(!vis[i]){
            unordered_set<int>* component = new unordered_set<int>();
            dfs(edges, i, component, vis);
            output->insert(component);
        }
    }   
    return output;
}



int main(){
    

    int n;
    cin>>n;
    vector<vector<int>>edges(n);
    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        int j,k;
        cin>>j>>k;
        edges[j-1].push_back(k-1);
        edges[k-1].push_back(j-1);
    }
    unordered_set<unordered_set<int>*>* components =  getComponents(edges, n);
    unordered_set<unordered_set<int>*> :: iterator it1 = components->begin();
    while(it1!=components->end()){
        unordered_set<int>* component = *it1;
        unordered_set<int>::iterator it2 = component->begin();
        while(it2!=component->end()){
            cout<<*it2+1<<" ";
            it2++;
        }
        cout<<endl;
        delete component;
        it1++;
    }
    delete components;
    return 0;
}