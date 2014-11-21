#include <iostream>
#include "ChainedHashTable.h"
#include "DataStructureTester.h"
#include "LinearHashTable.h"
#include "BinarySearchTree.h"
#include "RedBlackTree.h"

using namespace std;
using namespace ods;

int main() {

  int sa1 = 0;
  int sa2 = 0;
  int sa3 = 0;
  int sa4 = 0;
  int sr1 = 0;
  int sr2 = 0;
  int sr3 = 0;
  int sr4 = 0;

  int ms1 = 0;
  int mr1 = 0;
  int ms2 = 0;
  int ms3 = 0;
  int ms4 = 0;
  int mr2 = 0;
  int mr3 = 0;
  int mr4 = 0;

  int sf1 = 0;
  int sf2 = 0;
  int sf3 = 0;
  int sf4 = 0;
  int rf1 = 0;
  int rf2 = 0;
  int rf3 = 0;
  int rf4 = 0;

  for (int x = 1; x <= 100; x++) {
    DataStructureTester<BinarySearchTree<BSTNode1<int>, int> > test;
    DataStructureTester<RedBlackTree<RedBlackNode1<int>, int> > test2;
    DataStructureTester<ChainedHashTable<int>> test3;
    DataStructureTester<LinearHashTable<int>> test4;

    cout << "Iteration: " << x << endl;

    ///////////////
    cout << "Testing BinarySearchTree Sequential Add..." << endl;
    int t1 = test.DoSequentialAdd(0, 100000, 2);
    cout << "Done. Time: " << t1 << "ms" << endl;
    sa1 += t1;

    cout << "Testing BinarySearchTree Sequential Find..." << endl;
    int r1 = test.DoSequentialFind(0, 100000, 2);
    cout << "Done. Time: " << r1 << "ms" << endl;
    sf1 += r1;

    cout << "Testing BinarySearchTree Sequential Remove..." << endl;
    r1 = test.DoSequentialRemove(0, 100000, 2);
    cout << "Done. Time: " << r1 << "ms" << endl;
    sr1 += r1;

    cout << "Testing BinarySearchTree Random Add..." << endl;
    t1 = test.DoRandomAdd(50000);
    cout << "Done. Time: " << t1 << "ms" << endl;
    ms1 += t1;

    cout << "Testing BinarySearchTree Random Find..." << endl;
    r1 = test.DoRandomFind(50000);
    cout << "Done. Time: " << r1 << "ms" << endl;
    rf1 += r1;

    cout << "Testing BinarySearchTree Random Remove..." << endl;
    r1 = test.DoRandomRemove(50000);
    cout << "Done. Time: " << r1 << "ms" << endl;
    mr1 += r1;

    ///////////////
    cout << "Testing RedBlackTree Sequential Add..." << endl;
    int t2 = test2.DoSequentialAdd(0, 100000, 2);
    cout << "Done. Time: " << t2 << "ms" << endl;
    sa2 += t2;

    cout << "Testing RedBlackTree Sequential Find..." << endl;
    int r2 = test2.DoSequentialFind(0, 100000, 2);
    cout << "Done. Time: " << r2 << "ms" << endl;
    sf2 += r2;

    cout << "Testing RedBlackTree Sequential Remove..." << endl;
    r2 = test2.DoSequentialRemove(0, 100000, 2);
    cout << "Done. Time: " << r2 << "ms" << endl;
    sr2 += r2;

    cout << "Testing RedBlackTree Random Add..." << endl;
    t2 = test2.DoRandomAdd(50000);
    cout << "Done. Time: " << t2 << "ms" << endl;
    ms2 += t2;

    cout << "Testing RedBlackTree Random Find..." << endl;
    r2 = test2.DoRandomFind(50000);
    cout << "Done. Time: " << r2 << "ms" << endl;
    rf2 += r2;

    cout << "Testing RedBlackTree Random Remove..." << endl;
    r2 = test2.DoRandomRemove(50000);;
    cout << "Done. Time: " << r2 << "ms" << endl;
    mr2 += r2;

    //////////////
    cout << "Testing ChainedHashTable Sequential Add..." << endl;
    int t3 = test3.DoSequentialAdd(0, 100000, 2);
    cout << "Done. Time: " << t3 << "ms" << endl;
    sa3 += t3;

    cout << "Testing ChainedHashTable Sequential Find..." << endl;
    int r3 = test3.DoSequentialFind(0, 100000, 2);
    cout << "Done. Time: " << r3 << "ms" << endl;
    sf3 += r3;

    cout << "Testing ChainedHashTable Sequential Remove..." << endl;
    r3 = test3.DoSequentialRemove(0, 100000, 2);
    cout << "Done. Time: " << r3 << "ms" << endl;
    sr3 += r3;

    cout << "Testing ChainedHashTable Random Add..." << endl;
    t3 = test3.DoRandomAdd(50000);
    cout << "Done. Time: " << t3 << "ms" << endl;
    ms3 += t3;

    cout << "Testing ChainedHashTable Random Find..." << endl;
    r3 = test3.DoRandomFind(50000);
    cout << "Done. Time: " << r3 << "ms" << endl;
    rf3 += r3;

    cout << "Testing ChainedHashTable Random Remove..." << endl;
    r3 = test3.DoRandomRemove(50000);
    cout << "Done. Time: " << r3 << "ms" << endl;
    mr3 += r3;

    //////////////
    cout << "Testing LinearHashTable Sequential Add..." << endl;
    int t4 = test4.DoSequentialAdd(0, 100000, 2);
    cout << "Done. Time: " << t4 << "ms" << endl;
    sa4 += t4;

    cout << "Testing LinearHashTable Sequential Find..." << endl;
    int r4 = test4.DoSequentialFind(0, 100000, 2);
    cout << "Done. Time: " << r4 << "ms" << endl;
    sf4 += r4;

    cout << "Testing LinearHashTable Sequential Remove..." << endl;
    r4 = test4.DoSequentialRemove(0, 100000, 2);
    cout << "Done. Time: " << r4 << "ms" << endl;
    sr4 += r4;

    cout << "Testing LinearHashTable Random Add..." << endl;
    t4 = test4.DoRandomAdd(50000);
    cout << "Done. Time: " << t4 << "ms" << endl;
    ms4 += t4;

    cout << "Testing LinearHashTable Random Find..." << endl;
    r4 = test4.DoRandomFind(50000);
    cout << "Done. Time: " << r4 << "ms" << endl;
    rf4 += r4;

    cout << "Testing LinearHashTable Random Remove..." << endl;
    r4 = test4.DoRandomRemove(50000);
    cout << "Done. Time: " << r4 << "ms" << endl;
    mr4 += r4;

    cout << endl;
  }

  sa1 = sa1 / 100;
  sa2 = sa2 / 100;
  sa3 = sa3 / 100;
  sa4 = sa4 / 100;

  cout << endl;
  cout << "Average BinarySearchTree Sequential Add Time: " << sa1 << "ms" << endl;
  cout << "Average RedBlackTree Sequential Add Time:     " << sa2 << "ms" << endl;
  cout << "Average ChainedHashTable Sequential Add Time: " << sa3 << "ms" << endl;
  cout << "Average LinearHashTable Sequential Add Time:  " << sa4 << "ms" << endl;

  sr1 = sr1 / 100;
  sr2 = sr2 / 100;
  sr3 = sr3 / 100;
  sr4 = sr4 / 100;

  cout << endl;
  cout << "Average BinarySearchTree Sequential Remove Time: " << sr1 << "ms" << endl;
  cout << "Average RedBlackTree Sequential Remove Time:     " << sr2 << "ms" << endl;
  cout << "Average ChainedHashTable Sequential Remove Time: " << sr3 << "ms" << endl;
  cout << "Average LinearHashTable Sequential Remove Time:  " << sr4 << "ms" << endl;

  ms1 = ms1 / 100;
  ms2 = ms2 / 100;
  ms3 = ms3 / 100;
  ms4 = ms4 / 100;

  cout << endl;
  cout << "Average BinarySearchTree Random Add Time: " << ms1 << "ms" << endl;
  cout << "Average RedBlackTree Random Add Time:     " << ms2 << "ms" << endl;
  cout << "Average ChainedHashTable Random Add Time: " << ms3 << "ms" << endl;
  cout << "Average LinearHashTable Random Add Time:  " << ms4 << "ms" << endl;

  mr1 = mr1 / 100;
  mr2 = mr2 / 100;
  mr3 = mr3 / 100;
  mr4 = mr4 / 100;

  cout << endl;
  cout << "Average BinarySearchTree Random Remove Time: " << mr1 << "ms" << endl;
  cout << "Average RedBlackTree Random Remove Time:     " << mr2 << "ms" << endl;
  cout << "Average ChainedHashTable Random Remove Time: " << mr3 << "ms" << endl;
  cout << "Average LinearHashTable Random Remove Time:  " << mr4 << "ms" << endl;

  sf1 = sf1 / 100;
  sf2 = sf2 / 100;
  sf3 = sf3 / 100;
  sf4 = sf4 / 100;

  cout << endl;
  cout << "Average BinarySearchTree Sequential Find Time: " << sf1 << "ms" << endl;
  cout << "Average RedBlackTree Sequential Find Time:     " << sf2 << "ms" << endl;
  cout << "Average ChainedHashTable Sequential Find Time: " << sf3 << "ms" << endl;
  cout << "Average LinearHashTable Sequential Find Time:  " << sf4 << "ms" << endl;

  rf1 = rf1 / 100;
  rf2 = rf2 / 100;
  rf3 = rf3 / 100;
  rf4 = rf4 / 100;

  cout << endl;
  cout << "Average BinarySearchTree Random Find Time: " << rf1 << "ms" << endl;
  cout << "Average RedBlackTree Random Find Time:     " << rf2 << "ms" << endl;
  cout << "Average ChainedHashTable Random Find Time: " << rf3 << "ms" << endl;
  cout << "Average LinearHashTable Random Find Time:  " << rf4 << "ms" << endl;

  return 0;
}


/*
RESULTS

BinarySearchTree:
  SequentialAdd: 36098ms
  SequentialRemove: 15ms
  SequentialFind: 35881ms
  RandomAdd: 51ms
  RandomRemove: 40ms
  RandomFind: 32ms

RedBlackTree:
  SequentialAdd: 49ms
  SequentialRemove: 46ms
  SequentialFind: 17ms
  RandomAdd: 51ms
  RandomRemove: 41ms
  RandomFind: 31ms

ChainedHasTable:
  SequentialAdd: 1619ms
  SequentialRemove: 261ms
  SequentialFind: 575ms
  RandomAdd: 792ms
  RandomRemove: 414ms
  RandomFind: 788ms
  
LinearHashTable:
  SequentialAdd: 25ms
  SequentialRemove: 17ms
  SequentialFind: 14ms
  RandomAdd: 20ms
  RandomRemove: 14ms
  RandomFind: 7ms

*/