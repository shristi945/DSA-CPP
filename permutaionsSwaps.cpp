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

    int t;
    cin>>t;
    while(t--){

        int n,m;
        cin>>n>>m;
        vector<vector<int>>edges(m);
        vector<int> p(n);
        vector<int> q(n);
        for(int i=0;i<n;i++){
            cin>>p[i];
        }
        for(int i=0;i<n;i++){
            cin>>q[i];
        }
        for(int i=0;i<m;i++){
            int j,k;
            cin>>j>>k;
            edges[j-1].push_back(k-1);
            edges[k-1].push_back(j-1);
        }
        
        unordered_set<unordered_set<int> *>* components = getComponents(edges, n);
        unordered_set<unordered_set<int> *>::iterator it1 = components->begin();
        int flag = 0;
        while(it1!=components->end()){
            unordered_set<int>* component = *it1;
            unordered_set<int>::iterator it2 = component->begin();
            unordered_set<int>pValues;
            unordered_set<int>qValues;
            while(it2!=component->end()){
                pValues.insert(p[(*it2+1)]);
                qValues.insert(q[(*it2+1)]);
                it2++;
            }
            
            if(pValues!=qValues) {
                cout<<"NO"<<endl;
                flag = 1;
                break;
            }
            it1++;
        }
        if(flag == 0){
            cout<<"YES"<<endl;
        }
        
    }
    return 0;
}