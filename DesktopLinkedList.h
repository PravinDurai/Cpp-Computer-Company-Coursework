#ifndef DESKTOPLINKEDLIST_H
#define DESKTOPLINKEDLIST_H
#include "Desktop.h"
#include "Laptop.h"
#include "Server.h"

using namespace std;
class DesktopLinkedList
{
	public:
		Desktop* dtpPtr;
		Laptop* lapPtr;
		Server* serPtr;
		
		DesktopLinkedList* next;
	
		DesktopLinkedList();
	
		DesktopLinkedList(Desktop* dtpPtr);
	
		~DesktopLinkedList();
		
		void setDPtr(Desktop* dtpPtr);
		Desktop* getDPtr();
		void setLPtr(Laptop* lapPtr);
		Laptop* getLPtr();
		void setSPtr(Server* serPtr);
		Server* getSPtr();
};

#endif