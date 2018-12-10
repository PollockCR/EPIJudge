/* 15.1 TEST IF A BINARY TREE SATISFIES THE BST PROPERTY
Write a program that takes as input a binary tree and checks if the tree satisfies the
BST property.
*/
#include <memory>
#include "binary_tree_node.h"
#include "test_framework/generic_test.h"
using std::unique_ptr;

bool AreKeysInRange(const unique_ptr<BinaryTreeNode<int>>& tree, int low, int high){
  if(tree == NULL){
    return true;
  }
  if(tree->data >= low && tree->data <= high){
    return AreKeysInRange(tree->left, low, tree->data) &&
      AreKeysInRange(tree->right, tree->data, high);
  } else {
    return false;
  }
}

bool IsBinaryTreeBST(const unique_ptr<BinaryTreeNode<int>>& tree) {
  return AreKeysInRange(tree, std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"tree"};
  return GenericTestMain(args, "is_tree_a_bst.cc", "is_tree_a_bst.tsv",
                         &IsBinaryTreeBST, DefaultComparator{}, param_names);
}
