//
//   Name:       Lu, Curtis
//   Due:        11/29/12
//   Course:     CSCI-133C
//
//   Description:
//      File name: DecisionTreeDemo.cpp
//      Simple application that implements Binary Decision Tree
//      to play a animal guessing game.
//      
//   Compiler: Microsoft Visual Studio 2010 C++ 32-bit
//
#include "decisiontree.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
   bool exit = false;
   int choice;
   string input;
   DecisionTree guessing_game;
   guessing_game.build_tree();
   cout << "Welcome to Animal Guessing Game V.01 " << endl << endl;

   do
   {
      cout << setw(25) << "***************************" << endl
           << setw(25) << "*        Main Menu        *" << endl
           << setw(25) << "***************************" << endl
           << setw(25) << "*                         *" << endl
           << setw(25) << "*      1. Play Game       *" << endl
           << setw(25) << "*      2. Exit            *" << endl
           << setw(25) << "*                         *" << endl
           << setw(25) << "***************************" << endl
           << endl << "Please select an option (1-2): ";
      getline(cin, input);
      choice = atoi(input.c_str());
      cout << endl;

      switch(choice)
      {
	  case 1:  cout << "Think of an animal and I will try to guess it." << endl << endl;
			      guessing_game.play();
				  cout << endl << endl;
                  break;

         case 2:  cout << "Thank you for using Animal Guessing Game application!!" << endl;
			      exit = true;
                  break;

         default: cout << "Sorry invalid input." << endl
                       << "Please use the numerical value "
                       << "from the list (1 or 2)." << endl << endl;
      }
   }while(!exit);
   return 0;
}
