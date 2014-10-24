#include "ChainedHashTable.h"
#include "LinearHashTable.h"
#include <stdlib.h>
#include <iostream>

using namespace std;
using namespace ods;


int main() {
  // Test ChainedHashTable with new Hash function
  ChainedHashTable<int> table1;
  for (int i = 0; i < 700; i++) {
    table1.add(rand() % 1000);
  }
  DLList<int> longest_list = table1.GetLongestList();
  
  cout << "Test ChainedHashTable with get longest list methood and new hash function." << endl;
  cout << "Longest list length with loadfactor = 1: " << longest_list.size() << endl;

  table1.SetLoadFactor(5); // change load factor which calls resize() and rehashes
  longest_list = table1.GetLongestList(); // get new longest list

  cout << "Longest list length with loadfactor = 5: " << longest_list.size() << endl;
  cout << endl;

  // test Double backed LinearHashTable
  LinearHashTable<int> lTable1;
  for (int i = 0; i < 100; i++) { // add 100 random values
    lTable1.add(rand() % 500);
  }

  cout << "Test double backed LinearHashTable." << endl;
  cout << "Find and resize functions are called by the add and remove functions." << endl;
  cout << "LinearHashTable size after 100 add() calls: " << lTable1.size() << endl;

  // test remove functions by removing 100 random numbers
  for (int i = 0; i < 100; i++) {
    lTable1.remove(rand() % 500);
  }

  cout << "LinearHashTable size after 100 random remove() calls: " << lTable1.size() << endl;

 
  return 0;
}
