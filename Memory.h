#ifndef MEMORY_H
#define MEMORY_H
#include<string.h>

using namespace std;

class Memory
{
	private:
		int compMem;
		string compHType;
		int compHCapacity;
	public:
		Memory();
		Memory(int compMem,string compHType,int compHCapacity);
		~Memory();
		
		void setCompMem(int);
		int getCompMem();
		void setCompHType(string);
		string getCompHType();
		void setCompHCapacity(int);
		int getCompHCapacity();
		void displayCompMemInputs();
};
#endif