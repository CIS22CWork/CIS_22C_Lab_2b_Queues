#include <sstream>
#include <limits>
#include "Currency.h"
#include "CurrencyDollar.h"
#include "CurrencyEuro.h"
#include "CurrencyRupee.h"
#include "CurrencyYen.h"
#include "CurrencyYuan.h"
#include "Queue.h"

class CommandLineUI
{
private:
	Queue<int>* QueueInt;
	Queue<std::string>* QueueString;
	Queue<Currency>* QueueCurrency;
	int menuOption;
	int currentMenu;
public:
	CommandLineUI (Queue<int> *QueueObjInt, Queue<std::string> *QueueObjString, Queue<Currency> *QueueObjCurrency);
	void enterLoop ();
	void intQueuePush ();
	void intQueuePush2 ();
	void intQueuePop ();
	void intQueueClear ();
	void stringQueuePush ();
	void stringQueuePush2 ();
	void stringQueuePop ();
	void stringQueueClear ();
	void currencyQueuePush ();
	void currencyQueuePush2 ();
	void currencyQueuePop ();
	void currencyQueueClear ();
};