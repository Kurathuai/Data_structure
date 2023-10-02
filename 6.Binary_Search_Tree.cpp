#include <iostream>

// Node structure for the Binary Search Tree
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

// BinarySearchTree class
class BinarySearchTree {
private:
    TreeNode* root;

    // Helper function to insert a value into the BST
    TreeNode* insertRecursive(TreeNode* current, int value) {
        if (current == nullptr) {
            return new TreeNode(value);
        }

        if (value < current->data) {
            current->left = insertRecursive(current->left, value);
        } else if (value > current->data) {
            current->right = insertRecursive(current->right, value);
        }

        return current;
    }

    // Helper function to find the minimum value node in a BST
    TreeNode* findMin(TreeNode* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    // Helper function to delete a value from the BST
    TreeNode* deleteRecursive(TreeNode* current, int value) {
        if (current == nullptr) {
            return nullptr;
        }

        if (value < current->data) {
            current->left = deleteRecursive(current->left, value);
        } else if (value > current->data) {
            current->right = deleteRecursive(current->right, value);
        } else {
            // Node with only one child or no child
            if (current->left == nullptr) {
                TreeNode* temp = current->right;
                delete current;
                return temp;
            } else if (current->right == nullptr) {
                TreeNode* temp = current->left;
                delete current;
                return temp;
            }

            // Node with two children: Get the inorder successor (smallest in the right subtree)
            TreeNode* temp = findMin(current->right);

            // Copy the inorder successor's data to this node
            current->data = temp->data;

            // Delete the inorder successor
            current->right = deleteRecursive(current->right, temp->data);
        }

        return current;
    }

    // Helper function for searching a value in the BST
    TreeNode* searchRecursive(TreeNode* current, int value) {
        if (current == nullptr || current->data == value) {
            return current;
        }

        if (value < current->data) {
            return searchRecursive(current->left, value);
        }

        return searchRecursive(current->right, value);
    }

    // Helper function for preorder traversal
    void preorderTraversal(TreeNode* current) {
        if (current != nullptr) {
            std::cout << current->data << " ";
            preorderTraversal(current->left);
            preorderTraversal(current->right);
        }
    }

    // Helper function for inorder traversal
    void inorderTraversal(TreeNode* current) {
        if (current != nullptr) {
            inorderTraversal(current->left);
            std::cout << current->data << " ";
            inorderTraversal(current->right);
        }
    }

    // Helper function for postorder traversal
    void postorderTraversal(TreeNode* current) {
        if (current != nullptr) {
            postorderTraversal(current->left);
            postorderTraversal(current->right);
            std::cout << current->data << " ";
        }
    }

public:
    // Constructor
    BinarySearchTree() : root(nullptr) {}

    // Function to insert a value into the BST
    void insert(int value) {
        root = insertRecursive(root, value);
    }

    // Function to delete a value from the BST
    void deleteNode(int value) {
        root = deleteRecursive(root, value);
    }

    // Function to search for a value in the BST
    TreeNode* search(int value) {
        return searchRecursive(root, value);
    }

    // Function to display the elements of the BST in preorder traversal
    void displayPreorder() {
        std::cout << "Preorder Traversal: ";
        preorderTraversal(root);
        std::cout << std::endl;
    }

    // Function to display the elements of the BST in inorder traversal
    void displayInorder() {
        std::cout << "Inorder Traversal: ";
        inorderTraversal(root);
        std::cout << std::endl;
    }

    // Function to display the elements of the BST in postorder traversal
    void displayPostorder() {
        std::cout << "Postorder Traversal: ";
        postorderTraversal(root);
        std::cout << std::endl;
    }
};

int main() {
    BinarySearchTree myBST;

    // Insert elements into the BST
    myBST.insert(5);
    myBST.insert(3);
    myBST.insert(8);
    myBST.insert(2);
    myBST.insert(4);
    myBST.insert(7);
    myBST.insert(9);

    // Display the elements in different traversals
    myBST.displayPreorder(); 
    myBST.displayInorder();   
    myBST.displayPostorder(); 

    // Search for an element
    TreeNode* searchResult = myBST.search(7);
    if (searchResult != nullptr) {
        std::cout << "Element 7 found in the BST." << std::endl;
    } else {
        std::cout << "Element 7 not found in the BST." << std::endl;
    }

    // Delete an element from the BST
    myBST.deleteNode(3);
    myBST.displayInorder(); 

    return 0;
}
// code by Kur Athuai
