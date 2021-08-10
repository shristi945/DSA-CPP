#include<bits/stdc++.h>
using namespace std;

map<char,int> create_map()
{
  map<char,int> getScore;
  getScore['x'] = 1;
  getScore['o'] = 2;
  return getScore;
}
map<char,int> getScore = create_map();

map<int,char> create_map_()
{
  map<int,char> getSymbol;
  getSymbol[1] = 'x';
  getSymbol[2] = 'o';
  return getSymbol;
}
map<int,char> getSymbol = create_map_();

class Player{
    private:
    string playerName;
    int playerId;
    int ranking;
    string email;
    char playerSymbol;

    public:
    
    void setPlayerName(string name){
        playerName = name;
    }
    string getPlayerName(){
        return playerName; 
    }
    char getPlayerSymbol(){
        return playerSymbol;
    }
    void setPlayerId(int id){
        playerId = id;
    }
    void setPlayerSymbol(char symbol){
        playerSymbol = symbol;
    }
};



class GameBoard{

    private:
    int boardSize;
    vector<vector<int>>board;
    queue<Player>nextTurn;
    

    public:

    GameBoard(int boardSize, vector<Player>players){
        boardSize = boardSize;
        board.reserve(boardSize);
        initializeBoard(board);
        nextTurn.push(players[0]);
        nextTurn.push(players[1]);

    }

    void initializeBoard(vector<vector<int>> &board){
        for(int i=0;i<boardSize;i++){
            for(int j=0;j<boardSize;j++){
                board[i][j]=0;
            }
        }
    }

    void printBoard(){
        for(int i=0;i<boardSize;i++){
            for(int j=0;j<boardSize;j++){
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    vector<int> getUserInput(Player currPlayer){
        int row, col;
        cout<<currPlayer.getPlayerName()<<" Please Enter your input in row and col number "<<endl;
        printBoard();
        cin>>row>>col;
        if(row>=boardSize || col>=boardSize || row<0 || col<0){
            cout<<"Invalid Input!"<<endl;
        }
        return {row,col};
    }

    bool checkEndGame(Player currPlayer, int row, int col){
        bool winRow = true, winCol = true, winDia = true, winRdia = true; 
        for(int i=0;i<boardSize;i++){
            if(getSymbol[board[row][i]]!=currPlayer.getPlayerSymbol()){
                winRow = false;
            }
            if(getSymbol[board[i][col]]!=currPlayer.getPlayerSymbol()){
                winCol = false;
            }
            if(getSymbol[board[i][i]]!=currPlayer.getPlayerSymbol()){
                winDia = false;
            }
            if(getSymbol[board[i][boardSize-i-1]]!=currPlayer.getPlayerSymbol()){
                winRdia = false;
            }
        }
        if(winRow || winRdia || winCol || winDia) return true;
        return false;
    }    

    void startGame(){
        int count = 0;
        while(true){
            count++;
            Player currPlayer = nextTurn.front();
            nextTurn.pop();

            if(count == (boardSize*boardSize)-1){
                cout<<"Match Draw"<<endl;break;
            }

            vector<int>input = getUserInput(currPlayer);
            int row = input[0];
            int col = input[1];

            board[row][col] = getScore[currPlayer.getPlayerSymbol()];
            printBoard();

            if(count>=(2*boardSize)-1 && checkEndGame(currPlayer, row, col)){
                cout<<currPlayer.getPlayerSymbol()<<" Won the Game! "<<endl;
                break;
            }
            nextTurn.push(currPlayer);

        }
    }

};



int main(){
    
    

    Player p1;
    p1.setPlayerName("shristi");
    p1.setPlayerId(1);
    p1.setPlayerSymbol('x');

    Player p2;
    p2.setPlayerName("Gupta");
    p2.setPlayerId(2);
    p2.setPlayerSymbol('o');

    vector<Player> players{p1,p2};
    GameBoard gb(3, players); 
    gb.startGame();
    return 0;
}