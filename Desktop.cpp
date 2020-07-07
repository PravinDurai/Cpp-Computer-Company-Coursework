#include<iostream>
#include<conio.h>
#include<string>
#include "Desktop.h"
using namespace std;

		Desktop::Desktop()
		{
			comp=new Computer();
		}
		
		/*
		Desktop::Desktop(int compId,string compCpu,int compCCount=1,string compGpu,int compGCount=1,int compMem,string compHType,int compHCapacity,string compOs):Computer(compId, compCpu,compCCount,compGpu,compGCount,compMem,compHType,compHCapacity)
		{
			this->compId=compId;
			this->compOs=compOs;
		}
		*/

		Desktop::~Desktop()
		{
			delete(comp);
			//cout<<"\n<Destructor call>\tDesktop is Deleted Successfully\n";
		}
		
		Computer* Desktop::getCompPtr()
		{
			return(comp);
		}
		
		void Desktop::setCompId(int compId)
		{
			this->compId=compId;
			comp->setCompId(compId);
		}
		
		int Desktop::getCompId()
		{
			return(comp->getCompId());
		}
		
			void Desktop::setCompOs(string compOs)
		{
			this->compOs=compOs;
		}

		string Desktop::getCompOs()
		{
			return(compOs);
		}
		
		int Desktop::getResCpu()
		{
			int opt=0;
			while((opt<=0)||(opt>=3))
			{
				cout<<"\nCPU can be either <1 or 2> for a Desktop :\t";
				opt=validateStringInput();
				//cout<<"\nnumber :\t"<<opt;
				if((opt<=0)||(opt>=3))
				{
					cout<<"\nInvalid Input....";
				}
			}
			//while((opt<=0)||(opt>=3));
			return(opt);
		}
		
		int Desktop::getResGpu()
		{
			int opt=0;
			string inp;
			do
			{
				cout<<"\nPlease select the Number of GPU b/w < 1 - 4 > :\t";
				opt=validateStringInput();
				if((opt<=0)||(opt>=5))
				{
					cout<<"\nInvalid Input....\n";
				}
			}while((opt<=0)||(opt>=5));
			return(opt);
		}
		
		string Desktop::getResHType()
		{
			int opt;
			string inp;
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
			
				cout<<"\nYour Choice is :\t";
				opt=validateStringInput();
				if((opt<=0)||(opt>=4))
				{
					//cout<<"\nInvalid Number is :\t"<<opt;
					cout<<"\nInvalid Input....\nPlease choose an option from the below list\n";
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
		
		string Desktop::getResOs()
		{
			int opt;
			string inp;
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
			
				cout<<"\nYour Choice is :\t";
				opt=validateStringInput();
				if((opt<=0)||(opt>=4))
				{
					cout<<"\nInvalid Input....\nPlease choose an option from the below list\n";
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
		
		void Desktop::getAllInputs(int id)
		{
			string compOs;
			string cpu;
			string gpu;
			int compMem1=0;
			string compHType1;
			int compHCapacity1=0;
			char opt;
			string inp;
			string sMemSize;
			string sHCapacity;
			do{
				cout<<flush;
				
				cpu="\0";
				gpu="\0";
				compMem1=0;
				//compHType1="";
				compHCapacity1=0;
				
				system("CLS");
				cout<<"\n********************************************************************************\n";
				cout<<"\n                             Desktop Spec										 \n";
				cout<<"\n********************************************************************************\n";
				comp->setCompId(id);
				//cout<<"Class :\tDesktop\tInput successfully reaced this point";
				//clrscr();
				cout<<"\n1.\tCPU <Hint : String> :\t";
				while(cpu=="\0")
				{
					getline(cin,cpu);
				}
				comp->setCpuInputs(cpu,getResCpu());
				cout<<"\n2.\tGPU <Hint : String> :\t";
				getline(cin,gpu);
				comp->setGpuInputs(gpu,getResGpu());
				cout<<"\n3.\tMemory Size :\t";
				while(compMem1==0)
				{
					compMem1=validateStringInput();
				}
				cout<<"\n4.\tHardDisk Type :\t";
				compHType1=getResHType();
				cout<<"\n5.\tHardDisk Capacity :\t";
				while(compHCapacity1==0)
				{
					compHCapacity1=validateStringInput();
				}
				comp->setMemoryInputs(compMem1,compHType1,compHCapacity1);
				cout<<"\nWhich OS do you prefer :\t";
				compOs=getResOs();
				setCompOs(compOs);
				system("CLS");
				cout<<"\nThanks! Please check your input before we proceed\n"; 
				displayDesktopInputs();
				cout<<"\nPlease choose ' Y ' if everything looks okay else please press ' N ' to start again :\t";
				cin>>opt;
			}while(opt=='N'||opt=='n');
		}
		
		void Desktop::displayDesktopInputs()
		{
			cout<<"\n*******************************************************************************\n";
			cout<<"\n                             Desktop Spec										\n";
			cout<<"\n*******************************************************************************\n";
			
			comp->displayCompInputs();
			cout<<"\n9.\tOs Type :"<<getCompOs()<<"\n";
			cout<<flush;
		}
		
		void Desktop::desktopCostDescription()
		{
			system("CLS");
			cout<<"\n*******************************************************************************\n";
			cout<<"\n                       Desktop Specification with Cost                         \n";
			cout<<"\n*******************************************************************************\n";
			cout<<"\n1.\tComputer ID :\t"<<comp->getCompId();
			comp->displayCompCostInputs();
			cout<<"\n5.\tComputer OS :\t"<<getCompOs()<<"      Compliment";
			cout<<"\n*******************************************************************************\n";
			cout<<"              Total Cost :\t"<<calculateDesktopCost();
			cout<<"\n*******************************************************************************\n";
		}
		
		float Desktop::calculateDesktopCost()
		{
			return(comp->costCalculator());
		}
		
		int Desktop::validateStringInput()
		{
			int number=0;
			string sNumber="";
			try
			{
				//cout<<"\nEnter your Input <Hint : Int> :\t";
				getline(cin,sNumber);
				number=stoi(sNumber);
				
			}catch(invalid_argument &m)
			{
				cout<<"\nPlease enter a valid data <Only Number> [Spaces and special characters and strings not allowed]\n";
				//cout<<"\n Input is :\t"<<number;
			}
			//cout<<"\nNumber Returned is :\t"<<number;
			return(number);
		}