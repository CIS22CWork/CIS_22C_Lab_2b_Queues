/*
Branden Lee, Stephen Lee, and Alex Morfin
CIS 22C
Fall 2017
Lab 2

Used Microsoft Visual Studio 2017

CommandLineUI class
contains the presentational and interactive interface in the command line for the user.
KEEP ALL COUT<< AND CIN>> HERE
*/

#include <iostream>
#include <fstream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

#include "commandLineUI.h"
#include "List.h"

using namespace std;

CommandLineUI::CommandLineUI (Stack<int> *stackObjInt, Stack<std::string> *stackObjString, Stack<Currency> *stackObjCurrency)
{
	stackInt = stackObjInt;
	stackString = stackObjString;
	stackCurrency = stackObjCurrency;
}

/* ******************** enterLoop ********************
the main menu UI loop
*/
void CommandLineUI::enterLoop ()
{
	cout << "Welcome to our linked list demo. ";
	bool loopActive = true;
	while (loopActive)
	{
		cout << "Please enter the number representing the menu options below:" << endl
			<< "1. Push random integers to the integer type stack" << endl
			<< "2. Pop from the integer type stack" << endl
			<< "3. Clear the integer type stack" << endl
			<< "4. Push \"ExampleStrings.txt\" to the string type stack." << endl
			<< "5. Pop from the string type stack" << endl
			<< "6. Clear the string type stack" << endl
			<< "7. Push a random Currency to the currency type stack" << endl
			<< "8. Pop from the Currency type stack" << endl
			<< "9. Clear the Currency type stack" << endl
			<< "10. Exit Application" << endl << endl
			<< "Selection Number: ";
		// there is a bug that when you enter "test,2,3,hey" in the menu selection. 
		// The program gets stuck in an infinite loop
		cin >> menuOption;
		if (cin.fail ())
		{
			cin.clear (); // clears failure state
			cin.ignore (std::numeric_limits<std::streamsize>::max (), '\n'); // discards "bad" characters
			menuOption = 0;
		}
		cout << endl;
		if (menuOption < 1 || menuOption > 10)
		{
			cout << "************************************" << endl;
			cout << "Your selection was not valid. Please try again." << endl;
			cout << "************************************" << endl << endl;
		}
		else
		{
			/* please keep each sub-menu in a separate function to increase readability and prevent
			a huge blob of unorganized code. */
			if (menuOption == 1) intStackPush ();
			else if (menuOption == 2) intStackPop ();
			else if (menuOption == 3) intStackClear ();
			else if (menuOption == 4) stringStackPush ();
			else if (menuOption == 5) stringStackPop ();
			else if (menuOption == 6) stringStackClear ();
			else if (menuOption == 7) currencyStackPush ();
			else if (menuOption == 8) currencyStackPop ();
			else if (menuOption == 9) currencyStackClear ();
			else if (menuOption == 10) loopActive = false;
		}
	}
}

//******************************************************
// CommandLineUI::intStackPush   
//      
// This is an example of the stack push method
//******************************************************
void CommandLineUI::intStackPush ()
{
	int intRandom = rand () % 99999;
	stackInt->push (intRandom);
	cout << "integer stack items:" << endl << stackInt << endl << endl;
}

//******************************************************
// CommandLineUI::intStackPop         
//      
// This is an example of the stack pop method
//******************************************************
void CommandLineUI::intStackPop ()
{
	if (stackInt->empty ())
	{
		cout << "************************************" << endl;
		cout << "Stack is empty! Underflow Condition!" << endl;
		cout << "************************************" << endl << endl;
	}
	else
	{
		stackInt->pop ();
		cout << "integer stack items:" << endl << stackInt << endl << endl;
	}
}

//******************************************************
// CommandLineUI::intStackClear         
//      
// This is an example of the list clear method
//******************************************************
void CommandLineUI::intStackClear ()
{
	stackInt->clear ();
	cout << "integer stack items:" << endl << stackInt << endl << endl;
}

//******************************************************
// CommandLineUI::stringStackPush
//      
// This is an example of the stack push method
//******************************************************
void CommandLineUI::stringStackPush ()
{
	string buffer;
	ifstream read_input_file ("ExampleStrings.txt");

	cout << "Pushing \"ExampleStrings.txt\" contents to stack:" << endl;
	while (true)
	{
		read_input_file >> buffer;
		if (!read_input_file) break;
		stackString->push (buffer);
	}
	read_input_file.close ();
	cout << "string stack items:" << endl << stackString << endl << endl;
}

//******************************************************
// CommandLineUI::stringStackPop        
//      
// This is an example of the stack pop method
//******************************************************
void CommandLineUI::stringStackPop ()
{
	if (stackString->empty ())
	{
		cout << "************************************" << endl;
		cout << "Stack is empty! Underflow Condition!" << endl;
		cout << "************************************" << endl << endl;
	}
	else
	{
		stackString->pop ();
		cout << "string stack items:" << endl << stackString << endl << endl;
	}
}

//******************************************************
// CommandLineUI::stringStackClear         
//      
// This is an example of the list clear method
//******************************************************
void CommandLineUI::stringStackClear ()
{
	stackString->clear ();
	cout << "string stack items:" << endl << stackString << endl << endl;
}

//******************************************************
// CommandLineUI::currencyStackPush
//      
// This is an example of the stack push method
//******************************************************
void CommandLineUI::currencyStackPush ()
{
	// randomly generates a derived currency class class and fills it with
	// money 0-100 whole and 0-99 fractional parts then pushes it onto the stack
	int intRandom = rand () % 4;
	if (intRandom == 0) stackCurrency->push (CurrencyDollar (rand () % 100, rand () % 99));
	else if (intRandom == 1) stackCurrency->push (CurrencyEuro (rand () % 100, rand () % 99));
	else if (intRandom == 2) stackCurrency->push (CurrencyRupee (rand () % 100, rand () % 99));
	else if (intRandom == 3) stackCurrency->push (CurrencyYen (rand () % 100, rand () % 99));
	else if (intRandom == 4) stackCurrency->push (CurrencyYuan (rand () % 100, rand () % 99));
	cout << "Currency stack items:" << endl << stackCurrency << endl << endl;
}

//******************************************************
// CommandLineUI::currencyStackPop      
//      
// This is an example of the stack pop method
//******************************************************
void CommandLineUI::currencyStackPop ()
{
	if (stackCurrency->empty ())
	{
		cout << "************************************" << endl;
		cout << "Stack is empty! Underflow Condition!" << endl;
		cout << "************************************" << endl << endl;
	}
	else
	{
		stackCurrency->pop ();
		cout << "Currency stack items:" << endl << stackCurrency << endl << endl;
	}
}

//******************************************************
// CommandLineUI::currencyStackClear         
//      
// This is an example of the list clear method
//******************************************************
void CommandLineUI::currencyStackClear ()
{
	stackCurrency->clear ();
	cout << "Currency stack items:" << endl << stackCurrency << endl << endl;
}

//******************************************************
// operator<<        
//******************************************************
template <class T>
std::ostream& operator<< (std::ostream &foo, List<T> *ListPtr)
{
	// Since operator<< is a friend of the List class, we can access
	// it's members directly.
	int itemCount = 0;
	if (ListPtr->empty ()) cout << "List is empty" << endl;
	else
	{
		Node<T> *currPtr = ListPtr->getTail ();
		while (currPtr != nullptr)
		{
			itemCount++;
			foo << itemCount << ". " << currPtr->value << endl;
			currPtr = currPtr->next;
		}
	}
	return foo;
}
template <class T>
std::ostream& operator<< (std::ostream &foo, Stack<T> *ListPtr)
{
	// Since operator<< is a friend of the List class, we can access
	// it's members directly.
	int itemCount = 0;
	if (ListPtr->empty ()) cout << "List is empty" << endl;
	else
	{
		Node<T> *currPtr = ListPtr->getTail ();
		while (currPtr != nullptr)
		{
			itemCount++;
			foo << itemCount << ". " << currPtr->value << endl;
			currPtr = currPtr->next;
		}
	}
	return foo;
}