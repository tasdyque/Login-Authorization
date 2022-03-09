// HashTable.h

#ifndef HASHTABLE_H
#define HASHTABLE_H


#include <stdexcept>
#include <iostream>

///reference to the BSTree class via file path
#include <C:\c++\CSC 2201 Lab 2\BSTree.cpp>

using namespace std;

/// <summary>
/// Templated Hash Table class
/// </summary>
/// <typeparam name="DataType"></typeparam>
/// <typeparam name="KeyType"></typeparam>
template <typename DataType, typename KeyType>
class HashTable {
  public:
    /// <summary>
    /// constructor with a required initial table size 
    /// </summary>
    /// <param name="initTableSize"></param>
    HashTable(int initTableSize);

    /// <summary>
    /// copy constructor 
    /// </summary>
    /// <param name="other"></param>
    HashTable(const HashTable& other);

    /// <summary>
    /// assignment operator overload
    /// </summary>
    /// <param name="other"></param>
    /// <returns></returns>
    HashTable& operator=(const HashTable& other);

    ///destructor
    ~HashTable();

    /// <summary>
    /// insert function inserts a data item into the hash table with hash function and chaining to deal with collisions
    /// </summary>
    /// <param name="newDataItem"></param>
    void insert(const DataType& newDataItem);

    /// <summary>
    /// remove function removes a specified data item from the table
    /// </summary>
    /// <param name="deleteKey"></param>
    /// <returns></returns>
    bool remove(const KeyType& deleteKey);

    /// <summary>
    /// function that hashes the key
    /// </summary>
    /// <param name="temp"></param>
    /// <returns></returns>
    unsigned int hash(const KeyType& temp) const;

    /// <summary>
    /// function retrieves a data item with specified key, copies it to returnItem
    /// </summary>
    /// <param name="searchKey"></param>
    /// <param name="returnItem"></param>
    /// <returns></returns>
    bool retrieve(const KeyType& searchKey, DataType& returnItem) const;

    /// <summary>
    /// function clears the table
    /// </summary>
    void clear();

    /// <summary>
    /// function checks if table is empty
    /// </summary>
    /// <returns></returns>
    bool isEmpty() const;

    /// <summary>
    /// function outputs the hashtable structure
    /// </summary>
    void showStructure() const;


  private:

    /// <summary>
    /// date item stores the size of the table
    /// </summary>
    int tableSize;
    
    /// <summary>
    /// data member stores the number of data items in a table
    /// </summary>
    int dataSize; //records how many data values there are, used to maintain isEmpty function

    /// <summary>
    /// table of binary search trees
    /// </summary>
    BSTree<DataType, KeyType>* dataTable;

};

#endif	
