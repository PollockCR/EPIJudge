/* 12.1 SEARCH A SORTED ARRAY FOR FIRST OCCURRENCE OF k
Write a method that takes a sorted array and a key and returns the index of the
first occurrence of that key in the array.
*/

#include <vector>
#include "test_framework/generic_test.h"
using std::vector;

int SearchFirstOfKHelper(const int start, const int end, const vector<int>& A, int k){
  if(start > end){
    return -1;
  }
  int mid = (start + end) / 2;
  if(A[mid] == k){
    /* initial approach: backtrack to first k
    while(mid >= start && A[mid] == k){
      mid--;
    }
    return mid+1;
    */
    // approach w/ hint from EPI: continue binary search_first_key
    if(start == mid){
      return mid;
    }
    return SearchFirstOfKHelper(start, mid, A, k);
  }
  if(A[mid] > k){
    return SearchFirstOfKHelper(start, mid-1, A, k);
  }
  if(A[mid] < k){
    return SearchFirstOfKHelper(mid+1, end, A, k);
  }
}

int SearchFirstOfK(const vector<int>& A, int k) {
  return SearchFirstOfKHelper(0, A.size()-1, A, k);
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A", "k"};
  return GenericTestMain(args, "search_first_key.cc", "search_first_key.tsv",
                         &SearchFirstOfK, DefaultComparator{}, param_names);
}
