#include <iostream>     // Provides cout and cin
#include <cstdlib>      // Provides NULL, srand, rand, EXIT_SUCCESS
using namespace std;

struct node {
    int data;
    node *next;
    node *prev;
};

class DoublyLinkedList {

private:
    int count=0;
    node *head=NULL;    //head of linked-list
    node *tail=NULL;    //end of linked-list

public:
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
            ptr->prev = tail;
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

    void PrintElements() {
        node* currentptr = head;			  //create new node that points to headptr

        while (currentptr) {                                    //traverse through entire list
            //check when to end with a new line or a comma
            if (currentptr == tail) { cout << currentptr->data << endl; }
            else { cout << currentptr->data << ", "; }

            currentptr = currentptr->next;                      //move to next node
        }
    }

    void PrintReverse(){
        node* current = tail;
        while (current) {
            // Use the ternary operator not to print comma after the last element
            cout << current->data << (current == head ? "" : ", ");
            current = current->prev;
        }
        cout << endl;
    }	
};

int main() {
    DoublyLinkedList list;

    // Seed the random number generator to get a different sequence each time
    srand(time(0));

    // Add 15 random elements to the list
    for (int i = 0; i < 15; ++i) {
        list.AddToTail(rand() % 100);
    }
    list.PrintElements();

    int choice;
    do {
        cout << "Menu:" << endl;
        cout << "Option 1: Add new element." << endl;
        cout << "Option 2: Print List elements." << endl;
        cout << "Option 3: Print List elements in reverse order." << endl;
        cout << "Option 4: Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int element;
                cout << "Enter the new element: ";
                cin >> element;
                list.AddToTail(element);
                break;
            }
            case 2:
                cout << "List elements: " << endl;
                list.PrintElements();
                break;
            case 3:
                cout << "List elements in reverse order: " << endl;
                list.PrintReverse();
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return EXIT_SUCCESS;
}
