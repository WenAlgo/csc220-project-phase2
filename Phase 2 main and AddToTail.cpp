#include <iostream>
using namespace std;
#include <cstdlib>

struct node{
	int data;
	node *next;
	node *prev;
};

int count=0;
node *head=NULL;		//head of linked-list
node *tail=NULL;		//end of linked-list
node *current;			//curent node	

void AddToTail(int b){
	node *ptr;					
	ptr=new node;
	ptr->data=b;
	if (count==0){			//if there is no list yet, 
		ptr->prev=NULL;		//we make the new entrys prev NULL,
		head=ptr;			//and then we make head equal to the new entry
	}
	else{					//else, if the linked list already has data
		tail->next=ptr;		//the current tail's next becomes the new entry			
	}
							//to update the nodes now...	
	ptr->next=NULL;			//we make the new entries next NULL
	tail=ptr;				//then we update the tail to the new entry
	count++;	
}

void AddToHead(int a){
	node *ptr;
	ptr=new node;
	ptr->data=a;
	if (count==0){
		ptr->next=NULL;
		tail=ptr;
	}
	else{
		ptr->next=head;	
		head->prev=ptr;					
	}
	ptr->prev=NULL;
	head=ptr;
	count++;			
}
			
void PrintElements(){
	
}
void PrintReverse(){
	
}	
			

int main(){
	for (int i=0; i<15; i++){AddToTail(rand()%100);}
	PrintElements();
	cout<<endl;
	
	int choice;
	int num;
	do{
		cout<<"Enter your choice: Add a new element(1), Print(2), Print reverse(3), or exit(4): ";
		cin>>choice;
		if((choice==1) ||(choice==2)||(choice==3)){		
			if (choice==1){
				cout<<"Enter an integer: ";
				cin>>num;
				AddToTail(num);
			}
			if (choice==2){PrintElements();}
			if (choice==3){PrintReverse();}
		}
		else{cout<<"Your entry is invalid."<<endl;}
	}while(choice!=4);
	
	return 0;

}