#include "HashTable.h"

/// <summary>
/// constructor initializes values and sets tableSize = to specified paramater value
/// 
/// precondition: hashtable is uninitialized
/// postcondition: hash table is initialized
/// </summary>
/// <typeparam name="DataType"></typeparam>
/// <typeparam name="KeyType"></typeparam>
/// <param name="initTableSize"></param>
template <typename DataType, typename KeyType>
HashTable<DataType, KeyType>::HashTable(int initTableSize)
{
	tableSize = initTableSize;
	dataTable = new BSTree<DataType, KeyType>[tableSize];
	dataSize = 0;
}


/// <summary>
/// copy constructor copies values from another table and deep copies the table contents
/// 
/// precondition: hash table is not initialized
/// postcondition: hash table is initialized with the values of the other hash table
/// </summary>
/// <typeparam name="DataType"></typeparam>
/// <typeparam name="KeyType"></typeparam>
/// <param name="other"></param>
template <typename DataType, typename KeyType>
HashTable<DataType, KeyType>::HashTable(const HashTable& other)
{
	this->tableSize = other.tableSize;
	this->dataTable = new BSTree[tableSize];
	this->dataSize = other->dataSize;
	for (int i = 0; i < other.tableSize; i++)
	{
		this->datatable[i] = other.dataTable[i];
	}
}

/// <summary>
/// assignment operator overload copies values from another table and deep copies the table contents
/// 
/// precondition: hash table data members do not equal other hash table
/// postcondition: hash table data members equal other hash table
/// </summary>
/// <typeparam name="DataType"></typeparam>
/// <typeparam name="KeyType"></typeparam>
/// <param name="other"></param>
/// <returns></returns>
template <typename DataType, typename KeyType>
HashTable<DataType, KeyType>& HashTable<DataType, KeyType>::operator = (const HashTable& other)
{
	this->tableSize = other.tableSize;
	this->dataTable = new BSTree[tableSize];
	this->dataSize = other->dataSize;
	for (int i = 0; i < other.tableSize; i++)
	{
		this->datatable[i] = other.dataTable[i];
	}
}

/// <summary>
/// destructor deallocates the memory in the hash table 
/// 
/// precondition: memory is allocated in the hash table
/// postcondition: all memory is deallocated
///
/// </summary>
/// <typeparam name="DataType"></typeparam>
/// <typeparam name="KeyType"></typeparam>
template <typename DataType, typename KeyType>
HashTable<DataType, KeyType>::~HashTable()
{
	delete[] dataTable;
}


/// <summary>
/// function hashes the key of the dataitem and uses the BSTree insert function to insert the value at the tree located at that index
/// and also increments dataSize
/// 
/// precondition: data item is not inserted into the tree
/// postcondition: data item is inserted in the tree
/// </summary>
/// <typeparam name="DataType"></typeparam>
/// <typeparam name="KeyType"></typeparam>
/// <param name="newDataItem"></param>
template <typename DataType, typename KeyType>
void HashTable<DataType, KeyType>::insert(const DataType& newDataItem)
{
	int index = newDataItem.hash(newDataItem.getKey()) % tableSize;
	
	dataTable[index].insert(newDataItem);
	dataSize++;

}

/// <summary>
/// helper function accesses the data items hash function to hash the key. 
/// 
/// precondition: Key is not hashed
/// postcondition: Key is hashed
/// </summary>
/// <typeparam name="DataType"></typeparam>
/// <typeparam name="KeyType"></typeparam>
/// <param name="tempKey"></param>
/// <returns></returns>
template <typename DataType, typename KeyType>
 unsigned int  HashTable<DataType, KeyType>::hash(const KeyType& tempKey) const
{
	DataType tempData;
	return tempData.hash(tempKey);
}


/// <summary>
/// function, if table isnt empty, locates a data item by hashing the key and using the BSTree at that indexs' remove function 
///  and also decrements dataSize
/// 
///  precondition: data item remains in the table
///  postcondition: data item is removed from the table 
/// </summary>
/// <typeparam name="DataType"></typeparam>
/// <typeparam name="KeyType"></typeparam>
/// <param name="deleteKey"></param>
/// <returns></returns>
template <typename DataType, typename KeyType>
bool HashTable<DataType, KeyType>::remove(const KeyType& deleteKey)
{
	if (isEmpty())
	{
		return false;
	}
	else
	{
		int index = hash(deleteKey) % tableSize;
		if (dataTable[index].remove(deleteKey))
		{
			dataSize--;
			return true;
		}
	}

	return false;
}


/// <summary>
/// function uses hashed key index to retrieve a value using the tree at that index's retrieve function
/// 
/// precondition: search data item is not stored in returnItem
/// postcondition: search data item is stored in returnItem
/// </summary>
/// <typeparam name="DataType"></typeparam>
/// <typeparam name="KeyType"></typeparam>
/// <param name="searchKey"></param>
/// <param name="returnItem"></param>
/// <returns></returns>
template <typename DataType, typename KeyType>
bool HashTable<DataType, KeyType>::retrieve(const KeyType& searchKey, DataType& returnItem) const
{
	
	int index = hash(searchKey) % tableSize;
	
	if (dataTable[index].retrieve(searchKey, returnItem))
	{
		return true;
	}

	return false;
}


/// <summary>
/// function clears each tree in the table
/// 
/// precondition: Table has memory allocated
/// postcondition: Table memory is cleared
/// </summary>
/// <typeparam name="DataType"></typeparam>
/// <typeparam name="KeyType"></typeparam>
template <typename DataType, typename KeyType>
void HashTable<DataType, KeyType>::clear()
{
	for (int i = 0; i < tableSize; i++)
	{
		dataTable[i].clear();
	}

}

/// <summary>
/// function checks if table is empty using dataSize
/// 
/// precondition: table is not empty
/// postcondition: table is empty
/// </summary>
/// <typeparam name="DataType"></typeparam>
/// <typeparam name="KeyType"></typeparam>
/// <returns></returns>
template <typename DataType, typename KeyType>
bool HashTable<DataType, KeyType>::isEmpty() const
{
	if (dataSize == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}


/// <summary>
/// function outputs the table structure by outputting each tree key set
/// 
/// precondition: structure is not shown
/// postcondition: structure is shown 
/// </summary>
/// <typeparam name="DataType"></typeparam>
/// <typeparam name="KeyType"></typeparam>
template <typename DataType, typename KeyType>
void HashTable<DataType, KeyType>::showStructure() const 
{
	for (int i = 0; i < tableSize; ++i) 
	{
		cout << i << ": ";
		dataTable[i].writeKeys();
		cout << endl;
	}
}


