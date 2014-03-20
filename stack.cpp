//Simple Stack data structure
#include <iostream>
using namespace std;

// Exception Classes

class RuntimeException {
private: 
  string errorMsg;
public:
  RuntimeException(const string& err) { errorMsg = err; }
  string getMessage() const {return errorMsg; }
};

class StackEmptyException : public RuntimeException {
public:
  StackEmptyException(const string& err) : RuntimeException(err) {}
};

class StackFullException : public RuntimeException {
public:
  StackFullException(const string& err) : RuntimeException(err) {}
};

// Stack Template implemented with an Array

template <typename Object>
class ArrayStack {
private:
  enum {CAPACITY = 1000 };
  int capacity;
  Object* S;
  int t;
public:
  ArrayStack(int cap = CAPACITY);
  ~ArrayStack();
  ArrayStack& operator=(const ArrayStack& st);
  ArrayStack(const ArrayStack& st);
  int size() const;
  bool isEmpty() const;
  const Object& peek() throw(StackEmptyException);
  Object& unsafePeek() throw(StackEmptyException);
  void push(const Object& obj) throw(StackFullException);
  Object pop() throw(StackEmptyException);
};

template <typename Object>
ArrayStack<Object>::ArrayStack(int cap)
{
  capacity = cap;
  S = new Object[capacity];
  t = -1;
}

template <typename Object>
ArrayStack<Object>::~ArrayStack()
{
  delete [] S;
}

template <typename Object>
int ArrayStack<Object>::size() const
{
  return (t + 1);
}

template <typename Object>
bool ArrayStack<Object>::isEmpty() const
{
  return (t < 0);
}

template <typename Object>
const Object& ArrayStack<Object>::peek() throw(StackEmptyException)
{
  if (isEmpty())
    throw StackEmptyException("Access to empty stack");
  return S[t];
}

template <typename Object>
Object& ArrayStack<Object>::unsafePeek() throw(StackEmptyException)
{
  if (isEmpty())
    throw StackEmptyException("Access to empty stack");
  return S[t];
}

template <typename Object>
void ArrayStack<Object>::push(const Object& elem) throw(StackFullException) 
{
  if(size() == capacity)
    throw StackFullException("Stack overflow");
  S[++t] = elem;
}

template <typename Object>
Object ArrayStack<Object>::pop() throw(StackEmptyException) 
{
  if (isEmpty())
    throw StackEmptyException("Access to empty stack");
  return S[t--];
}

template <typename Object>
ArrayStack<Object>::ArrayStack(const ArrayStack& st)
{
  capacity = st.capacity;
  t = st.t;
  S = new Object[capacity];
  for (int i = 0; i <= t; i++) {
    S[i] = st.S[i];
  }
}

template <typename Object>
ArrayStack<Object>& ArrayStack<Object>::operator=(const ArrayStack& st)
{
  if (this != &st) {
    delete [] S;
    capacity = st.capacity;
    t = st.t;
    S = new Object[capacity];
    for (int i = 0; i <= t; i++) {
      S[i] = st.S[i];
    }
  }
    return *this;
}

int main() {
  ArrayStack<int> s;
  s.push(10);
  cout << s.peek() << endl;
  return 0;
}
