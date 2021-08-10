#include<bits/stdc++.h>
# define pi pair<int, int>
using namespace std;

vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
    vector<int>res;
    priority_queue<pi, vector<pi>, greater<pi>>serverMapping;
    for(int i=0;i<servers.size();i++){
        serverMapping.push(make_pair(servers[i], i));
    }
    priority_queue<pair<long, pi>, vector<pair<long,pi>>, greater<pair<long,pi>>>process;
    long timer = 0;
    for(int i=0;i<tasks.size();i++){
        timer = max((long)i, timer);

        if(serverMapping.empty() && process.top().first>timer){
            timer = process.top().first;
        }

        if(process.empty()){
            process.push(make_pair(i+tasks[i], 
            make_pair(serverMapping.top().first, serverMapping.top().second)));
            res.push_back(serverMapping.top().second);
            serverMapping.pop();
        }
        else{
            while(!process.empty() && process.top().first<=timer){
                int server_wt = process.top().second.first;
                int server_num = process.top().second.second;
                process.pop();
                serverMapping.push(make_pair(server_wt, server_num));
            }
            process.push(make_pair(timer+tasks[i], 
            make_pair(serverMapping.top().first, serverMapping.top().second)));
            res.push_back(serverMapping.top().second);
            serverMapping.pop();
        }
    }
    return res;
}


int main(){

    vector<int>server{10,63,95,16,85,57,83,95,6,29,71};
    vector<int>tasks{70,31,83,15,32,67,98,65,56,48,38,90,5};

    vector<int>ans = assignTasks(server, tasks);

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }

    return 0;
}