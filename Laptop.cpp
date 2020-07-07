#include<iostream>
#include<string.h>
#include "Laptop.h"

Laptop::Laptop()
{
	comp=new Computer();
}

Laptop::~Laptop()
{
	//cout<<"\n<Destructor call>\tLaptop is Deleted Successfully\n";
}

		Computer* Laptop::getCompPtr()
		{
			return(comp);
		}
		
		void Laptop::setCompId(int compId)
		{
			this->compId=compId;
			comp->setCompId(compId);
		}
		
		int Laptop::getCompId()
		{
			//cout<<"\nLaptop Computer Id :\t"<<comp->getCompId();
			return(comp->getCompId());
		}
		
		void Laptop::setCompOs(string compOs)
		{
			this->compOs=compOs;
		}

		string Laptop::getCompOs()
		{
			return(compOs);
		}
		
		void Laptop::setSSize(float sSize)
		{
			this->sSize=sSize;
		}
		
		float Laptop::getSSize()
		{
			return(sSize);
		}
		
		void Laptop::setMake(string make)
		{
			this->make=make;
		}
		
		string Laptop::getMake()
		{
			return(make);
		}
		
		
		string Laptop::getResHType()
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
		
		string Laptop::getResOs()
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
		
		
		float Laptop::getResSSize()
		{
			int opt;
			float op;
			do
			{
				//system("CLS");
				cout<<flush;
				cout<<"\n****************************************************************************\n";
				cout<<"\n           Please select one of the below Screen Size                       \n";
				cout<<"\n****************************************************************************\n";
				cout<<"\n1.\t11.1''\n";
				cout<<"\n2.\t12\n";
				cout<<"\n3.\t13.3\n";
				cout<<"\n4.\t14''\n";
				cout<<"\n5.\t15.6\n";
				cout<<"\n6.\t17.3\n";
				cout<<"\nYour Choice is <Hint : Int> :\t";
				opt=comp->validateStringInput();
				if((opt<=0)||(opt>=7))
				{
					cout<<"\nInvalid Input....\nPlease choose an option from the above list";
				}
			}while((opt<=0)||(opt>=7));
			switch(opt)
			{
				case 1:
					op=11.1;
					break;
				case 2:
					op=12;
					break;
				case 3:
					op=13.3;
					break;
				case 4:
					op=14;
					break;
				case 5:
					op=15.6;
					break;
				case 6:
					op=17.3;
					break;
			}
			return(op);
		}
		
		
		void Laptop::getAllInputs(int id)
		{
			
			string make;
			string cpu;
			string gpu;
			int compMem1;
			string compHType1;
			int compHCapacity1;
			float sSize;
			string compOs;
			
			char opt;
			do{
				compMem1=0;
				compHCapacity1=0;
				
				system("CLS");
				cout<<"\n********************************************************************************\n";
				cout<<"\n                             Laptop Spec										 \n";
				cout<<"\n********************************************************************************\n";
				comp->setCompId(id);
				//cout<<"Class :\tLaptop\tInput successfully reaced this point";
			
				cout<<flush;
				cout<<"\n1.\tManufacturer <Hint : String> :\t";
				//cin.ignore();
				getline(cin,make);
				setMake(make);
				cout<<"\n1.\tCPU <Hint : String> :\t";
				//cin.ignore();
				getline(cin,cpu);
				comp->setCpuInputs(cpu,1);
				cout<<"\n2.\tGPU <Hint : String> :\t";
				//cin.ignore();
				getline(cin,gpu);
				comp->setGpuInputs(gpu,1);
				cout<<"\n3.\tMemory Size <Hint : Int> :\t";
				while(compMem1==0)
					compMem1=comp->validateStringInput();
				cout<<"\n4.\tHardDisk Type :\t";
				compHType1=getResHType();
				cout<<"\n5.\tHardDisk Capacity <Hint : Int> :\t";
				while(compHCapacity1==0)
					compHCapacity1=comp->validateStringInput();
				comp->setMemoryInputs(compMem1,compHType1,compHCapacity1);
				cout<<"\nScreen Size :\t";
				sSize=getResSSize();
				setSSize(sSize);
				cout<<"\nWhich OS do you prefer :\t";
				compOs=getResOs();
				setCompOs(compOs);
				system("CLS");
				cout<<"\nThanks! Please check your input before we proceed\n"; 
				displayLaptopInputs();
				cout<<"\nPlease choose ' Y ' if everything looks okay else please press ' N ' to start again :\t";
				cin>>opt;
			}while(opt=='N'||opt=='n');
		}
		
		void Laptop::displayLaptopInputs()
		{
			cout<<flush;
			cout<<"\n*******************************************************************************\n";
			cout<<"\n                             Laptop Spec										\n";
			cout<<"\n*******************************************************************************\n";
			
			comp->displayCompInputs();
			cout<<"\n9.\tManufacturer :\t"<<getMake();
			cout<<"\n10.\tOs Type :"<<getCompOs();
			cout<<"\n11.\tScreen Size :\t"<<getSSize();
			cout<<flush;
			
		}
		
		void Laptop::laptopCostDescription()
		{
			system("CLS");
			cout<<"\n*******************************************************************************\n";
			cout<<"\n                       Laptop Specification with Cost                         \n";
			cout<<"\n*******************************************************************************\n";
			cout<<"\n1.\tComputer ID :\t"<<comp->getCompId();
			comp->displayCompCostInputs();
			cout<<"\n5.\tComputer OS :\t"<<getCompOs()<<"      Compliment";
			cout<<"\n6.\tScreen Size :\t"<<getSSize();
			cout<<"\n7.\tManufacturer :\t"<<getMake();
			cout<<"\n*******************************************************************************\n";
			cout<<"              Total Cost :\t"<<calculateLaptopCost();
			cout<<"\n*******************************************************************************\n";
		}
		
		float Laptop::calculateLaptopCost()
		{
			return(comp->costCalculator());
		}
