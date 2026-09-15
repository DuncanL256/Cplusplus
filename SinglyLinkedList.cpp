//
// Singly linked list manipulation


#include <iostream>
#include <stdlib.h>
using namespace std;

struct NODE				
{					
	int data;
	NODE * next ;		
};


NODE* CreateList(NODE *head)
{
	return NULL;
}

NODE* DeleteList(NODE *head)
{
	NODE *cur;

	cur = head;

	while (cur != NULL)
	{
		cur = head->next;
		delete head;
		head = cur;
	}

	return NULL;
}


NODE* InsertElement(NODE *head, int value, bool& result)
{
	NODE *cur, *previous, *tmp;

	result = false;

	tmp = new NODE;
	if (tmp == NULL)
		return head;

	tmp->data = value;
	tmp->next = NULL;

	if (head == NULL)
	{
		tmp->next = head;
		head = tmp;
		result = true;
		return head;
	}

	if (value <= head->data)
	{
		tmp->next = head;
		head = tmp;
		result = true;
		return head;
	}

	cur = head;
	previous = NULL;
	while ((cur != NULL) && (cur->data < value))
	{
		previous = cur;
		cur = cur->next;
	}

	previous->next = tmp;
	tmp->next = cur;

	result = true;

	return head;
}
				


NODE* DeleteElement(NODE *head,  int value, bool& result)
{
	NODE *cur, *previous;

	result = false;

	if (head == NULL)
		return head;
	
	if (value == head->data)
	{
		cur = head->next;
		delete head ;
		result = true;
		head = cur;
		return head;
	}

	cur = head;
	while ((cur != NULL) && (cur->data != value))
	{
		previous = cur;
		cur = cur->next;
	}
	
	if (cur == NULL)
		return head;

	previous->next = cur->next;

	delete cur;

	result = true;

	return head;
}


NODE* ModifyElement(NODE *head, int oldValue, int newValue, bool& result)
{
	NODE *cur;

	result = false;

	cur = head;

	while ((cur != NULL) && (cur->data != oldValue))
		cur = cur->next;


	if (cur == NULL)
		return head;

	cur->data = newValue;

	result = true;

	return head;
}



NODE* SearchElement(NODE *head, int value)
{
	NODE *cur;

	if (head == NULL)
		return head;

	cur = head;;
	while ((cur != NULL) && (cur->data != value))
		cur = cur->next;

	return cur;
}
				

bool IsInList(NODE *head, int value)
{
	NODE *cur;

	if (head == NULL)
		return false;

	cur = head;;
	while ((cur != NULL) && (cur->data != value))
		cur = cur->next;

	if (cur == NULL)
		return false;

	return true;
}


int GetEltNbr(NODE *head)
{
	NODE *cur;
	int nbr = 0;

	if (head == NULL)
		return 0;

	cur = head;
	while (cur != NULL) 
	{
		nbr++;
		cur = cur->next;
	}

	return nbr;
}

int GetEltNbrRec(NODE *head)
{
	if(!head) return 0;
	return 1+ GetEltNbrRec(head->next);

}


void PrintList(NODE *head)
{
	NODE *cur;

	if (head == NULL)
	{
		cout << "The list is empty" << endl;
		return;
	}

	cur = head;
	while (cur != NULL) 
	{
		cout << cur->data << "\t";
		cur = cur->next;
	}
	
	cout << endl;

}

// Newly added functions are below _________________________________________________________________
void reverseList(NODE*& head)	// Reverse the linked list by modifying the next pointers
{
	NODE *prev = NULL;
	NODE *cur = head;
	NODE *next;

	// We have to store next before reversing the pointer or the list coul get lost
	while (cur != NULL)
	{
		next = cur->next;   // Save next node
		cur->next = prev;   // Reverse the pointer
		prev = cur;         // Move prev forward
		cur = next;         // Move current forward
	}

	head = prev; // update head
}

// Merge two sorted linked lists
NODE* mergeSortedLists(NODE* l1, NODE* l2)
{
	if (l1 == NULL)	// If one list is empty, return the other
		return l2;

	if (l2 == NULL)
		return l1;

	if (l1->data <= l2->data) // Here we compare the values and link the smaller one first
	{
		l1->next = mergeSortedLists(l1->next, l2);
		return l1;
	}
	else
	{
		l2->next = mergeSortedLists(l1, l2->next);
		return l2;
	}
}

// Remove duplicate values from a sorted list
void removeDuplicates(NODE*& head)
{
	NODE *cur = head;
	bool result;

	// Since the list is sorted, the duplicates will appear next to each other
	while (cur != NULL && cur->next != NULL)
	{
		if (cur->data == cur->next->data)
		{
			head = DeleteElement(head, cur->next->data, result); // Remove the duplicate node using the provided function
		}
		else
		{
			cur = cur->next;	// Move to the next node
		}
	}
}



int main(int argc, char* argv[])
{
	int choice = 1;
	NODE *head;
	NODE *tmp;
	int val, val1;
	bool result;
	
	head = CreateList(head);

	cout << "A list of integers has been created (it will be sorted by increasing order) " << endl;
	
	while (choice != 0)
	{
		cout << endl
			 << "     ======================" << endl
		     << "     1: InsertElement() : " << endl
			 << "     2: DeleteElement() : " << endl
			 << "     3: SearchElement() : " << endl
			 << "     4: IsInList()      : " << endl
			 << "     5: ModifyElement() : " << endl
			 << "     6: PrintList()     : " << endl
			 << "     7: GetEltNbr()     : " << endl
			 << "     8: DeleteList()    : " <<endl
			 << "     9: GetEltNbrRec()  : " << endl
			 << "     10: Reverse List()   : " << endl	// Added to help tests
			 << "     11: Remove Duplicates() : " << endl // Added to help tests
			 << "     ======================" << endl
			 << "     0: Quit" << endl
			 << "     ======================" << endl
			 << endl
			 << "Your Choice : ";
		
		cin >> choice;
		cout << endl;

		switch(choice)
		{
		case 1 :
			cout << "Type the element's value : ";
			cin >> val;
			head = InsertElement(head, val, result);
			if (result == false)
			{
				cout << "Insertion failed " << val << endl;
				head = DeleteList(head);
				exit(0);
			}
			else
				cout << "The value "<< val << " has been added" << endl;
			break;
		
		case 2 :
			cout << "Type the value to delete : ";
			cin >> val;
			head = DeleteElement(head, val, result);
			if (result == false)
				cout << "Deletion failed : " << val << endl;
			else
				cout << "The value "<< val << " has been deleted" << endl;
			break;
		
		case 3 :
			cout << "Type the value to search : ";
			cin >> val;
			tmp = SearchElement(head, val);
			if (tmp == NULL)
				cout << val << "is not in the list" << endl;
			else
				cout << "The value "<< val << "is in the list with address : " << tmp << endl;
			break;

		case 4 :
			cout << "type the value to search : ";
			cin >> val;
			if (IsInList(head, val))
				cout << val << " is in the list" << endl;
			else
				cout << val << " is not in the list " << endl;
			break;

		case 5 :
			cout << "Type the old value : ";
			cin >> val;
			cout <<endl << "Type the new value : ";
			cin >> val1;
			head = ModifyElement(head, val, val1, result);
			if (result == false)
				cout << "Modification failed " << val << " en "<< val1 <<endl;
			else
				cout << "The value "<< val << " has been modified " << val1 <<endl;

			break;

		case 6 :
			PrintList(head);
			break;

		case 7 :
			cout << "The list contains " << GetEltNbr(head) << " elements."<< endl;
			break;
		case 8 :
			  head= DeleteList(head); 
			  cout<<"The list has been deleted " << endl;
			break;
		case 9 :
			cout << "The list contains " << GetEltNbrRec(head) << " elements."<< endl;
			break;
		case 10 :	//New case added to test new functions
			reverseList(head);
			cout << "The list has been reversed." << endl;
			PrintList(head);
			break;

		case 11 :	//New case added to test new functions
			removeDuplicates(head);
			cout << "Duplicates removed." << endl;
			PrintList(head);
			break;
		case 0 :
			break;
		}
	}


	head = DeleteList(head);
	cout << "The list has been deleted " << endl;

	//This area is to test the merging____________________________
	NODE *list1 = NULL;
	NODE *list2 = NULL;

	bool res;

	list1 = InsertElement(list1, 1, res);	//List building
	list1 = InsertElement(list1, 3, res);
	list1 = InsertElement(list1, 5, res);

	list2 = InsertElement(list2, 2, res);
	list2 = InsertElement(list2, 4, res);
	list2 = InsertElement(list2, 6, res);

	NODE *merged = mergeSortedLists(list1, list2);
	cout << "     " << std::endl; // Spacer string to make the console a little prettier
	cout << "Merged list: ";
	PrintList(merged);
	//Merge area end________________________________________________

	return 0;
}

