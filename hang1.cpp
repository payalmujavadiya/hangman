
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

const int MAX_TRIES=5;

int letterFill (char, string, string&);

int main ()
{
string name;
char letter,ch;
int num_of_wrong_guesses=0;
string word;
string words[] ={
"india",
"pakistan",
"nepal",
"malaysia",
"philippines",
"australia",
"iran",
"ethiopia",
"oman",
"indonesia"
};
do{
//choose and copy a word from array of words randomly
srand(time(NULL));
int n=rand()% 10;
word=words[n];
num_of_wrong_guesses=0;
// Initialize the secret word with the * character.
string unknown(word.length(),'*');

// welcome the user
cout << "\n\nWelcome to hangman...Guess a country Name";
cout << "\n\nEach letter is represented by a star.";
cout << "\n\nYou have to type only one letter in one try";
cout << "\n\nYou have " << MAX_TRIES << " tries to try and guess the word.";
cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";

// Loop until the guesses are used up
while (num_of_wrong_guesses < MAX_TRIES)
{
cout << "\n\n" << unknown;
cout << "\n\nGuess a letter: ";
cin >> letter;
// Fill secret word with letter if the guess is correct,
// otherwise increment the number of wrong guesses.
if (letterFill(letter, word, unknown)==0)
{
cout << endl << "Whoops! That letter isn't in there!" << endl;
num_of_wrong_guesses++;
if(num_of_wrong_guesses==1){
cout<<"+----+"<<endl;
cout<<"     |"<<endl<<" o"<<"   |"<<endl<<"     |"<<endl<<"     |"<<endl;

}
 if(num_of_wrong_guesses==2){
cout<<"+----+"<<endl;
cout<<"     |"<<endl<<" o"<<"   |"<<endl<<" |"<<"   |"<<endl<<"     |"<<endl;
}

 if(num_of_wrong_guesses==3){
cout<<"+----+"<<endl;
cout<<"     |"<<endl<<" o"<<"   |"<<endl<<"/"<<"|"<<"\\"<<"  |"<<endl<<"     |"<<endl;
}

if(num_of_wrong_guesses==4){
cout<<"+----+"<<endl;
cout<<"     |"<<endl<<" o"<<"   |"<<endl<<"/"<<"|"<<"\\"<<"  |"<<endl<<"/"<<" \\"<<"  |"<<endl;
}
if(num_of_wrong_guesses==5){
cout<<"+----+"<<endl;
cout<<" |"<<"   |"<<endl<<" o"<<"   |"<<endl<<"/"<<"|"<<"\\"<<"  |"<<endl<<"/"<<" \\"<<"  |"<<endl<<"     |"<<endl;
}

}
else
{
cout << endl << "You found a letter! Isn't that exciting!" << endl;
}
// Tell user how many guesses has left.
cout << "You have " << MAX_TRIES - num_of_wrong_guesses;
cout << " guesses left." << endl;
// Check if user guessed the word.
if (word==unknown)
{
cout << word << endl;
cout << "Yeah! You got it!";
break;
}

}
if(num_of_wrong_guesses == MAX_TRIES)
{
cout << "\nSorry, you lose...you've been hanged." << endl;
cout << "The word was : " << word << endl;
}
cout<<"do you want to play again ";
cin>>ch;
}
while(ch=='y'||ch=='Y');
if(ch!='y'||ch!='Y')
return 0;
cin.ignore();
cin.get();

return 0;
}

/* Take a one character guess and the secret word, and fill in the
unfinished guessword. Returns number of characters matched.
Also, returns zero if the character is already guessed. */

int letterFill (char guess, string secretword, string &guessword)
{
int i;
int matches=0;
int len=secretword.length();
for (i = 0; i< len; i++)
{
// Did we already match this letter in a previous guess?
if (guess == guessword[i])
return 0;

// Is the guess in the secret word?
if (guess == secretword[i])
{
guessword[i] = guess;
matches++;
}
}
return matches;
}
