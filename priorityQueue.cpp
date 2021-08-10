#include <iostream> 
#include <queue> 
#include<bits/stdc++.h>
using namespace std; 
  
void showpq( 
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > gq) 
{ 
    priority_queue<pair<int, int>, vector<pair<int, int>>,  
                                greater<pair<int, int>> > g = gq; 
    while (!g.empty()) { 
        cout << g.top().first<<" "<<g.top().second<<endl; 
        g.pop(); 
    } 
    cout << '\n'; 
} 
  
int main() 
{   
    vector<vector<int>>orders = {{10, 5, 0}, {15, 2, 1}, {25, 1, 1}, {30, 4, 0}};

    priority_queue<pair<int, int>, vector<pair<int, int>>,   
                       greater<pair<int, int>> > gquiz; 
    gquiz.push(make_pair(10, 5)); 
    gquiz.push(make_pair(15,2)); 
    gquiz.push(make_pair(25, 1)); 
    gquiz.push(make_pair(30, 4)); 
     
  
    cout << "The priority queue gquiz is : "; 
    showpq(gquiz); 
    // cout<< gquiz.top()<<endl;

  
    return 0; 
}