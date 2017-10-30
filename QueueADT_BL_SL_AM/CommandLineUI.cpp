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

CommandLineUI::CommandLineUI (Queue<int> *QueueObjInt, Queue<std::string> *QueueObjString, Queue<Currency> *QueueObjCurrency)
{
	QueueInt = QueueObjInt;
	QueueString = QueueObjString;
	QueueCurrency = QueueObjCurrency;
}

/********************* enterLoop ********************
the main menu UI loop
Pre: None
Post: None
Purpose: Loop for the user interface, allows the user to perform operations
through a if else statement;
*/
void CommandLineUI::enterLoop ()
{
	cout << "Welcome to our linked list demo. ";
	bool loopActive = true;
	while (loopActive)
	{
		cout << "Please enter the number representing the menu options below:" << endl
			<< "1. Push random integer to the integer type Queue" << endl
			<< "2. Push custom integer to the integer type Queue" << endl
			<< "3. Pop from the integer type Queue" << endl
			<< "4. Clear the integer type Queue" << endl
			<< "5. Push \"ExampleStrings.txt\" to the string type Queue." << endl
			<< "6. Push custom string to the string type Queue" << endl
			<< "7. Pop from the string type Queue" << endl
			<< "8. Clear the string type Queue" << endl
			<< "9. Push a random Currency to the currency type Queue" << endl
			<< "10. Push custom Currency to the Currency type Queue" << endl
			<< "11. Pop from the Currency type Queue" << endl
			<< "12. Clear the Currency type Queue" << endl
			<< "13. Exit Application" << endl << endl
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
		if (menuOption < 1 || menuOption > 13)
		{
			cout << "************************************" << endl;
			cout << "Your selection was not valid. Please try again." << endl;
			cout << "************************************" << endl << endl;
		}
		else
		{
			/* please keep each sub-menu in a separate function to increase readability and prevent
			a huge blob of unorganized code. */
			if (menuOption == 1) intQueuePush ();
			else if (menuOption == 2) intQueuePush2 ();
			else if (menuOption == 3) intQueuePop ();
			else if (menuOption == 4) intQueueClear ();
			else if (menuOption == 5) stringQueuePush ();
			else if (menuOption == 6) stringQueuePush2 ();
			else if (menuOption == 7) stringQueuePop ();
			else if (menuOption == 8) stringQueueClear ();
			else if (menuOption == 9) currencyQueuePush ();
			else if (menuOption == 10) currencyQueuePush2 ();
			else if (menuOption == 11) currencyQueuePop ();
			else if (menuOption == 12) currencyQueueClear ();
			else if (menuOption == 13) loopActive = false;
		}
	}
}

//******************************************************
// CommandLineUI::intQueuePush   
//      
// This is an example of the Queue push method
//
// Pre: None
// Post: None
// Purpose: Push a random integer into the integer queue by calling push();
//******************************************************
void CommandLineUI::intQueuePush ()
{
	int intRandom = rand () % 99999;
	QueueInt->push (intRandom);
	cout << "integer Queue items:" << endl << QueueInt << endl << endl;
}

//******************************************************
// CommandLineUI::intQueuePush2   
//      
// This is an example of the Queue push method
//
// Pre: None
// Post: None
// Purpose: Push an user inputted integer into the integer queue by calling push();
//******************************************************
void CommandLineUI::intQueuePush2 ()
{
	int inputInt;
	cout << "Input an integer: ";
	cin >> inputInt;
	QueueInt->push (inputInt);
	cout << endl;
	cout << "integer Queue items:" << endl << QueueInt << endl << endl;
}

//******************************************************
// CommandLineUI::intQueuePop         
//      
// This is an example of the Queue pop method
//
// Pre: None
// Post: None
// Purpose: Pop an integer from the integer queue by calling pop();
//******************************************************
void CommandLineUI::intQueuePop ()
{
	if (QueueInt->empty ())
	{
		cout << "************************************" << endl;
		cout << "Queue is empty! Underflow Condition!" << endl;
		cout << "************************************" << endl << endl;
	}
	else
	{
		QueueInt->pop ();
		cout << "integer Queue items:" << endl << QueueInt << endl << endl;
	}
}

//******************************************************
// CommandLineUI::intQueueClear         
//      
// This is an example of the list clear method
//
// Pre: None
// Post: None
// Purpose: Clears the integer queue by calling clear();
//******************************************************
void CommandLineUI::intQueueClear ()
{
	QueueInt->clear ();
	cout << "integer Queue items:" << endl << QueueInt << endl << endl;
}

//******************************************************
// CommandLineUI::stringQueuePush
//      
// This is an example of the Queue push method
//
// Pre: None
// Post: None
// Purpose: Push a string from a txt file into the string queue by calling push();
//******************************************************
void CommandLineUI::stringQueuePush ()
{
	string buffer;
	ifstream read_input_file ("ExampleStrings.txt");

	cout << "Pushing \"ExampleStrings.txt\" contents to Queue:" << endl;
	while (true)
	{
		read_input_file >> buffer;
		if (!read_input_file) break;
		QueueString->push (buffer);
	}
	read_input_file.close ();
	cout << "string Queue items:" << endl << QueueString << endl << endl;
}

//******************************************************
// CommandLineUI::stringQueuePush2
//      
// This is an example of the Queue push method
//
// Pre: None
// Post: None
// Purpose: Push an user inputted string into the string queue by calling push();
//******************************************************
void CommandLineUI::stringQueuePush2 ()
{
	string inputString;
	cout << "Input a string: ";
	cin.clear ();
	cin.ignore (std::numeric_limits<std::streamsize>::max (), '\n'); // discards "bad" characters
	getline (cin, inputString);
	QueueString->push (inputString);
	cout << endl;
	cout << "string Queue items:" << endl << QueueString << endl << endl;
}

//******************************************************
// CommandLineUI::stringQueuePop        
//      
// This is an example of the Queue pop method
//
// Pre: None
// Post: None
// Purpose: Pop from the front of the string queue by calling pop();
//******************************************************
void CommandLineUI::stringQueuePop ()
{
	if (QueueString->empty ())
	{
		cout << "************************************" << endl;
		cout << "Queue is empty! Underflow Condition!" << endl;
		cout << "************************************" << endl << endl;
	}
	else
	{
		QueueString->pop ();
		cout << "string Queue items:" << endl << QueueString << endl << endl;
	}
}

//******************************************************
// CommandLineUI::stringQueueClear         
//      
// This is an example of the list clear method
//
// Pre: None
// Post: None
// Purpose: Clears the string queue by calling clear();
//******************************************************
void CommandLineUI::stringQueueClear ()
{
	QueueString->clear ();
	cout << "string Queue items:" << endl << QueueString << endl << endl;
}

//******************************************************
// CommandLineUI::currencyQueuePush
//      
// This is an example of the Queue push method
//
// Pre: None
// Post: None
// Purpose: Push a random currency into the currency queue by calling push();
//******************************************************
void CommandLineUI::currencyQueuePush ()
{
	// randomly generates a derived currency class class and fills it with
	// money 0-100 whole and 0-99 fractional parts then pushes it onto the Queue
	int intRandom = rand () % 4;
	if (intRandom == 0) QueueCurrency->push (CurrencyDollar (rand () % 100, rand () % 99));
	else if (intRandom == 1) QueueCurrency->push (CurrencyEuro (rand () % 100, rand () % 99));
	else if (intRandom == 2) QueueCurrency->push (CurrencyRupee (rand () % 100, rand () % 99));
	else if (intRandom == 3) QueueCurrency->push (CurrencyYen (rand () % 100, rand () % 99));
	else if (intRandom == 4) QueueCurrency->push (CurrencyYuan (rand () % 100, rand () % 99));
	cout << "Currency Queue items:" << endl << QueueCurrency << endl << endl;
}

//******************************************************
// CommandLineUI::currencyQueuePush2
//      
// This is an example of the Queue push method
//
// Pre: None
// Post: None
// Purpose: Push an user inputted currency into the currency queue by calling push();
//******************************************************
void CommandLineUI::currencyQueuePush2 ()
{
	string inputString;
	cout << "Dollar/Euro/Rupee/Yen/Yuan" << endl;
	cout << "Input a Currency: ";
	cin.clear ();
	cin.ignore (std::numeric_limits<std::streamsize>::max (), '\n'); // discards "bad" characters
	getline (cin, inputString);
	if (inputString == "Dollar") QueueCurrency->push (CurrencyDollar (rand () % 100, rand () % 99));
	else if (inputString == "Euro") QueueCurrency->push (CurrencyEuro (rand () % 100, rand () % 99));
	else if (inputString == "Rupee") QueueCurrency->push (CurrencyRupee (rand () % 100, rand () % 99));
	else if (inputString == "Yen") QueueCurrency->push (CurrencyYen (rand () % 100, rand () % 99));
	else if (inputString == "Yuan") QueueCurrency->push (CurrencyYuan (rand () % 100, rand () % 99));
	cout << endl;
	cout << "Currency Queue items:" << endl << QueueCurrency << endl << endl;
}

//******************************************************
// CommandLineUI::currencyQueuePop      
//      
// This is an example of the Queue pop method
//
// Pre: None
// Post: None
// Purpose: Pop an currency from the currency queue by calling pop();
//******************************************************
void CommandLineUI::currencyQueuePop ()
{
	if (QueueCurrency->empty ())
	{
		cout << "************************************" << endl;
		cout << "Queue is empty! Underflow Condition!" << endl;
		cout << "************************************" << endl << endl;
	}
	else
	{
		QueueCurrency->pop ();
		cout << "Currency Queue items:" << endl << QueueCurrency << endl << endl;
	}
}

//******************************************************
// CommandLineUI::currencyQueueClear         
//      
// This is an example of the list clear method
//
// Pre: None
// Post: None
// Purpose: Clears the currency queue by calling clear();
//******************************************************
void CommandLineUI::currencyQueueClear ()
{
	QueueCurrency->clear ();
	cout << "Currency Queue items:" << endl << QueueCurrency << endl << endl;
}

//******************************************************
// operator<<        
//******************************************************
template <class T>
std::ostream& operator<< (std::ostream &foo, List<T> *ListPtr)
{
	unsigned int i, j;
	unsigned int n = ListPtr->size ();
	if (ListPtr->empty ()) cout << "List is empty" << endl;
	else
		for (i = 0; i < n; i++)
		{
			foo << i + 1 << ". " << ListPtr->getValue (i) << endl;
		}
	return foo;
}
template <class T>
std::ostream& operator<< (std::ostream &foo, Queue<T> *ListPtr)
{
	int itemCount = 0;
	if (ListPtr->empty ()) cout << "Queue is empty" << endl;
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