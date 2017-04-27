#include "PMACS_Menu.h"
#include "PMACS_Utility.h"
#include "PMACS_Defines.h"
#include "PMACS_Globals.h"
#include "PMACS_Logger.h"
#include "PMACS_String.h"
#include "PMACS_Input.h"
#include "PMACS_Batch.h"
#include "PMACS_Date.h"
#include <iostream>
#include <iomanip>

void displayUtilityMenu()
{
	Menu utilityMenu;
	utilityMenu.setMenuName("PMACS Utilities Menu");
	utilityMenu.addMenuItem('1', "Change System Date");
	utilityMenu.addMenuItem('2', "Set Sequence Number");
	utilityMenu.addMenuItem('0', "Exit PMACS Utilities Menu");
	char selection = 0; // 0 as in NULL not '0' as in ascii zero

	while (selection != '0')
	{
		selection = utilityMenu.displayMenuGetSelection();

		switch (selection)
		{
		case '1':
			setSystemDate();
			break;
		case '2':
			// setSequenceNumber;
			break;
		case '0':
			return;
		default:
			break;
		}
	}
}

void displayPOSMenu()
{
	// Reset currentAccountNumber because we're leaving
	currentCustomerNumber = -1;
	currentCustomerIndex = -1;
}

void displayStoreMenu()
{
	Menu storeMenu;
	storeMenu.setMenuName("Store Management Menu");
	storeMenu.addMenuItem('1', "Finalize Store Sales for Store");
	storeMenu.addMenuItem('2', "Request Inventory for Store");
	storeMenu.addMenuItem('0', "Exit Store Management Menu");
	char selection = 0; // 0 as in NULL not '0' as in ascii zero

	while (selection != '0')
	{
		selection = storeMenu.displayMenuGetSelection();

		switch (selection)
		{
		case '1':
			// finalizeStoreSales;
			break;
		case '2':
			// requestStoreInventory;
			break;		
		case '0':
			return;
		default:
			break;
		}
	}
}

void displayInventoryMenu()
{
	Menu storeMenu;
	storeMenu.setMenuName("Inventory Management Menu");
	storeMenu.addMenuItem('1', "Add Item to Item Selections");
	storeMenu.addMenuItem('2', "Clear Item Selections");
	storeMenu.addMenuItem('3', "Display Item Selections - Simple");
	storeMenu.addMenuItem('4', "Display Item Selections - Full");
	storeMenu.addMenuItem('5', "Update Inventory Menu");
	storeMenu.addMenuItem('6', "Assign Selected Item(s) to Store");
	storeMenu.addMenuItem('7', "Remove Selected Item(s) from Store");
	storeMenu.addMenuItem('0', "Exit Inventory Management Menu");
	char selection = 0; // 0 as in NULL not '0' as in ascii zero

	while (selection != '0')
	{
		selection = storeMenu.displayMenuGetSelection();

		switch (selection)
		{
		case '1':
			selectItem();
			break;
		case '2':
			clearItemSelections();
			break;
		case '3':
			displayCurrentList();
			break;
		case '4':
			displayItemInfo();
			break;
		case '5':
			displayUpdateInventoryMenu();
			break;
		case '6':
			assignItemsToStore();
			break;
		case '7':
			removeItemsFromStore();
			break;
		case '0':
			return;
		default:
			break;
		}
	}
}

void selectItem()
{
	Menu selectItemMenu;
	selectItemMenu.setMenuName("Select Item Menu");
	selectItemMenu.addMenuItem('1', "Select Item by Number");
	selectItemMenu.addMenuItem('2', "Select Item by Name");
	selectItemMenu.addMenuItem('0', "Exit Select Item Menu");

	char selection = 0; // 0 as in NULL not '0' as in ascii zero

	int itemNumber = -1;
	std::string itemName = "";

	while (selection != '0')
	{
		selection = selectItemMenu.displayMenuGetSelection();

		switch (selection)
		{
		case '1':
			itemNumber = selectItemMenu.displayDialogGetEntryInt("Please enter the item number to add to selected items: ");
			if (itemNumber != -1)
				setCurrentItemByNumber(itemNumber);
			break;
		case '2':
			itemName = selectItemMenu.displayDialogGetEntryString("Please enter the item name to add to selected items: ");
			if (itemName != "")
				setCurrentItemByName(itemName);
			break;
		case '0':
			return;
		default:
			break;
		}
	}

}

void displaySalesMenu()
{
	Menu salesMenu;
	salesMenu.setMenuName("Sales Management Menu");
	salesMenu.addMenuItem('1', "Sales Report by Store");
	salesMenu.addMenuItem('2', "Sales Report by Item");
	salesMenu.addMenuItem('3', "Couple Items");
	salesMenu.addMenuItem('4', "Uncouple Items");
	salesMenu.addMenuItem('5', "Add Coupon");
	salesMenu.addMenuItem('6', "Delete Coupon");
	salesMenu.addMenuItem('7', "Update Item Discount");
	salesMenu.addMenuItem('0', "Exit Sales Management Menu");
	char selection = 0; // 0 as in NULL not '0' as in ascii zero

	while (selection != '0')
	{
		selection = salesMenu.displayMenuGetSelection();

		switch (selection)
		{
		case '1':
			// salesReportByStore
			break;
		case '2':
			// salesReportByItem
			break;
		case '3':
			// coupleItem
			break;
		case '4':
			// uncoupleItem
			break;
		case '5':
			// addCoupon
			break;
		case '6':
			// deleteCoupon
			break;
		case '7':
			// updateItemDiscount
			break;
		case '0':
			return;
		default:
			break;
		}
	}
}

void displayBatchMenu()
{
	Menu batchMenu;
	batchMenu.setMenuName("Offline Batch Menu");
	batchMenu.addMenuItem('1', "Run Offline Batch Process");
	batchMenu.addMenuItem('0', "Exit Offline Batch Menu");
	char selection = 0; // 0 as in NULL not '0' as in ascii zero

	bool batchResult;

	while (selection != '0')
	{
		selection = batchMenu.displayMenuGetSelection();

		switch (selection)
		{
		case '1':
			batchResult = runOfflineBatchProcess();
			if (!batchResult)
				batchMenu.displayDialogNoReturn("Offline batch process failed!  Please check PMACS_Log.txt");
			break;
		case '0':
			return;
		default:
			break;
		}
	}
}

void displayMainMenu()
{
	Menu mainMenu;
	mainMenu.setMenuName("Main Menu");
	mainMenu.addMenuItem('1', "Point of Sale Menu");
	mainMenu.addMenuItem('2', "Store Management Menu");
	mainMenu.addMenuItem('3', "Inventory Management Menu");
	mainMenu.addMenuItem('4', "Sales Management Menu");
	mainMenu.addMenuItem('5', "Offline Batch Menu");
	mainMenu.addMenuItem('6', "PMACS Utility Menu");
	mainMenu.addMenuItem('0', "Exit PMACS");
	char selection = 0; // 0 as in NULL not '0' as in ascii zero

	while (selection != '0')
	{
		selection = mainMenu.displayMenuGetSelection();

		switch (selection)
		{
		case '1':
			displayPOSMenu();
			break;
		case '2':
			displayStoreMenu();
			break;
		case '3':
			displayInventoryMenu();
			break;
		case '4':
			displaySalesMenu();
			break;
		case '5':
			displayBatchMenu();
			break;
		case '6':
			displayUtilityMenu();
			break;
		case '0':
			return;
		default:
			break;
		}
	}
}

void Menu::displayHeader()
{
	system("cls");

	std::cout << "==";	

	if (menuName == "")
		std::cout << "";
	else
		std::cout << menuName;

	std::cout << "==" << std::endl;

	std::cout << "** Please press enter to cancel any prompt **" << std::endl;

	std::cout << "System Date: " << systemDate.GetDate() << std::endl;


	std::cout << "Store Number: ";
	if (currentStoreNumber == -1)
		std::cout << "NOT SET";
	else
		std::cout << currentStoreNumber;
	
	std::cout << std::endl;

	std::cout << "Cashier Number: ";
	if (currentCashierNumber == -1)
		std::cout << "NOT SET";
	else
		std::cout << currentCashierNumber;

	std::cout << std::endl;

	std::cout << "Customer Number: ";
	if (currentCustomerNumber == -1)
		std::cout << "NOT SET";
	else
		std::cout << currentCustomerNumber;

	std::cout << std::endl;

	std::cout << "Customer Name: ";
	if (currentCustomerNumber == -1)
		std::cout << "NOT SET";
	else
		std::cout << customer_table[currentCustomerIndex].name;

	std::cout << std::endl;

	std::cout << "Customer Address: ";
	if (currentCustomerNumber == -1)
		std::cout << "NOT SET";
	else
		std::cout << customer_table[currentCustomerIndex].address;

	/*std::cout << std::endl;

	std::cout << "Item Number: ";
	if (currentItemListSize == 0)
		std::cout << "NOT SET";
	else
		std::cout << warehouse_table[currentItemIndex].item_number;*/

	std::cout << std::endl;

	std::cout << std::endl << std::endl;
	
}

void Menu::displayFooter()
{
	std::cout << std::endl << std::endl;

	std::cout << "==";

	std::cout << errorMessage;

	std::cout << "==" << std::endl;
}

void Menu::setMessage(std::string in_string)
{
	errorMessage = in_string;
}

void Menu::setMenuName(std::string in_string)
{
	menuName = in_string;
}

void Menu::setErrorMessage(std::string in_string)
{
	errorMessage = in_string;
}

void Menu::addMenuItem(char selectKey, std::string menuText)
{
	menuItemKey.push_back(selectKey);
	menuItemText.push_back(menuText);
}

void Menu::resetErrorMessage()
{
	errorMessage = "Welcome to PMACS - Errors displayed down here";
}

void Menu::displayMenuNoReturn()
{
	displayHeader();
	
	std::cout << "== Please select from one of the following options: == \n";
	
	for (int i = 0; i < menuItemKey.size(); i++)
	{
		std::cout << "[" << menuItemKey[i] << "]   " << menuItemText[i] << std::endl;
	}

	displayFooter();
}

char Menu::displayMenuGetSelection()
{
	displayMenuNoReturn();

	bool validateResult = false;
	bool foundKey = false;

	std::string getInput;

	while (!validateResult || !foundKey)
	{
		
		std::getline(cin, getInput);
		validateResult = validateInput(getInput, g_type_char_any, 1, 1);
		foundKey = findMenuItemKey(getInput[0]);
		if (!validateResult || !foundKey)
		{
			setErrorMessage("Error:  You did not enter a valid option.  Please try again.");
			displayMenuNoReturn();
		}		

	}
	
	resetErrorMessage();
	return getInput[0];
}

void Menu::displayDialogNoReturn(std::string in_string, int expected_type)
{
	displayHeader();

	std::cout << " ============== Message ============== \n";
	std::cout << in_string << std::endl;
	if (expected_type == -1)
		std::cout << " ============ Press Enter ============ \n";
	else
		std::cout << " ===================================== \n";
	
	displayFooter();

	std::string dummy;
	if (expected_type == -1)
		std::getline(cin, dummy);
}

int Menu::displayDialogGetEntryInt(std::string in_string, int max_length)
{
	displayDialogNoReturn(in_string, g_type_int);

	bool validateResult = false;
	

	std::string getInput;

	while (!validateResult)
	{
		std::getline(cin, getInput);

		if (getInput == "")
			return -1;

		validateResult = validateInput(getInput, g_type_int, max_length, 0);
		if (!validateResult)
		{
			setErrorMessage("Error:  Your input could not be validated.  Please try again.");
			displayDialogNoReturn(in_string, g_type_int);
		}
	}	

	resetErrorMessage();
	return StringToInt(getInput);
}

double Menu::displayDialogGetEntryDouble(std::string in_string, int max_length)
{
	displayDialogNoReturn(in_string, g_type_double);

	bool validateResult = false;


	std::string getInput;

	while (!validateResult)
	{
		std::getline(cin, getInput);

		if (getInput == "")
			return -1;

		validateResult = validateInput(getInput, g_type_double, max_length, 0);
		if (!validateResult)
		{
			setErrorMessage("Error:  Your input could not be validated.  Please try again.");
			displayDialogNoReturn(in_string, g_type_double);
		}
	}

	resetErrorMessage();
	return StringToDouble(getInput);
}


long long Menu::displayDialogGetEntryLongLong(std::string in_string, int max_length)
{
	displayDialogNoReturn(in_string, g_type_longlong);

	bool validateResult = false;

	std::string getInput;
	
	

	while (!validateResult)
	{
		std::getline(cin, getInput);

		if (getInput == "")
			return -1;

		validateResult = validateInput(getInput, g_type_longlong, max_length, 0);
		if (!validateResult)
		{
			setErrorMessage("Error:  Your input could not be validated.  Please try again.");
			displayDialogNoReturn(in_string, g_type_longlong);
		}
	}

	resetErrorMessage();
	return StringToLongLong(getInput);
}

std::string Menu::displayDialogGetEntryString(std::string in_string, int max_length)
{
	displayDialogNoReturn(in_string, g_type_string_any);

	bool validateResult = false;

	std::string getInput;
	
	while (!validateResult)
	{
		std::getline(cin, getInput);

		if (getInput == "")
			return "";

		validateResult = validateInput(getInput, g_type_string_any, max_length, 0);
		if (!validateResult)
		{
			setErrorMessage("Error:  Your input could not be validated.  Please try again.");
			displayDialogNoReturn(in_string, g_type_string_any);
		}
	}

	resetErrorMessage();
	return getInput;
}

char Menu::displayDialogGetEntryChar(std::string in_string)
{
	displayDialogNoReturn(in_string, g_type_char_any);

	bool validateResult = false;

	std::string getInput;

	while (!validateResult)
	{
		std::getline(cin, getInput);
		validateResult = validateInput(getInput, g_type_char_any, 1, 0);

		if (in_string == "")
			return 0;
		
		if (!validateResult)
		{
			setErrorMessage("Error:  Your input could not be validated.  Please try again.");
			displayDialogNoReturn(in_string, g_type_char_any);
		}
	}

	resetErrorMessage();
	return getInput[0];
}

bool Menu::findMenuItemKey(char in_key)
{
	for (int i = 0; i < menuItemKey.size(); i++)
	{
		if (menuItemKey[i] == in_key)
			return true;
	}

	return false;
}

void displayUpdateInventoryMenu()
{
	Menu updateItemMenu;
	updateItemMenu.setMenuName("Update Item Menu");
	updateItemMenu.addMenuItem('1', "Change Item Status");
	updateItemMenu.addMenuItem('2', "Change Vendor Number");
	updateItemMenu.addMenuItem('3', "Change Item Dosage");
	updateItemMenu.addMenuItem('4', "Change Item Name");
	updateItemMenu.addMenuItem('5', "Change Item Description");
	updateItemMenu.addMenuItem('6', "Change Warehouse Reorder Quantity");
	updateItemMenu.addMenuItem('7', "Change Warehouse Reorder Level");
	updateItemMenu.addMenuItem('8', "Change Base Price");
	updateItemMenu.addMenuItem('0', "Exit Sales Management Menu");
	char selection = 0; // 0 as in NULL not '0' as in ascii zero

	while (selection != '0')
	{
		selection = updateItemMenu.displayMenuGetSelection();

		switch (selection)
		{
		case '1':
			changeItemStatus();
			break;
		case '2':
			changeVendorNumber();
			break;
		case '3':
			changeItemDosage();
			break;
		case '4':
			changeItemName();
			break;
		case '5':
			changeItemDescription();
			break;
		case '6':
			changeWarehouseReorderQuantity();
			break;
		case '7':
			changeWarehouseReorderLevel();
			break;
		case '8':
			changeBasePrice();
			break;
		case '0':
			return;
		default:
			break;
		}
	}
}