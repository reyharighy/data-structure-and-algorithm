/*
    File ini digunakan sebagai antarmuka untuk seluruh subProgram yang ada di dalam Chapter Senarai Berantai (Linked List). Setiap objek kelas 
    yang dideklarasikan di dalam file ini menyediakan berbagai fungsi spesifik yang dienkapsulasi untuk melakukan aktivitas pengoperasian 
    atau manipulasi data beserta attribute members yang diperlukan.
*/

#ifndef LINKED_LIST_CHAPTER
#define LINKED_LIST_CHAPTER

#include "../Program Interface Files/programInterface.hpp"
#include "../Custom Utility Files/customUtility.hpp"
#include <stdexcept>

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 1: Namespace untuk berbagai masalah yang berkaitan dengan Linked List dan Doubly Linked List.
----------------------------------------------------------------------------------------------------------------------------------------*/

template<typename T>
struct Node {
    T data;
    Node<T>* next{nullptr}; // Pointer to the next node.
};
template<typename T>
    struct DoublyNode { // Doubly linked list node structure.
        T data;
        DoublyNode<T>* prev{nullptr}; // Pointer to the previous node.
        DoublyNode<T>* next{nullptr}; // Pointer to the next node.
    };

template<typename T>
class LinkedList {
protected:
    Node<T>* head{nullptr}; // Head of the linked list.

    Node<T>* getNodePointer(int index) { // Returns a pointer to a node at a given index.
        Node<T>* currentNode = head; // Starts from the head.
        for (int i = 0; i < index; ++i) {
            if (currentNode == nullptr || currentNode->next == nullptr) { // Checks if the next points to nullptr, before moving to it.
                throw std::out_of_range("Index out of bounds.");
            }
            currentNode = currentNode->next; // Moves to the next node.
        }
        return currentNode;
    }

public:
    LinkedList() = default; // Default constructor.

    // Copy constructor.
    LinkedList(const LinkedList& other) : head(nullptr) {
        Node<T>* prevNode{nullptr}; // Previous node pointer.
        for (Node<T>* otherNode = other.head; otherNode != nullptr; otherNode = otherNode->next) { // Traverses the other linked list.
            Node<T>* node = new Node<T>{otherNode->data, nullptr}; // Creates a new node with copied data.

            if (head == nullptr) { // Checks if the head is null.
                head = node; // Assigns the node to the head.
            } else if (prevNode != nullptr) { // Checks if the previous node is not null.
                prevNode->next = node; // Assigns the node to the next of the previous node.
            }
            prevNode = node;
        }
    }

    // Adds a node to the end of the linked list.
    void add(T value) {
        Node<T>* node = new Node<T>{value, nullptr}; // Creates a new node.
        if (head == nullptr) { // Checks if the head is null.
            head = node; // Assigns the node to the head.
        } else {
            Node<T>* currentPtr = head; // Starts from the head.
            while (currentPtr->next != nullptr) {
                currentPtr = currentPtr->next; // Traverses to the end of the linked list.
            }
            currentPtr->next = node; // Assigns the node to the next of the last node.
        }
    }

    // Adds a node at a given index.
    void add(int index, T value) {
        Node<T>* newNode = new Node<T>{value, nullptr};
        if (index == 0) { // For insertion at the head.
            newNode->next = head;
            head = newNode;
        } else {
            Node<T>* currentNode = getNodePointer(index - 1);
            newNode->next = currentNode->next;
            currentNode->next = newNode;
        }
    }

    // Removes a node at a given index.
    void remove(int index) {
        if (index == 0 && head != nullptr) { // For head deletion.
            Node<T>* nodeToBeDeleted = head;
            head = head->next;
            delete nodeToBeDeleted;
        } else {
            Node<T>* previousNode = getNodePointer(index - 1);
            Node<T>* nodeToBeDeleted = previousNode->next;
            if (nodeToBeDeleted == nullptr) throw std::out_of_range("Index out of bounds.");
            previousNode->next = nodeToBeDeleted->next;
            delete nodeToBeDeleted;
        }
    }

    // Removes the element at a given index and returns the element.
    T take(int index) {
        T takenItem = get(index); // Gets the data from the node at the given index.
        remove(index); // Removes the node at the given index.
        return takenItem;
    }

    // Returns data from a node at a given index.
    T get(int index) {
        Node<T>* currentNode = getNodePointer(index);
        return currentNode->data;
    }

    // Returns the number of elements.
    int length() {
        int count = 0;
        Node<T>* currentNode = head;
        while (currentNode != nullptr) {
            ++count;
            currentNode = currentNode->next;
        }
        return count;
    }

    // Removes all elements from the list.
    void removeAll() {
        while (head != nullptr) {
            remove(0);
        }
    }

    // Swaps data of two nodes.
    void swap(int index1, int index2) {
        Node<T>* first = getNodePointer(index1);
        Node<T>* second = getNodePointer(index2);

        T temp = first->data;
        first->data = second->data;
        second->data = temp;
    }

    // Destructor.
    ~LinkedList() {
        removeAll();
    }
};

template<typename T>
class DoublyLinkedList { // Doubly linked list implementation.
    protected:
        DoublyNode<T>* head{nullptr}; // Head of the doubly linked list.
        DoublyNode<T>* tail{nullptr}; // Tail of the doubly linked list.
    public:
        DoublyLinkedList() {}; // Constructor for the doubly linked list.
        void add(T value) { // Adds a node to the doubly linked list.
            DoublyNode<T>* newNode = new DoublyNode<T>; // Creates a new node.
            newNode->data = value; // Assigns the value to the new node.

            if (head == nullptr) { // Checks if the head is null.
                head = newNode; // Assigns the new node to the head.
                tail = newNode; // Assigns the new node to the tail.
            }
            else {
                DoublyNode<T>* currentNode = head; // Starts from the head.
                while (currentNode->next != nullptr) { // Traverses to the end of the doubly linked list.
                    currentNode = currentNode->next; // Moves to the next node.
                }
                currentNode->next = newNode; // Assigns the new node to the next of the last node.
                newNode->prev = currentNode; // Assigns the last node to the previous of the new node.
                tail = newNode; // Assigns the new node to the tail.
            }
        }
        void remove(int index) { // Removes a node at a given index.
            if (index == 0) { // For head deletion.
                DoublyNode<T>* nodeToRemove = head; // Assigns the head to the node to be removed.
                this->head = head->next; // Assigns the next of the head to the head.
                head->prev = nullptr; // Assigns the previous of the head to null.
                delete nodeToRemove; // Deletes the node.
            }
            else {
                DoublyNode<T>* currentNode = head; // Starts from the head.
                for (int i = 0; i < index; ++i) {
                    if (currentNode->next == nullptr) { // Checks if the next of the current node is null.
                        throw std::out_of_range("Index out of range"); 
                    }
                    currentNode = currentNode->next; // Moves to the next node.
                }
                if (currentNode->next != nullptr) { // Checks if the next of the current node is not null.
                    currentNode->next->prev = currentNode->prev;
                }
                if (currentNode->prev != nullptr) { // Checks if the previous of the current node is not null.
                    currentNode->prev->next = currentNode->next;
                }
                delete currentNode; // Deletes the current node.
            }
        }
        void forwardTraverseDemo() { // Traverses the doubly linked list in the forward direction.
            DoublyNode<T>* currentNode = head; // Starts from the head.
            while (currentNode->next != nullptr) { // Traverses to the end of the doubly linked list.
                std::cout << currentNode->data; // Prints the data.
                if (currentNode->next != nullptr) { // Checks if the next of the current node is not null.
                    std::cout << "; "; // Prints a separator.
                }
                currentNode = currentNode->next; // Moves to the next node.
            }
            std::cout << currentNode->data;
            std::cout << "\n";
        }
        void reverseTraverseDemo() { // Traverses the doubly linked list in the reverse direction.
            DoublyNode<T>* currentNode = tail; // Starts from the tail.
            while (currentNode->prev != nullptr) { // Traverses to the start of the doubly linked list.
                std::cout << currentNode->data; // Prints the data.
                if (currentNode->prev != nullptr) { // Checks if the previous of the current node is not null.
                    std::cout << "; "; // Prints a separator.
                }
                currentNode = currentNode->prev; // Moves to the previous node.
            }
            std::cout << currentNode->data;
            std::cout << "\n";
        }
};

template <typename T>
class OrderedLinkedList : public LinkedList<T> { // Ordered linked list implementation.
    public:
        void add(std::string newNodeValue) { // adds a node in an ordered manner.
            Node<std::string>* newNode = new Node<std::string>; // creates a new node.
            newNode->data = newNodeValue; // assigns the value to the new node.

            if (this->head == nullptr) { // checks if the head is null.
                this->head = newNode; // assigns the new node to the head.
            }
            else {
                Node<std::string>* currentNode{this->head}; // starts from the head.
                Node<std::string>* prevNode{nullptr}; // previous node pointer.
                while (newNodeValue.compare(currentNode->data) > 0 && currentNode->next != nullptr) { 
                    /* traverse until the new value is less than the current value
                    or the current value's next is a nullptr
                    */
                    prevNode = currentNode;
                    currentNode = currentNode->next;
                }
                if (prevNode == nullptr) { // runs if there's only one node: the while breaks when next is nullptr
                    if (newNodeValue.compare(currentNode->data) <= 0) { // checks if the new node is smaller or equal to the only member
                        this->head = newNode;
                        newNode->next = currentNode;
                    }
                    else {
                        currentNode->next = newNode;
                    }
                }
                else if (newNodeValue.compare(currentNode->data) <= 0) { // checks if the new value is less than the current value
                    prevNode->next = newNode;
                    newNode->next = currentNode;
                }
                else { // checks if the next value of the current node points to nothing
                    currentNode->next = newNode;
                }
                
            }
        }
        T get(int index) { // returns the data from a node at a given index.
            return LinkedList<T>::get(index);
        }
        int length() { // returns the number of elements in the linked list.
            return LinkedList<T>::length();
        }
        void remove(int index) { // removes a node at a given index.
            LinkedList<T>::remove(index);
        }
        void removeAll() { // removes all elements from the linked list.
            LinkedList<T>::removeAll();
        }
        T take(int index) { // removes a node at a given index and returns the data.
            return LinkedList<T>::take(index);
        }
};



/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 1.
----------------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 2: Dasar-dasar implementasi Linked List.
----------------------------------------------------------------------------------------------------------------------------------------*/

template <typename T>
class Stack {
private:
    int top{-1};
    LinkedList<T> stack;

public:
    Stack() = default;

    bool isEmpty() const {
        return top == -1;
    }

    void push(T item) {
        stack.add(item);
        ++top;
    }
    int length() const { // returns the number of elements.
        return top + 1;
    }
    T pop() {
        if (isEmpty()) throw std::out_of_range("Stack is empty.");
        return stack.take(top--);
    }

    T peek() const {
        if (isEmpty()) throw std::out_of_range("Stack is empty.");
        return stack.get(top);
    }
};

template <typename T>
class Queue {
private:
    int front{-1};
    int rear{-1};
    LinkedList<T> queue;

public:
    Queue() = default;

    bool isEmpty() const {
        return front == -1;
    }

    void enqueue(T item) {
        queue.add(item);
        if (isEmpty()) front = 0;
        ++rear;
    }

    T dequeue() {
        if (isEmpty()) throw std::out_of_range("Queue is empty.");
        if (front == rear) front = rear = -1;
        return queue.take(0);
    }

    T peek() const {
        if (isEmpty()) throw std::out_of_range("Queue is empty.");
        return queue.get(0);
    }
};

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 2.
----------------------------------------------------------------------------------------------------------------------------------------*/

class linkedListTwoFour: public Program {
public:
    void start() override;
};

class linkedListThreeOne: public Program {
public:
    void start() override;
};

class linkedListThreeTwo: public Program {
public:
    void start() override;
};

class linkedListThreeThree: public Program {
public:
    void start() override;
};

class linkedListThreeFour: public Program {
public:
    void start() override;
};

class linkedListThreeFive: public Program {
public:
    void start() override;
};

class linkedListThreeSix: public Program {
public:
    void start() override;
};

#endif