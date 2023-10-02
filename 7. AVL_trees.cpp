#include <iostream>
#include <algorithm>

// Node structure for AVL tree
struct AVLNode {
    int data;
    AVLNode* left;
    AVLNode* right;
    int height;

    AVLNode(int value) : data(value), left(nullptr), right(nullptr), height(1) {}
};

// AVLTree class
class AVLTree {
private:
    AVLNode* root;

    // Helper function to get the height of a node
    int getHeight(AVLNode* node) {
        return (node == nullptr) ? 0 : node->height;
    }

    // Helper function to update the height of a node
    void updateHeight(AVLNode* node) {
        if (node != nullptr) {
            node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));
        }
    }

    // Helper function to get the balance factor of a node
    int getBalanceFactor(AVLNode* node) {
        return (node == nullptr) ? 0 : getHeight(node->left) - getHeight(node->right);
    }

    // Helper function to perform a right rotation
    AVLNode* rightRotate(AVLNode* y) {
        AVLNode* x = y->left;
        AVLNode* T2 = x->right;

        // Perform rotation
        x->right = y;
        y->left = T2;

        // Update heights
        updateHeight(y);
        updateHeight(x);

        return x;
    }

    // Helper function to perform a left rotation
    AVLNode* leftRotate(AVLNode* x) {
        AVLNode* y = x->right;
        AVLNode* T2 = y->left;

        // Perform rotation
        y->left = x;
        x->right = T2;

        // Update heights
        updateHeight(x);
        updateHeight(y);

        return y;
    }

    // Helper function to insert a value into the AVL tree
    AVLNode* insertRecursive(AVLNode* node, int value) {
        // Standard BST insert
        if (node == nullptr) {
            return new AVLNode(value);
        }

        if (value < node->data) {
            node->left = insertRecursive(node->left, value);
        } else if (value > node->data) {
            node->right = insertRecursive(node->right, value);
        } else {
            // Duplicate values are not allowed in AVL tree
            return node;
        }

        // Update height of the current node
        updateHeight(node);

        // Get the balance factor to check if the node became unbalanced
        int balance = getBalanceFactor(node);

        // Left Left Case
        if (balance > 1 && value < node->left->data) {
            return rightRotate(node);
        }

        // Right Right Case
        if (balance < -1 && value > node->right->data) {
            return leftRotate(node);
        }

        // Left Right Case
        if (balance > 1 && value > node->left->data) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Right Left Case
        if (balance < -1 && value < node->right->data) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    // Helper function for searching a value in the AVL tree
    AVLNode* searchRecursive(AVLNode* node, int value) {
        if (node == nullptr || node->data == value) {
            return node;
        }

        if (value < node->data) {
            return searchRecursive(node->left, value);
        }

        return searchRecursive(node->right, value);
    }

public:
    // Constructor
    AVLTree() : root(nullptr) {}

    // Function to insert a value into the AVL tree
    void insert(int value) {
        root = insertRecursive(root, value);
    }

    // Function to search for a value in the AVL tree
    AVLNode* search(int value) {
        return searchRecursive(root, value);
    }
};

int main() {
    AVLTree avlTree;

    // Insert elements into the AVL tree
    avlTree.insert(10);
    avlTree.insert(20);
    avlTree.insert(30);
    avlTree.insert(40);
    avlTree.insert(50);
    avlTree.insert(25);

    // Search for an element
    int searchValue = 30;
    AVLNode* searchResult = avlTree.search(searchValue);

    if (searchResult != nullptr) {
        std::cout << "Element " << searchValue << " found in the AVL tree." << std::endl;
    } else {
        std::cout << "Element " << searchValue << " not found in the AVL tree." << std::endl;
    }

    return 0;
}
//code by Kur Athuai
