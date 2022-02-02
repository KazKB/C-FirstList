#include<iostream>
using namespace std;

class First_List 
{
	private: 
		struct node 
	{
		int data;	// will store information
		node *next;	// the reference to the next node
	} *head;//Global declaration

	public:
		First_List ();
		void insert_At_First (int &info, int &counter);
		void traverseList (int &counter);
		void insert_At_Last (int &info,int &counter);
		void insert_After_Specified_Num_Of_Nodes (int &info, int &counter, int &node_number);
		void delete_At_First_Node (int &counter);
		void delete_At_Last_Node (int &counter);
		void delete_Specified_Num_Of_Node (int &info, int &counter, int &node_number);
		void sort_Nodes ();
		void display_Nodes ();
		bool emptyList ();		
};

///function
First_List :: First_List ()
{
	head = NULL;	//empty linked list
}//First_List constructor

bool First_List :: emptyList ()
{
	return (head->next==NULL);
}//emptyList

void First_List :: insert_At_First (int &info, int &counter)
{
	cout << "ENTER ANY NUMBER:";
	cin >> info;			// take input data
	cout << "Input data: " << info << "  Node No: " << ++counter;
	
	node *temp;		// create a type, pointer to a node
	temp = new node;	// allocate space for node
	temp->data = info;	// store data(first field)
	temp->next=head;	// store the address of the pointer head(second field)
	head = temp;		// transfer the address of 'temp' to 'head'
}//insert

void First_List :: traverseList (int &counter)
{
	node *temp1;	   // create a type, pointer to a node
	temp1 = head;  // transfer the address of 'head' to 'temp'

	if (temp1 == NULL)
	{
		cout << endl << "The linked list is empty" << endl;
		//break;
	}
	else
	{
		cout << "Linked list: ";
		
		while( temp1!=NULL )
		{
			cout << temp1->data << " ";		// show the data in the linked list
			temp1 = temp1->next;		// tranfer the address of 'temp->next' to 'temp'
		}
	
		cout << endl << "Number of nodes: " << counter << endl;
		//break;
	}
}//traverseList

void First_List :: insert_At_Last (int &info,int &counter)
{
	// check linked list is empty
	if (emptyList())
	{
		cout << "ENTER ANY NUMBER:";
		cin >> info;		 // take input data
		cout << "Input data: " << info;
		
		node *temp;		 // create a temporary node
		temp = new node;	 // allocate space for node
		temp->data = info;	  // store data(first field)
		temp->next = NULL;  // second field will be null
		head = temp;		 // transfer the address of 'temp' to 'head'
		counter++;
	}
	else
	{
		cout << "ENTER ANY NUMBER:";
		cin >> info;			// take input data
		cout << "Input data: " << info;
		
		node *temp1;			// create a temporary node
		temp1 = new node;	           // allocate space for node
		temp1 = head;		// transfer the address of 'head' to 'temp'
		
		while (temp1->next!=NULL)	// go to the last node
			temp1 = temp1->next;		//tranfer the address of 'temp->next' to 'temp'
		
		node *temp;				// create a temporary node
		temp = new node;                             // allocate space for node
		temp->data = info;			// store data(first field)
		temp->next = NULL;		// second field will be null(last node)
		temp1->next = temp;			// 'temp' node will be the last node
	}
}//insert_At_Last()

void First_List :: insert_After_Specified_Num_Of_Nodes (int &info, int &counter, int &node_number)
{
	// check linked list is empty
	if (emptyList())
	{
		cout << "The Linked List is empty" << endl;
		//break;
	}//if
	
	cout << "ENTER ANY NUMBER:";
	cin >> info;			                    // take input data
	cout << "Input data: " << info << endl;
	
	cout << "ENTER THE NODE NUMBER:";
	cin >> node_number;			       // take the node number from user
	
	node *temp1;				      // create a temporary node
	temp1 = new node;;	// allocate space for node
	temp1 = head;
	
	for( int i = 1 ; i < node_number ; i++ )
	{
		temp1 = temp1->next;		                           // go to the next node
		
		if( temp1 == NULL )
		{
			cout << node_number << " node is not exist" << endl;
			//break;
		}
	}//for
	
	node *temp;				 // create a temporary node
	temp = new node;			// allocate space for node
	temp->data = info;			// store data(first field)
	temp->next = temp1->next;		//transfer the address of temp1->next to temp->next
	temp1->next = temp;			//transfer the address of temp to temp1->next
	counter++;

}//insert_After_Specified_Num_Of_nodes()

void First_List :: delete_At_First_Node (int &counter)
{
	// check linked list is empty
	if (head==NULL)
	{
		cout << "The Linked List is empty" << endl;
		////break;
	}//if
	else					// check linked list has only one node
	if (emptyList())
	{
		head = NULL;
		cout << "The first node of the Linked List is deleted" << endl;
		cout << "The Linked List is empty" << endl;
		counter--;
		//break;
	}//if
	
	node *temp;				// create a temporary node
	temp = new node;			// allocate space for node
	temp = head;				// transfer the address of 'head' to 'temp'
	head = temp->next;			// transfer the address of 'temp->next' to 'head'
	delete temp;                                       // Reclaim memory
	
	cout << "The first node of the Linked List is deleted" << endl;
	counter--;
	}//delete_At_First_Node()

void First_List :: delete_At_Last_Node (int &counter)
{
	// check linked list is empty
	if (emptyList())
	{
		cout << "The Linked List is empty" << endl;
		//break;
	}//if
	else	// check linked list has only one node
	if (head->next==NULL)
	{
		head = NULL;
		cout << "The last node of the Linked List is deleted" << endl;
		cout << "The Linked List is empty" << endl;
		counter--;
		//break;
	}//if
	node *temp1;				// create a temporary node
	temp1 = new node;			// allocate space for node
	temp1 = head;			//transfer the address of head to temp1
	node *old_temp;			// create a temporary node
	
	old_temp = new node;	// allocate space for node
	
	while (temp1->next!=NULL)	// go to the last node
	{
		old_temp = temp1;			   // transfer the address of 'temp1' to 'old_temp'
		temp1 = temp1->next;		// transfer the address of 'temp1->next' to 'temp1'
	}//while
	
	old_temp->next = NULL;		// previous node of the last node is null
	delete temp1;
	cout << "The last node of the Linked List is deleted" << endl;
	counter--;
}//Delete at last node

void First_List :: delete_Specified_Num_Of_Node (int &info, int &counter, int &node_number)
{
	// Check if link list is empty
	if (emptyList())
	{
		cout << "The Linked List is empty" << endl;
		//break;
	}//if
	else	// check linked list has only one node
	if (head->next==NULL)
	{
		head = NULL;
		cout << "The last node of the Linked List is deleted" << endl;
		cout << "The Linked List is empty" << endl;
		counter--;
		//break;
	}//if
	
	cout << "ENTER THE NODE NUMBER:";
	cin >> node_number;		// take location
	
	// Check if node is exist
	if (node_number > counter)
	{
		cout << "No such node is exist";
		////break;
	}//if
	
	node *temp1;		// create a temporary node
	temp1 = new node;	// allocate space for node
	temp1 = head;	// transfer the address of 'head' to 'temp1'
	
	node *old_temp;		// create a temporary node
	old_temp = new node;	// allocate space for node
	old_temp = temp1;		// transfer the address of 'temp1' to 'old_temp'
	
	// Check node number is 1
	if ( node_number == 1 )
	{
		head = temp1->next;		// transfer the address of 'temp1->next' to 'head'
		delete temp1;
		counter--;
		cout << node_number << " node of the Linked List is deleted" << endl;
		//break;
	}//if
	// Go to the node number of the node
	for ( int i = 1 ; i < node_number ; i++ )
	{
		old_temp = temp1;				// store previous node
		temp1 = temp1->next;			// store current node
	}//for
	
	old_temp->next = temp1->next;// transfer the address of 'temp1->next' to 'old_temp->next'
	delete temp1;
	counter--;
	cout << node_number << " node of the Linked List is deleted" << endl;
}//delete_Specified_Num_Of_Node()

void First_List :: sort_Nodes ()
{
	node *temp1;					// create a temporary node
	temp1 = new node;				// allocate space for node
	node *temp2;					// create a temporary node
	temp2 = new node;				// allocate space for node
	int temp = 0;					// store temporary data value
	
	for ( temp1 = head ; temp1!=NULL ; temp1 = temp1->next )
		{
		for ( temp2 = temp1->next ; temp2!=NULL ; temp2 = temp2->next )
		{
			if ( temp1->data > temp2->data )
			{
				temp = temp1->data;
				temp1->data = temp2->data;
				temp2->data = temp;
			}//if
		}//for
	}//for
	cout << "Nodes of the Linked List is sorted" << endl;
}//sort_Nodes

void First_List :: display_Nodes ()
{
	node *temp;					// create a temporary node
	temp = head;
	cout << "Nodes are" << endl;
	
	while (!(temp==NULL))
	{
		cout << temp->data << endl;
		temp = temp->next;
	}//while
}//display_Nodes

int main () {
	int info = 0, node_number = 0,  counter = 0;
	char ch = ' ';
	First_List list;

	do {
		cout << "\n\n";
		cout << "0.Quit\n\n";
		cout << "1.Insert at first\n\n";
		cout << "2.Traverse\n\n";
		cout << "3.Insert at last\n\n";
		cout << "4.Insert after specified number of node\n\n";
		cout << "5.Delete at first node\n\n";
		cout << "6.Delete at last node\n\n";
		cout << "7.Delete specified number of node\n\n";
		cout << "8.Sort nodes\n\n";
		cout << "9.Display nodes\n\n";
		cout << "Enter your choice: ";
		cin >> ch;

	switch (ch) {
		case '0':
		break;
	
		case '1':
		{
			list.insert_At_First (info,counter);
			break;
		}//case 1
	
		case '2':
		{
			list.traverseList (counter);
			break;
		}//case 2
		
		case '3':
		{
			list.insert_At_Last (info,counter);
			break;
		}//case 3
		
		case '4':
		{
			list.insert_After_Specified_Num_Of_Nodes (info,counter,node_number);
			break;
		}//case 4
		
		case '5':
		{
			list.delete_At_First_Node (counter);
			break;
		}//case 5
		
		case '6':
		{
			list.delete_At_Last_Node (counter);
			break;
		}//while
		
		case '7':
		{
			list.delete_Specified_Num_Of_Node (info,counter,node_number);
			break;
		}// case 7
		
		case'8':
		{
			list.sort_Nodes ();
			break;
		}//case 8
		
		case'9':
		{
			list.display_Nodes ();
			break;
		}//case 9
	}//switch
	
} while(ch!='0');

return 0;
}//main

