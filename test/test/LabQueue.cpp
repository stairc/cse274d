#include "LabQueue.h"


LabQueue::LabQueue()
{
  for (int i = 0; i < sizeof(array); i++)
  {
    array[i] = 0;
  }
}


bool LabQueue::Enqueue(char item)
{
  for (int i = 0; i < sizeof(array); i++)
  {
    if (array[i] == 0)
    {
      array[i] = item;
      return true;
    }
  }

  return false;
}


char LabQueue::Dequeue()
{
  char result = array[0];

  for (int i = 0; i < sizeof(array) - 1; i++)
  {
    array[i] = array[i + 1];
  }

  array[sizeof(array) - 1] = 0;
}

