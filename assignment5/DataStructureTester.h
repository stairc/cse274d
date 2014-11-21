
#include <iostream>
#include "time.h"

namespace ods {

  template<class H>
  class DataStructureTester {
  protected:
    H list;

  public:
    void AddRandom(int i) {
      list.add(i);
      //std::cout << "find " << list.find(i) << std::endl;
    }
    int DoSequentialAdd(int start, int stop, int step);
    int DoRandomAdd(int n);
    int DoSequentialRemove(int start, int stop, int step);
    int DoRandomRemove(int n);
    int DoSequentialFind(int start, int stop, int step);
    int DoRandomFind(int n);
  };

  template<class H>
  int DataStructureTester<H>::DoSequentialAdd(int start, int stop, int step) {
    clock_t t;
    t = clock();

    for (int i = start; i < stop; i = i + step) {
      list.add(i);
    }

    t = clock() - t;
    int r = ((((float)t) / CLOCKS_PER_SEC) * 1000);
    return r;
  }

  template<class H>
  int DataStructureTester<H>::DoSequentialRemove(int start, int stop, int step) {
    clock_t t;
    t = clock();

    for (int i = start; i < stop; i = i + step) {
      list.remove(i);
    }

    t = clock() - t;
    int r = ((((float)t) / CLOCKS_PER_SEC) * 1000);
    return r;
  }

  template<class H>
  int DataStructureTester<H>::DoSequentialFind(int start, int stop, int step) {
    clock_t t;
    t = clock();

    for (int i = start; i < stop; i = i + step) {
      list.find(i);
    }

    t = clock() - t;
    int r = ((((float)t) / CLOCKS_PER_SEC) * 1000);
    return r;
  }

  template<class H>
  int DataStructureTester<H>::DoRandomAdd(int n) {
    clock_t t;
    t = clock();

    srand(1);

    for (int i = 0; i < n; i++) {
      list.add(rand());
    }

    t = clock() - t;
    int r = ((((float)t) / CLOCKS_PER_SEC) * 1000);
    return r;
  }

  template<class H>
  int DataStructureTester<H>::DoRandomRemove(int n) {
    clock_t t;
    t = clock();

    srand(1);
    for (int i = 0; i < n; i++) {
      list.remove(rand());
    }

    t = clock() - t;
    int r = ((((float)t) / CLOCKS_PER_SEC) * 1000);
    return r;
  }

  template<class H>
  int DataStructureTester<H>::DoRandomFind(int n) {
    clock_t t;
    t = clock();
    
    srand(1);
    for (int i = 0; i < n; i = i++) {
      list.find(rand());
    }

    t = clock() - t;
    int r = ((((float)t) / CLOCKS_PER_SEC) * 1000);
    return r;
  }
}