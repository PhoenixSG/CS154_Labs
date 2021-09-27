/*
	Buggy code made by Shashwat Garg, 200050130.
	Lab 8, CS154
	May 3, 2021
*/

#include <iostream>
using namespace std;
//#define NDEBUG  // uncomment to turn off Assertions

#include <cassert>
// A program which is not correct
class Collection
{
  int *S;
  int cap, card;

public:
  Collection(int sz)
  {
    assert(sz > 0); //precondition
    S = new int[sz];
    card = 0;
    cap = sz;          ///THIS WAS NOT PRESENT IN INITIAL CODE. COMMENT IT OUT TO SEE THE ERROR, TRIGGERS THE FOLLOWING ASSERT STATEMENT.
    assert(sz == cap); //precondition
    assert(card == 0); //precondition
  }

  void push_back(int elem)
  {
    assert(card < cap); //precondition
    S[card] = elem;
    card++;
    assert(card <= cap); //class invariant & postcondition
    assert(card >= 0);   //class invariant
  }

  int pop_back()
  {
    assert(card > 0); //precondition
    card--;
    assert(card >= 0);   //class invariant & postcondition
    assert(card <= cap); //class invariant
    return S[card];
  }
};
int main()
{
  Collection c1(3);
  int n;

  cout << "For constructor initialisation error present in initial code,\nplease refer to the comments in the code or observations.txt\n\n";
  cout << "Enter 1 for PUSHBACK error and 2 for POP error\n";
  cin >> n;

  assert(n == 1 || n == 2);

  if (n == 1)
  {
    c1.push_back(3);
    c1.push_back(4);
    c1.push_back(45);
    c1.push_back(100);
  }
  else
  {
    c1.pop_back();
  }

  return 0;
}
