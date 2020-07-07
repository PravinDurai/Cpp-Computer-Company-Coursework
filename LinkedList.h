#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Desktop.h"
#include "Laptop.h"
#include "Server.h"

using namespace std;
class LinkedList
{
	public:
		Desktop* dtpPtr;
		Laptop* lapPtr;
		Server* serPtr;
		
		LinkedList* next;
	
		LinkedList();
	
		LinkedList(Desktop* dtpPtr);
		
		LinkedList(Laptop* lapPtr);
	
		~LinkedList();
		
		void setDPtr(Desktop* dtpPtr);
		Desktop* getDPtr();
		void setLPtr(Laptop* lapPtr);
		Laptop* getLPtr();
		void setSPtr(Server* serPtr);
		Server* getSPtr();
};

#endif