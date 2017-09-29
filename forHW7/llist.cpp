//INSTRUCTION:
//Use the provided text to help create llist.cpp
//based on Yoshii  CS311  Notes-6A

//- Make sure PURPOSE and PARAMETER comments are given
//  DO NOT DELETE my descriptions but USE them.
//- Make sure all if-then-else are commented describing which case it is
//- Make sure all local variables are described fully with their purposes
//EMACS HINT:
//  control-K cuts and control-Y pastes
//  Esc X replace-str does string replacements
//  Esc > goes to the end of the file; Esc < to the beginning
//  Tab on each line will indent perfectly for C++

// ====================================================
//HW#: HW3P1 llist
//Your name: Antonio Monje
//Complier:  g++
//File type: llist implementation file
//=====================================================

using namespace std;

#include<iostream>
#include"llist.h" 

//Constructor
//- initialize Front and Rear to be NULL and Count = 0.
//- This does not create any node.  The new list is empty.
//PURPOSE: constructor initializes front and rear to NULL and count to 0
//ALGORITHM: NONE
//PARAMETERS: NONE
llist::llist()
{
  Front = NULL;//front initialized to NULL
  Rear = NULL;//rear initialized to NULL
  Count = 0;//Count initialized to 0
  cout << "....in the llist constructor" << endl;
}

//Destructor  
//- while the list is not empty, call deleteFront repeatedly to delete all nodes.
//- Please place a cout in this function "calling the llist desctructor."
//PURPOSE: To destroy the linked list
//ALGORITHM: while loop that calls deletefront until the list is empty then displays a message
//PARAMETER: NONE
llist::~llist()
{
  el_t x;//variable of el_t for delete front to recieve
  while(!isEmpty())//While the list i nont empty keep going
    {
      deleteFront(x);//calls deletefront to delete the lsit until its empty
    }
  cout << "....in the llist destructor." << endl;
}

//  - return true if Front and Rear are both pointing to NULL and Count is 0.
//  - (all 3 conditions must be checked)
//PURPOSE: To check if the linked list is empty
//ALGORITHM: If the front and rear are null and count is 0 then return true else return false
//PARAMETERS: NONE
bool llist::isEmpty()
{
  if(Front == NULL && Rear == NULL && Count == 0)//checks if the list is empty
    {
      return true;//if it empty return true
    }
  else
    return false;//else return false
}

//  - Special case: if the list is empty, display [ empty ] ).
//  - Regular: 
//    displays each element of the list horizontally starting from Front in [ ].
//PURPOSE: To display the contents of the linked list
//ALGORITHM: if the the list is empty display empty else while node p is not null display the element and increment
//PARAMETERS: NONE
void llist::displayAll()
{
  Node* p = Front;
  if(isEmpty())//If the list is empty display empty
    {
      cout << " [ Empty ] " << endl;
    }
  
  else//else go through the list and display the elements until the end of the list
    {
      cout << " [ ";
      while(p != NULL)//goes until p reaches NULL 
	{
	  cout << p -> Elem << " ";//displays the element 
	  p = p -> Next;  //increments the pointer
	}
      cout << "] ";
      cout << endl;
    }
}

//2 cases:
//  - Special case: if this is going to be the very first node, you must
//    create a new node and make Front and Rear point to it. Place NewNum and
//    Count is updated.
//  - Regular: adds a new node at the rear and puts NewNum in the Elem field
//    of this new node. Count is updated.
//PURPOSE: To add an element to the rear of the linked list
//ALGORITHM: if this is going to be the very first node, you must
//    create a new node and make Front and Rear point to it. Place NewNum and
//    Count is updated.
//else adds a new node at the rear and puts NewNum in the Elem field
//    of this new node. Count is updated.
//Parameters: you pass the element to be added
void llist::addRear(el_t NewNum)
{
  if(isEmpty())//checks if the list is empty
    {
      Front = Rear = new Node;//makes a new node
      Rear->Elem = NewNum;//rear element gets the element being passed
      Rear->Next = NULL;//rear next gets null
      Count++;//incrcement
    }
  else
    {
      //Regular case:
      Rear->Next = new Node;// make a new node
      Rear = Rear->Next;//move rear to the next node
      Rear->Elem = NewNum;//place the elementd you passed into the new node
      Rear->Next = NULL;// rear next gets null
      Count++;//increment
    }
}
//PURPOSE:To add an element to the list
//ALGORITHM:
//2 cases:
//- Special case: if this is going to be the very first node, you must
//   create a new node and make Front and Rear point to it. Place NewNum and
//   Count is updated.
//- Regular: add a new node to the front of the list and 
//  Count is updated.
//PARAMETERS: you pass the element to be added
void llist::addFront(el_t NewNum)
{
  if(isEmpty())//checks if the list is empty if so it makes a new node add the element to it and increments
    {
      Front = Rear = new Node;//creates a new node
      Front->Elem = NewNum;//puts the element in the new node
      Front->Next = NULL;//puts null in front next
      Count++;//increment
    }
  else
    {
      // Regular case:
  Node *x;
  x = new Node;//make a new node
  x->Next = Front;// the nodes next gets front
  Front = x;// front gets x
  Front->Elem = NewNum;// front element gets the element you want to add
  Count++;//increment
    }
}

//PURPOSE: To delete the front element from the list
//ALGORITHM:
//3 cases:
//- Error case: if the List is empty, throw Underflow
//- Special case: if currently only one Node,
//   give back the front node element through OldNum (pass by reference) and
//   make sure both Front and Rear become NULL. Count is updated.
//- Regular: give back the front node element through OldNum (pass by reference)
//  and also removes the front node.  Count is updated.
//PARAMETERS:You pass the element to be deleted by reference
void llist::deleteFront(el_t& OldNum)
{
  if(isEmpty())//if the list is empty throw underflow
    {
      throw Underflow();//if the list is empty and they try to delete
    }
  else if(Count == 1)//if their is one node then save the front element in a variable
    {
      OldNum = Front->Elem;//save the variable to be passed by reference 
      delete Front;//delete the front element after it was saved in the variable
      Front = NULL;//since the first was deleted set front to null
      Rear = NULL;//since the first was deleted set rear to null
      Count--;// decrement
    }
  else
    {
      //Regular case:
      OldNum = Front->Elem;//save front element in the variable being passed
      Node *Second;//declare a node
      Second = Front->Next;//make the node get front next
      delete Front;//delete front
      Front = Second;//front gets second nthat contains front next
      Count--;//decrement
    }
}

//PURPOSE:To delete the rear element from the list
//ALGORITHM:
// 3 cases:
//- Error case: if empty, throw Underflow
//- Special case: if currently only one node,
//   give back the rear node element through OldNum (pass by reference) and
//   make sure both Front and Rear become NULL. Count is updated.
//- Regular: give back the rear node element through OldNum (pass by reference)
//  and also remove the rear node. Count is updated.
//PARAMETERS: you pass the element your deleting by referencec
void llist::deleteRear(el_t& OldNum)  
{
  //OldNum = Rear->Elem;
  //Node *p = Front;
  //Make p go to the one right before rear (using while)
  //while(p->Next != Rear)
  // {
  //   p = p-> Next;
  // }
  //delete Rear;
  //Rear = p;
 
  if(isEmpty())//checks the if the list is empty
    {
	  throw Underflow();
    }
  else if(Count == 1)//If the count is 1 then store the element in the variable then delete
    {
      OldNum = Rear->Elem;//store the value into oldnum
      delete Rear;//delete the rear 
      Front = NULL;//since its the first make front null
      Rear = NULL;//since its the first make rear null
      Count--;//decrement
    }
  else//Regular case
    {
      OldNum = Rear->Elem;
      Node *p = Front;
      //Make p go to the one right before rear (using while)
      while(p->Next != Rear)//Go until p is rear
	{
	  p = p-> Next;// moves to the next node
	}
      delete Rear;//delete
      Rear = p;
      Rear->Next = NULL;
      Count--;//decrement
    }
  
}

//PURPOSE:To delete a certain element from the list
//ALGORITHM;
//4 cases:
//- Error case: 
//  If I is an illegal value (i.e. > Count or < 1) throw OutOfRange.
//- Special cases: this should simply call deleteFront when I is 1 
//- or deleteRear when I is Count
//- Regular: delete the Ith node (I starts out at 1).  Count is updated.
//<see the template loops in the notes to move 2 pointers to the right nodes;
//and make sure you indicate the purposes of these local pointers>
//PARAMETERS: you pass the number your looking for I and pass back the delete number Oldnum
void llist::deleteIth(int I, el_t& OldNum)
{
  if(I > Count || I < 1)//error case if its out of range
    {
      throw OutOfRange();//out of range mesage
    }
  else if(I == 1)// first element just delete the front
    {
      deleteFront(OldNum);
    }
  else if(I == Count)//if its the last element just delete the rear
    {
      deleteRear(OldNum);
    }
  else //else search through the list and delete it
    {
      Node *p = Front;
      Node *T = Front->Next;
      //goes through the list until you reach the node before the one you are searching for
      for(int K = 1; K < I-1; K++)
	{
	  p = p->Next;//moves to the next node
	  T = T->Next;//moves to the next node
	}

      p->Next= p->Next->Next;// move p to the next node
      OldNum = T->Elem;//save the element thats being deleted into the variable
      delete T; //deleting the node your searching for
      Count--;//decrement
    }
}


//PURPOSE:To add an element before another element in the list
//ALGORITHM:
//4 cases:
//-  Error case:
//   If I is an illegal value (i.e. > Count+1 or < 1) throw OutOfRange.
//-  Special cases: this should simply call addFront when I is 1 or addRear when
//   I is Count+1
//-  Regular: add right before the Ith node. Cout if updated.
//<see the template loops in the notes to move 2 pointers to the right nodes
//and make sure you indicate the purposes of these local pointers>
//PARAMETERS:You pass the number your looking for and pass back the element thats deleting
void llist::addbeforeIth(int I, el_t newNum)
{
  if(I > (Count+1) || I < 1)//checks if its out of range
    {
      throw OutOfRange();//error for out of range
    }
  else if(I == 1)// if its the first element just add front
    {
      addFront(newNum);
    }
  else if(I == (Count+1))//if its the last element just add rear
    {
      addRear(newNum);
    }
  else//regular case
    {
      Node *p = Front;//makes node p point to front
      Node *T;// makes node t
      //goes through the list until you reach the node before the one you are searching for
      for(int K = 1; K < I-1; K++)
	{
	  p = p->Next;//moves the next node
	}
      T = new Node;// makes a new node
      T->Next = p->Next;
      p->Next = T;//p next gets t
      T->Elem = newNum;//t element gets newNum which is the element you want to add
      Count++;//increment
    }

}
