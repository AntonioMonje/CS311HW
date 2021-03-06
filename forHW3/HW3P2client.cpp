//INSTRUCTION
//Look for ** to complete all of them
//The output should match my assingment sheet
//DO not forget to Tab on each line

//=========================================================
//HW#: HW3P2 slist
//Your name: Antonio Monje
//Complier:  g++
//File type: client program (tester)
//===========================================================

using namespace std;

#include <iostream>
#include "slist.h"

//PURPOSE of the program: to test slist inheritance by checking if addrear functions and addfront work while also checking if the new functions work. it makes sure that display works as well and to see if outofrange error is still called and the destructor is called.
int main()
{ slist L;  // the list 
  int foundPos; // to hold the found position 
  int counter = 1; // used to display test line number
  try
    {
      //  1)add to front once (element 4)
      cout << "Part: " << counter << endl; counter++;
      L.addFront(4);
     
      //  2)add to rear 3 times (elements 6,7,8)
      cout << "Part: " << counter << endl; counter++;
      L.addRear(6);
      L.addRear(7);
      L.addRear(8);
      //  3)displayAll    - 4 6 7 8
      cout << "Part: " << counter << endl; counter++;
      L.displayAll();
      cout << endl;
      //  4)search for 6, report the result  - found in pos 2
      cout << "Part: " << counter << endl; counter++;
      foundPos = L.search(6);
      if(foundPos >= 1)
	{
      cout << "Found in position: " << foundPos << endl;
	}
      else
	{
	  cout << "NOT FOUND" << endl;
	}
      
      //  5)replace the 6 with 0 using the search result
      cout << "Part: " << counter << endl; counter++;
            L.replace(0 , foundPos);
      //  6)search for 8 and report the result . found in pos 4
      cout << "Part: " << counter << endl; counter++;
      foundPos = L.search(8);
      if(foundPos >= 1)
	{
      cout << "Found in position: " << foundPos << endl;
	}
      else
	{
	cout << "NOT FOUND" << endl;
	}
      //  7)replace the 8 with 2 using the search result
      cout << "Part: " << counter << endl; counter++;
       L.replace(2,foundPos);
      //  8)displayAll                       - 4 0 7 2
      cout << "Part: " << counter << endl; counter++;
      L.displayAll();
      cout << endl;
      //  9)search for 5 and report the result   - not found
      cout << "Part: " << counter << endl; counter++;
      foundPos = L.search(5);
      if(foundPos >= 1)
	{
	  cout << "Found in position: " << foundPos << endl;
	}
      else
	{   
	  cout << "NOT FOUND" << endl;
	}
      
      
      // 10) replace postion 7 with 10
      cout << "Part: " << counter << endl; counter++;
       L.replace(7,foundPos);
    }//end of try

  catch(slist::OutOfRange)
    { cerr << "ERROR: Bad position was given" << endl;}
  cout << "-----------------------------------------------" << endl;  
}//end of program
