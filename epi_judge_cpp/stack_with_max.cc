/* 9.1 IMPLEMENT A STACK WITH MAX API
Design a stack that includes a max operation, in addition to push and pop. The max
method should return the maximum value stored in the stack.
*/

#include <stdexcept>
#include <stack>
#include "test_framework/generic_test.h"
#include "test_framework/serialization_traits.h"
#include "test_framework/test_failure.h"
using std::length_error;
using namespace std;
class Stack {
 public:
  bool Empty() const {
    return myStack.empty();
  }
  int Max() const {
    if(Empty()){
      throw length_error("Max() Error: empty stack");
    }
    return myStack.top().max;
  }
  int Pop() {
    if(Empty()){
      throw length_error("Pop() Error: empty stack");
    }
    int poppedVal = myStack.top().value;
    myStack.pop();
    return poppedVal;
  }
  void Push(int x) {
    Element xEl;
    xEl.value = x;
    xEl.max = (Empty() || Max() < x) ? x : Max();
    myStack.push(xEl);
    return;
  }
 private:
   struct Element {
     int value, max;
   };
   stack<Element> myStack;
};
struct StackOp {
  std::string op;
  int argument;
};

template <>
struct SerializationTraits<StackOp> : UserSerTraits<StackOp, std::string, int> {
};

void StackTester(const std::vector<StackOp>& ops) {
  try {
    Stack s;
    for (auto& x : ops) {
      if (x.op == "Stack") {
        continue;
      } else if (x.op == "push") {
        s.Push(x.argument);
      } else if (x.op == "pop") {
        int result = s.Pop();
        if (result != x.argument) {
          throw TestFailure("Pop: expected " + std::to_string(x.argument) +
                            ", got " + std::to_string(result));
        }
      } else if (x.op == "max") {
        int result = s.Max();
        if (result != x.argument) {
          throw TestFailure("Max: expected " + std::to_string(x.argument) +
                            ", got " + std::to_string(result));
        }
      } else if (x.op == "empty") {
        int result = s.Empty();
        if (result != x.argument) {
          throw TestFailure("Empty: expected " + std::to_string(x.argument) +
                            ", got " + std::to_string(result));
        }
      } else {
        throw std::runtime_error("Unsupported stack operation: " + x.op);
      }
    }
  } catch (length_error&) {
    throw TestFailure("Unexpected length_error exception");
  }
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"ops"};
  return GenericTestMain(args, "stack_with_max.cc", "stack_with_max.tsv",
                         &StackTester, DefaultComparator{}, param_names);
}
