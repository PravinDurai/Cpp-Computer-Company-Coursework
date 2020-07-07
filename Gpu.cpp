#include<iostream>
#include<string.h>
#include "Gpu.h"

Gpu::Gpu()
{
	
}

Gpu::Gpu(string compGpu,int compGCount)
{
	this->compGpu=compGpu;
	this->compGCount=compGCount;
}

Gpu::~Gpu()
{
	//cout<<"\n<Destructor call>\tGPU is Deleted Successfully\n";
}

void Gpu::setCompGpu(string compGpu)
{
	this->compGpu=compGpu;
}

string Gpu::getCompGpu()
{
	return(compGpu);
}

void Gpu::setGCount(int compGCount)
{
	this->compGCount=compGCount;
}

int Gpu::getGCount()
{
	return(compGCount);
}

void Gpu::displayGpuInputs()
{
	cout<<"\n4.\tGPU :\t"<<getCompGpu();
	cout<<"\n5.\tNumber of GPU :\t"<<getGCount();
}
