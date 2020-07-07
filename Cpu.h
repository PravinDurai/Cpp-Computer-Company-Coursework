#ifndef CPU_H
#define CPU_H
#include<string.h>

using namespace std;

class Cpu
{
	private:
		string compCpu;
		int compCCount;
	public:
		
		Cpu();
		
		Cpu(string compCpu,int compCCount);
		
		~Cpu();
		
		void setCompCpu(string);
		
		string getCompCpu();
		
		void setCCount(int);
		
		int getCCount();
		
		void displayCpuInputs();
};
#endif