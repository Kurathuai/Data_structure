#include <iostream>

// Node structure for the singly linked list
struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

// SinglyLinkedList class
class SinglyLinkedList {
private:
    Node* head;

public:
    // Constructor
    SinglyLinkedList() : head(nullptr) {}

    // Function to insert an element at the beginning of the list
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // Function to insert an element at ith position in the list
    void insertAtPosition(int value, int position) {
        if (position < 1) {
            std::cout << "Invalid position." << std::endl;
            return;
        }

        Node* newNode = new Node(value);
        if (position == 1) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* current = head;
        for (int i = 1; i < position - 1 && current != nullptr; ++i) {
            current = current->next;
        }

        if (current == nullptr) {
            std::cout << "Invalid position." << std::endl;
            delete newNode;
            return;
        }

        newNode->next = current->next;
        current->next = newNode;
    }

    // Function to remove an element from the beginning of the list
    void removeFromBeginning() {
        if (head == nullptr) {
            std::cout << "List is empty." << std::endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // Function to remove an element from ith position in the list
    void removeFromPosition(int position) {
        if (head == nullptr || position < 1) {
            std::cout << "List is empty or invalid position." << std::endl;
            return;
        }

        if (position == 1) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* current = head;
        Node* previous = nullptr;
        for (int i = 1; i < position && current != nullptr; ++i) {
            previous = current;
            current = current->next;
        }

        if (current == nullptr) {
            std::cout << "Invalid position." << std::endl;
            return;
        }

        previous->next = current->next;
        delete current;
    }

    // Function to search for an element and return its pointer
    Node* search(int value) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == value) {
                return current;
            }
            current = current->next;
        }
        return nullptr; // Element not found
    }

    // Function to display the elements of the list
    void display() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    SinglyLinkedList myList;

    // Insert elements at the beginning
    myList.insertAtBeginning(5);
    myList.insertAtBeginning(3);
    myList.insertAtBeginning(8);
    myList.display();

    // Insert element at position 2
    myList.insertAtPosition(10, 2);
    myList.display();

    // Remove element from the beginning
    myList.removeFromBeginning();
    myList.display();

    // Remove element from position 2
    myList.removeFromPosition(2);
    myList.display(); 

    // Search for an element
    Node* searchResult = myList.search(5);
    if (searchResult != nullptr) {
        std::cout << "Element found at address: " << searchResult << std::endl;
    } else {
        std::cout << "Element not found." << std::endl;
    }

    return 0;
}
// code made by kur Athuai//
