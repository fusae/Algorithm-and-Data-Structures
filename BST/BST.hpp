#ifndef BST_HPP
#define BST_HPP

#include <iostream>
#include <algorithm>

template <typename T>
struct BSTNode
{
    T data;
    BSTNode* left;
    BSTNode* right;

    BSTNode(const T&x): data(x),
                        left(nullptr),
                        right(nullptr)
    {}
};
template <typename T>
class BinarySearchTree
{
private:
    BSTNode<T>* root_; 
    std::size_t nodes;

    int max(int left_height, int right_height)  {return left_height > right_height? left_height: right_height;}
    BSTNode<T>* delete_node_(BSTNode<T>* root, const T& x);
    void checkBST(BSTNode<T>* root, T* array);
public:
    BinarySearchTree():root_(nullptr), nodes(0)  {}
    BSTNode<T>* find(BSTNode<T> *bst, T x);
    BSTNode<T>* findMin(BSTNode<T>* root);
    BSTNode<T>* findMax(BSTNode<T>* root);
    void insert(const T& x);
    void delete_node(const T& x);
    void inorder_traversal(BSTNode<T> *bst);
    BSTNode<T> *getRoot()  {return root_;}
    bool isEmpty()  {return root_ == nullptr;}
    int findHeight(BSTNode<T>* root);
    std::size_t get_nodes_count()   {return nodes;}
    bool isBST();
    BSTNode<T>* get_successor(T data);


};

template <typename T>
BSTNode<T> *BinarySearchTree<T>::find(BSTNode<T> *bst, T x)
{
    while (bst)
    {
        if (x > bst->data)
            bst = bst->right;
        else if (x < bst->data)
            bst = bst->left;
        else
            return bst;
    }
    return nullptr;
}

template <typename T>
BSTNode<T>* BinarySearchTree<T>::findMin(BSTNode<T>* root)
{
    if (!isEmpty())
    {
        BSTNode<T>* curr = root;
        if (curr)
            while (curr->left)
                curr = curr->left;
        return curr;
    }
    std::cerr << "Error: Tree is empty\n";
    return nullptr;
}

template <typename T>
BSTNode<T>* BinarySearchTree<T>::findMax(BSTNode<T>* root)
{
    if (!isEmpty())
    {
        BSTNode<T>* curr = root;
        if (curr)
            while (curr->right)
                curr = curr->right;
        return curr;
    }
    std::cerr << "Error: Tree is empty\n";
    return nullptr;
}

template <typename T>
void BinarySearchTree<T>::insert(const T& x)
{
    BSTNode<T>* newNode = new BSTNode<T>(x);
    BSTNode<T>* parent = nullptr;

    if (isEmpty())
    {
        root_ = newNode;
        ++nodes;
        return;
    }

    BSTNode<T>* curr = root_;
    // find the Node's parent
    while (curr)
    {
        parent = curr;
        curr = newNode->data > curr->data? curr->right: curr->left;
    }

    if (newNode->data < parent->data)
        parent->left = newNode;
    else
        parent->right = newNode;
    
    ++nodes;
}

template <typename T>
void BinarySearchTree<T>::inorder_traversal(BSTNode<T> *bst)
{
    if (bst)
    {
        inorder_traversal(bst->left);
        std::cout << bst->data << " ";
        inorder_traversal(bst->right);
    }
}

template <typename T>
int BinarySearchTree<T>::findHeight(BSTNode<T>* root)
{
    if (!root)
        return -1;
    int left_height = findHeight(root->left);
    int right_height = findHeight(root->right);
    return max(left_height, right_height) + 1;
}

template <typename T>
BSTNode<T>* BinarySearchTree<T>::delete_node_(BSTNode<T>* root, const T& x)
{
    if (root == nullptr)
        return root;
    else if (root->data < x)
        root->right = delete_node_(root->right, x);
    else if (root->data > x)
        root->left = delete_node_(root->left, x);
    else    // found it 
    {
        // case 1, left node
        if (root->left == nullptr && root->right == nullptr)
        {
            delete root;
            root = nullptr;
        }

        // case 2, parent node with 1 child
        else if (root->left == nullptr)
        {
            BSTNode<T>* temp = root;
            root = root->right;
            delete temp;
        }
        else if (root->right == nullptr)
        {
            BSTNode<T>* temp = root;
            root = root->left;
            delete temp;
        }

        // case 3, parent node with 2 children
        else
        {
            BSTNode<T>* temp = findMin(root->right);
            root->data = temp->data;
            root->right = delete_node_(root->right, temp->data);
        }
    }

    return root;
}

template <typename T>
void BinarySearchTree<T>::delete_node(const T& x)
{
    root_ = delete_node_(root_, x);
    if (nodes > 0)
        nodes--;
}

template <typename T>
void BinarySearchTree<T>::checkBST(BSTNode<T>* root, T* array)
{
    // do inorder traversal and store data in an array,
    // then check if array sorted
    static int index = 0;
    if (root)
    {
        checkBST(root->left, array);
        array[index++] = root->data;
        checkBST(root->right, array);
    }
}

template <typename T>
bool BinarySearchTree<T>::isBST()
{
    T array[nodes];
    checkBST(root_, array);
    if (std::is_sorted(array, array+nodes))
        return true;
    else
        return false;
}

template <typename T>
BSTNode<T>* BinarySearchTree<T>::get_successor(T data)
{
    // search the node
    BSTNode<T>* current = find(root_, data);
    if (current == nullptr) return nullptr;

    // case 1: Node has right subtree
    if (current->right != nullptr)
    {
        return findMin(current->right);
    }
    // case 2: No right subtree
    else
    {
        BSTNode<T>* successor = nullptr;
        BSTNode<T>* ancestor = root_;
        while (ancestor != current)
        {
            if (current->data < ancestor->data)
            {
                successor = ancestor;
                ancestor = ancestor->left;
            }
            else
                ancestor = ancestor->right;
        }
        return successor;
    }

}


#endif
