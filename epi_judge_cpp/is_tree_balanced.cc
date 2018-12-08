/* 10.l TEST IF A BINARY TREE IS HEIGHT-BALANCED
Write a program that takes as input the root of a binary tree and checks whether the
tree is height-balanced.
*/

#include "binary_tree_node.h"
#include "test_framework/generic_test.h"

struct balancedStatus{
  bool balanced;
  int height;
};

balancedStatus BalanceCheck(const unique_ptr<BinaryTreeNode<int>>& tree){
  if(tree == NULL){
    return {true, -1};
  }
  auto leftResult = BalanceCheck(tree->left);
  if(!leftResult.balanced){
    return {false, 0};
  }
  auto rightResult = BalanceCheck(tree->right);
  if(!rightResult.balanced){
    return {false, 0};
  }
  bool balanced = std::abs(leftResult.height - rightResult.height) <= 1;
  int height = std::max(leftResult.height, rightResult.height) + 1;
  return {balanced, height};
}

bool IsBalanced(const unique_ptr<BinaryTreeNode<int>>& tree) {
  return BalanceCheck(tree).balanced;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"tree"};
  return GenericTestMain(args, "is_tree_balanced.cc", "is_tree_balanced.tsv",
                         &IsBalanced, DefaultComparator{}, param_names);
}
