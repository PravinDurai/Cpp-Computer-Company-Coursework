#ifndef COMPUTER_H
#define COMPUTER_H
#include<iostream>
#include<string.h>
#include "Cpu.h"
#include "Gpu.h"
#include "Memory.h"

using namespace std;

class Computer : public Cpu , public Gpu , public Memory
{
	private:
		
		
		Cpu* cpu=new Cpu();
		Gpu* gpu=new Gpu();
		Memory* mem=new Memory();
		
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
		float cost;
		static float cpuPrice;
		static float gpuPrice;
		static float memPrice;
		static float ssdPrice;
		static float hhdPrice;
		static float sshdPrice;
	public:
		Computer();
		
		~Computer();
		
		
		Cpu* getCPtr();
		Gpu* getGPtr();
		Memory* getMPtr();
		
		void setCompId(int);
		int getCompId();
		void setCpuInputs(string,int);
		void setGpuInputs(string,int);
		void setMemoryInputs(int,string,int);
		void displayCompInputs();
		void displayCompCostInputs();
		float costCalculator();
		int validateStringInput();
};
#endif