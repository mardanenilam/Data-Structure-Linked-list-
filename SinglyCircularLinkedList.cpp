// singly circular LL in CPP   // what is mean by terminate called recursively
#include<iostream>

using namespace std;

typedef struct node{
	int Data;
	struct node *Next;
}NODE, *PNODE;

class SinglyCL{
	private:
	   PNODE Head;
	   PNODE Tail;
	   int iSize;
	public:
	   SinglyCL(){   //Default contructor
		   Head=NULL;
		   Tail=NULL;
		   iSize=0;
	   }
	   void InsertFirst(int iNo){
		   PNODE newN=NULL;
		   
		   newN=new NODE;
		   newN->Data=iNo;
		   newN->Next=NULL;
		   
		   if((Head==NULL) && (Tail==NULL)){   // LL is empty
			    Head=newN; //100
				Tail=newN;  //100
				//iSize++; // numbr of nodes:1
				//Tail->Next=Head; //100
		   }
		   else{   //LL contains at least one node
			   newN->Next=Head;
			   Head=newN;
			   //iSize++;
			   //Tail->Next=Head;
		   }
		   iSize++;
		   Tail->Next=Head;
		   
	   }
	   void InsertLast(int iNo){
		   PNODE newN=NULL;
		   PNODE Temp=Head;
		   newN=new NODE;
		   newN->Data=iNo;
		   newN->Next=NULL;
		   
		   if((Head==NULL) && (Tail==NULL)){   // LL is empty
			    Head=newN; //100
				Tail=newN;  //100
				//iSize++; // numbr of nodes:1
				//Tail->Next=Head; //100
		   }
		   else{   //LL contains at least one node
			   Tail->Next=newN;
			   Tail=Tail->Next; //Tail=newN     is also correct
			   //iSize++;
			   //Tail->Next=Head;
		   }
		   iSize++;
		   Tail->Next=Head; // these two lines of code is common so it can be outside
	   }
	   int Count(){
		   return iSize;
	   }
	   void Display(){
		   int i=0;
		   PNODE Temp=Head;
		   for(i=1;i<=iSize;i++){
			   cout<<Temp->Data<<"\t";
			   Temp=Temp->Next;
		   }
		   cout<<"\n";
	   }
	   void InsertAtPosition(int iNo, int iPos){
		    PNODE newN=NULL;
			PNODE Temp=Head; 
			if((iPos<0)||(iPos>iSize+1)){
				return;
			}
			
			if(iPos==1){
				InsertFirst(iNo);
			}
			else if(iPos==(iSize+1)){
				InsertLast(iNo);
			}
			else{
				newN=new NODE;
		        newN->Data=iNo;
		        newN->Next=NULL;
				int i=0;
		        for(i=1;i<iPos-1;i++){
					Temp=Temp->Next;
                }
				newN->Next=Temp->Next;
				Temp->Next=newN;
			}
			iSize++;
		    Tail->Next=Head;
	   }
	   void DeleteFirst(){
		   if(iSize==0){ //   ((Head==NULL)&&(Tail==NULL)){
			   return;
		   }
		   else if(iSize==1){  // else if(Head==Tail)
			   delete Head;
			   Head=NULL;
			   Tail=NULL;
			   iSize--; //iSize=0;
		   }
		   else{
			   Head=Head->Next; // 200
			   delete (Tail->Next); // deleted 100;
			   Tail->Next=Head; // //200
			   iSize--;
		   }
	    }
	   	void DeleteLast(){
		   if(iSize==0){ //   ((Head==NULL)&&(Tail==NULL)){
			   return;
		   }
		   else if(iSize==1){
			   delete Head; //delete Tail
			   Head=NULL;
			   Tail=NULL;
			   iSize--; //iSize=0;
		   }
		   else{
			   int i=0;
			   PNODE Temp=Head;
			   for(i=1;i<iSize;i++){
				  Temp=Temp->Next; 
			   }
			   delete Tail;//delete Temp->Next;
			   Tail=Temp;
			   Tail->Next=Head;
			   iSize--;
		   }
	   }
	   void DeleteAtPosition(int iPos){
	        PNODE newN=NULL;
			PNODE Temp=Head; 
			PNODE Target=NULL;
			if((iPos<0)||(iPos>iSize+1)){
				return;
			}
			
			if(iPos==1){
				DeleteFirst();
			}
			else if(iPos==(iSize+1)){
				DeleteLast();
			}
			else{
				int i=0;
		        for(i=1;i<iPos-1;i++){
					Temp=Temp->Next;
                }
				Target=Temp->Next;
				Temp->Next=Target->Next;
				delete Target;
			}
		    //Tail->Next=Head;
			iSize--;
	   }
};

int main(){
	SinglyCL obj; // created object of class.
	int iChoice=1,iRet=0,iPos=0,iValue=0;
	while(iChoice!=0){
		cout<<"Enter your choice:\n";
		cout<<"1:Insert First\n";
		cout<<"2:Insert Last\n";
		cout<<"3:Insert at position\n";
		cout<<"4:Delete first\n";
		cout<<"5:Delete last\n";
		cout<<"6:Delete from given position\n";
		cout<<"7:Display the list\n";
		cout<<"8:Count the number of nodes in list\n";
		cout<<"0:Exit theapplication\n";
		
		cin>>iChoice;
		
		switch(iChoice){
			case 1:
			   cout<<"Enter number\n";
			   cin>>iValue;
			   obj.InsertFirst(iValue);
			   break;
			case 2:
			   cout<<"Enter number\n";
			   cin>>iValue;
			   obj.InsertLast(iValue);
			   break;
			case 3:
			   cout<<"Enter number\n";
			   cin>>iValue;
			   cout<<"Enter position\n";
			   cin>>iPos;   
			   obj.InsertAtPosition(iValue,iPos);
			   break;
			case 4:
			   obj.DeleteFirst();
			   break;
			case 5:
			   obj.DeleteLast();
			   break;
			case 6:
			   cout<<"Enter the position\n";
			   cin>>iPos;
			   obj.DeleteAtPosition(iPos);
			   break;
			case 7:
			   obj.Display();
			   break;
			case 8:
			   iRet=obj.Count();
			   cout<<"Number of nodes in list:"<<iRet<<"\n";
			   break;
			case 0:
			   cout<<"Thank you!!!";
			   break;
			default:
			   cout<<"Please enter valid choice\n";
			   break;
		}//endof switch
	}//end of while
	return 0;
}// end of main