#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

void welcome()
{
  cout << "Welcome to the Casino!" << endl << endl;
  cout << "Pick a number from 1-10" << endl;
  cout << "If you guessed the number correct, you will get 10x the amount you betted" << endl;
  cout << "If you lose, then your bet will be taken" << endl << endl;
}

int main()
{
  welcome();
  int choice;
  string name;
  int balance;
  int bettingAmount;
  int winnings;
  int losings;
  int totalWin;
  int dice;
  char quit;
  srand(time(0));

  cout << "What is your name: ";
  getline(cin, name);
  cout << endl;
  cout << "Enter starting balance to play the game: ";
  cin >> balance;
  cout << "Your balance is $" << balance << endl << endl;
   
  do
  {
  cout << "Hello, " << name << "! Enter amount to bet: ";
  cin >> bettingAmount;
  if (balance < bettingAmount)
  {
    cout << "Not enough balance!" << endl << endl;
  }
  else
  {
    cout << "Guess any betting number between 1 & 10: ";
    cin >> choice;
    if (choice <= 0 || choice > 10)
    {
      cout << "The number should be within 1-10" << endl;
      cout << "Re-enter number: ";
      cin >> choice;
    }
    else
    {
      winnings = bettingAmount * 10;
      dice = rand()%10 + 1;
      if(dice == choice)
      {
        cout << "\nYou are in luck! You have won $" << bettingAmount * 10 << "!" << endl << endl;
        cout << "Your balance is $" << winnings + balance << endl << endl;
        totalWin = winnings + balance;
        balance = totalWin;
      }
      else
      {
        losings = balance - bettingAmount;
        cout << "You lost!" << endl;
        cout << "You lost $" << bettingAmount << endl;
        cout << "Your balance is $" << losings << endl << endl;
        balance = losings;
      }
    }
  }
  cout << "Press 'y' to continue or 'q' to quit: ";
  cin >> quit;
  if (quit == 'q')
  {
    cout << "\nThank you for playing! Your total winnings are $" << balance;
    break;
  }
  cout << endl;
  }while(quit != 'q');
}