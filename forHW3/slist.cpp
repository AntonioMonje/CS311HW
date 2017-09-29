// ====================================================
//HW#: HW3P2 slist
//Your name: Antonio Monje
//Complier:  g++
//File type: llist implementation file
//=====================================================

using namespace std;

#include<iostream>
#include"slist.h"
//Purpose: Constructor initializes Front and rear to Null and sets the counter for slist to 0
slist::slist()
{

  Front = NULL;//indicate an empty list
  Rear = NULL;//indicate an empty list
  Count = 0;//indicate an empty list
}
//Purpose: To allow us to compare two list using the = operator.
//Algorithm: if the list are different then delete the list while its not empty and whilee the list is nt null put the elements into the list so that the list gets the elements from the other list.
//Parameters: You pass the lisst that you are getting the elements from
slist& slist::operator=(const slist& OtherOne)
{
  el_t x;
  // First make sure this-> and OtherOne are not the same object.
  // To do this, compare the pointers to the objects .
  if(&OtherOne != this)
    {
      // this-> object has to be emptied first.
      while(!this->isEmpty())
	this->deleteRear(x);
      // this-> object has to be built up by allocating new cells 
      Node* P;//local pointer to OtherOne
      P = OtherOne.Front;
      while(P!=NULL)
	{
	  this -> addRear(P->Elem);//P's element is added to this->
	  P=P->Next;//go to next node in OhterOne
	}
    }
  return *this;
}
//Purpose: To allow us to compare two list using the == operator
//Algorithm: first check if the have the same amount of elements if yes go until the node is null check if the elements are the same in each list if yes keep checking if not return false. if they are the same return true.
//Parameters: You pass the lisst that you are getting the elements from
bool slist::operator==(const slist& Other)
{
  Node *p = this->Front;
  Node *t = Other.Front;
  if(Other.Count != this->Count)// checks if the sizes are the same if not return false
    {
      return false;
    }
  else//the sizes are the same so go through the wile loop to check the elements
    {
      while(p!=NULL)//go until it reaches null
	{
	  if(p->Elem != t->Elem)//compares to see if the elements are the same
	    {
	      return false;
	    }
	  else
	    {
	      p=p->Next;//increments this-> to the next node
	      t=t->Next;//increments other to the next node
	    }
	}
      return true;
    }
}
//Purpose:to create a new object this-> as a copy of the original
//Algorithm is a while loop the adds the elements into the other list from the original list until the original list reaches null
//Parameters: Original is being passes to the constructor by reference
slist::slist(const slist& Original)
{
  //this-> data members initialized
    this->Front = NULL;
    this->Rear = NULL;
    this->Count = 0;
    Node *P;
    P = Original.Front;
    //go until original reaches null
    while(P!=NULL)
      {
	this->addRear(P->Elem);//P's element is added to this->
	P=P->Next;//go to next node
      }
}



//Purpose: to search for an element in the list and return its position in the list
//Algorithm: a while loop that goes through the list until you find the element and returns the position or else return 0
//Parameters:you pass the element being searched
int slist::search(el_t Num)
{
  Node *p = Front;//initialize p
  int i = 0;// counter for the position
  
  //go through the list until you reach null if you find th element return the position
  while(p != NULL)
    {
      i++;//counter for the position increments
      if(p->Elem == Num)//if its the element return the position
	{
	  return i;
	}
      else// else increment to the next node
	{
	  p=p->Next;//moves to the next null
	}
    }
  return 0;//if its not found return 0
  
  
}

//Purpose: To replace the Ith node you want with a new element using the position from the search function
//Algorithm: checks for boundaries then goes through a loop until it reaches the number your looking for then replaces the old element with a new element
//Parameters: you pass the element you want to replace the old number with and the position of the old number
void slist::replace(el_t Num, int I)
{
  if(I > Count || I < 1)//error case if its out of range
    {
      throw OutOfRange();//out of range mesage
    }
  else //else search through the list and delete it
    {
      Node *p = Front;
      
      //goes through the list until you reach the node before the one you are searching for
      for(int K = 1; K <= I-1; K++)
        {
          p = p->Next;//moves to the next node
        }
      
      
      p->Elem = Num;//save the element thats being deleted into the variable
    }
}


