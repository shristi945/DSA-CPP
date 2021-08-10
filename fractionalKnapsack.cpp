#include<bits/stdc++.h>
using namespace std;
bool comp(pair<int,int>&a, pair<int,int>&b){
    double value1 = ((double)a.first)/(a.second);
    double value2 = ((double)b.first)/(b.second);
    return value1>value2;
}
int main(){
    
    // write your code here
    int N;double W;
    cin>>N>>W;
    int n[200001];
    int wt[100001];
    vector<pair<int,int>> item(N);
    for(int i=0;i<N;i++){
        cin>>n[i]>>wt[i];
        item[i] = make_pair(n[i],wt[i]);
    }
    sort(item.begin(),item.end(),comp); double tot=0; int curr=0;
    for(int i=0;i<N;i++){
       if(curr+item[i].second<=W){
           curr += item[i].second;
           tot += item[i].first;
       }
        else{
            int rem = W-curr;
            tot += item[i].first*((double)rem/item[i].second);
            break;
        }
    }
    cout<<fixed;
    cout<<setprecision(6);
    cout<<tot<<endl;
    
    
    return 0;
}