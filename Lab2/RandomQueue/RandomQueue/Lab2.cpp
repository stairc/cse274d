#include "RandomQueue.h"
#include <iostream>

using namespace std;

int main() {
  RandomQueue queue;
  queue.Enqueue('k');
  queue.Enqueue('c');
  char result1 = queue.Dequeue();
  char result2 = queue.Dequeue();
  cout << "result 1: " << result1 << endl;
  cout << "result 2: " << result2 << endl;
  return 0;
}



