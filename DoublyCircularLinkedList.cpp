//Doubly circular in CPP

#include<iostream>
using namespace std;

typedef struct node{
	int Data;
	struct node *Next;
	struct node *Prev;
}NODE, *PNODE;

class DoublyCL{
	private:
	   PNODE Head;
	   PNODE Tail;
	   int iSize;
	public:
	   DoublyCL(){
		   Head=NULL;
		   Tail=NULL;
		   iSize=0;
	   }
	   //FUNCTION DECLARATIONS:
	   void InsertFirst(int);
	   void InsertLast(int);
	   void InsertAtPos(int,int);
	   void DeleteFirst();
	   void DeleteLast();
	   void DeleteAtPos(int);
	   void Display();
	   int Count();
};

//DEFINATIONS:   // :: is scope resolution 
void DoublyCL::InsertFirst(int iNo){
	PNODE newN=NULL;
	newN=new NODE();
	// OR  PNODE newN=new NODE();
	newN->Data=iNo;
	newN->Next=NULL;
	newN->Prev=NULL;
	
	if((Head==NULL)&&(Tail==NULL)){  // if(iSize==0){}  // LL is empty
		Head=newN;
		Tail=newN;
	}
	
	else{
		newN->Next=Head;
		Head->Prev=newN;
		Head=newN;
	}
	Tail->Next=Head;
	Head->Prev=Tail;
	iSize++;

}
void DoublyCL::InsertLast(int iNo){
	PNODE newN=NULL;
	newN=new NODE();
	// OR  PNODE newN=new NODE();
	newN->Data=iNo;
	newN->Next=NULL;
	newN->Prev=NULL;
	
	if((Head==NULL)&&(Tail==NULL)){  // if(iSize==0){}  // LL is empty
		Head=newN;
		Tail=newN;
	}
	else{
		Tail->Next=newN;
		newN->Prev=Tail;
		Tail=newN;
	}
	Tail->Next=Head;
	Head->Prev=Tail;
	iSize++;

}
void DoublyCL::InsertAtPos(int iNo, int iPos){
	if((iPos<1)||(iPos>iSize+1)){
		return;
	}
	
	if(iPos==1){
		InsertFirst(iNo);
	}
	else if(iPos==iSize+1){
		InsertLast(iNo);
	}
	else{
		PNODE newN=new NODE;
		newN->Data=iNo;
		newN->Next=NULL;
		newN->Prev=NULL;
		
		PNODE Temp=Head;
		for(int i=1;i<iPos-1;i++){
			Temp=Temp->Next;
		}
		newN->Next=Temp->Next;
		Temp->Next->Prev=newN;
		Temp->Next=newN;
		newN->Prev=Temp;
		iSize++;
	}
	
}
void DoublyCL::DeleteFirst(){
	if(iSize==0){
		return;
	}
	else if(iSize==1){
		delete Head;
		Head=NULL;
		Tail=NULL;
		iSize=0;
	}
	else{
		Head=Head->Next;
		delete(Tail->Next);  //delete(Head->Prev);
		Tail->Next=Head;
		Head->Prev=Tail;
		iSize--;
	}
}
void DoublyCL::DeleteLast(){
	if(iSize==0){
		return;
	}
	else if(iSize==1){
		delete Tail; 
		Head=NULL;
		Tail=NULL;
		iSize=0;
	}
	else{
		Tail=Tail->Prev;  //300
		delete(Tail->Next); //delete(Head->Prev)
		Tail->Next=Head;
		Head->Prev=Tail;
		iSize--;
	}
}
void DoublyCL::DeleteAtPos(int iPos){
	if((iPos<0) ||(iPos>iSize)){
		return;
	}
	
	if(iPos==1){
		DeleteFirst();
	}
	else if(iPos==iSize){
		DeleteLast();
	}
	else{
		PNODE Temp=Head;
		for(int i=1;i<iPos-1;i++){
			Temp=Temp->Next;
		}
		Temp->Next=Temp->Next->Next;
		delete(Temp->Next->Prev);
		Temp->Next->Prev=Temp;
		iSize--;
	}
}
void DoublyCL::Display(){
	PNODE Temp=Head;
	for(int i=1;i<=iSize;i++){
        cout<<"|"<<Temp->Data<<"|=>"<<"\t";
		Temp=Temp->Next;
	}
	cout<<"\n";
}
int DoublyCL::Count(){
	return iSize;
}

int main(){
	int iChoice=1,iRet=0,iNo=0,iPos=0;
	
	DoublyCL obj;
	
	while(iChoice!=0){
		cout<<"Enter youe choice\n";
		cout<<"1:Insert First\n";
		cout<<"2:Insert Last\n";
		cout<<"3:Insert at position\n";
		cout<<"4:Delete First\n";
		cout<<"5:Delete Last\n";
		cout<<"6:Delete from given position\n";
		cout<<"7:Display nodes\n";
		cout<<"8:Count nodes:\n";
		cout<<"0:Exit the application\n";
		
		cin>>iChoice;
		
		switch(iChoice){
			case 1:
			    cout<<"Enter number\n";
				cin>>iNo;
				obj.InsertFirst(iNo);
				break;
				
			case 2:
			    cout<<"Enter number\n";
				cin>>iNo;
				obj.InsertLast(iNo);
				break;

			case 3:
			    cout<<"Enter number\n";
				cin>>iNo;
				cout<<"Enter position\n";
				cin>>iPos;
				obj.InsertAtPos(iNo,iPos);
				break;

			case 4:
				obj.DeleteFirst();
				break;

			case 5:
				obj.DeleteLast();
				break;

			case 6:
				cout<<"Enter position\n";
				cin>>iPos;
				obj.DeleteAtPos(iPos);
				break;

			case 7:
				obj.Display();
				break;

			case 8:
			    iRet=obj.Count();
				cout<<"Number of nodes in list:"<<iRet<<"\n";
				break;
		
			default:
			    cout<<"THANK YOU!!!!\n";
				break;

		}
	}
	
	return 0;
}