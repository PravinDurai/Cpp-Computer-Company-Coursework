#ifndef FILEOPERATIONS_H
#define FILEOPERATIONS_H
#include<sstream>
#include<fstream>
#include<string.h>
#include<stdlib.h>
#include "LinkedList.h"

using namespace std;

class FileOperations
{
	private:
	   string inputFile="InputFile.cfg";
	   int fRead=0;
	public:
	
	//File Operations
	LinkedList* fileToList();
	void listToFile(LinkedList*);
	void getInputs(string sysType);
	void clearMemory(LinkedList*);
	//int getfRead();
	
	
	//List Operations
	void reConfigCpu(LinkedList*,string);
	void reConfigCCount(LinkedList*,int);
	void reConfigGpu(LinkedList*,string);
	void reConfigGCount(LinkedList*,int);
	void reConfigMem(LinkedList*,int);
	void reConfigHType(LinkedList*,string);
	void reConfigHCapacity(LinkedList*,int);
	void reConfigSSize(LinkedList*,float);
	void reConfigOs(LinkedList*,string);
	
	int getMaxSysId(LinkedList*);
	LinkedList* createNewNode();
	LinkedList* addNewNode(LinkedList* node,LinkedList* dtpLL);
	void displayAllNodes(LinkedList* node,int sysType);
	void displayCDescription(LinkedList*,int,int);
	void getNodeDetails(LinkedList*,int,int);
	void deleteNode(LinkedList*,int,int);
	void updateNode(LinkedList*,int,int);
	
	int validateStringInput();
};

#endif