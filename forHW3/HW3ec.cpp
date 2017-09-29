//INSTRUCTION
//Look for ** to complete all of them
//The output should match my assingment sheet

//=========================================================
//HW#: HW3P3 slist
//Your name: Antonio Monje
//Complier:  g++
//File type: client program (tester)
//===========================================================


#include <iostream>
#include "slist.h"
using namespace std;
//Purpose: To test the == operator overloading function for lists when they are being compared.
//Algorithm// Part 1 test if they are the same if they are both empty. Part 2 test to check if they compare when one list has more elements. Part 3 does the same as part two but with the other list. Part 4 test when they have the same elements and same number of elements. Part five checks when one has less elements than the other one. part six checks when one list has more elements then the other one. Part 7 checks when the have the same count but differenet elements. Each part returns true or false if the are they same it true or else it returns false.
int main()
{
  slist L1, L2;
  int temp;
  //L1 is empty and L2 is empty
  cout << "Part 1 " << endl;
  cout << "L1 is empty and L2 is empty:  ";
  //if they re the same return true else its false
  if( L1 == L2)
    {
      cout <<"True";
    }
  else
    {
      cout << "False";
    }
  cout << endl;
  //L1 is empty and L2 has 2 elements
  cout << "Part 2 " << endl;
  cout << "L1 is empty and L2 has 2 elements:  ";

  L2.addRear(3);
  L2.addFront(2);
  //if they re the same return true else its false
  if( L1 == L2)
    {
      cout <<"True";
    }
  else
    {
      cout << "False";
    }
  cout << endl;
  //L1 has 2 elements and L2 is empty
  cout << "Part 3 " << endl;
  cout << "L1 has 2 elements and L2 is empty:  ";

  L2.deleteRear(temp);
  L2.deleteRear(temp);
  L1.addRear(3);
  L1.addFront(2);
  //if they re the same return true else its false
  if( L1 == L2)
    {
      cout <<"True";
    }
  else
    {
      cout << "False";
    }
  cout << endl;
  //L1 has 1,2,3 and L2 has 1,2,3
  cout << "Part 4 " << endl;
  cout << "L1 has 1,2,3 and L2 has 1,2,3:  ";
  L2.addRear(3);
  L2.addFront(2);
  L2.addFront(1);
  L1.addFront(1);
  //if they re the same return true else its false
  if( L1 == L2)
    {
      cout <<"True";
    }
  else
    {
      cout << "False";
    }
  cout << endl;
  //L1 has 1,2,3 and L2 has 1,2
  cout << "Part 5 " << endl;
  cout << "L1 has 1,2,3 and L2 has 1,2:  ";

  L2.deleteRear(temp);
  //if they re the same return true else its false
  if( L1 == L2)
    {
      cout <<"True";
    }
  else
    {
      cout << "False";
    }
  cout << endl;
  //L1 has 1,2,3 and L2 has 1,2,3,4
  cout << "Part 6 " << endl;
  cout << "L1 has 1,2,3 and L2 has 1,2,3,4:  ";

  L2.addRear(3);
  L2.addRear(4);
  //if they re the same return true else its false
  if( L1 == L2)
    {
      cout <<"True";
    }
  else
    {
      cout << "False";
    }
  cout << endl;
  //L1 has 1,2,3 and L2 has 1,2,4
  cout << "Part 7 " << endl;
  cout << "L1 has 1,2,3 and L2 has 1,2,4:  ";
  L2.deleteIth(3,temp);
  //if they re the same return true else its false
  if( L1 == L2)
    {
      cout <<"True";
    }
  else
    {
      cout << "False";
    }
  cout << endl;
  cout << endl;
  return 0;
}


