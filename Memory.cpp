#include<iostream>
#include<conio.h>
#include<string>
#include "Memory.h"

using namespace std;

		Memory::Memory()
		{
			
		}
		
		Memory::Memory(int compMem,string compHType,int compHCapacity)
		{
			this->compMem=compMem;
			this->compHType=compHType;
			this->compHCapacity=compHCapacity;
		}
		
		Memory::~Memory()
		{
			//cout<<"\n<Destructor call>\tMemory is Deleted Successfully\n";
		}
		
		void Memory::setCompMem(int compMem)
		{
			this->compMem=compMem;
		}
		
		int Memory::getCompMem()
		{
			return(compMem);
		}
		
		void Memory::setCompHType(string compHType)
		{
			this->compHType=compHType;
		}
		
		string Memory::getCompHType()
		{
			return(compHType);
		}
		
		void Memory::setCompHCapacity(int compHCapacity)
		{
			this->compHCapacity=compHCapacity;
		}
		
		int Memory::getCompHCapacity()
		{
			return(compHCapacity);
		}
		
		void Memory::displayCompMemInputs()
		{
			cout<<"\n6.\tcompMem :\t"<<getCompMem();
			cout<<"\n7.\tHard Disc Type :\t"<<getCompHType();
			cout<<"\n8.\tHard Disc Capacity :\t"<<getCompHCapacity();
		}
