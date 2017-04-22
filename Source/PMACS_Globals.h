#ifndef PMACS_GLOBALS_H
#define PMACS_GLOBALS_H
#include <vector>
#include "PMACS_Data_Structures.h"
#include "PMACS_Logger.h"
extern std::vector<WarehouseItemData> warehouse_table;
extern std::vector<StoreInventory> store_inventory_table;
extern std::vector<StoreData> store_data_table;
extern std::vector<Customer> customer_table;
extern std::vector<Coupon> coupon_table;
extern std::vector<Transaction> transaction_table;
extern Logger Plog;
#endif