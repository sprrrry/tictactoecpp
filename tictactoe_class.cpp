//Tic-Tac-Toe in C++ using class by Yashas Ranjan

#include <iostream>
using namespace std;

class Tictactoe {

    private:
    
    //2D array for the grid
    char grid[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
    //Variable Declaration
    int digit=0; //to store cell input from player
    int row,column; //to store row and column from cell number 
    
    public:

    char turn = 'X'; 
    bool tie = false;

    //Function to print Tic-Tac-Toe grid
    void grid_print(){

        cout<<"\t\t     |     |     \n";
        cout<<"\t\t  "<<grid[0][0]<<"  |  "<<grid[0][1]<<"  |  "<<grid[0][2]<<" \n";
        cout<<"\t\t_____|_____|_____\n";
        cout<<"\t\t     |     |     \n";
        cout<<"\t\t  "<<grid[1][0]<<"  |  "<<grid[1][1]<<"  |  "<<grid[1][2]<<" \n";
        cout<<"\t\t_____|_____|_____\n";
        cout<<"\t\t     |     |     \n";
        cout<<"\t\t  "<<grid[2][0]<<"  |  "<<grid[2][1]<<"  |  "<<grid[2][2]<<" \n";
        cout<<"\t\t     |     |     \n\n";

        
    }

    //Function to take player input
    void player_choice(){
        //checking whose turn it is
        if(turn == 'X'){
            cout<<"\nPlayer 1's [X] turn : ";
        }
        else if(turn == 'O'){
            cout<<"\nPlayer 2's [O] turn : ";
        }
        //taking input from player
        cin>>digit; 

        //switch case to get the row and column to be updated
        switch(digit){
                case 1: 
                    row=0; column=0; 
                    break;
                case 2: 
                    row=0; column=1; 
                    break;
                case 3: 
                    row=0; column=2; 
                    break;
                case 4: 
                    row=1; column=0; 
                    break;
                case 5: 
                    row=1; column=1; 
                    break;
                case 6: 
                    row=1; column=2; 
                    break;
                case 7: 
                    row=2; column=0; 
                    break;
                case 8: 
                    row=2; column=1; 
                    break;
                case 9: 
                    row=2; column=2; 
                    break;
                default:
                    cout<<"Invalid Move, please enter again!";
                    digit=0;
                    player_choice();
                
        }
    }

    //Function to update the game grid
    void grid_update(){
        if(turn == 'X' && grid[row][column] != 'X' && grid[row][column] != 'O'){
            //updating the position for 'X' if it is not already occupied
            grid[row][column] = 'X';
            turn = 'O';
        }else if(turn == 'O' && grid[row][column] != 'X' && grid[row][column] != 'O'){
            //updating the position for 'O' if it is not already occupied
            grid[row][column] = 'O';
            turn = 'X';
        }else {
            //if input position already filled
            cout<<"Box already filled!\n Please choose another!\n";
            player_choice();
            grid_update();
        }
        grid_print();
    }

    //Function to get the game status   
    bool game_over(){
        
        //checking the win for rows and columns
        for(int i=0; i<3; i++)
        if(grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2] || grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i])
        return true;

        //checking the win for both diagonals

        if(grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2] || grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0])
        return true;

        //checking if the game is in continuation
        for(int i=0; i<3; i++){    
            for(int j=0; j<3; j++){
                if(grid[i][j] != 'X' && grid[i][j] != 'O'){
                    return false;
                }
            }
        }

        //checking if the game is a tie
        tie = true;
        return true;
    }

}; // class defination end



int main(){
    cout<<"\n\n\tLet's Play TIC-TAC-TOE !!\n\n";
    cout<<"\tPLAYER 1 - [X]\t PLAYER 2 - [O]\n\n";

    Tictactoe game; //creating an object 'game' in which grid is stored

    game.grid_print();       //print game grid

    while(!game.game_over()){     //if the game is not over
        game.player_choice();    //take player choice
        game.grid_update();      //fill the grid
        game.game_over();         //check if the game is over
    }
    if(game.turn == 'O' && game.tie == false){
        cout<<"\nCongratulations! Player 1 with 'X' has won the game\n";
    }
    else if(game.turn == 'X' && game.tie == false){
        cout<<"\nCongratulations! Player 2 with 'O' has won the game\n";
    }
    else{
        cout<<"\nGame is a Draw!\n";
    }

    system("pause"); //to prevent the abrupt exit after game is over



}