#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//for the random number needed to pick a word from the words arrays
#include <time.h>

/*HANGMAN
This program randomly generates a word from a 'library' of ten words, and tells the user the length
The user then guesses a letter
If the letter guessed is in the word, then the program will tell the user where
If the user runs out of guesses, they have lost, and the program ends
If all the letters in the word have been guessed, a victory statement is outputted to the user and the program ends

This program displays working with user input, arrays, strings, nested loops, if statements, and functions from different libraries.
*/

//a function to check whether or not they have won
//if so return 1, if not return 0
int win(char answer[], char letters_guessed[], int answer_length, int num_guessed_letters){
    /*outside loop iterates through the answer string and the inside loop makes sure each letter
    in the answer string is in the string of the letters guessed by the user*/
    for(int i = 0; i<answer_length; i++){
        int count = 0;
        for(int j = 0; j<num_guessed_letters; j++){
            if(answer[i] == letters_guessed[j]){
                count++;
            }
        }
        if(count == 0){
            return 0;
        }
    }
    
    return 1;
}



int main(){
    //create an array with all the words
    char words[10][100] = {"pepper", "mango", "tree", "car", "snow", "christmas", "summer", "water", "koala", "penguin"};
    
    
    //randomly select an index from 0 to 9
    srand(time(0));
    int random_index = rand() % 10;
    
    //now copy the chosen word into a fresh string and find length of word
    char answer[100] = "";
    strcat(answer, words[random_index]);
    int answer_length = strlen(answer);
    
    //now the user is prompted to guess a letter, user has 5 guesses
    const int guess_limit = 5;
    
    printf("Welcome to hangman!\nThe secret word is %d letters long\n", answer_length);
    printf("Guess a letter: ");
    int ch = getchar();
    
    int correct_guesses = 0;
    char correct_guesses_arr[100] = "";
    int wrong_guesses = 0;

    
    //loop through and collect letters from user until out of guesses
    while(wrong_guesses < guess_limit){
        
        int number_of_appearances = 0;
        for(int i = 0; i<answer_length; i++){
            if(ch == answer[i]){
                printf("the letter %c is at position %d in the word\n", ch, i+1);
                number_of_appearances++;
                correct_guesses_arr[correct_guesses] = ch;
                correct_guesses++;
                correct_guesses_arr[correct_guesses] = '\0';
            }
            
            //check if they won
            if( win( answer, correct_guesses_arr, strlen(answer), strlen(correct_guesses_arr)  ) && (ch != '\n')){
                printf("You won, the word was %s\n", answer);
                return 1;
            }
            
            
        }
        //up the count if more letters have been guessed
        if(number_of_appearances == 0 && ch != '\n'){
            printf("the letter %c does not appear in the word\n", ch);
            wrong_guesses++;
            
        }

        //if statement to account for when the user pushes the enter key
        if(ch != '\n'){
            if(wrong_guesses<guess_limit){
            printf("\nguess a letter: ");
            }
        }
        ch = getchar();
        
        //if the user runs out of guesses
        if(wrong_guesses > guess_limit){
            printf("You ran out of guesses!\n");
            exit(0); 
        }
        
    }
    
    //the program only exits the loop if the user is out of guesses
    printf("You ran out of guesses!\n");
    
    return 0;
}
