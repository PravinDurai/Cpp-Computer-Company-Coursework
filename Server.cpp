#include<iostream>
#include<string.h>
#include "Server.h"

Server::Server()
{
	comp=new Computer();
}

Server::~Server()
{
	//cout<<"\n<Destructor call>\tServer is Deleted Successfully\n";
}

		Computer* Server::getCompPtr()
		{
			return(comp);
		}
		
		void Server::setCompId(int compId)
		{
			this->compId=compId;
			comp->setCompId(compId);
		}
		
		int Server::getCompId()
		{
			return(comp->getCompId());
		}
		
		void Server::setCompOs(string compOs)
		{
			this->compOs=compOs;
		}

		string Server::getCompOs()
		{
			return(compOs);
		}
		
		int Server::getResCpu()
		{
			int opt;
			do
			{
				cout<<"\nPlease select the Number of CPU b/w < 1 - 16 >\nYour Choice is <Hint : Int> :\t";
				opt=comp->validateStringInput();
				if((opt<=0)||(opt>=17))
				{
					cout<<"\nInvalid Input....\nPlease choose an option from the above list";
				}
			}while((opt<=0)||(opt>=17));
			return(opt);
		}
		
		int Server::getResGpu()
		{
			int opt;
			do
			{
				cout<<"\nPlease select the Number of GPU b/w < 1 - 32 > \nYour Choice is <Hint : Int> :\t";
				opt=comp->validateStringInput();
				if((opt<=0)||(opt>=33))
				{
					cout<<"\nInvalid Input....\nPlease choose an option from the above list";
				}
			}while((opt<=0)||(opt>=33));
			return(opt);
		}
		
		string Server::getResHType()
		{
			int opt;
			string op;
			do
			{
				//system("CLS");
				cout<<flush;
				cout<<"\n****************************************************************************\n";
				cout<<"\n           Please select one of the below Hard Disk Types                   \n";
				cout<<"\n****************************************************************************\n";
				cout<<"\n1.\tssd\n";
				cout<<"\n2.\thdd\n";
				cout<<"\n3.\tsshd\n";
				
				cout<<"\nYour Choice is <Hint : Int> :\t";
				opt=comp->validateStringInput();
				if((opt<=0)||(opt>=4))
				{
					cout<<"\nInvalid Input....\nPlease choose an option from the above list";
				}
			}while((opt<=0)||(opt>=4));
			switch(opt)
			{
				case 1:
					op="ssd";
					break;
				case 2:
					op="hdd";
					break;
				case 3:
					op="sshd";
					break;
			}
			return(op);		
		}
		
		string Server::getResOs()
		{
			int opt;
			string op;
			do
			{
				//system("CLS");
				cout<<flush;
				cout<<"\n****************************************************************************\n";
				cout<<"\n           Please select one of the below Operating System                  \n";
				cout<<"\n****************************************************************************\n";
				cout<<"\n1.\tWindows\n";
				cout<<"\n2.\tLinux\n";
				cout<<"\n3.\tMac\n";
				
				cout<<"\nYour Choice is <Hint : Int> :\t";
				opt=comp->validateStringInput();
				if((opt<=0)||(opt>=4))
				{
					cout<<"\nInvalid Input....\nPlease choose an option from the above list";
				}
			}while((opt<=0)||(opt>=4));
			switch(opt)
			{
				case 1:
					op="Windows";
					break;
				case 2:
					op="Linux";
					break;
				case 3:
					op="Mac";
					break;
			}
			return(op);
		}
		
		void Server::getAllInputs(int id)
		{
			string compOs;
			string cpu;
			string gpu;
			int compMem1;
			string compHType1;
			int compHCapacity1;
			char opt;
			do
			{
				system("CLS");
				cout<<"\n********************************************************************************\n";
				cout<<"\n                             Server Spec										 \n";
				cout<<"\n********************************************************************************\n";
				comp->setCompId(id);
				//cout<<"Class :\tServer\tInput successfully reaced this point";
			
				//clrscr();
				cout<<"\n1.\tCPU <Hint : String> :\t";
				cin.ignore();
				getline(cin,cpu);
				comp->setCpuInputs(cpu,getResCpu());
				cout<<"\n2.\tGPU <Hint : String> :\t";
				cin.ignore();
				getline(cin,gpu);
				comp->setGpuInputs(gpu,getResGpu());
				cout<<"\n3.\tMemory Size <Hint : Int> :\t";
				compMem1=comp->validateStringInput();
				cout<<"\n4.\tHardDisk Type <Hint : String> :\t";
				compHType1=getResHType();
				cout<<"\n5.\tHardDisk Capacity <Hint : Int> :\t";
				compHCapacity1=comp->validateStringInput();
				comp->setMemoryInputs(compMem1,compHType1,compHCapacity1);
				cout<<"\nWhich OS do you prefer <Hint : Int> :\t";
				compOs=getResOs();
				setCompOs(compOs);
				system("CLS");
				cout<<"\nThanks! Please check your input before we proceed\n"; 
				displayServerInputs();
				cout<<"\nPlease choose ' Y ' if everything looks okay else please press ' N ' to start again :\t";
				cin>>opt;
			}while(opt=='N'||opt=='n');
		}
		
		void Server::displayServerInputs()
		{
			
			cout<<"\n*******************************************************************************\n";
			cout<<"\n                             Server Spec										\n";
			cout<<"\n*******************************************************************************\n";
			
			comp->displayCompInputs();
			cout<<"\n9.\tOs Type :"<<getCompOs();
			cout<<flush;
			
		}
		
		void Server::serverCostDescription()
		{
			system("CLS");
			cout<<"\n*******************************************************************************\n";
			cout<<"\n                       Server Specification with Cost                         \n";
			cout<<"\n*******************************************************************************\n";
			cout<<"\n1.\tComputer ID :\t"<<comp->getCompId();
			comp->displayCompCostInputs();
			cout<<"\n5.\tComputer OS :\t"<<getCompOs()<<"      Compliment";
			cout<<"\n*******************************************************************************\n";
			cout<<"              Total Cost :\t"<<calculateServerCost();
			cout<<"\n*******************************************************************************\n";
		}
		
		float Server::calculateServerCost()
		{
			return(comp->costCalculator());
		}
