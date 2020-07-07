#ifndef GPU_H
#define GPU_H
#include<string.h>

using namespace std;

class Gpu 
{
	private:
		string compGpu;
		int compGCount;
	public:
		Gpu();
		
		Gpu(string compGpu,int compGCount);
		
		~Gpu();
		
		void setCompGpu(string);
		
		string getCompGpu();
		
		void setGCount(int);
		
		int getGCount();
		
		void displayGpuInputs();
};
#endif