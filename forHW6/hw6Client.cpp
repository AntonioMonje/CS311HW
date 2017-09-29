// ====   For the HW6 Client file ====================================
//INSTRUCTION: Complete this file and comment using How to Comment file.
//implemented by Antonio Monje
using namespace std;
#include <iostream>
#include <locale>
#include "dgraph.h"
//Purpose: to test our dgraph functions and display the elements from the text file. Also it shows the outdegree and the adjacent ones for the vertex entered
//Algorithm: fwhile loop that doesn't stop unless a bad vertex is called or the user presses 0
int main()
{//variables initialized
  slist l1;
  el_t x;
  el_t y;
  dgraph T;
  ////////////
  T.fillTable();//fills the table from the text file
  T.displayGraph();//displays the contents neatly
  ///////////////////////////////////////////////////////////////////////
  cout << "Find the OUTDEGREE of the vertex" << endl;
  
  //do while loop while not 0 or bad vertex ask the user for information to find the outdegree and hecks for bad vertex
    
    do{      
      cout << endl;
      cout << "Enter a vertex or press 0 to quit and find the adjacency" << endl;  
      cin >> x;
      x = toupper(x);
      
      if(x!='0')
	{    
	  try{
	    cout << "Vertex " << x << " Out degree: ";	  
	    T.findOutDegree(x);//gets the outdegree for that vertex
	    cout << T.findOutDegree(x);
	  }
	  catch(dgraph::BadVertex)//called if a bad vertex is entered
	    {cout << " **Error: Bad Vertex!** " << endl;}
	}
    }while(x != '0');
    
    

    // catch(dgraph::BadVertex)//bad vertex is called when a bad vertex is entered
    //  {cout<< " **Error: Bad Vertex!** " << endl;}
    
    
    
    
    ////////////////////////////////////////////////////////////////
    cout << endl;
    cout << "Find the ADJANCENCY of the vertex" << endl;
   
    //do while llop until 0 or bad vertex is called to get information for the adjancet ones
    do{
      cout << "Enter a vertex or press 0 to quit" << endl;
      cin >> x;
      x = toupper(x);
      if(x!='0')
	{
	  try{
	  l1 = T.findAdjacency(x);//gets the adjacent ones for that vertex
	  l1.displayAll();
	  cout << endl;
	  }
    
    catch(dgraph::BadVertex)//called if a bad vertex is entered
      {cout<< " **Error: Bad Vertex!** " << endl;}
	}
    }while(x != '0');
    cout << "End of program" << endl;
}
/*
  
int main()
{ 0.Declare table object
  1.fillTable()
  2.displayGraph()
  while (the user does not want to stop)
    a.the user will specify which vertex     
    b.findOutDegree of the vertex and display the result
    c.catch exception but do not exit

  while (the user does not want to stop)
    a.the user will specify which vertex
    b.findAdjacency of the vertex and display the result (see Hint)
    c.catch exception but do not exit
}


Hint:
  slist l1;
  l1 = G.findAdjacency('a');
  // how do you display l1?  Hint: it is an slist from HW3.

*/
