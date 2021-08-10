#include<bits/stdc++.h>
using namespace std;



// input:
// 2
// 3 90
// 56 76
// 3
// 99 10
// 30 20
// 20 5

int minMoves(map<int,int>&lad, map<int,int>&snake){

    int moves = 0;
    queue<int>q;

    q.push(1);
    bool found = false; // if reached 100

    vector<int>visited(101, 0);
    visited[1] = true;
    
    while(!q.empty() and !found){
        int sz = q.size();
        while(sz--){
            int t = q.front();
            q.pop();
            for(int die=1;die<=6;die++){
                if(t+die == 100){
                    found =true;
                }
                if(t+die <= 100 and lad[t+die] and !visited[lad[t+die]]){
                    visited[lad[t+die]]=true;
                    if(lad[t+die] == 100){
                        found = true;
                    }
                    q.push(lad[t+die]);
                }
                else if(t+die <= 100 and snake[t+die] and !visited[snake[t+die]]){
                    visited[snake[t+die]]=true;
                    if(snake[t+die] == 100){
                        found = true;
                    }
                    q.push(snake[t+die]);
                }
                else if(t+die<=100 and !visited[t+die] and !snake[t+die] and !lad[t+die]){
                    visited[t+die] = true;
                    if(t+die==100){
                        found = true;
                    }
                    q.push(t+die);
                }
            }
        }
        moves++;
    }


    if(found) return moves;
    return -1;
}


int main(){

    int snakes, ladders;
    
    cin>>ladders;
    map<int,int>lad;
    map<int,int>snake;

    for(int i=0;i<ladders;i++){
        int p1, p2;
        cin>>p1>>p2;
        lad[p1] = p2;
    }
    cin>>snakes;
    for(int i=0;i<snakes;i++){
        int p1, p2;
        cin>>p1>>p2;
        snake[p1] = p2;
    }


    cout<<minMoves(lad, snake);

    return 0;
}