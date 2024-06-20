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
    PART 1: Namespace untuk berbagai masalah yang berkaitan dengan Linked List, Doubly Linked List, dan Ordered Linked List.
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

    void add(T value) { // Adds a node to the end of the linked list.
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

    void add(size_t index, T value) { // Adds a node at a given index.
        Node<T>* newNode = new Node<T>{value, nullptr};
        if (index == 0) { // For insertion at the head.
            newNode->next = head;
            head = newNode;
        } else {
            Node<T>* currentNode = getNodePointer(index - 1);
            for (int i = 0; i < index - 1; ++i) {
                if (currentNode->next == nullptr) {
                    throw std::out_of_range("Index out of bounds.");
                }

                currentNode = currentNode->next;
            }
            newNode->next = currentNode->next;
            currentNode->next = newNode;
        }
    }

    void remove(size_t index) { // Removes a node at a given index.
        if (index == 0 && head != nullptr) { // For head deletion.
            Node<T>* nodeToBeDeleted = head;
            head = head->next;
            delete nodeToBeDeleted;
        } else {
            Node<T>* currentNode = head;
            Node<T>* previousNode = nullptr;
            for (int i = 0; i < index; ++i) {
                if (currentNode->next == nullptr) {
                    throw std::out_of_range("Index out of bounds.");
                }

                previousNode = currentNode;
                currentNode = currentNode->next;
            }
            previousNode->next = currentNode->next;
            delete currentNode;
        }
    }

    T take(size_t index) {
        T takenItem = get(index); // Gets the data from the node at the given index.
        remove(index); // Removes the node at the given index.
        return takenItem;
    }

    T get(size_t index) { // returns data from a node at a given index.
        Node<T>* currentNode = head;
        for (int i = 0; i <= index; ++i) {
            if (i == index) {
                return currentNode->data;
            }
            if (currentNode->next == nullptr) {
                break;
            }
            currentNode = currentNode->next;
        }
        throw std::out_of_range("Index out of bounds");
    };

    size_t length() { // returns the number of elements.
        int i{0};
        Node<T>* currentNode = head;
        if (head != nullptr) {
            while (currentNode->next != nullptr) {
                ++i;
                currentNode = currentNode->next;
            }
            ++i;
        }
        return i;
    };

    void removeAll() { // removes all elements from the list.
        while(head) {
            remove(0);
        };
    };

    void swap(int index1, int index2) { // Swaps data of two nodes.
        Node<T>* first = getNodePointer(index1);
        Node<T>* second = getNodePointer(index2);

        T temp = first->data;
        first->data = second->data;
        second->data = temp;
    }

    ~LinkedList() { // Destructor.
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
    PART 2: Implementasi Linked List untuk stack dan queue.
----------------------------------------------------------------------------------------------------------------------------------------*/

template <typename T>
class Stack {
private:
    int size{}; 
    int top{-1}; // Top of the stack.
    LinkedList<T> stack; // Linked list to store the stack.

public:
    Stack(int size = -1) {
        this->size = size;
    }
    bool isEmpty() {
        return top == -1;
    }
    bool isFull() {
        return (top == size - 1) && (size != -1);
    }
    size_t length() {
        return top + 1;
    }
    void push(T item) {
        if (!isFull()) {
            stack.add(item);
            ++top;
        }
        else {
            throw std::out_of_range("Stack is full.");
        }
    } 
    T pop() {
        if (top == - 1) {
            throw std::out_of_range("Stack is empty.");
        }
        else {
            T data = stack.take(top);
            --top;
            return data;
        }
    }
    T peek() {
        return stack.get(top);
    }
};

template <typename T>
class Queue {
    private:
        int front{-1};
        int rear{-1};
        LinkedList<T> queue = LinkedList<T>();
    public:
        size_t size{};
        Queue(size_t size = 0) {
            this->size = size;
        }
        bool isEmpty() {
            return front == -1 && rear == -1;
        }
        bool isFull() {
            return front == 0 && rear == size - 1;
        }
        void enqueue(T item) {
            if (!isFull()) {
                queue.add(item);
                if (isEmpty()) {
                    front = 0;
                }
                ++rear;
            }
            else {
                throw std::out_of_range("Queue is full.");
            }
        }
        T dequeue() {
            if (!isEmpty()) {
                T data = queue.take(front);
                --rear;
                if (rear < front) {
                    front = -1;
                }
                return data;
            }
            throw std::out_of_range("Queue is empty.");
        }
        T peek() {
            if (!isEmpty()) {
                return queue.get(front);
            }
            throw std::out_of_range("Queue is empty.");
        }
};

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 2.
----------------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 3: Implementasi Linked List untuk berbagai tugas.
----------------------------------------------------------------------------------------------------------------------------------------*/

class linkedListTwoFour: public Program {
private:
    std::string invalidIntInput;
public:
    void start() override;
};

class linkedListThreeOne: public Program {
private:
    std::string invalidIntInput;
public:
    void start() override;
};

class linkedListThreeTwo: public Program {
private:
    std::string invalidIntInput;
public:
    void start() override;
};

class linkedListThreeThree: public Program {
private:
    std::string invalidIntInput;
public:
    void start() override;
};

class linkedListThreeFour: public Program {
private:
    std::string invalidIntInput;
public:
    void start() override;
};

class linkedListThreeFive: public Program {
private:
    std::string invalidIntInput;
public:
    void start() override;
};

class linkedListThreeSix: public Program {
private:
    std::string invalidIntInput;
public:
    void start() override;
};

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 3.
----------------------------------------------------------------------------------------------------------------------------------------*/

#endif