/* 13.2: Is an anonymous letter constructable?
Write a program which takes text for an anonymous letter and text for a magazine
and determines if it is possible to write the anonymous letter using the magazine.
The anonymous letter can be written using the magazine if for each character in the
anonymous letter, the number of times it appears in the anonymous letter is no more
than the number of times it appears in the magazine
*/

#include <string>
#include <unordered_map>
#include "test_framework/generic_test.h"
using std::string;

bool IsLetterConstructibleFromMagazine(const string& letter_text,
                                       const string& magazine_text) {
  std::unordered_map<char, int> letter_count, magazine_count;
  for(char letter : letter_text){
    ++letter_count[letter];
  }
  for(char letter : magazine_text){
    ++magazine_count[letter];
  }
  for(const auto& l : letter_count){
    if(l.second > magazine_count[l.first]){
      return false;
    }
  }
  return true;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"letter_text", "magazine_text"};
  return GenericTestMain(args, "is_anonymous_letter_constructible.cc",
                         "is_anonymous_letter_constructible.tsv",
                         &IsLetterConstructibleFromMagazine,
                         DefaultComparator{}, param_names);
}
