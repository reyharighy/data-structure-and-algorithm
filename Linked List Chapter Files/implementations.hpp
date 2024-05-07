#ifndef IMPLEMENTATIONS_H
#define IMPLEMENTATIONS_H
// for data structures that implement the linkedlist class as defined in ./linkedlist.hpp.
#include "linkedlist.hpp"

namespace Implementations {
    template <typename T>
    class Stack {
        private:
            int size{}; 
            int top{-1};
            LinkedList::LinkedList<T> stack = LinkedList::LinkedList<T>();
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
            void push(T item) {
                if (!isFull()) {
                    stack.add(item);
                    ++top;
                }
            } 
            T pop() {
                T data = stack.take(top);
                --top;
                return data;
            }
            T peek() {
                return stack.get(top);
            }
    };
}   

#endif