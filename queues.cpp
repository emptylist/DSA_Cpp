// Queue Data Structure
#include <iostream>
using namespace std;

//Exception Classes

class RuntimeException {
private:
  string errorMsg;
public:
  RuntimeException(const string& err) { errorMsg = err; }
  string getMessage() const {return errorMsg; }
};

// Queue Template

template <typename Object>
class ArrayQueue {
private:
  enum {CAPACITY = 1000 };
  int capacity;
  Object* Q;
  int front;
  int rear;
public:
  int size() const {
    return (capacity - front + rear) % capacity;
  }
  bool isEmpty const {
    return (front == rear);
  }
  
