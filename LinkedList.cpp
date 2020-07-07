#include "LinkedList.h"

using namespace std;

LinkedList::LinkedList()
{
	dtpPtr=NULL;
	lapPtr=NULL;
	serPtr=NULL;
	next=NULL;
}
	
LinkedList::LinkedList(Desktop* dtpPtr)
{
	this->dtpPtr=dtpPtr;
	lapPtr=NULL;
	serPtr=NULL;
	next=NULL;
}

LinkedList::LinkedList(Laptop* lapPtr)
{
	this->lapPtr=lapPtr;
	dtpPtr=NULL;
	serPtr=NULL;
	next=NULL;
}

LinkedList::~LinkedList()
{
	delete(dtpPtr);
	delete(lapPtr);
	delete(serPtr);
}

void LinkedList::setDPtr(Desktop* dtpPtr)
{
	this->dtpPtr=dtpPtr;
	lapPtr=NULL;
	serPtr=NULL;
	next=NULL;
}

Desktop* LinkedList::getDPtr()
{
	return(dtpPtr);
}

void LinkedList::setLPtr(Laptop* lapPtr)
{
	dtpPtr=NULL;
	this->lapPtr=lapPtr;
	serPtr=NULL;
	next=NULL;
}

Laptop* LinkedList::getLPtr()
{
	return(lapPtr);
}

void LinkedList::setSPtr(Server* serPtr)
{
	dtpPtr=NULL;
	lapPtr=NULL;
	this->serPtr=serPtr;
	next=NULL;
}

Server* LinkedList::getSPtr()
{
	return(serPtr);
}
	