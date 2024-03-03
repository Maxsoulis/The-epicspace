#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "board.h"
using std::ifstream;
using std::string;
using std::cout;
using std::cin;
using std::vector;
int main(){
 bool play = true;
 while(play){
  system("clear");
  srand((unsigned) time(NULL));
  std::ifstream input;    
  input.open("common_words.txt");
  std::string word;
  //Chooses a word from the file
  int line = rand() % 988;
   
  for(int i = 0; i < line; i++){
     std::getline(input, word);
      
  }
  //Creates an array of boolean values that will be initialized to false
  //This is used in determining if a letter was entered and will be printed if the value is true 
  bool arr[word.length()];
  for(int i = 0; i < sizeof(arr); i++){
    arr[i] = false;
  }
  char letters[word.length()];
  int index = 0;
  for( char& letter: word){
    letters[index] = letter;
    index++;
  }
  int incorrect_guess = 0;
  string guess = " ";
  // The array is used later to print all the incorrect letters to the screen
  char wrong_letters[6] = {' ',' ',' ',' ',' ', ' '};
 
 create_board(  incorrect_guess);
 int word_letters_index = 0;
 //prints the amount of letters that is in the word
  for(int i = 0 ; i < word.length(); i++){
    cout << "_ ";
  }
    vector<char> guessed_letters;
  while(incorrect_guess < 6){
     
    cin >> guess;
    char guess_letter = guess[0];
    bool same_letter = false;
     if(guess == word){
    cout << " You win ";
    break;
    }
    
    // will check if the inputted letter has already been inputted
    for(int i = 0; i < guessed_letters.size(); i++){
      if(guessed_letters[i] == guess_letter){
        same_letter = true;
        cout << "You have already either chosen that letter, or that is the incorrect word,  try again" << '\n';
        
      }
    }
    if(same_letter == false){
      //adds the letter to the vector if inputed letters. 
      //If I were to add it if it was the same letter, than that would just be weird and take longer
        guessed_letters.push_back(guess_letter);
    int correct_letter = 0;
   // will loop through the the letters of the word and compare it with the letter first letter of user_input and if it is the same as any of the letters in the word
    for(int i = 0; i < word.length(); i++){
      if(guess[0] == letters[i]){
      arr[i] = true;
      correct_letter++;
       
      }
      // if I were to modify incorrect_letters in the else
      //it would add as many times as it runs
     
    }
    // Checks if the amount of correct letters is zero, and if the amount of correct letters is zero, then that means that it was not a correct letter and will add to incorrect letters
    if( correct_letter == 0){
      cout << "incorrect" << '\n';
      incorrect_guess ++; 
       wrong_letters[word_letters_index] = guess[0];
       word_letters_index++;
    }
    /*prints what the current word looks like
    so if the word is cortisol and the user entered o and that is in the word, it would look like _ o _ _ _ _ o _ and int the bool array would look like false true false false false false true false the true value is what is going to be printed
    */
    
    create_board( incorrect_guess );
    for(int i = 0; i < sizeof(wrong_letters); i++){
      cout << wrong_letters[i];
    }
    cout << '\n';
    for(int i = 0; i < sizeof(arr); i++){
          if(arr[i] == true){
          cout << letters[i] << " "; 
        } 
        else {cout << "_ ";   }
        }
  }
         
    }  
    
    cout << word << '\n'; 
    char play_again = ' ';
    bool invalid = true;
    while(invalid){
    cout << "Would you like to play again (y/n)"  << '\n';
    cin >> play_again;
    if( play_again == 'y'){
      play = true;
      invalid = false;
   
    }
    else if (play_again =='n'){
      play = false;
      invalid = false;
       
    }
    else {invalid = true; cout << "invalid try again" << '\n';}
    }
  }
  
}
