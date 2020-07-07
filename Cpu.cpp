#include<iostream>
#include<string.h>
#include "Cpu.h"

Cpu::Cpu()
{
	
}

Cpu::Cpu(string compCpu,int compCCount)
{
	this->compCpu=compCpu;
	this->compCCount=compCCount;
}

Cpu::~Cpu()
{
	//cout<<"\n<Destructor call>\tCPU is Deleted Successfully\n";
}	

void Cpu::setCompCpu(string compCpu)
{
	this->compCpu=compCpu;
}

string Cpu::getCompCpu()
{
	return(compCpu);
}

void Cpu::setCCount(int compCCount)
{
	this->compCCount=compCCount;
}

int Cpu::getCCount()
{
	return(compCCount);
}

void Cpu::displayCpuInputs()
{
	cout<<"\n2.\tCPU :\t"<<getCompCpu();
	cout<<"\n3.\tNumber of CPU :\t"<<getCCount();
}
