#include <iostream>

// Node structure for the circular linked list
struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

// CircularLinkedList class
class CircularLinkedList {
private:
    Node* head;

public:
    // Constructor
    CircularLinkedList() : head(nullptr) {}

    // Function to insert an element in the list
    void insert(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            head->next = head; // Circular link to itself
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head; // Circular link to the head
        }
    }

    // Function to remove an element from the list
    void remove(int value) {
        if (head == nullptr) {
            std::cout << "List is empty." << std::endl;
            return;
        }

        Node* current = head;
        Node* prev = nullptr;

        // Search for the element to be removed
        do {
            if (current->data == value) {
                break;
            }
            prev = current;
            current = current->next;
        } while (current != head);

        // If the element is not found
        if (current == head && current->data != value) {
            std::cout << "Element not found." << std::endl;
            return;
        }

        // If the element is found at the head
        if (current == head) {
            prev->next = head->next;
            delete head;
            head = prev->next;
        } else {
            prev->next = current->next;
            delete current;
        }
    }

    // Function to search for an element and return its pointer
    Node* search(int value) {
        if (head == nullptr) {
            return nullptr;
        }

        Node* current = head;
        do {
            if (current->data == value) {
                return current;
            }
            current = current->next;
        } while (current != head);

        return nullptr; // Element not found
    }

    // Function to display the elements of the list
    void display() {
        if (head == nullptr) {
            std::cout << "List is empty." << std::endl;
            return;
        }

        Node* current = head;
        do {
            std::cout << current->data << " ";
            current = current->next;
        } while (current != head);

        std::cout << std::endl;
    }
};

int main() {
    CircularLinkedList myList;

    // Insert elements in the list
    myList.insert(4);
    myList.insert(3);
    myList.insert(8);
    myList.display(); 

    // Remove an element from the list
    myList.remove(3);
    myList.display(); 

    // Search for an element
    Node* searchResult = myList.search(8);
    if (searchResult != nullptr) {
        std::cout << "Element found at address: " << searchResult << std::endl;
    } else {
        std::cout << "Element not found." << std::endl;
    }

    return 0;
}
// coded by kur Athuai
