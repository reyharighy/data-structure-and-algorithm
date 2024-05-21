#include "./Linked List Chapter Files/declaration.hpp"

#include <iostream>

int main() {
    while (true) {
        std::cout << "Aplikasi Linked List" << "\n";
        // std::cout << "what the fuck am i supposed to do from here" << "\n";
        std::cout << "(1) String Reversal | (2) Stack Implementation | (3) Queue Implementation | "
        << "(4) Ordered Data Input | (5) Doubly Linked List | (6) Infix-Postfix Processing | (7) Kode-Nama | (8) Keluar\n";
        int input{};
        std::cout << "Input: ";
        std::cin >> input;

        switch (input) {
            case 1:
            // call string reversal function.
                LinkedListChapter::ReverseString::demo();
                break;
            case 2:
            // call stack implementation function.
                LinkedListChapter::StackDemo::demo();
                break;
            case 3:
            // call queue implementation function.
                LinkedListChapter::QueueDemo::demo();
                break;
            case 4:
            // call ordered data input function.
                LinkedListChapter::OrderedListDemo::demo();
                break;
            case 5:
            // call doubly linked list function.
                LinkedListChapter::DoublyLinkedListDemo::demo();
                break;
            case 6:
                LinkedListChapter::PostfixProcessingDemo::demo();
            // call infix-postfix processing function.
                break;
            case 7:
                LinkedListChapter::KeyValListDemo::demo();
            case 8:
                return 0;
                break;
            default:
                break;
        }
    }
}