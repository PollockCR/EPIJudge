/* 14.1 COMPUTE THE INTERSECTION OF TWO SORTED ARRAYS
Write a program which takes as input two sorted arrays, and returns a new array
containing elements that are present in both of the input arrays. The input arrays
may have duplicate entries, but the returned array should be free of duplicates. For
example, the input is (2,3,3,5,5,6,7,7,8, 12) and (5,5,6,8,8,9, 10, 10), your output
should be (5, 6, 8).
*/
#include <vector>
#include "test_framework/generic_test.h"
using std::vector;

vector<int> IntersectTwoSortedArrays(const vector<int>& A,
                                     const vector<int>& B) {
  vector<int> intersect;
  int iA = 0, iB = 0;
  while(iA < A.size() && iB < B.size()){
    if(A[iA] == B[iB]){
      if(intersect.empty() || intersect.back() != A[iA]){
        intersect.emplace_back(A[iA]);
      }
      iA++;
      iB++;
    } else if(A[iA] < B[iB]){
      iA++;
    } else {
      iB++;
    }
  }
  return intersect;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A", "B"};
  return GenericTestMain(
      args, "intersect_sorted_arrays.cc", "intersect_sorted_arrays.tsv",
      &IntersectTwoSortedArrays, DefaultComparator{}, param_names);
}
