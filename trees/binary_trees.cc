#include "binary_trees.hpp"

// Write a function that creates a binary tree node
/**
 * binary_tree_node - creates a new node and appends to the head
 * @parent: pointer to the parent node
 * @value: value of the node.
 *
 * Return: pointer to new node on success otherwise NULL.
*/
std::shared_ptr<BinaryTreeNode> binary_tree_node(std::shared_ptr<binary_tree_t> parent, int value)
{
	 auto node = std::make_shared<BinaryTreeNode>(BinaryTreeNode(value));

    if (node == nullptr)
        return nullptr;
    node->n = value;
    node->parent = parent;
    return node;
}

//Write a function that inserts a node as the left-child of another node
std::shared_ptr<BinaryTreeNode> binary_tree_insert_left(std::shared_ptr<BinaryTreeNode>& parent, int value){

    if (parent == nullptr)
        return nullptr;
    auto temp = parent->left;

    auto node = std::make_shared<BinaryTreeNode>( BinaryTreeNode(value));

    if (node == nullptr) return nullptr;
    parent->left = node;

    node->left = temp;
    
    return node;
    
}



//Write a function that inserts a node as the right-child of another node
std::shared_ptr<BinaryTreeNode> binary_tree_insert_right(std::shared_ptr<BinaryTreeNode>& parent, int value){

    if (parent == nullptr)
        return nullptr;
    auto temp = parent->right;

    auto node = std::make_shared<BinaryTreeNode>( BinaryTreeNode(value));

    if (node == nullptr) return nullptr;
    parent->right = node;

    node->right = temp;
    
    return node;
}

// Write a function that deletes an entire binary tree

void binary_tree_delete(std::shared_ptr<BinaryTreeNode>&tree){

    if (tree== nullptr) return;

    binary_tree_delete(tree->left);
    binary_tree_delete(tree->right);

    tree.reset();
}