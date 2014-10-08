#include "DLList.h"
#include <stdlib.h>
#include <iostream>

using namespace std;
using namespace ods;


int main() {
  // Test all of the functions that were added in assignment2

  // Test IsPalendrome() function
  DLList<int> palList;
  palList.add(4);
  palList.add(2);
  palList.add(3);
  palList.add(2);
  palList.add(1);

  cout << "IsPalendrome() test" << endl;
  cout << "should return false (0): " << palList.IsPalindrome() << endl;
  palList.set(0, 1);
  cout << "should return true (1):  " << palList.IsPalindrome() << endl;
  palList.add(2, 3);
  cout << "should return true (1):  " << palList.IsPalindrome() << endl;
  cout << endl;

  // Test Rotate() function
  cout << "Rotate() test" << endl;
  DLList<int> rotList;
  rotList.add(3);
  rotList.add(4);
  rotList.add(5);
  rotList.add(1);
  rotList.add(2);
  rotList.Rotate(3);
  cout << "rot[0]: " << rotList.get(0) << endl;
  cout << "rot[1]: " << rotList.get(1) << endl;
  cout << "rot[2]: " << rotList.get(2) << endl;
  cout << "rot[3]: " << rotList.get(3) << endl;
  cout << "rot[3]: " << rotList.get(4) << endl;
  cout << endl;

  // Test Absorb() fuction
  DLList<int> absorbList;
  absorbList.add(1);
  absorbList.add(2);

  DLList<int> absorbList2;
  absorbList2.add(3);
  absorbList2.add(4);
  cout << "Absorb() test" << endl;
  cout << "Size l1: " << absorbList.size() << endl;
  cout << "Size l2: " << absorbList2.size() << endl;
  DLList<int>* pL2 = &absorbList2;
  absorbList.Absorb(pL2);
  cout << "Size l1 after absorb: " << absorbList.size() << endl;
  cout << "Size l2 after absorb: " << absorbList2.size() << endl;
  cout << "l1[0]: " << absorbList.get(0) << endl;
  cout << "l1[1]: " << absorbList.get(1) << endl;
  cout << "l1[2]: " << absorbList.get(2) << endl;
  cout << "l1[3]: " << absorbList.get(3) << endl;
  cout << endl;

  // Test deal() function
  DLList<int> dealList;
  dealList.add(1);
  dealList.add(2);
  dealList.add(3);
  dealList.add(4);
  dealList.add(5);
  dealList.add(6);
  dealList.add(7);
  dealList.add(8);
  dealList.add(9);
  dealList.add(10);
  dealList.add(11);

  DLList<int> dealList2 = dealList.deal();
  cout << "deal() test" << endl;
  cout << "Size of dealList2 (list returned by the function):" << dealList2.size() << endl;
  cout << dealList2.get(0) << endl;
  cout << dealList2.get(1) << endl;
  cout << dealList2.get(2) << endl;
  cout << dealList2.get(3) << endl;
  cout << dealList2.get(4) << endl;
  cout << endl;
  cout << "Size of dealList (original list that was delt from):" << dealList.size() << endl;
  cout << dealList.get(0) << endl;
  cout << dealList.get(1) << endl;
  cout << dealList.get(2) << endl;
  cout << dealList.get(3) << endl;
  cout << dealList.get(4) << endl;
  cout << dealList.get(5) << endl;

  return 0;
}
