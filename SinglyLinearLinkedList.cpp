//Singly Linear LL in c++
using namespace std;

#include<iostream>

typedef struct node{
	 int Data;
	 struct node *Next;
 }NODE, *PNODE;

// OR
/*struct node{
	int Data;
	struct node *Next;
};

typedef struct node NODE;
typedef struct node * PNODE;
*/
 
class SinglyLL{
	private:
	  PNODE Head; //not accessicble outside
	  int iSize;
	public:
	   SinglyLL(){// default constructor
		   Head=NULL;
		   iSize=0;
	   }
	   
	   int Count(){   //Time complexity is zero
 		   iSize;
	   }
	   void Display(){
		   PNODE Temp=Head;
		   while(Temp!=NULL){
			   cout<<Temp->Data<<"\t";
			   Temp=Temp->Next;
		   }
		   cout<<"\n";
	   }
	   void InsertFirst(int iValue){
		  PNODE newN=NULL;
		  newN= new NODE; //allocation
		  newN->Data=iValue;
		  newN->Next=NULL;
          if(Head==NULL){ // LL is empty
			 Head=newN; 
		  }
		  else{
			 newN->Next=Head;
			 Head=newN;
		  }
		  iSize++;
	   }
	    
	   void InsertLast(int iValue){
		  PNODE newN=NULL;
		  PNODE Temp=Head;
		  newN= new NODE; //allocation
		  newN->Data=iValue;
		  newN->Next=NULL;
          if(Head==NULL){ // LL is empty
			Head=newN; 
		  }
		  else{
			while(Temp->Next!=NULL){
				Temp=Temp->Next;
			}
			Temp->Next=newN;
		  }
		  iSize++;
	   }
	   void DeleteFirst(){
		   /*if(Head==NULL){
			   return;
		   }
		   else{
			   PNODE Temp=Head;
			   Head=Head->Next;
			   delete Temp;
			   iSize--;
		   }*/
		   //OR
		   if(Head!=NULL){
			   PNODE Temp=Head;
			   Head=Head->Next;
			   delete Temp;
			   iSize--;
		   }
	   }
	    void DeleteLast(){
		  	if(Head==NULL){
				return;
			}
			else if(Head->Next==NULL){
				delete Head;
				Head=NULL;
				iSize--;
			}
			else{
				PNODE Temp=Head;
				while(Head->Next->Next!=NULL){
					Temp=Temp->Next;
				}
				delete Temp->Next;
				Temp->Next=NULL;
				iSize--;
			}
	   }
};
int main(){
	int iChoice=1, iNo=0;
	
	SinglyLL obj1;
	while(iChoice!=0){
		cout<<"Enter your choice:"<<"\n";
		cout<<"1:Insert at first position"<<"\n";
		cout<<"2:Insert at last position"<<"\n";
		cout<<"3:Insert at given position"<<"\n";
		cout<<"4:Delete first"<<"\n";
		cout<<"5:Delete last"<<"\n";
		cout<<"6:Delete from given positive_sign"<<"\n";
		cout<<"7:Display list"<<"\n";
		cout<<"8:count the nodes in list"<<"\n";
		cout<<"0:Exit the application"<<"\n";
		
		cin>>iChoice;
		
		switch(iChoice){
			case 1:
			    cout<<"Enter number\n";
				cin>>iNo;
				obj1.InsertFirst(iNo);
			    break;
			 
			case 2:
			    cout<<"Enter number\n";
				cin>>iNo;
				obj1.InsertLast(iNo);
			    break;
			
			case 3:
			   break;
			   
			case 4:
			    obj1.DeleteFirst();
			    break;
			   
			case 5:
			    obj1.DeleteLast();
			    break;
			   
			case 6:
			   break;
			   
			case 7:
		       obj1.Display();	
			   break;
			   
			case 8:
			   iNo=obj1.Count();
			   cout<<"Number of nodes are:"<<iNo<<"\n";
			   break;
			  
			case 0:
			   cout<<"Thank you!!!!!!!!\n";
			   break;
			   
			default:
			   cout<<"Please enter valid choice";
		}
	}
	return 0;
}