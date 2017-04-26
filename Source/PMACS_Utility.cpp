#include "PMACS_Globals.h"

int getSequenceNumber(int seq_index)
{
	return sequenceNumber[seq_index];
}

int getRecordLength(int rec_index)
{
	return recordLength[rec_index];
}

// UNTESTED !!!!!!
int findStore(int store_number)
{
	for (int i = 0; i < store_data_table.size(); i++)
	{
		if (store_data_table[i].store_number == store_number)
			return i;
	}

	return -1;
}


int findStoreItem(int item_number, int store_number)
{
	for (int i = 0; i < store_inventory_table.size(); i++)
	{
		if (store_inventory_table[i].item_number == item_number && store_inventory_table[i].store_number == store_number)
			return i;
	}

	return -1;
}

int findWarehouseItem(int item_number)
{
	for (int i = 0; i < warehouse_table.size(); i++)
	{
		if (warehouse_table[i].item_number == item_number)
			return i;
	}

	return -1;
}

int findCustomer(int account_number)
{
	for (int i = 0; i < customer_table.size(); i++)
	{
		if (customer_table[i].account_number == account_number)
			return i;
	}

	return -1;
}

bool setCurrentCustomer(int account_number)
{
	int findResult = findCustomer(account_number);
	if (findResult == -1)
	{
		Plog.logError("setCurrentCustomer", "Failed to set currentCustomerAccount, account not found");
		return false;
	}

	currentCustomerNumber = account_number;
	currentCustomerIndex = findResult;

	return true;
}

bool setCurrentStore(int store_number)
{
	int findResult = findStore(store_number);
	if (findResult == -1)
	{
		Plog.logError("setCurrentStore", "Failed to set currentCustomerAccount, store not found");
		return false;
	}

	currentStoreNumber = store_number;
	currentStoreIndex = findResult;

	return true;
}

bool setCurrentCashier(int cashier_number)
{
	currentCashierNumber = cashier_number;	

	return true;
}


//give itemnumber and character to get list of all containing the item
vector<int> getStoreItemList(int item_number)
{
	vector<int> list; 

	for (int i = 0; i < store_inventory_table.size(); i++)						//for all the store items
	{
		if (store_inventory_table[i].item_number == item_number)				//match number
		{
			list.push_back(i);													//add index to list
		}
	}
	return list;
}