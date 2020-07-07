#include<iostream>
#include<string.h>
#include "Computer.h"

using namespace std;

Computer::Computer()
{
	cost=0;
}

/*
Computer::Computer(int compId, string compCpu,int compCCount,string compGpu,int compGCount,int compMem,string compHType,int compHCapacity)//:Cpu(compCpu,compCCount),Gpu(compGpu,compGCount),Memory(compMem,compHType,compHCapacity)
{
	cost=0;
	this->compId=compId;
	this->compCpu=compCpu;
	this->compCCount=compCCount;
	this->compGpu=compGCount;
	this->compMem=compMem;
	this->compHType=compHType;
	this->compHCapacity=compHCapacity;
}
*/

Computer::~Computer()
{
	//cout<<"\n<Destructor call>\tComputer is Deleted Successfully\n";
	delete(cpu);
	delete(gpu);
	delete(mem);
}

void Computer::setCompId(int compId)
{
	this->compId=compId;
}

int Computer::getCompId()
{
	return(compId);
}

Cpu* Computer::getCPtr()
{
	return(cpu);	
}

Gpu* Computer::getGPtr()
{
	return(gpu);
}

Memory* Computer::getMPtr()
{
	return(mem);
}

void Computer::setCpuInputs(string compCpu,int compCCount)
{
	//this->compCpu=compCpu;
	cpu->setCompCpu(compCpu);
	//this->compCCount=compCCount;
	//cout<<"\nClass :\tComputer.cpp \t Copde reached this point";
	cpu->setCCount(compCCount);
}

void Computer::setGpuInputs(string compGpu,int compGCount)
{
	//this->compGpu=compGpu;
	gpu->setCompGpu(compGpu);
	//this->compGCount=compGCount;
	gpu->setGCount(compGCount);
}

void Computer::setMemoryInputs(int compMem,string compHType,int compHCapacity)
{
	//this->compMem=compMem;
	mem->setCompMem(compMem);
	//this->compHType=compHType;
	mem->setCompHType(compHType);
	//this->compHCapacity=compHCapacity;
	mem->setCompHCapacity(compHCapacity);
}


//Displaying the outputs
void Computer::displayCompInputs()
{
	cout<<"\n1.\tComputer Id :\t"<<getCompId();
	cpu->displayCpuInputs();
	gpu->displayGpuInputs();
	mem->displayCompMemInputs();
}

//Display the output interms of cost (More like Billing)
void Computer::displayCompCostInputs()
{
	float hCost=0;
	cout<<"\n2.\tCPU :\t"<<cpu->getCompCpu()<<"      "<<cpu->getCCount()<<" x "<<cpuPrice<<"      "<<cpu->getCCount() * cpuPrice;
	cout<<"\n3.\tGPU :\t"<<gpu->getCompGpu()<<"      "<<gpu->getGCount()<<" x "<<gpuPrice<<"      "<<gpu->getGCount() * gpuPrice;
	cout<<"\n4.\tMemory :\t"<<mem->getCompMem()<<"GB      "<<mem->getCompMem()<<" x "<<memPrice<<"      "<<mem->getCompMem() / (memPrice * 100);
	if(mem->getCompHType()=="ssd")
		hCost=ssdPrice;
	else
		if(mem->getCompHType()=="hhd")
			hCost=hhdPrice;
		else
			hCost=sshdPrice;
    cout<<"\n4.\tHard Disc Type :\t"<<mem->getCompHType()<<"      "<<mem->getCompHCapacity()<<" x "<<hCost<<"      "<<mem->getCompHCapacity() / (hCost * 100);	
}

//1 CPU Price -> 30 Pounds
//1 GPU Price -> 35 Pounds
//Memory 1 GB = .25 => how to calculate is Memory / (0.25 *100)
//ssd = .35 hhd =.5 shhd = .75 how to calculate HCapacity / (0.25/.5/.75 * 100)
float Computer::costCalculator()
{
	cost=0;
	cout<<flush;
	cost+=cpu->getCCount() * cpuPrice;
	cost+=gpu->getGCount() * gpuPrice;
	cost+=mem->getCompMem() / (memPrice * 100);
	if(mem->getCompHType()=="ssd")
		cost+=mem->getCompHCapacity() / (ssdPrice * 100);
	else
		if(mem->getCompHType()=="hhd")
			cost+=mem->getCompHCapacity() / (hhdPrice * 100);
		else
			cost+=mem->getCompHCapacity() / (sshdPrice * 100);
	return(cost);
}


int Computer::validateStringInput()
{
	int num=0;
	string sNumber="";
	try
	{
		getline(cin,sNumber);
		num=stoi(sNumber);
	}
	catch(invalid_argument &m)
	{
		cout<<"\nPlease enter a valid data <Only Number> [Spaces and special characters and strings not allowed]\n";
	}
	return(num);
}

float Computer :: cpuPrice=30;
float Computer :: gpuPrice=35;
float Computer :: memPrice=.45;
float Computer :: ssdPrice=2.2;
float Computer :: hhdPrice=2.75;
float Computer :: sshdPrice=3.15;