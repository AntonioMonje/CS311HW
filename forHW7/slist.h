// =======================================================
// HW#: HW3P2 slist
// Your name: Antonio
// Compiler:  g++
// File type: headher file
//=======================================================
#include "llist.h"
//---------------------------------------------------------
//Purpose to use inhertance from llist so that slist can use the public and protected functions
class slist : public llist
{

 public:
  //PURPOSE: Constructor for the list  
  slist();
  //PURPOSE: Constructor for the slist for list using pointers
  //PARAMETERS: the list you are passing 
  slist(const slist&);
  //PURPOSE: To make the two ist compare using the = operator
  //PARAMETERS: the list you are passing
  slist& operator=(const slist&);
  //PURPOSE: To make the two list compare using the == operator 
  //PARAMETERS: the list you are passing
  bool operator==(const slist&); 
  //PURPOSE: To search for a element in the list and report its location
  //PARAMETERS:provide a holder for the element searched and its position  (pass by ref)
  int search(el_t);
  //PURPOSE: To replace a element in the list with a new element
  //PARAMETERS: provide a holder for the element tht was deleted  (pass by ref)
  void replace(el_t, int);

};
