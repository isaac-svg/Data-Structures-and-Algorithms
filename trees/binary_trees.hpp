#include <memory>
#include <iostream>
#include <stdlib.h>

/**
 * struct BinaryTreeNode - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct BinaryTreeNode
{
    int n;
    std::shared_ptr<BinaryTreeNode> parent;
    std::shared_ptr<BinaryTreeNode> left;
    std::shared_ptr<BinaryTreeNode> right;
    BinaryTreeNode(int value): n(value), left(nullptr),right(nullptr){}
};

typedef struct BinaryTreeNode binary_tree_t;
typedef struct BinaryTreeNode bst_t;
typedef struct BinaryTreeNode avl_t;
typedef struct BinaryTreeNode heap_t;


std::shared_ptr<BinaryTreeNode> binary_tree_node(std::shared_ptr<binary_tree_t> parent, int value);

std::shared_ptr<BinaryTreeNode> binary_tree_insert_left(std::shared_ptr<BinaryTreeNode>&parent, int value);

std::shared_ptr<BinaryTreeNode> binary_tree_insert_right(std::shared_ptr<BinaryTreeNode>&parent, int value);

void binary_tree_delete(std::shared_ptr<BinaryTreeNode>&tree);
