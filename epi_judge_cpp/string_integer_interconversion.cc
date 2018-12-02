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
  string sCopy = s;
  int sInt = 0;
  int tenMult = 1;
  while(!sCopy.empty()){
    char letter = sCopy.back();
    sCopy.pop_back();
    if(letter == '-'){
      sInt *= -1;
    }
    else
    {
      sInt += (letter - '0') * tenMult;
      tenMult *= 10;
    }
  }
  cout << sInt << endl;
  return sInt;
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
