/* 7.1 INTERCONVERT STRINGS AND INTEGERS
A string is a sequence of characters. A string may encode an integer, e.g., "123"
encodes 123. In this problem, you are to implement methods that take a string
representing an integer and return the corresponding integer, and vice versa. Your
code should handle negative integers. You cannot use library functions like stoi in
C++ and parselnt in Java.
Implement string/integer inter-conversion functions.
*/

#include <string>
#include "test_framework/generic_test.h"
#include "test_framework/test_failure.h"
using std::string;
using namespace std;
string IntToString(int x) {
  string xString = "";
  bool isNegative = false;
  if(x == 0){
    return "0";
  }
  if(x < 0){
    isNegative = true;
  }
  while(x){
    xString += '0' + abs(x % 10);
    x /= 10;
  }
  if(isNegative){
    xString += '-';
  }
  return {xString.rbegin(), xString.rend()};
}
int StringToInt(const string& s) {
  int result = 0;
  for(int digit = (s[0] == '-' ? 1 : 0); digit < s.size(); digit++){
    result = (result * 10) + s[digit] - '0';
  }
  return (s[0] == '-' ? result * -1 : result);
}
void Wrapper(int x, const string& s) {
  if (IntToString(x) != s) {
    throw TestFailure("Int to string conversion failed");
  }

  if (StringToInt(s) != x) {
    throw TestFailure("String to int conversion failed");
  }
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x", "s"};
  return GenericTestMain(args, "string_integer_interconversion.cc",
                         "string_integer_interconversion.tsv", &Wrapper,
                         DefaultComparator{}, param_names);
}
