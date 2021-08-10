#include<bits/stdc++.h>
using namespace std;


// the board size is 10x10 -> winner at 100
// multiplayer
// snakes(to score number) ladder(to climb up, gain number) and dice(1-6)
// initially all players are at start position of the board
// players follows turn in round robin manner
// Assumption: there is atleast one possible way to win
// there should not be any infinite loop
// snakes ladders and number of players are decided before the game begins, 
// once the game begins they can't be changed
// rolled dice should have a random value
// game will end when the player is reaching 100
// the game ends if we have a winner

// class diagram : 

// Player class : id, name, currPosition
// Game class: players: vector<Player>, currTurn, winner Player*
// Snakes&Ladder: unordered_map<int, int>
// API-> roll -> bool 

// Snake class: start, end
// Ladder class: start, end


class Snake{

public:
    Snake(int, int){
        
    }



};





















