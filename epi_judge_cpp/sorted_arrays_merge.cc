/* 11.1 MERGE SORTED FILES
Write a program that takes as input a set of sorted sequences and computes the union
of these sequences as a sorted sequence. For example, if the input is (3, 5, 7), (0, 6),
and (0, 6, 28), then the output is (0, 0, 3, 5, 6, 6, 7, 28).
*/
#include <vector>
#include <queue>
#include "test_framework/generic_test.h"
using std::vector;
vector<int> MergeSortedArrays(const vector<vector<int>>& sorted_arrays) {
  vector<int> final_array;
  std::priority_queue<int, vector<int>, std::greater<int>> min_heap;
  for(auto single_array : sorted_arrays){
    for(auto value : single_array){
      min_heap.emplace(value);
    }
  }
  while(!min_heap.empty()){
    final_array.emplace_back(min_heap.top());
    min_heap.pop();
  }
  return final_array;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"sorted_arrays"};
  return GenericTestMain(args, "sorted_arrays_merge.cc",
                         "sorted_arrays_merge.tsv", &MergeSortedArrays,
                         DefaultComparator{}, param_names);
}
