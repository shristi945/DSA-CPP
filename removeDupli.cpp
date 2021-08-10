#include<iostream>
#include<vector>
#include<set>
using namespace std;

vector<int> removeDuplicates(vector<int>a){
    set<int> s;
    set<int>::iterator it;
    for(int i=0;i<a.size();i++){
        s.insert(a[i]);
    }
    vector<int> res;
    for(it=s.begin();it!=s.end();it++){
        res.push_back(*it);
    }
    return res;
}

int main(){
    int n;
    cin>>n;
    vector<int>arr;
    for(int i = 0; i<n;i++){
        int ele;
        cin>>ele;
        arr.push_back(ele);
    }
    vector<int>new_arr;
    vector<int>::iterator it;
    new_arr = removeDuplicates(arr);
    for(it=new_arr.begin(); it!=new_arr.end(); it++){
        cout<< *it<<endl;
    }
    return 0;
}