#ifndef MYUI_H
#define MYUI_H
#include "LinkedList.h"
//#include "Desktop.h"
//#include "Laptop.h"
//#include "Server.h"
#include "FileOperations.h"


class MyUi //: public Desktop, public Laptop, public Server
{
	private:
		int keyGenId=0;
		int tempFlag=0;
		Desktop* dtp = new Desktop();
		Laptop* ltp = new Laptop();
		Server* ser = new Server();
		FileOperations* fOperations=new FileOperations();
		LinkedList* linkedList=NULL;
	public:
		MyUi();
		
		~MyUi();
		
		void formatDec(int opt);
	
		void createGUI1();
	
		void createGUI2(int model);
	
		int generateId(LinkedList*);
		
		int validateStringInput();
	
};

#endif