#include <iostream>
#include "BST.hpp"

int main(void)
{
    BinarySearchTree<int> bst;
    bst.insert(5);
    bst.insert(1);
    bst.insert(9);
    bst.insert(2);
    bst.insert(7);
    bst.insert(3);
    bst.insert(6);


    bst.inorder_traversal(bst.getRoot());
    bst.delete_node(3);
    std::cout << "\n";
    bst.inorder_traversal(bst.getRoot());
    std::cout << "\n";
    if (bst.isBST())
    {
        std::cout << "This is a BST\n";
    }

    BSTNode<int>* successor = bst.get_successor(2);
    std::cout << "2's successor is " << successor->data << "\n";

    std::cout << "Height: " << bst.findHeight(bst.getRoot()) << "\n";
    std::cout << "The number of nodes are " << bst.get_nodes_count() << "\n";


    return 0;
}
