#include<bits/stdc++.h>
using namespace std;
# define pii pair<int,int>
vector<int> getOrder(vector<vector<int>>& tasks) {
    for(int i=0;i<tasks.size();i++){
        tasks[i].push_back(i);
    }
    sort(tasks.begin(),tasks.end());   
    vector<int>res;
    int i = 0, t = tasks[0][0];
    priority_queue<pii, vector<pii>,greater<pii> > waiting;
    while(!waiting.empty() || i<tasks.size()){
        while(i<tasks.size() and t>=tasks[i][0]){
            waiting.push(make_pair(tasks[i][1], tasks[i][2]));
            i++;
        }
        
        if(waiting.empty()){
            t = tasks[i][0];
        }
        else{
            int procTime = waiting.top().first;
            int index = waiting.top().second;
            t += procTime;
            res.push_back(index);
            waiting.pop();

        }
    }
    return res;
}

int main() {
    vector<vector<int>>tasks{
        {7,10},
        {7,12},
        {7,5},
        {7,4},
        {7,2}
    };
    vector<int> res = getOrder(tasks);
    for (int i = 0; i < res.size(); i++)
    {
        cout<<res[i]<<" ";
    }
    
}