#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <string>

namespace LinkedListChapter {
    template <typename T>
    struct Node {
        T data;
        Node<T>* next{nullptr};
    };

    template <typename T>
    class LinkedList {
        private:
            Node<T>* getNodePointer(size_t index) { // returns a pointer to a node at a given index
                Node<T>* currentNode = head;
                for (int i{0}; i < index; ++i) {
                    if (currentNode->next == nullptr) { // Checks if the next points to nullptr, before moving to it. 
                        throw std::out_of_range("Index out of bounds.");  
                    }
                    currentNode = currentNode->next;
                }
                return currentNode;
            }
            Node<T>* head{nullptr};
            int size{0};
            int maxsize{-1};
        public:
            void add(T value) { // appends node to the linkedlist.
                Node<T>* node = new Node<T>;
                node->data = value;

                if (head == nullptr) {
                    head = node;
                }
                else {
                    Node<T>* currentPtr = head;
                    while (currentPtr->next != nullptr) {
                        currentPtr = currentPtr->next;
                    }
                    currentPtr->next = node;
                }
            };
            void add(size_t index, T value) { // adds a node at a given index
                Node<T>* newNode = new Node<T>;
                newNode->data = value;

                if (index == 0) { // for insertion on the head.
                    newNode->next = head;
                    head = newNode;
                }
                else {
                    Node<T>* currentNode = head;
                    for (int i = 0; i < index - 1; ++i) {
                        if (currentNode->next == nullptr) {
                            throw std::out_of_range("Index out of bounds.");
                        }

                        currentNode = currentNode->next;
                    }
                    newNode->next = currentNode->next;
                    currentNode->next = newNode;
                }
            };
            void remove(size_t index) { // removes an element at a given index
                if (index == 0) { // for head deletion.
                    Node<T>* nodeToBeDeleted = head;
                    head = head->next;
                    delete nodeToBeDeleted;
                }
                else {
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
            };
            T take(size_t index) { // removes the element at a given index and returns the element given. 
                T takenItem = get(index);
                remove(index);
                return takenItem;
            };
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
            void swap(size_t index1, size_t index2) { // swaps data of two nodes.
                Node<T>* first = getNodePointer(index1);
                Node<T>* second = getNodePointer(index2);
                
                T temp = first->data;
                first->data = second->data;
                second->data = temp;
            }
            ~LinkedList() { // destructor. 
                removeAll();
            };
    };
}

#endif