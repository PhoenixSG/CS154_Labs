/*
	Buggy code made by Shashwat Garg, 200050130.
	Lab 8, CS154
	May 3, 2021
*/

#include <iostream>
#include <string>
//#define NDEBUG  // uncomment to turn off Assertions
#include <cassert>
using namespace std;

int str2int(string s)
{
   /*
   This function converts a string into an integer.
   The only way this is possible is if the string has only digits inside it and the integer can be contained inside the int data type.
   */

   int v = 0, temporary_value = 0;
   int lengthofstring = s.length(); //variable definition

   assert(lengthofstring <= 10);    //precondition
   assert(s[0]!=48);                //precondition

   for (int i = 0; i < lengthofstring; i++)
   {
      temporary_value = v;
      assert(s[i] >= 48 && s[i] <= 57); //precondition
      v *= 10;
      v += s[i] - 48;

      if (i >= 1)
         assert(v / temporary_value >= 10); //postcondition
   }
   return v;

   /*
The initial precondition checks for very large string at the very beginning of the code.
The next one checks for vague inputs like 0004 instead of 4, again due to a faulty algorithm.
The first one is a precondition and is asserted at the beginning of each loop iteration.
It asserts that the character is between 0 to 9.

The postcondition is called at the end of each loop iteration.
It checks whether the integer goes out of bound in a clever way, by checking if its value goes negative or decreases after any step.
*/
}

int main(int argc, char *argv[])
{

   string input;
   int converted;

   cout << "Enter a string which is actually a number\n";
   cin >> input;

   converted = str2int(input);

   //if control reaches here it means that conversion went fine.
   cout << "The input has been successfully converted to an int- " << converted << endl;
}
