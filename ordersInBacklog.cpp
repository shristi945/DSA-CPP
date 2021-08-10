#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, long long> pi;
int getNumberOfBacklogOrders(vector<vector<int>>& orders){
    priority_queue<pi, vector<pi>, greater<pi>>  sell; // min heap
    priority_queue<pi> buy; // max heap
    for(int i=0;i<orders.size();i++){
        // checking if sell heap is empty or does not meet the sell condition then simply push in backlog
        if(orders[i][2]== 0 && (sell.empty()||orders[i][0]<sell.top().first)){
            buy.push(make_pair(orders[i][0], orders[i][1]));    
        }
        // if sale condition is true
        else if(orders[i][2]==0 && (orders[i][0]>=sell.top().first)){
            // check if amount of both sell top ele and current ele is equal then pop from backlog
            vector<int> curr = orders[i];
            while(!sell.empty() && curr[0]>=sell.top().first){
                if(sell.top().second == curr[1]){
                    sell.pop();
                }
                // check if amount of sell top > curr order amt then pop the top ele and push with updated amt
                else if(sell.top().second > curr[1]){
                    int top_price = sell.top().first;
                    sell.pop();
                    sell.push(make_pair(top_price, sell.top().second-curr[1]));
                }
                // check if amt of sell top < curr order amt then pop the top ele from sell and push remaining in buy backlog
                else if(sell.top().second < curr[1]){
                    int amount_sell_top = sell.top().second;
                    sell.pop();
                    curr[1] = curr[1]-amount_sell_top;
                }
            }
            if(curr[1]>0){
                buy.push(make_pair(curr[0], curr[1]));
            }
        }
        if(orders[i][2]==1 && (buy.empty() || orders[i][0]>buy.top().first)){
            sell.push(make_pair(orders[i][0],orders[i][1]));
        }
        else if(orders[i][2]==1 && (orders[i][0]<=buy.top().first)){
            vector<int> curr = orders[i];
            while(!buy.empty() && curr[0]<=buy.top().first){
                if(buy.top().second == curr[1]) buy.pop();
                else if(buy.top().second > curr[1]){
                    int top_price = buy.top().first;
                    buy.pop();
                    buy.push(make_pair(top_price, buy.top().second-curr[1]));
                }
                else if(buy.top().second < curr[1]){
                    int amount_buy_top = buy.top().second;
                    buy.pop();
                    curr[1] = curr[1]-amount_buy_top;
                }
            }
            if(curr[1]>0){
                sell.push(make_pair(curr[0], curr[1]));
            }
        }
    }
    long long result = 0;
    while (!sell.empty()) { 
        result += sell.top().second;
        sell.pop(); 
    } 
    while (!buy.empty()) { 
        result += buy.top().second;
        buy.pop(); 
    } 
    return result%1000000007;
}

int main(){

    vector<vector<int>> orders = {{10,5,0},{15,2,1},{25,1,1},{30,4,0}};
    cout<<getNumberOfBacklogOrders(orders);
    return 0;
}