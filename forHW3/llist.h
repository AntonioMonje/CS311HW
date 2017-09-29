//INSTRUCTION:
//Llist class - header file template (by Yoshii) based on Notes-6A
//You must complete the ** parts and then complete llist.cpp
// Don't forget PURPOSE and PARAMETERS 
// =======================================================
// HW#: HW3P1 llist
// Your name: Antonio
// Compiler:  g++ 
// File type: headher file 
//=======================================================

//----- Globally setting up the alias and struct  ----------------
typedef int el_t ;  // elements will be int

//a list node is defined here as a struct Node
// I could have done class Node and add the data members under public
// but it would use too much space
struct Node
{
  el_t Elem;   // elem is the element stored
  Node *Next;  // next is the pointer to the next node
};
//---------------------------------------------------------

class llist
{
  
 protected:
  Node *Front;       // pointer to the front node
  Node *Rear;        // pointer to the rear node
  int  Count;        // counter for the number of nodes
  
 public:

  // Exception handling classes 
  class Underflow{};   // thrown when you try to remove from an empty list
  class OutOfRange{};  // thrown when the specified Node is out of range

  llist ();     // constructor to create a list object
  ~llist();     // destructor to destroy all nodes
  
  //Purpose: To check if the list is empty
  //Parameters: Nothing
  bool isEmpty();
    
  //Purpose: To display the content of the linked list
  //Parameters: Nothing
  void displayAll();

  //Purpose: To add an element to the list
  //Parameters: you pass the eelement to be added
  void addFront(el_t);
    
  //Purpose: To add an element to the rear of the list
  //Parameters: you pass the element to be added
  void addRear(el_t);

  //Purpose: To delete the from element from the list
  //Parameters: provide a holder for the element removed (pass by ref)
  void deleteFront(el_t&);
    
  //Purpose: To delete rear element from the list
  //Parameters: provide a holder for the element removed (pass by ref)
  void deleteRear(el_t&);
    
  //Purpose: To delete the element you want from the list
  //Paramters: provide a holder for the element removed (pass by ref)
  void deleteIth(int, el_t&);

  //Purpose: To add an element before another certain element in the list
  //Parameters: you pass an integer and element to be added
  void addbeforeIth(int, el_t);
    
};
