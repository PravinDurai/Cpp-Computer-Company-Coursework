#include "DesktopLinkedList.h"

using namespace std;

DesktopLinkedList::DesktopLinkedList()
{
	dtpPtr=NULL;
	lapPtr=NULL;
	serPtr=NULL;
	next=NULL;
}
	
DesktopLinkedList::DesktopLinkedList(Desktop* dtpPtr)
{
	this->dtpPtr=dtpPtr;
	next=NULL;
}

DesktopLinkedList::~DesktopLinkedList()
{
	
}

void DesktopLinkedList::setDPtr(Desktop* dtpPtr)
{
	this->dtpPtr=dtpPtr;
	lapPtr=NULL;
	serPtr=NULL;
	next=NULL;
}

Desktop* DesktopLinkedList::getDPtr()
{
	return(dtpPtr);
}

void DesktopLinkedList::setLPtr(Laptop* lapPtr)
{
	dtpPtr=NULL;
	this->lapPtr=lapPtr;
	serPtr=NULL;
	next=NULL;
}

Laptop* DesktopLinkedList::getLPtr()
{
	return(lapPtr);
}

void DesktopLinkedList::setSPtr(Server* serPtr)
{
	dtpPtr=NULL;
	lapPtr=NULL;
	this->serPtr=serPtr;
	next=NULL;
}

Server* DesktopLinkedList::getSPtr()
{
	return(serPtr);
}
	