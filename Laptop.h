#ifndef LAPTOP_H
#define LAPTOP_H
#include "Computer.h"


class Laptop : public Computer
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
		float sSize;
		string make;
		Computer* comp;
		
	public:
		Laptop();
		
		~Laptop();

		//void setCompInputs(string,int,string,int,int,string,int);
		void setCompId(int);
		int getCompId();
		void setCompOs(string);
		string getCompOs();
		void setSSize(float);
		float getSSize();
		void setMake(string);
		string getMake();
		
		Computer* getCompPtr();
		
		//Restriced Inputsint
		int getResCpu();
		int getResGpu();
		string getResHType();
		string getResOs();
		float getResSSize();
		
		
		void getAllInputs(int);
		
		void displayLaptopInputs();

		void laptopCostDescription();	
		
		float calculateLaptopCost();
};

#endif