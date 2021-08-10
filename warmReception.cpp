#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Customer{
    public:
    int arrival;
    int departure;
};

bool compare(Customer* C1, Customer* C2){
    
    return C1->arrival < C2->arrival;
}

int main() {

	// Write your code here
    int n;
    cin>>n;

    Customer** customers=new Customer*[n];
    for(int i=0;i<n;i++){
        customers[i] = new Customer();
    }
    for(int i=0;i<n;i++){
        cin>>customers[i]->arrival;
    }
    for(int i=0;i<n;i++){
        cin>>customers[i]->departure;
    }
    std::sort(customers, customers+n, compare);
    
    for(int i=0; i<n;i++){
        cout<<customers[i]->arrival<<" "<<customers[i]->departure<<endl;
    }
    int max_stk_size = 0;
    priority_queue<int, vector<int>, greater<int> > gquiz;

    for(int i=0; i<n;i++){
       if(gquiz.empty()){
           gquiz.push(customers[i]->departure);
       }
       else if(gquiz.top() > customers[i]->arrival){
           gquiz.push(customers[i]->departure);
       }
       else{
           while(!(gquiz.empty()) and gquiz.top() <= customers[i]->arrival){
               gquiz.pop();
           }
           gquiz.push(customers[i]->departure);
       }
       if(gquiz.size()>max_stk_size){
               max_stk_size = gquiz.size();
        }

    }
    cout<<max_stk_size<<endl;
    return 0;
}





















// vector<int> v1, v2;
//     multimap<int, int> sorted_map;
//     for(int i=0;i<n;i++){
//     	int arrival;
//         cin>>arrival;
//         v1.push_back(arrival);
//     }
//     for(int i=0;i<n;i++){
//     	int departure;
//         cin>>departure;
//         v2.push_back(departure);
//     }
//     for(int i=0;i<n;i++){
//         sorted_map.insert(make_pair(v1[i],v2[i]));
//     }
//     for(auto it=sorted_map.begin();it!=sorted_map.end();it++){
//         cout<<it->first<<" "<<it->second<<endl; 
//     }
//     int max_stk_cnt = 0; int count = 0; stack <int> s;
//     for(auto it=sorted_map.begin();it!=sorted_map.end();it++){
//         int arrival =  it->first;
//         int departure = it->second;
//         if(s.empty() || arrival<s.top())
        

//     }