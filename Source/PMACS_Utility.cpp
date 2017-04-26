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

<<<<<<< HEAD
int findStoreItem(int item_number, int store_number)
=======

int findStoreItem(int item_number)
>>>>>>> af0aa398b0bf1bbe56cf615a8e1c37c016751a63
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

<<<<<<< HEAD
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
=======
//give number and store
int findStoreItem(int item_number, int storeNumber)
{
	for (int i = 0; i < store_inventory_table.size(); i++)						//for all the store items
	{
		if (store_inventory_table[i].store_number == storeNumber)				//match store
		{
			if (store_inventory_table[i].item_number == item_number)			//match item
			{
				return i;														//return index
			}
		}
	}
	return -1;
}

//give itemnumber and character to get list of all containing the item
vector<int> getStoreItemList(int item_number)
{
	vector<int> list; 

	for (int i = 0; i < store_inventory_table.size(); i++)						//for all the store items
	{
		if (store_inventory_table[i].item_number == item_number);				//match number
		{
			list.push_back(i);													//add index to list
		}
	}
	return list;
>>>>>>> af0aa398b0bf1bbe56cf615a8e1c37c016751a63
}