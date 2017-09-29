//INSTRUCTION
//Look for ** to complete all of them
//The output should match my assingment sheet

//=========================================================
//HW#: HW3P1 llist
//Your name: Antonio Monje
//Complier:  g++
//File type: client program (tester)
//===========================================================

using namespace std;

#include <iostream>
#include "llist.h"

//PURPOSE: Cases for the program to add rear elements and deletes rear and front elements and for displaying elements in the list
void caseOne()
{
  cout << "CASE 1:------------------- " << endl;
  llist L;   // this is my list
  int x;  // to hold a removed element

  //1 check empty and report the result  
  cout << 1 << endl;
  if(L.isEmpty())
    {
      cout << "List is Empty" << endl;
    }
  else 
    {
    cout << "List has some elements" << endl;
    }

  //2 display the list  
  cout << endl;
  cout << 2 << endl;
  L.displayAll();

  //3 add 4 integers 1,2,3,4
  cout << endl;    
  cout << 3 << endl;
  L.addRear(1);
  L.addRear(2);
  L.addRear(3);
  L.addRear(4);

  //4 display the list
  cout << endl;  
  cout << 4 << endl;
  L.displayAll();

  //5 remove from front twice (and display the elements removed)
  cout << endl;
  cout << 5 << endl;
  L.deleteFront(x);
  cout << x << " was removed" << endl;

  L.deleteFront(x);
  cout << x << " was removed" << endl;

  //6 display the list
  cout << endl;
  cout << 6 << endl;
  L.displayAll();
  cout << endl;

  //7 check empty and report the result
  cout << endl; 
  cout << 7 << endl;
   if(L.isEmpty())
     {
       cout << "List is Empty" << endl;
     }
   else
     {
       cout << "List has some elements" << endl;
     }

  //8 remove from the rear twice (display the element removed)
   cout << endl;
   cout << 8 << endl;
   L.deleteRear(x);
   cout << x << " was removed" << endl;
   L.deleteRear(x);
   cout << x << " was removed" << endl;

  //9 check empty again and report the result
   cout << endl;
   cout << 9 << endl; 
   if(L.isEmpty())
     {
       cout << "List is Empty" << endl;
     }
   else
     {
       cout << "List has some elements" << endl;
     }

}//end of case 1
 
//PURPOSE: test cases for adding front elements and rear elements and for deleting the I node
void caseTwo()
{ 
  cout << "Case 2: -----------------------" << endl;
  llist L2;  // another list
  int x;   // to hold the removed element 
  int c = 1;  // displayed step number

  // 1.add to front once   (element 5)
  cout << c << endl; c++;
  L2.addFront(5);

  // 2.add to front again  (element 4)
  cout << endl;
  cout << c << endl; c++;
  L2.addFront(4);

  // 3.delete Front 
  cout << endl;
  cout << c << endl; c++;
  L2.deleteFront(x);
  cout << x << " was removed" << endl;
  // 4.add to rear 3 times (elements 6,8,9)
  cout << endl;
  cout << c << endl; c++;
  L2.addRear(6);
  L2.addRear(8);
  L2.addRear(9);

  // 5. display all
  cout << endl;
  cout << c << endl; c++;
  L2.displayAll();

  // 6.add before the 1st  (element 4) . 4 5 6 8 9
  cout << endl;
  cout << c << endl; c++;
  L2.addbeforeIth(1,4);

  // 7.add before the 4th  (element 7) . 4 5 6 7 8 9
  cout << endl;
  cout << c << endl; c++;
  L2.addbeforeIth(4,7);

  // 8.add before the 7th  (element 10) . 4 5 6 7 8 9 10
  cout << endl;
  cout << c << endl; c++;
  L2.addbeforeIth(7,10);

  // 9.add before the 9th  (element 12) . error (out of range)
  cout << endl;
  cout << c << endl; c++;
  try{L2.addbeforeIth(9,12);} 
  catch(llist::OutOfRange)
    {cout << "Error: Out Of Range" << endl;}
  // 10.add before the 0th (element 0) . error (out of range)
  cout << endl; 
  cout << c << endl; c++;
  try{L2.addbeforeIth(0,0);} 
  catch(llist::OutOfRange)
    {cout << "Error: Out Of Range" << endl;}

  // 11.displayAll
  cout << endl;
  cout << c << endl; c++;
  L2.displayAll();
  // 12.delete Ith I==1 (indicate  the element removed) . 5 6 7 8 9 10
  cout << endl;
  cout << c << endl; c++;
  L2.deleteIth(1,x);
  cout << x << " was removed" << endl;

  // 13.delete Ith I==6 (indicate the element removed)  - 5 6 7 8 9 
  cout << endl;
  cout << c << endl; c++;
  L2.deleteIth(6,x);
  cout << x << " was removed" << endl;

  // 14.delete Ith I==3 (indicate the element removed)  - 5 6 8 9
  cout << endl;
  cout << c << endl; c++;
  L2.deleteIth(3,x);
  cout << x << " was removed" << endl;
 
  // 15.delete Ith I==5 . error (out of range)
  cout << endl;
  cout << c << endl; c++;
  try {L2.deleteIth(5,x);}
  catch(llist::OutOfRange){cout << "Error: Out Of Range" << endl; }

  // 16.delete Ith I==0 . error (out of range)
  cout << endl;
  cout << c << endl; c++;
  try {L2.deleteIth(0,x);}
  catch(llist::OutOfRange){cout << "Error: Out Of Range" << endl; }

  // 17.displayAll
  cout << endl;
  cout << c << endl; c++;
  L2.displayAll();
  // 18.delete from rear until it is empty (indicate the elements removed)
  cout << endl;
  cout << c << endl; c++;
  while(!L2.isEmpty())
    {
      L2.deleteRear(x);
      cout << x << " was removed from the list" << endl;
    }

  // 19.displayAll
  cout << endl;  
  cout << c << endl; c++;
  L2.displayAll();

}//end of case 2

//PURPOSE: to test cases for throwing errors for adding before the Ith element
void caseThree()
{
  cout << "Case 3:-------------------- " << endl;
  llist L3;
  int x;  // to hold the removed element

  // 1.add before the 0th . error (out of range)
  cout << endl;
  cout << 1 << endl;
  try {L3.addbeforeIth(0,x);}
  catch (llist::OutOfRange){cout << "Error: Out Of Range" << endl;}

  //2.delete front . error (underflow)
  cout << endl;
  cout << 2 << endl;
  try {L3.deleteFront(x);}
  catch (llist::Underflow){cout << "Error: trying to delete when list is empty" << endl;}
}   //end of case 3

//PURPOSE: to test cases for throwing errors when using delete the Ith element
void caseFour()
{
  cout << "Case 4:------------------------ " << endl;
  llist L4;
  int x;  // to hold the removed element

  //   1.delete 2nd . error (out of range)
  cout << endl;
  cout << 1 << endl;
  try {L4.deleteIth(2,x);}
  catch (llist::OutOfRange){cout << "Error: Out Of Range" << endl;}
  //    2.delete rear . error (underflow)
  cout << endl;
  cout << 2 << endl;
  try {L4.deleteRear(x);}
  catch (llist::Underflow){cout << "Error: trying to delete when list is empty" << endl;}
} // end of case 4


//PURPOSE Of The Program: To Test If The Linked List Class We Made Works
//Algorithm/Design: 4 test cases are divided into 3 functions and the user choses the cases they want to display until they pick 0 which makes them exit
int main()
{
  int selection; // this will indicate what the user wants to do
  //displays the menu for the user to chose a case  
  do
    {
      cout << endl << "MENU: These are your options: " << endl << endl;
      cout << "   (1) Case 1  " << endl;
      cout << "   (2) Case 2  " << endl;
      cout << "   (3) Case 3  " << endl;
      cout << "   (4) Case 4 " << endl;
      cout << "    Enter ( 0 ) to quit " << endl;
      cout << "===>";
      
      cin >> selection;
      
      switch(selection)//lets the user chose a case they want to display
	{
	case 1: caseOne(); break;
	case 2: caseTwo(); break;
	case 3: caseThree(); break;
	case 4: caseFour(); break;
	}
    }
  while(selection !=0);

}// end of main

