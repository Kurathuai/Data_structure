#include <iostream>

// Node structure for the queue
struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

// Queue class
class Queue {
private:
    Node* front;
    Node* rear;

public:
    // Constructor
    Queue() : front(nullptr), rear(nullptr) {}

    // Function to check if the queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Function to enqueue (insert) an element into the queue
    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    // Function to dequeue (remove) an element from the queue
    void dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty. Cannot dequeue." << std::endl;
            return;
        }

        Node* temp = front;
        front = front->next;
        delete temp;

        // If the queue becomes empty after dequeue
        if (front == nullptr) {
            rear = nullptr;
        }
    }

    // Function to get the front element of the queue
    int getFront() {
        if (isEmpty()) {
            std::cout << "Queue is empty. No front element." << std::endl;
            return -1; // Assuming -1 as a sentinel value for an empty queue
        }
        return front->data;
    }

    // Function to display the elements of the queue
    void display() {
        if (isEmpty()) {
            std::cout << "Queue is empty." << std::endl;
            return;
        }

        Node* current = front;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    Queue myQueue;

    // Enqueue elements
    myQueue.enqueue(5);
    myQueue.enqueue(2);
    myQueue.enqueue(7);

    // Display the queue
    std::cout << "Queue: ";
    myQueue.display();

    // Dequeue an element
    myQueue.dequeue();

    // Display the updated queue
    std::cout << "Updated Queue: ";
    myQueue.display();

    // Get the front element
    std::cout << "Front element: " << myQueue.getFront() << std::endl;

    return 0;
}
// code by Kur Athuai 
