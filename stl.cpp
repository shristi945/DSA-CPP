#include<iostream>
#include<vector>
#include<string>
#include<utility>
#include<set>
#include<map>
#include<unordered_map>
#include<algorithm>
using namespace std;

struct Intervals{
        int start;
        int end;
    };

bool compare(Intervals i1, Intervals i2){
    return i1.end<i2.end;
}

int main(){
    // vector<int> v;
    // vector<int>::iterator it;

    // for (int i =0; i<5; i++){
    //     v.push_back(i+1);
    // }

    // for (int i=0; i<5;i++){
    //     cout<< v[i]<<endl;
    // }

    // for(it=v.begin(); it!=v.end();it++){
        
    //     cout <<*it<<endl;
    // }

    // string str1 = "Shris";
    // string str2(str1, 2,4);
    // cout<< str1<<endl;
    // cout<< str2<<endl;
    // string strr3 = "Shrist";
    // cout<<str1.compare(strr3)<<endl;
    
    // pair<int, char> p;
    // pair<int, char> p1;
    // pair<int, char>p2(1,'a');
    // p = make_pair(2, 'b');
    // p1 = make_pair(3, 'b');
    // cout<<p2.first<<" "<<p2.second<<endl;
    // cout<< p.first<< " "<<p.second<<endl;
    // cout<<p1.first<<" "<<p1.second<<endl;

    // set<int> s;
    // int arr[] = {1,2,3,4,5,5};

    // for (int i = 0; i<6;i++){
    //     s.insert(arr[i]);
    // }
    // set<int>::iterator it;
    // for(it = s.begin();it!=s.end();it++){
    //     cout<<*it<<endl;
    // }
    // if(s.find(5) == s.end()){
    //     cout<<"not found!"<<endl;
    // }
    // else{
    //     cout<<"Found!";
    // }

    int arr[] = {2,3,3,4,5,5};
    // unordered_map<int,int> um;
    // for(int i=0; i<6;i++){
    //     um[arr[i]] = um[arr[i]]+1;
    // }
    // unordered_map<int, int>::iterator it;
    // for (it=um.begin();it!=um.end();it++){
    //     cout<<it->first<<":"<<it->second<<endl;
    // }
    // Intervals arr[] = {{5,5}, {6,3}, {2,4}, {1,0}, {9,0}};
    // sort(arr, arr+5, compare);
    // for(int i=0; i<5;i++){
    //     cout<<arr[i].start<<":"<<arr[i].end<<endl;
    // }
    // cout<< binary_search(arr, arr+6, -66);
    // cout<<endl;
    cout<<lower_bound(arr, arr+6,1)-arr;
    cout<<endl;
    // cout<<upper_bound(arr, arr+6, 5)-arr;
    // int x = std::distance(arr, std::find(arr, arr + 6, 3));
    // cout<<x<<endl;
    // cout<<endl;
    // cout<<__gcd(10,6);

    // cout<< endl;

    // int x = 10;
    // int y = 20;
    // swap(x,y);
    // cout<<  x<<","<<y;
    // cout << endl;
    // cout<< max(x,y);
    return 0;


}
