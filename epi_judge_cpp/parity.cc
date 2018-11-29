// Problem 5.1: Computing the parity of a word, pg 45
/*
The parity of a binary word is 1 if the number of ls in the word is odd; otherwise,
it is 0. For example, the parity of 1011 is 1, and the parity of 10001000 is 0. Parity
checks are used to detect single bit errors in data storage and communication. It is
fairly straightforward to write code that computes the parity of a single 64-bit word.
How would you compute the parity of a very large number of 64-bit words?
*/
#include "test_framework/generic_test.h"
short Parity(unsigned long long x) {
  short numOnes = 0;
  while(x){
    numOnes ^= x & 1;
    x >>= 1;
  }
  return numOnes % 2;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x"};
  return GenericTestMain(args, "parity.cc", "parity.tsv", &Parity,
                         DefaultComparator{}, param_names);
}
