#pragma once
class LabQueue
{
private:
  char array[50];
public:
  LabQueue();
  bool Enqueue(char item);
  char Dequeue();
};
