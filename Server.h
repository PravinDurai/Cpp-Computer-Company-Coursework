#ifndef SERVER_H
#define SERVER_H
#include "Computer.h"


class Server : public Computer
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
		Server();
		
		~Server();
		
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
		
		void getAllInputs(int);
		
		void displayServerInputs();

		void serverCostDescription();	
		
		float calculateServerCost();
		
	
};

#endif