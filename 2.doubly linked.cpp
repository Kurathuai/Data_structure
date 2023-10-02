#include <iostream>

// Node structure for the doubly linked list
struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};

// DoublyLinkedList class
class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    // Constructor
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // Function to insert an element at the beginning of the list
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // Function to insert an element at the end of the list
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Function to remove an element from the beginning of the list
    void removeFromBeginning() {
        if (head == nullptr) {
            std::cout << "List is empty." << std::endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            // List becomes empty after removal
            tail = nullptr;
        }

        delete temp;
    }

    // Function to remove an element from the end of the list
    void removeFromEnd() {
        if (head == nullptr) {
            std::cout << "List is empty." << std::endl;
            return;
        }

        Node* temp = tail;
        tail = tail->prev;
        if (tail != nullptr) {
            tail->next = nullptr;
        } else {
            // List becomes empty after removal
            head = nullptr;
        }

        delete temp;
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
    DoublyLinkedList myList;

    // Insert elements at the beginning
    myList.insertAtBeginning(5);
    myList.insertAtBeginning(3);
    myList.display();

    // Insert element at the end
    myList.insertAtEnd(8);
    myList.display();

    // Remove element from the beginning
    myList.removeFromBeginning();
    myList.display();

    // Remove element from the end
    myList.removeFromEnd();
    myList.display();

    return 0;
}
// code made by kur Athuai
