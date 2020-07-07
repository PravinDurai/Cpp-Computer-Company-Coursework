#include<stdio.h>
#include<iostream>
#include "MyUi.h"

using namespace std;
		MyUi::MyUi()
		{
		
		}
			
		MyUi::~MyUi()
		{
			//cout<<"\n<Destructor call>\tMyUi is Deleted Successfully\n";
		}
	
		void MyUi::formatDec(int opt)
		{
			switch(opt)
			{
				case 1:
					cout<<"\n************************************************************************\n";
					break;
				case 2:
					cout<<"\nInvalid Option\nPlease select an option from the above list";
					break;
				case 3:
			  
					break;
			}
		}
	
		void MyUi::createGUI1()
		{
			int opt;
			char choice='N';
			linkedList=fOperations->fileToList();
			//FileOperations* fOperations=new FileOperations();
			do
			{
				do
				{
					system("CLS");
				
					//read the content of the file ----------------------- has to be created in MyUI Class
					//readtheFileContents();
				
					formatDec(1);
					cout<<"\n                                  Catlog                    \n";
					formatDec(1);
				
					cout<<"\n1.\tDesktop";
					cout<<"\n2.\tLaptop";
					cout<<"\n3.\tServer";
					cout<<"\n4.\tExit";
					cout<<"\nWhat is your preference <Hint : Int> :\t";
					cout<<flush;
					opt=validateStringInput();
				
					if(opt>4||opt==0)
						cout<<"\nInvalid Input\nPlease select an option from the list";
					else
					{
						switch(opt)
						{
							case 1:
							case 2:
							case 3:
								createGUI2(opt);
								break;
						}
					}
				}while(opt>4||opt==0);
				cout<<flush;
				cout<<"\n< Main Menu Do you wish to continue > [ 'Y' / 'N' ] :\t";
				
				cin>>choice;
				
				if((choice!='Y')&&(choice!='y')&&(choice!='N')&&(choice!='n'))
				{
					do
					{
						cout<<flush;
						formatDec(2);
						cout<<" Do you wish to continue [ 'Y' / 'N' ] :\t";
						cin>>choice;
				
					}while((choice!='Y')&&(choice!='y')&&(choice!='N')&&(choice!='n'));
				}
			}while(choice=='Y' || choice =='y');
			//write the content of the root node to the file by opening the file in output mode
			//cout<<"\nPlease Wait Saving your updates";
			//if(fOperations->getfRead()==1)
			//{
			//	cout<<"\nfRead :\t"<<fOperations->getfRead();
				fOperations->listToFile(linkedList);
				fOperations->clearMemory(linkedList);
			//}
		}
	
	void MyUi::createGUI2(int model)
	{
		int opt=0;
		string compType;
		char choice;
		do
		{
			
			switch(model)
			{
				case 1:
					compType="Desktop";
					//dtp=new Desktop();
					break;
				case 2:
					compType="Laptop";
					//ltp=new Laptop();
					break;
				case 3:
					compType="Server";
					//ser=new Server();
					break;
			}
			switch(model)
			{
			
				case 1:
					do
					{
						opt=0;
						system("CLS");
						cout<<flush;
						formatDec(1);
						cout<<"                    Please Select An Option                          ";
						formatDec(1);
						cout<<"\n1.\tDisplay All "<<compType;
						cout<<"\n2.\tSearch a "<<compType<<" provided the ID";
						cout<<"\n3.\tAdd a "<<compType;
						cout<<"\n4.\tUpdate given an ID";
						cout<<"\n5.\tRemove "<<compType;
						cout<<"\n6.\tDisplay Spec "<<compType<<" and Cost ";
						cout<<"\n7.\tExit";
						
							cout<<"\nYour option is <Hint : Int> :\t";
							opt=validateStringInput();
							if(opt>7||opt==0)
							{
								formatDec(1);
								formatDec(2);
								cout<<" b/w [ 1 - 6 ] ";
							}
							else
							{
							
								Desktop* dtp=new Desktop();
								switch(opt)
								{
									//Display All Desktop
									case 1:
									{
										//Call the Linked List method to display all the contents of the Desktop List
										fOperations->displayAllNodes(linkedList,1);
									}
										break;
									//Search and diplay the content of Desktop based on ID
									case 2:
									{
										//Call the Linked List method to display to search for a Desktop wityh particular ID
										int id;
										cout<<"\nEnter the Compter Id to be searched <Hint : Int> :\t";
										id=validateStringInput();
										fOperations->getNodeDetails(linkedList,id,1);
									}
										break;
									//Add a new Desktop
									case 3:
									{
										//Validates and generate an unique id to desktop ---------- Method has to be created in MyUI Class
										int id=generateId(linkedList);
									
										//cout<<"\nClass :MyUi\tid :\t"<<id;
										//Get the Inputs ----------------------- Method has to be created in Desktop Class
										dtp->getAllInputs(id);
									
										//Adding the node to the LinkedList
										LinkedList* newLList=new LinkedList();
										newLList->setDPtr(dtp);
										linkedList=fOperations->addNewNode(linkedList,newLList);
									
									
										//Display all the inputs on the screen -------------- Method hast to be created in Desktop Class
										//dtp->displayDesktopInputs();
									}
									break;
									//Update the given Desktop based on Id
									case 4:
									{
										int id=0;
										cout<<"\nPlease enter the System ID which you wish to Re-Configure <hint : Int> :\t";
										while(id==0)
										{
											id=validateStringInput();
										}
										fOperations->updateNode(linkedList,id,1);
									}
										break;
									//Delete the given Desktop based on Id
									case 5:
									{
										int id=0;
										cout<<"\nEnter the Computer ID that has to be removed from the Database <Hint : Int> :\t";
										while(id==0)
										{
											id=validateStringInput();
										}
										fOperations->deleteNode(linkedList,id,1);
									}
										break;
									case 6:
									{
										int id=0;
										cout<<"\nEnter the Id for which the cost has to be fetched <Hint : Int> :\t";
										while(id==0)
										{
											id=validateStringInput();
										}
										fOperations->displayCDescription(linkedList,id,1);
									}
										break;
								}
							}
						}while(opt>7||opt==0);
					//}while(opt>7);
					break;
				case 2:
					do
					{
						cout<<flush;
						opt=0;
						system("CLS");
						cout<<flush;
						formatDec(1);
						cout<<"                    Please Select An Option                          ";
						formatDec(1);
						cout<<"\n1.\tDisplay All "<<compType;
						cout<<"\n2.\tSearch a "<<compType<<" provided the ID";
						cout<<"\n3.\tAdd a "<<compType;
						cout<<"\n4.\tUpdate given an ID";
						cout<<"\n5.\tRemove "<<compType;
						cout<<"\n6.\tDisplay Spec "<<compType<<" and Cost ";
						cout<<"\n7.\tExit";
						//do
						//{
							cout<<"\nYour option is <Hint : Int> :\t";
							opt=validateStringInput();
							if(opt>7||opt==0)
							{
								formatDec(1);
								formatDec(2);
								cout<<" b/w [ 1 - 6 ] ";
							}
							else
							{
							
								Laptop* ltp=new Laptop();
								switch(opt)
								{
									//Display All Desktop
									case 1:
									{
										//Call the Linked List method to display all the contents of the Desktop List
										fOperations->displayAllNodes(linkedList,2);
									}
										break;
									//Search and diplay the content of Desktop based on ID
									case 2:
									{
										//Call the Linked List method to display to search for a Desktop wityh particular ID
										int id;
										cout<<"\nEnter the Compter Id to be searched <Hint : Int> :\t";
										id=validateStringInput();
										fOperations->getNodeDetails(linkedList,id,2);
									}
										break;
									//Add a new Desktop
									case 3:
									{
										//Validates and generate an unique id to desktop ---------- Method has to be created in MyUI Class
										int id=generateId(linkedList);
									
										//cout<<"\nClass :MyUi\tid :\t"<<id;
										//Get the Inputs ----------------------- Method has to be created in Desktop Class
										ltp->getAllInputs(id);
									
										//Adding the node to the LinkedList
										LinkedList* newLList=new LinkedList();
										newLList->setLPtr(ltp);
										linkedList=fOperations->addNewNode(linkedList,newLList);
									
									
										//Display all the inputs on the screen -------------- Method hast to be created in Desktop Class
										//dtp->displayDesktopInputs();
									}
									break;
									//Update the given Desktop based on Id
									case 4:
									{
										int id=0;
										cout<<"\nPlease enter the System ID which you wish to Re-Configure <Hint : Int> :\t";
										while(id==0)
										{
											id=validateStringInput();
										}
										fOperations->updateNode(linkedList,id,2);
									}
										break;
									//Delete the given Desktop based on Id
									case 5:
									{
										int id=0;
										cout<<"\nEnter the Computer ID that has to be removed from the Database <Hint : Int> :\t";
										while(id==0)
										{
											id=validateStringInput();
										}
										fOperations->deleteNode(linkedList,id,2);
									}
										break;
									case 6:
									{
										int id=0;
										cout<<"\nEnter the Id for which the cost has to be fetched <Hint : Int> :\t";
										while(id==0)
										{
											id=validateStringInput();
										}
										fOperations->displayCDescription(linkedList,id,2);
									}
										break;
								}
							}
						}while(opt>7||opt==0);
					//}while(opt>7);
					break;
				
				case 3:
					do
					{
						system("CLS");
						cout<<flush;
						formatDec(1);
						cout<<"                    Please Select An Option                          ";
						formatDec(1);
						cout<<"\n1.\tDisplay All "<<compType;
						cout<<"\n2.\tSearch a "<<compType<<" provided the ID";
						cout<<"\n3.\tAdd a "<<compType;
						cout<<"\n4.\tUpdate given an ID";
						cout<<"\n5.\tRemove "<<compType;
						cout<<"\n6.\tDisplay Spec and Cost "<<compType;
						cout<<"\n7.\tExit";
						//do
						//{
							cout<<"\nYour option is <hint : Int> :\t";
							while(opt==0)
								opt=validateStringInput();
							if(opt>7||opt==0)
							{
								formatDec(1);
								formatDec(2);
								cout<<" b/w [ 1 - 6 ] ";
							}
							else
							{
								Server* ltp=new Server();
								switch(opt)
								{
									//Display All Desktop
									case 1:
									{
										//Call the Linked List method to display all the contents of the Desktop List
										fOperations->displayAllNodes(linkedList,3);
									}
										break;
									//Search and diplay the content of Desktop based on ID
									case 2:
									{
										//Call the Linked List method to display to search for a Desktop wityh particular ID
										int id;
										cout<<"\nEnter the Compter Id to be searched <Hint : Int> :\t";
										id=validateStringInput();
										fOperations->getNodeDetails(linkedList,id,3);
									}
										break;
								
									case 3:
									{
										//Validates and generate an unique id to desktop ---------- Method has to be created in MyUI Class
										int id=generateId(linkedList);
									
										cout<<"\nClass :MyUi\tid :\t"<<id;
										//Get the Inputs ----------------------- Method has to be created in Desktop Class
										ser->getAllInputs(id);
									
										//Adding the node to the LinkedList
										LinkedList* newLList=new LinkedList();
										newLList->setSPtr(ser);
										linkedList=fOperations->addNewNode(linkedList,newLList);
									
									
										//Display all the inputs on the screen -------------- Method hast to be created in Desktop Class
										//dtp->displayDesktopInputs();
									}
									break;
									//Update the given Desktop based on Id
									case 4:
									{
										int id=0;
										cout<<"\nPlease enter the System ID which you wish to Re-Configure <Hint : Int> :\t";
										while(id==0)
										{
											id=validateStringInput();
										}
										fOperations->updateNode(linkedList,id,3);
									}
										break;
									//Delete the given Desktop based on Id
									case 5:
									{
										int id=0;
										cout<<"\nEnter the Computer ID that has to be removed from the Database <Hint : Int> :\t";
										while(id==0)
										{
											id=validateStringInput();
										}
										fOperations->deleteNode(linkedList,id,3);
									}
										break;
									case 6:
									{
										int id;
										cout<<"\nEnter the Id for which the cost has to be fetched <Hint : Int> :\t";
										while(id==0)
										{
											id=validateStringInput();
										}
										fOperations->displayCDescription(linkedList,id,3);
									}
										break;
								}
							}
						}while(opt>7||opt==0);
					//}while(opt>7);
					break;
			}
			cout<<flush;
			cout<<"\n< Sub Menu Do you wish to continue > [ 'Y' / 'N' ] :\t";
				
			cin>>choice;
				
			if((choice!='Y')&&(choice!='y')&&(choice!='N')&&(choice!='n'))
			{
				do
				{
					cout<<flush;
					formatDec(2);
					cout<<" Do you wish to continue [ 'Y' / 'N' ] :\t";
					cin>>choice;
				
				}while((choice!='Y')&&(choice!='y')&&(choice!='N')&&(choice!='n'));
			}
		}while(choice=='Y' || choice =='y');
	}
	
	int MyUi::generateId(LinkedList* temp)
	{	
		//read the file and gives the 1+maximum number in the Id present in the file
		int uniqueCompId;
		if(keyGenId==0)
		{
			uniqueCompId=fOperations->getMaxSysId(temp);
			if(uniqueCompId==0)
				++keyGenId;
			else
				keyGenId=++uniqueCompId;
		}
		else
		{
			++keyGenId;
		}
		
		return(keyGenId);
	}
	
	int MyUi::validateStringInput()
	{
		int num;
		string sNumber;
		try
		{
			//cout<<"\nYour Input is :\t";
			//cin.ignore();
			getline(cin,sNumber);
			num=stoi(sNumber);
		}
		catch(invalid_argument &m)
		{
			cout<<"\nPlease enter a valid data <Only Number> [Spaces and special characters and strings not allowed]\n";
		}
		return(num);
	}
	
	
//int MyUi :: keyGenId =11;