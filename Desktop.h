#ifndef DESKTOP_H
#define DESKTOP_H
#include<string.h>
#include "Computer.h"

using namespace std;

class Desktop : public Computer
{
	private:
		
		int compId;
		/*
		string compCpu;
		static int compCCount;
		string compGpu;
		static int compGCount;
		int compMem;
		string compHType;
		int compHCapacity;
		*/
		string compOs;
		Computer* comp;
		
	public:
		Desktop();
		
		//Desktop(int compId,string compCpu,1,string compGpu,1,int compMem,string compHType,int compHCapacity,string compOs):Computer(compId, compCpu,compCCount,compGpu,compGCount,compMem,compHType,compHCapacity);
		
		~Desktop();

		//Getters and setters 
		//void setCompInputs(string,int,string,int,int,string,int);
		void setCompId(int);
		int getCompId();
		void setCompOs(string);
		string getCompOs();
		
		Computer* getCompPtr();
		
		//Restriced Inputsint
		int getResCpu();
		int getResGpu();
		string getResHType();
		string getResOs();
		
		//General Functions
		void getAllInputs(int);
		void displayDesktopInputs();
		void desktopCostDescription();	
		float calculateDesktopCost();
		int validateStringInput();
};
#endif