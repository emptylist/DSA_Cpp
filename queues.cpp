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

class QueueEmptyException : public RuntimeException {
public:
  QueueEmptyException(const string& err) : RuntimeException(err) {}
};

// Queue Template

template <typename Object>
class ArrayQueue {
private:
  enum { CAPACITY = 1000 };
  int capacity;
  Object* Q;
  int front;
  int rear;
public:
  //Constructor, Destructor, etc.
  ArrayQueue(int cap = CAPACITY) {
    capacity = cap;
    Q = new Object[capacity];
    front = rear = 0;
  }

  ~ArrayQueue() {
    delete [] Q;
  }

  ArrayQueue& operator=(const ArrayQueue& qu); // assignment operator constructor
  ArrayQueue(const ArrayQueue& qu); //copy constructor

  // Data Structure Logic methods
  void enqueue(const Object& obj) throw(QueueFullException) {
    if (size() == capacity)
      throw QueueFullException("Queue overflow.");
    Q[rear] = obj;
    rear = rear++ % capacity;
  }

  Object dequeue() throw(QueueEmptyException) {
    if (size() == 0)
      throw QueueEmptyException("Access to empty Queue.");
    int output_loc = front;
    front = front++ % capacity;
    return Q[output_loc];
  }

  // Helper methods
  int size() const {
    return (capacity - front + rear) % capacity;
  }

  bool isEmpty() const {
    return (front == rear);
  }

  const Object first() const throw(QueueEmptyException) {
    return Q[front];
  }
};

template <typename Object>
ArrayQueue<Object>::ArrayQueue(const ArrayQueue& qu)
{
  capacity = qu.capacity;
  front = qu.front;
  rear = qu.rear;
  Q = new Object[capacity];
  int i = front;
  while(i != rear) {
    Q[i] = qu.Q[i];
    i = i++ % capacity;
  }
}

template <typename Object>
ArrayQueue<Object>& ArrayQueue<Object>::operator=(const ArrayQueue& qu)
{
  if (this != &qu) {
    delete [] Q;
    capacity = qu.capacity;
    front = qu.front;
    rear = qu.rear;
    Q = new Object[capacity];
    int i = front;
    while(i != rear) {
      Q[i] = qu.Q[i];
      i = i++ % capacity;
    }
  }
  return *this;
}

int main() {
  ArrayQueue<int> q;
  q.enqueue(10);
  cout << q.first() << endl;
  return 0;
}

