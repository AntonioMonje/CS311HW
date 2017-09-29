// =======================================================
// HW#: HW7P2 
// Your name: Antonio Monje
// Compiler:  g++
// File type: Implementation file
//=======================================================

#include <iostream>
#include "Ndgraph.h"
using namespace std;

int main()
{
  //variables initialized
  stack q;
  slist l1;
  el_t v;
  int vis = 0;
  dgraph T;
  //////////////
  T.fillTable();
  T.displayGraph();
  ///////////////
  q.push('A');//start with vertex A
  //do while the stack is not empty
  do{
    q.pop(v);//pop the vertex 
    //check if the vertex has been marked or not
    if(!T.isMarked(v))
      {
	vis++;      
	T.visit(vis, v);//visit the vertex  
	
	cout << "visited " << v << endl;
	l1 = T.findAdjacency(v);//put adjacent ones into a slist
	cout << "Pushing: ";
	l1.displayAll();
	cout << endl;
	//while list is not empty delete the lements and push them into the stack
	while(!l1.isEmpty())
	  {
	    l1.deleteRear(v);
	    q.push(v);
	  }
	cout << "Stack is: " << endl;
	q.displayAll();//display the stack
	cout << endl;
      }
    //if the vertex it marked just display the stack
    else if(T.isMarked(v))
      {
	cout << "Stack is: " << endl;
	q.displayAll();
	cout << endl;
      }
  }while(!q.isEmpty());//end of the loop
  
  cout << endl;
  T.displayGraph();
  
}



