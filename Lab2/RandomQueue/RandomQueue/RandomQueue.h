#include "stdlib.h"


class RandomQueue{
private:
  char array[5];
  int array_size_;
public:
  RandomQueue();
  ~RandomQueue();
  bool Enqueue(char item);
  char Dequeue();
};

RandomQueue::RandomQueue(){
  // Complexity is O(n)
  for (int i = 0; i < sizeof(array); i++) {
    array[i] = 0;
  }
  array_size_ = 0;
}

RandomQueue::~RandomQueue(){
}

bool RandomQueue::Enqueue(char item){
  // Complexity is O(n)
  for (int i = 0; i < sizeof(array); i++) {
    if (array[i] == 0) {
      array[i] = item;
      array_size_++;
      return true;
    }
  }
  return false;
}


// Returns a random element from the queue and removes returned element.
// If no elements are present in the queue, returns 0.
// Will always return a element if at least 1 exists in the queue.
char RandomQueue::Dequeue(){

  char result = 0;
  int num = -1;

  if (array_size_ != 0)
  {
    do
    {
      num = rand() % sizeof(array);
      result = array[num];
    } while (result == 0);

    array_size_--;
  }
  
  return result;
}

