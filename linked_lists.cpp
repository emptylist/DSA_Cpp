//Implementing Linked Lists and a Linked List-based stack

#include <iostream>
using namespace std;

//Exception Handling

class RuntimeException {
private:
  string errorMsg;
public:
  RuntimeException(const string& err) { errorMsg = err; }
  string getMessage() const {return errorMsg;}
};

class ListEmptyException : public RuntimeException {
  public ListEmptyException(const string& err) : RuntimeException(err) {}
};

//Linked List Implementation
typedef Node* NodePtr;

template <typename Object>
struct Node {
  Object element;
  NodePtr next;
  Node(const Object& e = Object(), Node* n = NULL) : element(e), next(n) { }
};
