#include<iostream>
#include<string.h>
#include "FileOperations.h"

using namespace std;

	//int FileOperations::getfRead()
	//{
	//	return(fRead);
	//}
	

	void FileOperations::clearMemory(LinkedList* temp)
	{
		while(temp!=NULL)
		{
			//cout<<"\nMemory "<<temp<<" is getting deleted";
			temp=temp->next;
			delete(temp);
		}
	}
	int FileOperations::getMaxSysId(LinkedList* tempLList)
	{
		int maxId=0;
		int tempNum;
		LinkedList* temp=tempLList;
		while(temp!=NULL)
		{
			if(temp->dtpPtr!=NULL)
			{
				tempNum=temp->dtpPtr->getCompId();
			}
			else
			{
				if(temp->lapPtr!=NULL)
				{
					tempNum=temp->lapPtr->getCompId();
				}
				else
				{
					if(temp->serPtr!=NULL)
					{
						tempNum=temp->serPtr->getCompId();
					}
					else
					{
						cout<<"\nError Class :\tFile Operations\tMethod :\tgetMaxSysId\nPlease check your cofig file\nSome how your input is not matching the criteria";
					}
				}
			}
			
			if(maxId<tempNum)
			{
				maxId=tempNum+maxId;
				tempNum=maxId-tempNum;
				maxId=maxId-tempNum;
			}
			temp=temp->next;
		}
		
		return(maxId);
	}
	
	void FileOperations::listToFile(LinkedList* lList)
	{
		ofstream oFile;
		try
		{
			oFile.open(inputFile);
			if(lList!=NULL)
			{
				while(lList!=NULL)
				{
					if(lList->dtpPtr!=NULL)
					{
						oFile<<"Desktop"<<" ";
						oFile<<lList->dtpPtr->getCompId()<<" ";
						oFile<<lList->dtpPtr->getCompPtr()->getCPtr()->getCompCpu()<<" ";
						oFile<<lList->dtpPtr->getCompPtr()->getCPtr()->getCCount()<<" ";
						oFile<<lList->dtpPtr->getCompPtr()->getGPtr()->getCompGpu()<<" ";
						oFile<<lList->dtpPtr->getCompPtr()->getGPtr()->getGCount()<<" ";
						oFile<<lList->dtpPtr->getCompPtr()->getMPtr()->getCompMem()<<" ";
						oFile<<lList->dtpPtr->getCompPtr()->getMPtr()->getCompHType()<<" ";
						oFile<<lList->dtpPtr->getCompPtr()->getMPtr()->getCompHCapacity()<<" ";
						oFile<<lList->dtpPtr->getCompOs();
						oFile<<"\n";
					}
					else
					{
						if(lList->lapPtr!=NULL)
						{
							oFile<<"Laptop"<<" ";
							oFile<<lList->lapPtr->getMake()<<" ";
							oFile<<lList->lapPtr->getCompId()<<" ";
							oFile<<lList->lapPtr->getCompPtr()->getCPtr()->getCompCpu()<<" ";
							oFile<<lList->lapPtr->getCompPtr()->getCPtr()->getCCount()<<" ";
							oFile<<lList->lapPtr->getCompPtr()->getGPtr()->getCompGpu()<<" ";
							oFile<<lList->lapPtr->getCompPtr()->getGPtr()->getGCount()<<" ";
							oFile<<lList->lapPtr->getCompPtr()->getMPtr()->getCompMem()<<" ";
							oFile<<lList->lapPtr->getCompPtr()->getMPtr()->getCompHType()<<" ";
							oFile<<lList->lapPtr->getCompPtr()->getMPtr()->getCompHCapacity()<<" ";
							oFile<<lList->lapPtr->getCompOs()<<" ";
							oFile<<lList->lapPtr->getSSize();
							oFile<<"\n";
						}
						else
						{
							if(lList->serPtr!=NULL)
							{
								oFile<<"Server"<<" ";
								oFile<<lList->serPtr->getCompId()<<" ";
								oFile<<lList->serPtr->getCompPtr()->getCPtr()->getCompCpu()<<" ";
								oFile<<lList->serPtr->getCompPtr()->getCPtr()->getCCount()<<" ";
								oFile<<lList->serPtr->getCompPtr()->getGPtr()->getCompGpu()<<" ";
								oFile<<lList->serPtr->getCompPtr()->getGPtr()->getGCount()<<" ";
								oFile<<lList->serPtr->getCompPtr()->getMPtr()->getCompMem()<<" ";
								oFile<<lList->serPtr->getCompPtr()->getMPtr()->getCompHType()<<" ";
								oFile<<lList->serPtr->getCompPtr()->getMPtr()->getCompHCapacity()<<" ";
								oFile<<lList->serPtr->getCompOs();
								oFile<<"\n";
							}
							else
							{
								throw("\nError class :\tFile Operations\tMethod :\tlistToFile");
							}
						}
					}
					lList=lList->next;
				}
			}
			else
			{
				system("CLS");
				cout<<"\nYou don't have any contents to store in your data base";
			}
			cout<<"\nSuccessfuly saved!!!";
			oFile.close();
		}
		catch(const char* msg)
		{
			cout<<"\nCaught in Exception inide class :\tFileOperations\tMethod :\tlistToFile\nAnd the Exception is :\t"<<msg;
		}
		
	}

	LinkedList* FileOperations::fileToList()
	{
		LinkedList* newLList=NULL;
		cout<<"\nLoading Historic Data...";
		
		//fRead=1;
		
		//----------------------------------------------------------------------------------------------
		
		ifstream iFile;
		try
		{
			iFile.open(inputFile);
			string line;
			if(!iFile)
			{
				throw("No Such File Found in the Directory");
			}
			else
			{
				string comp;
				int id;
				
				string make;
				string cpuName;
				int cpuValue;
				string gpuName;
				int gpuValue;
				int memSize;
				string memHType;
				int memHCapacity;
				string osType;
				float screenSize;
				
				//while(iFile.seekg( n ))
				while(getline(iFile,line))
				{
					LinkedList* tempList=createNewNode();
					istringstream iss(line);
					iss >> comp;
					cout<<"\nComp :\t"<<comp;
					if(comp=="Desktop")
					{
						iss >> id >>  cpuName >> cpuValue >> gpuName >> gpuValue >>  memSize >> memHType >> memHCapacity >>osType;
						
						Desktop* dtpPtr=new Desktop();
						dtpPtr->setCompId(id);
						dtpPtr->getCompPtr()->setCpuInputs(cpuName,cpuValue);
						dtpPtr->getCompPtr()->setGpuInputs(gpuName,gpuValue);
						dtpPtr->getCompPtr()->setMemoryInputs(memSize,memHType,memHCapacity);
						dtpPtr->setCompOs(osType);
						tempList->setDPtr(dtpPtr);
					}
					else
					{
						if(comp=="Laptop")
						{
							iss >> make >> id >>  cpuName >> cpuValue >> gpuName >> gpuValue >>  memSize >> memHType >> memHCapacity >>osType>>screenSize;
							
							//cout<<"\nMake :\t"<<make;
							//cout<<"\nId :\t"<<id;
							//cout<<"\nCPU :\t"<<cpuName;
							//cout<<"\nCPU Value :\t"<<cpuValue;
							//cout<<"\nGPU :\t"<<cpuName;
							//cout<<"\nGPU Value :\t"<<gpuValue;
							//cout<<"\nMemory :\t"<<memSize;
							//cout<<"\nMemory HType :\t"<<memHType;
							//cout<<"\nMemory HCapacity :\t"<<memHCapacity;
							//cout<<"\nOS :\t"<<osType;
							//cout<<"\nScreen Size :\t"<<screenSize;
							
							Laptop* lapPtr=new Laptop();
							lapPtr->setMake(make);
							lapPtr->setCompId(id);
							lapPtr->getCompPtr()->setCpuInputs(cpuName,cpuValue);
							lapPtr->getCompPtr()->setGpuInputs(gpuName,gpuValue);
							lapPtr->getCompPtr()->setMemoryInputs(memSize,memHType,memHCapacity);
							lapPtr->setCompOs(osType);
							lapPtr->setSSize(screenSize);
							
							tempList->setLPtr(lapPtr);
							
						}
						else
						{
							if(comp=="Server")
							{
								iss >> id >>  cpuName >> cpuValue >> gpuName >> gpuValue >>  memSize >> memHType >> memHCapacity>> osType;
								
								Server* serPtr=new Server();
								serPtr->setCompId(id);
								serPtr->getCompPtr()->setCpuInputs(cpuName,cpuValue);
								serPtr->getCompPtr()->setGpuInputs(gpuName,gpuValue);
								serPtr->getCompPtr()->setMemoryInputs(memSize,memHType,memHCapacity);
								serPtr->setCompOs(osType);
								
								tempList->setSPtr(serPtr);
								
							}
						}
					}
					//cout<<"\nNewNode Address :\t"<<tempList;
					newLList=addNewNode(newLList,tempList);
					
				}
			}	
		}
		catch(const char* msg)
		{
			cout<<"\nCaught in Exception inside \nClass :\t<FileOperations>\nMethod :\t<getInputs>\nException :\t<"<<msg<<">\n";
		}
		iFile.close();
		
		return(newLList);
	}
	
	
	
	//List Operation Methods
	
	
	LinkedList* FileOperations::createNewNode()
	{
		LinkedList* tList=new LinkedList();
		//cout<<"\nCreating new node List\nDesktop :\t"<<tList->dtpPtr<<"\nLaptop :\t"<<tList->lapPtr<<"\nServer :\t"<<tList->serPtr;
	}
	
	
	LinkedList* FileOperations::addNewNode(LinkedList* node,LinkedList* dtpLL)
	{
		cout<<"\nAdd New Node Method";
		if(node==NULL)
		{
			node=dtpLL;
		}
		else
		{
			LinkedList* temp=new LinkedList();
			temp=node;
			//LinkedList* newNode=createNewNode();
			//newNode->dtpPtr=dtpPtr;
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
			//temp->next=createNewNode();
			temp->next=dtpLL;
		}
		return(node);
	}
	
	void FileOperations::displayAllNodes(LinkedList* node,int sysType)
	{
		LinkedList* temp=node;
		switch(sysType)
		{
			case 1:
			{
				int notEmpty=0;
				while(temp!=NULL)
				{	
					
					//cout<<"\nTemp:\t"<<temp;
					//cout<<"\nTempPointer :\t"<<temp->dtpPtr;
					if(temp->dtpPtr!=NULL)
					{
						temp->dtpPtr->displayDesktopInputs();
						notEmpty++;
					}
					do
					{
						temp=temp->next;
					}while((temp!=NULL)&&(temp->dtpPtr==NULL));
					
					cout<<flush;
				}
				if(notEmpty==0)
				{
					cout<<"\nSorry there is no Data avaliable for Desktop...\n";
				}
				else
				{
					cout<<"\n\n\n The Total available Desktop is :\t"<<notEmpty<<"\n";
				}
				
			}
			break;
			case 2:
			{
				int notEmpty=0;
				while(temp!=NULL)
				{	
					
					//cout<<"\nTemp:\t"<<temp;
					//cout<<"\nTempPointer :\t"<<temp->lapPtr;
					if(temp->lapPtr!=NULL)
					{
						notEmpty++;
						temp->lapPtr->displayLaptopInputs();
					}
					do
					{
						temp=temp->next;
					}while((temp!=NULL)&&(temp->lapPtr==NULL));
					
					cout<<flush;
				}
				if(notEmpty==0)
				{
					cout<<"\nSorry there is no Data avaliable for Laptop...\n";
				}
				else
				{
					cout<<"\n\n\n The Total available Laptop is :\t"<<notEmpty<<"\n";
				}
			}
			break;
			case 3:
			{
				int notEmpty=0;
				while(temp!=NULL)
				{	
					
					//cout<<"\nTemp:\t"<<temp;
					//cout<<"\nTempPointer :\t"<<temp->lapPtr;
					if(temp->serPtr!=NULL)
					{
						notEmpty++;
						temp->serPtr->displayServerInputs();
					}
					do
					{
						temp=temp->next;
					}while((temp!=NULL)&&(temp->serPtr==NULL));
					
					cout<<flush;
				}
				if(notEmpty==0)
				{
					cout<<"\nSorry there is no Data avaliable for Server...\n";
				}
				else
				{
					cout<<"\n\n\n The Total available Server is :\t"<<notEmpty<<"\n";
				}
			}
			break;
		}
	}
	
	
	void FileOperations::displayCDescription(LinkedList* node,int id,int sType)
	{
		int found=0;
		LinkedList* temp=node;
		switch(sType)
		{
			case 1:
			{
				while((temp!=NULL))
				{
					if(temp->dtpPtr!=NULL)
					{
						if(temp->dtpPtr->getCompId()==id)
						{
							found=1;
							break;
						}
					}
					temp=temp->next;
				}
				if(found)
					temp->dtpPtr->desktopCostDescription();
				else
					cout<<"\nInvalid ID\nPlease check the give Id....";
			}
			    break;
			case 2:
			
			//---------------------------------------------
			
			{
				
				while((temp!=NULL))
				{	
					
					//cout<<"\nDesktop Pointer :\t"<<temp->dtpPtr;
					//cout<<"\nServer Pointer :\t"<<temp->serPtr;
					if(temp->lapPtr!=NULL)
					{
						//temp->lapPtr->displayLaptopInputs();
						if(temp->lapPtr->getCompId()==id)
						{
							found=1;
							break;
						}
					}
					do
					{
						temp=temp->next;
					}while((temp!=NULL)&&(temp->lapPtr==NULL));
					cout<<flush;
				}
				if(found)
					temp->lapPtr->laptopCostDescription();
				else
					cout<<"\nInvalid ID\nPlease check the give Id....";				
			}
			
			//-------------------------------------
			
			
			    break;
			case 3:
			{
				while(temp!=NULL)
				{
					if(temp->serPtr!=NULL)
					{
						if(temp->serPtr->getCompId()==id)
						{
							found=1;
							break;
						}
					}
					temp=temp->next;
				}
				if(found)
					temp->serPtr->serverCostDescription();
				else
					cout<<"\nInvalid ID\nPlease check the give Id....";
				
			}
			    break;
		}
	}

	void FileOperations::getNodeDetails(LinkedList* node,int id,int sType)
	{
		int found=0;
		LinkedList* temp=node;
		switch(sType)
		{
			case 1:
			{
				while(temp!=NULL)
				{
					if(temp->dtpPtr!=NULL)
					{
						if(temp->dtpPtr->getCompId()==id)
						{
							found=1;
							
							break;
						}
						
					}
					temp=temp->next;
				}
				if(found)
					temp->dtpPtr->displayDesktopInputs();
				else
					cout<<"\nInvalid ID\nPlease check the give Id....";
			}
			    break;
			case 2:
			{
				while(temp!=NULL)
				{
					if(temp->lapPtr!=NULL)
					{
						if(temp->lapPtr->getCompId()==id)
						{
							found=1;
							break;
						}
					}	
					temp=temp->next;
				}
				if(found)
					temp->lapPtr->displayLaptopInputs();
				else
					cout<<"\nInvalid ID\nPlease check the give Id....";
			}
			    break;
			case 3:
			{
				while(temp!=NULL)
				{
					if(temp->serPtr!=NULL)
					{
						if(temp->serPtr->getCompId()==id)
						{
							found=1;
							break;
						}
					}
					temp=temp->next;
				}
				if(found)
					temp->serPtr->displayServerInputs();
				else
					cout<<"\nInvalid ID\nPlease check the give Id....";
				
			}
			    break;
		}
	}
	
	void FileOperations::deleteNode(LinkedList* node,int id,int sType)
	{
		int found=0;
		LinkedList* temp=node;
		switch(sType)
		{
			case 1:
			{
				while(temp->next!=NULL)
				{
					if(temp->next->dtpPtr!=NULL)
					{
						if(temp->next->dtpPtr->getCompId()==id)
						{
							found=1;
							break;
						}
					}
					temp=temp->next;
				}
				if(found)
				{
					LinkedList* tempNode=temp->next;
					temp->next=temp->next->next;
					delete(tempNode);
					cout<<"\n Computer Deleted Successfully!!!";
				}
				else
					cout<<"\nInvalid ID\nPlease check the give Id....";
			}
			    break;
			case 2:
			{
				
				while(temp->next!=NULL)
				{
					if(temp->next->lapPtr!=NULL)
					{
						if(temp->next->lapPtr->getCompId()==id)
						{
							found=1;
							break;
						}
					}
					temp=temp->next;
				}
				
				if(found)
				{
					LinkedList* tempNode=temp->next;
					temp->next=temp->next->next;
					delete(tempNode);
					cout<<"\n Computer Deleted Successfully!!!";
				}
				else
					cout<<"\nInvalid ID\nPlease check the give Id....";				
			}
			    break;
			case 3:
			{
				while(temp->next!=NULL)
				{
					if(temp->next->serPtr!=NULL)
					{
						if(temp->next->serPtr->getCompId()==id)
						{
							found=1;
							break;
						}
					}
					temp=temp->next;
				}
				if(found)
				{
					LinkedList* tempNode=temp->next;
					temp->next=temp->next->next;
					delete(tempNode);
					cout<<"\n Computer Deleted Successfully!!!";
				}
				else
					cout<<"\nInvalid ID\nPlease check the give Id....";
			}
			    break;
		}
	}
	
	
	void FileOperations::updateNode(LinkedList* node,int id,int sType)
	{
		int found=0;
		char choice;
		string stringContent;
		int intContent=0;
		float floatContent;
		LinkedList* temp=node;
		do
		{
			
			switch(sType)
			{
				case 1:
				{
					while((temp!=NULL))
					{	
					
						//cout<<"\nDesktop Pointer :\t"<<temp->dtpPtr;
						//cout<<"\nServer Pointer :\t"<<temp->serPtr;
						if(temp->dtpPtr!=NULL)
						{
							//temp->lapPtr->displayLaptopInputs();
							if(temp->dtpPtr->getCompId()==id)
							{
								found=1;
								break;
							}
						}
						do
						{
							temp=temp->next;
						}while((temp!=NULL)&&(temp->dtpPtr==NULL));
						cout<<flush;
					}
					if(found)
					{
						cout<<flush;
						int opt=0;
						system("CLS");
						cout<<"\n*****************************************************************************\n";
						cout<<"\n        Please select the specification that has to be Re-configured\n";
						cout<<"\n*****************************************************************************\n";
						cout<<"\n1.\tCPU \t";
						cout<<"\n2.\tCPU Count\t";
						cout<<"\n3.\tGPU \t";
						cout<<"\n4.\tGPU Count\t";
						cout<<"\n5.\tMemory \t";
						cout<<"\n6.\tHard Disk Type";
						cout<<"\n7.\tHard Disk Capacity";
						cout<<"\n8.\tOS";
						cout<<"\nSelect any one of the above option <Hint : Int> :\t"<<opt;
						while(opt==0)
						{
							opt=validateStringInput();
						}
						switch(opt)
						{
							case 1:
							{
								cout<<"\nPlease provide the new Cpu <Hint : String> :\t";
								//cin.ignore();
								getline(cin,stringContent);
								reConfigCpu(temp,stringContent);
							}
							
							  break;
							case 2:
							{
								cout<<"\nPlease provide the new Cpu Count :\t";
								while(intContent==0)
								{
									intContent=temp->dtpPtr->getResCpu();
								}
								reConfigCCount(temp,intContent);
							}
							  break;
							case 3:
							{
								cout<<"\nPlease provide the new Gpu :\t";
								//cin.ignore();
								getline(cin,stringContent);
								reConfigGpu(temp,stringContent);								
							}
							  break;
							case 4:
							{
								cout<<"\nPlease provide the new GPU Count :\t";
								intContent=temp->dtpPtr->getResGpu();
								reConfigGCount(temp,intContent);
							}
							  break;
							case 5:
							{
								cout<<"\nPlease provide the new Memory :\t";
								intContent=temp->dtpPtr->getCompPtr()->validateStringInput();
								reConfigMem(temp,intContent);	
							}
							  break;
							  
							case 6:
							{
								cout<<"\nPlease provide the new Hard Disk Type :\t";
								stringContent=temp->dtpPtr->getResHType();
								reConfigHType(temp,stringContent);	
							}
							  break;
							  
							case 7:
							{
								cout<<"\nPlease provide the new Hard Disk Capacity :\t";
								intContent=temp->dtpPtr->getCompPtr()->validateStringInput();
								reConfigHCapacity(temp,intContent);	
							}
							  break;
							  
							case 8:
							{
								cout<<"\nPlease provide the new OS :\t";
								stringContent=temp->dtpPtr->getResOs();
								reConfigOs(temp,stringContent);
							}
							  break;
							
						}
						if(opt>0&&opt<9)
						{
							cout<<"\nSuccessfully Updated";
						}
						else
						{
							cout<<"\nInvalid Input";
						}
					}
					else
					{
						cout<<"\nInvalid ID\nPlease check the give Id....";
						break;
					}
				}
					break;
				case 2:
				
				{
					while((temp!=NULL))
					{	
					
						//cout<<"\nDesktop Pointer :\t"<<temp->dtpPtr;
						//cout<<"\nServer Pointer :\t"<<temp->serPtr;
						if(temp->lapPtr!=NULL)
						{
							//temp->lapPtr->displayLaptopInputs();
							if(temp->lapPtr->getCompId()==id)
							{
								found=1;
								break;
							}
						}
						do
						{
							temp=temp->next;
						}while((temp!=NULL)&&(temp->lapPtr==NULL));
						cout<<flush;
					}
					if(found)
					{
						int opt=0;
						system("CLS");
						cout<<"\n*****************************************************************************\n";
						cout<<"\n        Please select the specification that has to be Re-configured\n";
						cout<<"\n*****************************************************************************\n";
						cout<<"\n1.\tCPU \t";
						cout<<"\n2.\tGPU \t";
						cout<<"\n3.\tMemory \t";
						cout<<"\n4.\tHard Disk Type";
						cout<<"\n5.\tHard Disk Capacity";
						cout<<"\n6.\tScreen Size";
						cout<<"\n7.\tOS";
						
						cout<<"\nSelect your option <Hint : Int> :\t";
						while(opt==0)
						{
							opt=validateStringInput();
						}
						switch(opt)
						{
							case 1:
							{
								cout<<"\nPlease provide the new Cpu <Hint : String> :\t";
								cin.ignore();
								getline(cin,stringContent);
								reConfigCpu(temp,stringContent);
							}
							  break;
							case 2:
							{
								cout<<"\nPlease provide the new Gpu :\t";
								cin.ignore();
								getline(cin,stringContent);//temp->lapPtr->getCompPtr->validateStringInput();
								reConfigGpu(temp,stringContent);
							}
							  break;
							case 3:
							{
								cout<<"\nPlease provide the new Memory :\t";
								intContent=temp->lapPtr->getCompPtr()->validateStringInput();;
								reConfigMem(temp,intContent);
							}
							  break;
							case 4:
							{
								cout<<"\nPlease provide the new Hard Disk Type :\t";
								stringContent=temp->dtpPtr->getResHType();
								reConfigHType(temp,stringContent);
							}
							  break;
							case 5:
							{
								cout<<"\nPlease provide the new Hard Disk Capacity :\t";
								intContent=temp->lapPtr->getCompPtr()->validateStringInput();;
								reConfigHCapacity(temp,intContent);
							}
							  break;

							case 6:
							{
								cout<<"\nPlease provide new Screen Size :\t";
								floatContent=temp->lapPtr->getResSSize();
								reConfigSSize(temp,floatContent);
							}
							  break;
							  
							case 7:
							{
								cout<<"\nPlease provide the new OS :\t";
								stringContent=temp->dtpPtr->getResOs();
								reConfigOs(temp,stringContent);
							}
							  break;
						}
						
						if(opt>0&&opt<9)
						{
							cout<<"\nSuccessfully Updated";
						}
						else
						{
							cout<<"\nInvalid Input";
						}
					}
					else
					{
						cout<<"\nInvalid ID\nPlease check the give Id....";
						break;
					}
				}
					break;
				
				case 3:
				{
					while((temp!=NULL))
					{	
					
						//cout<<"\nDesktop Pointer :\t"<<temp->dtpPtr;
						//cout<<"\nServer Pointer :\t"<<temp->serPtr;
						if(temp->serPtr!=NULL)
						{
							//temp->lapPtr->displayLaptopInputs();
							if(temp->serPtr->getCompId()==id)
							{
								found=1;
								break;
							}
						}
						do
						{
							temp=temp->next;
						}while((temp!=NULL)&&(temp->serPtr==NULL));
						cout<<flush;
					}
					if(found)
					{
						int opt=0;
						system("CLS");
						cout<<"\n*****************************************************************************\n";
						cout<<"\n        Please select the specification that has to be Re-configured\n";
						cout<<"\n*****************************************************************************\n";
						cout<<"\n1.\tCPU \t";
						cout<<"\n2.\tCPU Count \t";
						cout<<"\n3.\tGPU \t";
						cout<<"\n4.\tGPU Count \t";
						cout<<"\n5.\tMemory \t";
						cout<<"\n6.\tHard Disk Type";
						cout<<"\n7.\tHard Disk Capacity";
						cout<<"\n8.\tOS";
						
						cout<<"\nSelect your option <Hint : String> :\t";
						while(opt==0)
						{
							opt=validateStringInput();
						}
						switch(opt)
						{
							case 1:
							{
								cout<<"\nPlease provide the new Cpu <Hint : String> :\t";
								cin.ignore();
								getline(cin,stringContent);
								reConfigCpu(temp,stringContent);
							}
							  break;
							case 2:
							{
								cout<<"\nPlease provide the new Cpu Count <Hint : Int> :\t";
								intContent=temp->serPtr->getResCpu();
								reConfigCCount(temp,intContent);
							}
							  break;
							case 3:
							{
								cout<<"\nPlease provide the new Gpu <Hint : String> :\t";
								cin.ignore();
								getline(cin,stringContent);
								reConfigGpu(temp,stringContent);
							}
							  break;
							case 4:
							{
								cout<<"\nPlease provide the new GPU Count <Hint : Int> :\t";
								intContent=temp->serPtr->getResGpu();
								reConfigGCount(temp,intContent);
							}
							  break;
							case 5:
							{
								cout<<"\nPlease provide the new Memory <Hint : Int> :\t";
								intContent=temp->serPtr->getCompPtr()->validateStringInput();
								reConfigMem(temp,intContent);
							}
							  break;
							  
							case 6:
							{
								cout<<"\nPlease provide the new Hard Disk Type <Hint : String> :\t";
								stringContent=temp->serPtr->getResHType();
								reConfigHType(temp,stringContent);
							}
							  break;
							case 7:
							{
								cout<<"\nPlease provide the new Hard Disk Capacity <Hint : Int> :\t";
								intContent=temp->serPtr->getCompPtr()->validateStringInput();
								reConfigHCapacity(temp,intContent);
							}
							  break;  
							case 8:
							{
								cout<<"\nPlease provide the new OS :\t";
								stringContent=temp->serPtr->getResOs();
								reConfigOs(temp,stringContent);
							}
							  break;
						}
						if(opt>0&&opt<9)
						{
							cout<<"\nSuccessfully Updated";
						}
						else
						{
							cout<<"\nInvalid Input";
						}
					}
					else
					{
						cout<<"\nInvalid ID\nPlease check the give Id....";
						break;
					}
				}
					break;
					
			}
			if(found)
			{
				do
				{
					cout<<"\n< Update Menu Do you wish to change any config > [ 'Y' / 'N' ] :\t";
					cin>>choice;
				}while((choice!='Y')&&(choice!='y')&&(choice!='N')&&(choice!='n'));
			}
			else
			{
				//cout<<"\nSorry!!!\nInvalid System Serial Number...\n";
				break;
			}
		}while(choice=='Y' || choice =='y');
	
	}
	
	
	
	
	
	void FileOperations::reConfigCpu(LinkedList* tempList,string newCpu)
	{
		if(tempList->dtpPtr!=NULL)
		{
			tempList->dtpPtr->getCompPtr()->setCpuInputs(newCpu,tempList->dtpPtr->getCompPtr()->getCPtr()->getCCount());
		}
		else
		{
			if(tempList->lapPtr!=NULL)
			{
				tempList->lapPtr->getCompPtr()->setCpuInputs(newCpu,tempList->lapPtr->getCompPtr()->getCPtr()->getCCount());
			}
			else
			{
				tempList->serPtr->getCompPtr()->setCpuInputs(newCpu,tempList->serPtr->getCompPtr()->getCPtr()->getCCount());
			}
		}
	}
	
	void FileOperations::reConfigCCount(LinkedList* tempList,int newCCount)
	{
		if(tempList->dtpPtr!=NULL)
		{
			tempList->dtpPtr->getCompPtr()->setCpuInputs(tempList->dtpPtr->getCompPtr()->getCPtr()->getCompCpu(),newCCount);
		}
		else
		{
			if(tempList->lapPtr!=NULL)
			{
				tempList->lapPtr->getCompPtr()->setCpuInputs(tempList->lapPtr->getCompPtr()->getCPtr()->getCompCpu(),newCCount);
			}
			else
			{
				tempList->serPtr->getCompPtr()->setCpuInputs(tempList->serPtr->getCompPtr()->getCPtr()->getCompCpu(),newCCount);
			}
		}
	}
	
	void FileOperations::reConfigGpu(LinkedList* tempList,string newGpu)
	{
		if(tempList->dtpPtr!=NULL)
		{
			tempList->dtpPtr->getCompPtr()->setGpuInputs(newGpu,tempList->dtpPtr->getCompPtr()->getGPtr()->getGCount());
		}
		else
		{
			if(tempList->lapPtr!=NULL)
			{
				tempList->lapPtr->getCompPtr()->setGpuInputs(newGpu,tempList->lapPtr->getCompPtr()->getGPtr()->getGCount());
			}
			else
			{
				tempList->serPtr->getCompPtr()->setGpuInputs(newGpu,tempList->serPtr->getCompPtr()->getGPtr()->getGCount());
			}
		}
	}
	
	void FileOperations::reConfigGCount(LinkedList* tempList,int newGCount)
	{
		if(tempList->dtpPtr!=NULL)
		{
			tempList->dtpPtr->getCompPtr()->setGpuInputs(tempList->dtpPtr->getCompPtr()->getGPtr()->getCompGpu(),newGCount);
		}
		else
		{
			if(tempList->lapPtr!=NULL)
			{
				tempList->lapPtr->getCompPtr()->setGpuInputs(tempList->lapPtr->getCompPtr()->getGPtr()->getCompGpu(),newGCount);
			}
			else
			{
				tempList->serPtr->getCompPtr()->setGpuInputs(tempList->serPtr->getCompPtr()->getGPtr()->getCompGpu(),newGCount);
			}
		}
	}
	
	void FileOperations::reConfigMem(LinkedList* tempList,int newMem)
	{
		if(tempList->dtpPtr!=NULL)
		{
			tempList->dtpPtr->getCompPtr()->setMemoryInputs(newMem,tempList->dtpPtr->getCompPtr()->getMPtr()->getCompHType(),tempList->dtpPtr->getCompPtr()->getMPtr()->getCompHCapacity());
		}
		else
		{
			if(tempList->lapPtr!=NULL)
			{
				tempList->lapPtr->getCompPtr()->setMemoryInputs(newMem,tempList->lapPtr->getCompPtr()->getMPtr()->getCompHType(),tempList->lapPtr->getCompPtr()->getMPtr()->getCompHCapacity());
			}
			else
			{
				tempList->serPtr->getCompPtr()->setMemoryInputs(newMem,tempList->serPtr->getCompPtr()->getMPtr()->getCompHType(),tempList->serPtr->getCompPtr()->getMPtr()->getCompHCapacity());
			}
		}
	}
	
	void FileOperations::reConfigHType(LinkedList* tempList,string newHType)
	{
		if(tempList->dtpPtr!=NULL)
		{
			tempList->dtpPtr->getCompPtr()->setMemoryInputs(tempList->dtpPtr->getCompPtr()->getMPtr()->getCompMem(),newHType,tempList->dtpPtr->getCompPtr()->getMPtr()->getCompHCapacity());
		}
		else
		{
			if(tempList->lapPtr!=NULL)
			{
				tempList->lapPtr->getCompPtr()->setMemoryInputs(tempList->lapPtr->getCompPtr()->getMPtr()->getCompMem(),newHType,tempList->lapPtr->getCompPtr()->getMPtr()->getCompHCapacity());
			}
			else
			{
				tempList->serPtr->getCompPtr()->setMemoryInputs(tempList->serPtr->getCompPtr()->getMPtr()->getCompMem(),newHType,tempList->serPtr->getCompPtr()->getMPtr()->getCompHCapacity());
			}
		}
	}
	
	void FileOperations::reConfigHCapacity(LinkedList* tempList,int newHCapacity)
	{
		if(tempList->dtpPtr!=NULL)
		{
			tempList->dtpPtr->getCompPtr()->setMemoryInputs(tempList->dtpPtr->getCompPtr()->getMPtr()->getCompMem(),tempList->dtpPtr->getCompPtr()->getMPtr()->getCompHType(),newHCapacity);
		}
		else
		{
			if(tempList->lapPtr!=NULL)
			{
				tempList->lapPtr->getCompPtr()->setMemoryInputs(tempList->lapPtr->getCompPtr()->getMPtr()->getCompMem(),tempList->lapPtr->getCompPtr()->getMPtr()->getCompHType(),newHCapacity);
			}
			else
			{
				tempList->serPtr->getCompPtr()->setMemoryInputs(tempList->serPtr->getCompPtr()->getMPtr()->getCompMem(),tempList->serPtr->getCompPtr()->getMPtr()->getCompHType(),newHCapacity);
			}
		}
	}
	
	void FileOperations::reConfigOs(LinkedList* tempList,string newOs)
	{
		if(tempList->dtpPtr!=NULL)
		{
			tempList->dtpPtr->setCompOs(newOs);
		}
		else
		{
			if(tempList->lapPtr!=NULL)
			{
				tempList->lapPtr->setCompOs(newOs);
			}
			else
			{
				tempList->serPtr->setCompOs(newOs);
			}
		}
	}
	
	void FileOperations::reConfigSSize(LinkedList* tempList,float newSSize)
	{
		if(tempList->lapPtr!=NULL)
		{
			tempList->lapPtr->setSSize(newSSize);
		}
		else
		{
			cout<<"\nClass :\tFileOperations\tMethgod :\treConfigSize\t\tSorry You can reconfigure the screen size only for the Laptops";
		}	
	}
	
	int FileOperations::validateStringInput()
	{
		int number=0;
		string sNumber="";
		try
		{
			//cout<<"\nEnter your Input <Hint : Int> :\t";
			getline(cin,sNumber);
			number=stoi(sNumber);
				
		}
		catch(invalid_argument &m)
		{
			cout<<"\nPlease enter a valid data <Only Number> [Spaces and special characters and strings not allowed]\n";
			//cout<<"\n Input is :\t"<<number;
		}
		//cout<<"\nNumber Returned is :\t"<<number;
		return(number);
	}
	
//string FileOperations :: inputFile ="InputFile.cfg";