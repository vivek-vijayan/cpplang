#include <iostream>

// * Defining the Tree
struct Tree
{
    struct Tree *left, *right;
    int data;
    Tree(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

Tree *
reverse_binary_tree(Tree *root)
{
    Tree *left, *right;
    if (root != NULL)
    {
        left = root->left;
        right = root->right;
        root->left = right;
        root->right = left;
        reverse_binary_tree(root->right);
        reverse_binary_tree(root->left);
    }
    return root;
}

int main()
{
    Tree *root = new Tree(10);
    root->left = new Tree(20);
    root->right = new Tree(30);
    root->left->left = new Tree(40);
    root->left->right = new Tree(50);

    std::cout << root->data << std::endl;
    std::cout << root->left->data << std::endl;
    std::cout << root->right->data << std::endl;
    std::cout << root->left->left->data << std::endl;
    std::cout << root->left->right->data << std::endl;


    std::cout << "After reversing \n ";
    Tree *reversed_root = reverse_binary_tree(root);

    std::cout << reversed_root->data << std::endl;
    std::cout << reversed_root->left->data << std::endl;
    std::cout << reversed_root->right->data << std::endl;
    std::cout << reversed_root->left->left->data << std::endl;
    std::cout << reversed_root->left->right->data << std::endl;

    return 0;
}