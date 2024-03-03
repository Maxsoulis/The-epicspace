#include "hangman_board.h"
#include <iostream>
#include <string>
#include <array>

using std::cout;
using std::array;
using std::string;
void create_board(int incorrect_guess   ){
  system("clear");
  int board[5][6] = {
    {0,2,2,0,0,0},
    {0,0,0,1,0,0},
    {0,0,0,1,0,0},
    {0,0,0,1,0,0},
    {0,2,2,2,2,2},
   
  };
   
  //The reason for having each one as an individual if statement is to ensure that the lower numbers  stay even if incorrect_ letters is higher 
 
  if(incorrect_guess >= 1){
    board[1][1] = 3;
  
     
  }
  if(incorrect_guess >= 2){
    board[2][1] = 1;
 
  }
  if(incorrect_guess >= 3){
    board[2][0] = 4;
    
  }
  if(incorrect_guess >=4){
    board[3][0] = 4;
    
  }
  if(incorrect_guess >=5){
    board[2][2] = 5;
  
  }
  if(incorrect_guess==6){
    board[3][2] = 5;
    
  }
   // prints the symbol based on the num at that position, being able to print both the board and the parts of the body.
  for(int i = 0; i < 5; i++){
    for(int j = 0; j < 6; j++){
    
      switch(board[i][j]){
        case 0: {
          cout<< " ";
          break;
        }
        case 1: {
          cout << "|";
          break;
        }
        
        case 2: {
          cout << "_";
          break;
        }
        case 3: {
          cout << "o";
          break;
        }
        case 4: {
          cout << "/";
          break;
        }
        case 5: {
          cout << "\\";
          break;
        }
        

      };
        
    }

      cout << '\n';
  
  }
}  
