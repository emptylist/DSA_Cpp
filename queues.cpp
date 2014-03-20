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

class QueueFullException : public RuntimeException {
public:
  QueueFullException(const string& err) : RuntimeException(err) {}
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
  //Constructor, Destructor, etc.
  ArrayQueue(int cap = CAPACITY) {
    capacity = cap;
    Q = new Object[capacity];
    f = r = 0;
  }

  ~ArrayQueue() {
    delete [] Q;
  }

  ArrayQueue& operator=(const ArrayQueue qu); // assignment operator constructor
  ArrayQueue(const ArrayQueue& qu); //copy constructor

  // Data Structure Logic methods
  void enqueue(const Object& obj) throw(QueueFullException) {
    if (size() == capacity)
      throw QueueFullException("Queue overflow.");
    Q[r] = obj;
    r = r++ % capacity;
  }

  Object dequeue() throw(QueueEmptyException) {
    if (size() == 0)
      throw QueueEmptyException("Access to empty Queue.");
    output_loc = f;
    f = f++ % capacity;
    return Q[output_loc];
  }

  // Helper methods
  int size() const {
    return (capacity - front + rear) % capacity;
  }

  bool isEmpty const {
    return (front == rear);
  }
  const Object& first() const throw(QueueEmptyException) {
  }
};
